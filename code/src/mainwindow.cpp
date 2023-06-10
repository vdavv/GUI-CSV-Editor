#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QMessageBox>
#include <QMouseEvent>
#include <QFileDialog>
#include <QTextStream>
#include "rowadddialog.h"
#include "roweditdialog.h"
#include "helpwindow.h"
#include "filterdialog.h"
#include "addrowcommand.h"
#include "removerowcommand.h"
#include "editrowcommand.h"
#include "logowindow.h"


const QVector<int> MainWindow::CSVCOLUMNS = {0, 1, 2, 3, 4, 5, 6, 7, 8};
const QString MainWindow::FILEPATH = CSV_FILE_PATH;


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), undoStack(new QUndoStack(this)), delegate(new CSVItemDelegate(&model, &filterModel, undoStack, this)) {
    ui->setupUi(this);
    // Install event filter
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
    // filterModel = new CSVFilterModel(this);
    filterModel.setSourceModel(&model);


    // Creating FilterDialog
    filterDialog = new FilterDialog(this);
    connect(filterDialog, &FilterDialog::filterChanged, this, &MainWindow::applyFilter);


    // Creating HelpWindow
    helpWindow = new HelpWindow(this);
    connect(helpWindow, &HelpWindow::languageChanged, this, &MainWindow::translateUi);
    connect(helpWindow, &HelpWindow::languageChanged, filterDialog, &FilterDialog::translateUi);


    // Creating LogoWindow
    // logoWindow = new LogoWindow(this);
    connect(ui->logoButton, &QPushButton::clicked, this, &MainWindow::on_logoButton_clicked);


    // Connect sectionClicked signal of the vertical header to handleRowHeaderClicked slot
    connect(ui->tableView->verticalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::handleRowHeaderClicked);


    // Connect your buttons with the slots
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
    // connect(ui->undoButton, &QPushButton::clicked, m_undoStack, &QUndoStack::undo);

    // Connect helpwindow translate box with translate functions

}


void MainWindow::AddRow()
{
    RowAddDialog dialog(this, lang);

    // Open the dialog and check if the user clicked OK
    if(dialog.exec() == QDialog::Accepted)
    {
        QStringList rowData = dialog.rowData();
        QItemSelectionModel *select = ui->tableView->selectionModel();
        int selectedRow = model.rowCount(); // default to end of list

        if(select->hasSelection()) // if a row is selected
        {
            int logicalIndex = select->selectedRows().first().row();
            QModelIndex proxyIndex = filterModel.index(logicalIndex, 0);
            QModelIndex sourceIndex = filterModel.mapToSource(proxyIndex);
            selectedRow = sourceIndex.row() + 1; // get selected row
        }

        AddRowCommand *command = new AddRowCommand(&model, rowData, selectedRow);
        undoStack->push(command);
    }
}


void MainWindow::RemoveRow()
{
    //TODO: Misdelete when filtered or sorted
    QItemSelectionModel *select = ui->tableView->selectionModel();

    if(select->hasSelection()) //check if has selection
    {
        QMessageBox::StandardButton reply;

        switch(lang){
        case 1:
            reply = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите удалить эту строку?",
                                          QMessageBox::Yes|QMessageBox::No);
            break;
        default:
            reply = QMessageBox::question(this, "Confirmation", "Are you sure you want to delete this row?",
                                          QMessageBox::Yes|QMessageBox::No);
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


void MainWindow::SaveCSV()
{
    QString dialogTitleName;
    switch(lang)
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
        CSV_FILE_PATH, // use your current file path
        tr("CSV files (*.csv)")
        );

    // if filePath is not empty, the user has not clicked Cancel
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream stream(&file);
            QStringList strList;

            // write headers
            strList.clear();
            for (int column = 0; column < model.columnCount(); ++column)
                strList << "\"" + model.headerData(column, Qt::Horizontal, Qt::DisplayRole).toString() + "\"";
            stream << strList.join(",") + "\n";

            // write data rows
            for (int row = 0; row < model.rowCount(); ++row) {
                strList.clear();
                for (int column = 0; column < model.columnCount(); ++column)
                    strList << "\"" + model.data(model.index(row, column)).toString() + "\"";
                stream << strList.join(",") + "\n";
            }

            file.close();
            // update the current file path
            // CSV_FILE_PATH = filePath;
        } else {
            // show an error message if the file couldn't be opened
            QMessageBox::critical(this, tr("Error"), tr("Could not open file for writing"));
        }
    }
}


void MainWindow::EditRow()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();

    if(select->hasSelection()) //check if has selection
    {
        // Getting the selected row number
        int logicalIndex = select->selectedRows().first().row();
        QModelIndex proxyIndex = filterModel.index(logicalIndex, 0);
        QModelIndex sourceIndex = filterModel.mapToSource(proxyIndex);

        int row = sourceIndex.row();

        // Getting current data of the row
        QStringList oldData = model.getRowData(row);

        // Create and setup dialog
        RowEditDialog dialog(this, lang);
        dialog.setRowData(oldData); // use setRowData instead of setData

        // If Ok is pressed then apply changes to the model
        if (dialog.exec() == QDialog::Accepted)
        {
            QStringList newData = dialog.rowData(); // use rowData instead of getData
            auto* command = new EditRowCommand(&model, row, oldData, newData);
            undoStack->push(command);
        }
    }
}


void MainWindow::ReloadCSV()
{
    filterModel.setSourceModel(nullptr); // Temporarily unset the source model
    model.clear(); // Clears the current data of the model
    if (!model.loadCSV(MainWindow::FILEPATH, MainWindow::CSVCOLUMNS)) // Load the CSV file again
    {
        QMessageBox::critical(this, "Error", "Failed to reload CSV file.");
    }
    filterModel.setSourceModel(&model); // Reset the source model to the loaded data
    undoStack->clear(); // Clear the undo stack
}


void MainWindow::handleRowHeaderClicked(int logicalIndex)
{
    QModelIndex proxyIndex = filterModel.index(logicalIndex, 0);
    QModelIndex sourceIndex = filterModel.mapToSource(proxyIndex);
    if (sourceIndex.isValid()) {
        // int row = proxyIndex.row(); // this is the visual index
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
    if(logoWindow)
    {
        logoWindow->raise(); // If logoWindow is already open, bring it to the front
        logoWindow->activateWindow();
    }
    else // If logoWindow is null, create a new LogoWindow
    {
        logoWindow = new LogoWindow(this, lang);
        logoWindow->setAttribute(Qt::WA_DeleteOnClose); // Set the attribute so that the window is deleted when it's closed

        // Connect the logoWindow's destroyed signal to a lambda that sets logoWindow back to nullptr when the window is closed
        QObject::connect(logoWindow, &QObject::destroyed, [this]() {
            this->logoWindow = nullptr;
        });

        logoWindow->show();
    }
}



void MainWindow::onFileChanged(const QString &path)
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
    if (index == 0) // Not Sorted
    {
        filterModel.sort(-1);
    }
    else
    {
        bool reverseOrder = ui->orderButton->isChecked();  // Check the state of the radio button
        filterModel.sort(index - 1, reverseOrder ? Qt::AscendingOrder : Qt::DescendingOrder);  // Pass the reverseOrder flag to sort()
        ui->tableView->setModel(&filterModel);
    }
}


void MainWindow::sort(int column, bool ascending)
{
    // Map column to CSV model index
    column = MainWindow::CSVCOLUMNS[column - 1];

    if (column < 0) // Not Sorted selected
    {
        filterModel.invalidate(); // Invalidate the current sorting
    }
    else
    {
        filterModel.setDynamicSortFilter(true); // Enable sorting
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
    ui->sortBox->setCurrentIndex(logicalIndex + 1);  // +1 because index 0 is 'Not Sorted'
}


void MainWindow::translateUi(int lang)
{
    switch(lang)
    {
    case 1:
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
    default:
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


MainWindow::~MainWindow()
{
    delete filterDialog;
    // delete filterModel;
    delete ui;
}
