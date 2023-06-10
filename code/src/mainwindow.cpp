#include "addrowcommand.h"
#include "editrowcommand.h"
#include "filterdialog.h"
#include "helpwindow.h"
#include "logowindow.h"
#include "mainwindow.h"
#include "removerowcommand.h"
#include "rowadddialog.h"
#include "roweditdialog.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QTableView>
#include <QTextStream>


const QVector<int> MainWindow::CSVCOLUMNS = {0, 1, 2, 3, 4, 5, 6, 7, 8};
const QString MainWindow::FILEPATH = CSV_FILE_PATH;


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow), undoStack(new QUndoStack(this)), delegate(new CSVItemDelegate(&model, &filterModel, undoStack, this))
{
    ui->setupUi(this);
    ui->tableView->verticalHeader()->installEventFilter(this);
    ui->tableView->setItemDelegate(delegate);


    if (!model.loadCSV(MainWindow::FILEPATH, MainWindow::CSVCOLUMNS))
    {
        QMessageBox::critical(this, "Error", "Failed to load CSV file.");
        return;
    }


    watcher.addPath(MainWindow::FILEPATH);
    connect(&watcher, &QFileSystemWatcher::fileChanged, this, &MainWindow::onFileChanged);
    ui->tableView->setModel(&model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);


    // Creating FilterSortModel
    filterModel.setSourceModel(&model);
    ui->tableView->setModel(&filterModel);


    // Creating FilterDialog
    filterDialog = new FilterDialog(this);
    connect(filterDialog, &FilterDialog::filterChanged, this, &MainWindow::applyFilter);


    // Creating HelpWindow
    helpWindow = new HelpWindow(this);
    connect(helpWindow, &HelpWindow::languageChanged, this, &MainWindow::translateUi);
    connect(helpWindow, &HelpWindow::languageChanged, filterDialog, &FilterDialog::translateUi);


    // Creating LogoWindow
    connect(ui->logoButton, &QPushButton::clicked, this, &MainWindow::on_logoButton_clicked);


    // Connect sectionClicked signal of the vertical header to handleRowHeaderClicked slot
    connect(ui->tableView->verticalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::handleRowHeaderClicked);


    // Connect buttons with the slots
    connect(ui->addRowButton, &QPushButton::clicked, this, &MainWindow::AddRow);
    connect(ui->removeRowButton, &QPushButton::clicked, this, &MainWindow::RemoveRow);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::SaveCSV);
    connect(ui->editRowButton, &QPushButton::clicked, this, &MainWindow::EditRow);
    connect(ui->reloadButton, &QPushButton::clicked, this, &MainWindow::ReloadCSV);
    connect(ui->helpButton, &QPushButton::clicked, this, &MainWindow::openHelpWindow);
    connect(ui->sortBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onSortBoxChanged(int)));
    connect(ui->orderButton, &QRadioButton::toggled, [this]() {
        emit ui->sortBox->currentIndexChanged(ui->sortBox->currentIndex());
    });
    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::onHeaderSectionClicked);
    connect(ui->filterButton, &QPushButton::clicked, this, &MainWindow::openFilterDialog);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::SaveCSV()
{
    QString dialogTitleName;
    switch (lang)
    {
    case 1:
        dialogTitleName = "Сохранить Файл";
        break;
    default:
        dialogTitleName = "Save File";
    }

    QString filePath = QFileDialog::getSaveFileName(
        this,
        dialogTitleName,
        CSV_FILE_PATH,
        tr("CSV files (*.csv)"));

    if (!filePath.isEmpty())
    {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly))
        {
            QTextStream stream(&file);
            QStringList strList;

            // write headers
            strList.clear();
            for (int column = 0; column < model.columnCount(); ++column)
                strList << "\"" + model.headerData(column, Qt::Horizontal, Qt::DisplayRole).toString() + "\"";
            stream << strList.join(",") + "\n";

            // write data rows
            for (int row = 0; row < model.rowCount(); ++row)
            {
                strList.clear();
                for (int column = 0; column < model.columnCount(); ++column)
                {
                    if (column != 0)
                    {
                        strList << model.data(model.index(row, column)).toString();
                        continue;
                    }
                    strList << "\"" + model.data(model.index(row, column)).toString() + "\"";
                }
                stream << strList.join(",") + "\n";
            }

            file.close();
        }

        else
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file for writing"));
        }
    }
}


void MainWindow::AddRow()
{
    RowAddDialog dialog(this, lang);

    if (dialog.exec() == QDialog::Accepted)
    {
        QStringList rowData = dialog.rowData();
        QItemSelectionModel* select = ui->tableView->selectionModel();
        int selectedRow = model.rowCount();// default to end of list

        if (select->hasSelection())// if a row is selected
        {
            int logicalIndex = select->selectedRows().first().row();
            QModelIndex proxyIndex = filterModel.index(logicalIndex, 0);
            QModelIndex sourceIndex = filterModel.mapToSource(proxyIndex);
            selectedRow = sourceIndex.row() + 1;
        }

        AddRowCommand* command = new AddRowCommand(&model, rowData, selectedRow);
        undoStack->push(command);
    }
}


void MainWindow::RemoveRow()
{
    QItemSelectionModel* select = ui->tableView->selectionModel();

    if (select->hasSelection())
    {
        QMessageBox::StandardButton reply;

        switch (lang)
        {
        case 1:
            reply = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите удалить эту строку?",
                                          QMessageBox::Yes | QMessageBox::No);
            break;
        default:
            reply = QMessageBox::question(this, "Confirmation", "Are you sure you want to delete this row?",
                                          QMessageBox::Yes | QMessageBox::No);
            break;
        }

        if (reply == QMessageBox::Yes)
        {
            int logicalIndex = select->selectedRows().first().row();
            QModelIndex proxyIndex = filterModel.index(logicalIndex, 0);
            QModelIndex sourceIndex = filterModel.mapToSource(proxyIndex);

            int row = sourceIndex.row();
            undoStack->push(new RemoveRowCommand(&model, row));
        }
    }
}


void MainWindow::EditRow()
{
    QItemSelectionModel* select = ui->tableView->selectionModel();

    if (select->hasSelection())
    {
        // Getting the selected row number
        int logicalIndex = select->selectedRows().first().row();
        QModelIndex proxyIndex = filterModel.index(logicalIndex, 0);
        QModelIndex sourceIndex = filterModel.mapToSource(proxyIndex);
        int row = sourceIndex.row();

        QStringList oldData = model.getRowData(row);
        RowEditDialog dialog(this, lang);
        dialog.setRowData(oldData);

        if (dialog.exec() == QDialog::Accepted)
        {
            QStringList newData = dialog.rowData();
            auto* command = new EditRowCommand(&model, row, oldData, newData);
            undoStack->push(command);
        }
    }
}


void MainWindow::ReloadCSV()
{
    undoStack->clear();
    filterModel.setSourceModel(nullptr);
    model.clear();
    if (!model.loadCSV(MainWindow::FILEPATH, MainWindow::CSVCOLUMNS))
    {
        QMessageBox::critical(this, "Error", "Failed to reload CSV file.");
    }
    filterModel.setSourceModel(&model);
}


void MainWindow::handleRowHeaderClicked(int logicalIndex)
{
    QModelIndex proxyIndex = filterModel.index(logicalIndex, 0);
    QModelIndex sourceIndex = filterModel.mapToSource(proxyIndex);
    if (sourceIndex.isValid())
    {
        int row = sourceIndex.row();
        QStringList rowData = model.getRowData(row);
        QStringList headerData = model.getHeaderData();

        QString info;
        for (int i = 0; i < rowData.size() && i < headerData.size(); i++)
        {
            info += QString("%1: %2").arg(headerData[i]).arg(rowData[i]) + "\n";
        }

        QMessageBox::information(this, "Row Data", info);
    }
}


void MainWindow::on_undoButton_clicked()
{
    undoStack->undo();
}


void MainWindow::on_logoButton_clicked()
{
    // Check if logoWindow is not null (i.e., it's already open)
    if (logoWindow)
    {
        logoWindow->raise();
        logoWindow->activateWindow();
    }

    else
    {
        logoWindow = new LogoWindow(this, lang);
        logoWindow->setAttribute(Qt::WA_DeleteOnClose);// Set the attribute so that the window is deleted when it's closed

        // Connect the logoWindow's destroyed signal to a lambda that sets logoWindow back to nullptr when the window is closed
        QObject::connect(logoWindow, &QObject::destroyed, [this]() {
            this->logoWindow = nullptr;
        });

        logoWindow->show();
    }
}


void MainWindow::onFileChanged(const QString& path)
{
    model.loadCSV(path, MainWindow::CSVCOLUMNS);
}


void MainWindow::openHelpWindow()
{
    helpWindow->show();
}


void MainWindow::openFilterDialog()
{
    filterDialog->show();
}


void MainWindow::applyFilter()
{
    QString stateFilter = filterDialog->getStateFilter();
    filterModel.setStateFilter(stateFilter);
    QMap<int, QPair<double, double>> filterMap = filterDialog->getFilterMap();

    filterModel.setFilterMap(filterMap);
    ui->tableView->setModel(&filterModel);
    filterModel.refreshFilter();
}


void MainWindow::onSortBoxChanged(int index)
{
    if (index == 0)// Not Sorted
    {
        filterModel.sort(-1);
    }
    else
    {
        bool reverseOrder = ui->orderButton->isChecked();                                    // Check the state of the radio button
        filterModel.sort(index - 1, reverseOrder ? Qt::AscendingOrder : Qt::DescendingOrder);// Pass the reverseOrder flag to sort()
        ui->tableView->setModel(&filterModel);
    }
}


void MainWindow::sort(int column, bool ascending)
{
    // Map column to CSV model index
    column = MainWindow::CSVCOLUMNS[column - 1];

    if (column < 0)// Not Sorted selected
    {
        filterModel.invalidate();
    }

    else
    {
        filterModel.setDynamicSortFilter(true);
        filterModel.setSortRole(Qt::DisplayRole);
        filterModel.setSortCaseSensitivity(Qt::CaseInsensitive);
        filterModel.sort(column, ascending ? Qt::AscendingOrder : Qt::DescendingOrder);
    }
}


void MainWindow::onHeaderSectionClicked(int logicalIndex)
{
    bool reverseOrder = false;
    if (logicalIndex == lastClickedSection)
    {
        // If the same section is clicked twice, reverse the order
        reverseOrder = !ui->orderButton->isChecked();
        ui->orderButton->setChecked(reverseOrder);
    }
    ui->tableView->setModel(&filterModel);
    lastClickedSection = logicalIndex;
    ui->sortBox->setCurrentIndex(logicalIndex + 1);// +1 because index 0 is 'Not Sorted'
}


void MainWindow::translateUi(int lang)
{
    switch (lang) // 1 - Russian, 0 - English, default - English
    {
    case 1:// Russian
        MainWindow::lang = 1;
        ui->undoButton->setText("Назад");
        ui->reloadButton->setText("Обновить");
        ui->saveButton->setText("Сохранить");
        ui->logoButton->setText("Лого");
        ui->helpButton->setText("Помощь");
        ui->sortBox->setItemText(0, "Не Отсортировано");
        ui->filterButton->setText("Фильтры");
        ui->editRowButton->setText("Редактировать");
        ui->addRowButton->setText("Добавить");
        ui->removeRowButton->setText("Удалить");
        return;
    default://English
        MainWindow::lang = 0;
        ui->undoButton->setText("Undo");
        ui->reloadButton->setText("Load");
        ui->saveButton->setText("Save");
        ui->logoButton->setText("Logo");
        ui->helpButton->setText("Help");
        ui->sortBox->setItemText(0, "Not Sorted");
        ui->filterButton->setText("Filter");
        ui->editRowButton->setText("Edit");
        ui->addRowButton->setText("Add");
        ui->removeRowButton->setText("Delete");
        return;
    }
}
