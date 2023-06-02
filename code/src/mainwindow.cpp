#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QMessageBox>
#include <QMouseEvent>
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


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), undoStack(new QUndoStack(this)), m_delegate(new CSVItemDelegate(&model, undoStack, this)) {
    ui->setupUi(this);
    // Install event filter
    ui->tableView->verticalHeader()->installEventFilter(this);
    ui->tableView->setItemDelegate(m_delegate);


    if (!model.loadCSV(MainWindow::FILEPATH, MainWindow::CSVCOLUMNS))
    {
        QMessageBox::critical(this, "Error", "Failed to load CSV file.");
        return;
    }


    watcher.addPath(MainWindow::FILEPATH);
    connect(&watcher, &QFileSystemWatcher::fileChanged, this, &MainWindow::onFileChanged);
    ui->tableView->setModel(&model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    //TODO: MAKE SORTING AVAILABLE WHILE FILTERING
    // Sorting using QSortFilterProxyModel
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(&model);
    ui->tableView->setModel(proxyModel);


    // Creating FilterModel
    filterModel = new CSVFilterModel(this);
    filterModel->setSourceModel(&model);


    // Creating FilterDialog
    filterDialog = new FilterDialog(this);
    connect(filterDialog, &FilterDialog::filterChanged, this, &MainWindow::applyFilter);


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
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->tableView->verticalHeader() && event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        int row = ui->tableView->verticalHeader()->logicalIndexAt(mouseEvent->pos());
        handleRowHeaderClicked(row);
        return true;
    }
    return QMainWindow::eventFilter(watched, event);
}


void MainWindow::AddRow()
{
    RowAddDialog dialog(this);

    // Open the dialog and check if the user clicked OK
    if(dialog.exec() == QDialog::Accepted)
    {
        QStringList rowData = dialog.rowData();
        QItemSelectionModel *select = ui->tableView->selectionModel();
        int selectedRow = model.rowCount(); // default to end of list

        if(select->hasSelection()) // if a row is selected
        {
            selectedRow = select->selectedRows().first().row() + 1; // get selected row
        }

        AddRowCommand *command = new AddRowCommand(&model, rowData, selectedRow);
        undoStack->push(command);
    }
}


void MainWindow::RemoveRow()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();

    if(select->hasSelection()) //check if has selection
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation", "Are you sure you want to delete this row?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            // m_model.removeRow(select->selectedRows().first().row(), QModelIndex());
            int row = select->selectedRows().first().row();
            undoStack->push(new RemoveRowCommand(&model, row));
        }
    }
}


void MainWindow::SaveCSV()
{
    if (!model.saveCSV(MainWindow::FILEPATH))
    {
        QMessageBox::critical(this, "Error", "Failed to save CSV file.");
    }
}


void MainWindow::EditRow()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();

    if(select->hasSelection()) //check if has selection
    {
        // Getting the selected row number
        int row = select->selectedRows().first().row();

        // Getting current data of the row
        QStringList oldData = model.getRowData(row);

        // Create and setup dialog
        RowEditDialog dialog(this);
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
    proxyModel->setSourceModel(nullptr); // Temporarily unset the source model
    model.clear(); // Clears the current data of the model
    if (!model.loadCSV(MainWindow::FILEPATH, MainWindow::CSVCOLUMNS)) // Load the CSV file again
    {
        QMessageBox::critical(this, "Error", "Failed to reload CSV file.");
    }
    proxyModel->setSourceModel(&model); // Reset the source model to the loaded data
    filterModel->setSourceModel(&model);
}


void MainWindow::handleRowHeaderClicked(int row)
{
    QStringList rowData = model.getRowData(row);
    QStringList headerData = model.getHeaderData();

    QString info;
    for (int i = 0; i < rowData.size() && i < headerData.size(); i++)
    {
        info += QString("%1: %2").arg(headerData[i]).arg(rowData[i]) + "\n";
    }

    QMessageBox::information(this, "Row Data", info);
}


void MainWindow::on_undoButton_clicked()
{
    undoStack->undo();
}


void MainWindow::on_logoButton_clicked()
{
    // Show the logo window
    logoWindow = new LogoWindow(this);
    logoWindow->setAttribute(Qt::WA_DeleteOnClose); // Set the attribute so that the window is deleted when it's closed
    logoWindow->show();
}


void MainWindow::onFileChanged(const QString &path)
{
    model.loadCSV(path, MainWindow::CSVCOLUMNS);
}


void MainWindow::openHelpWindow()
{
    HelpWindow* helpWindow = new HelpWindow(this);
    helpWindow->show();
}


void MainWindow::openFilterDialog()
{
    filterDialog->show();
}


void MainWindow::applyFilter()
{
    QString stateFilter = filterDialog->getStateFilter();
    filterModel->setStateFilter(stateFilter);
    QMap<int, QPair<double, double>> filterMap = filterDialog->getFilterMap();

    filterModel->setFilterMap(filterMap);
    ui->tableView->setModel(filterModel);
    filterModel->refreshFilter();
}


void MainWindow::onSortBoxChanged(int index)
{
    if (index == 0) // Not Sorted
    {
        delete proxyModel;
        proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(&model);
        ui->tableView->setModel(proxyModel);
    }
    else
    {
        bool reverseOrder = ui->orderButton->isChecked();  // Check the state of the radio button
        proxyModel->sort(index - 1, reverseOrder ? Qt::AscendingOrder : Qt::DescendingOrder);  // Pass the reverseOrder flag to sort()
        ui->tableView->setModel(proxyModel);
    }
}


void MainWindow::sort(int column, bool ascending)
{
    // Map column to CSV model index
    column = MainWindow::CSVCOLUMNS[column - 1];

    if (column < 0) // Not Sorted selected
    {
        proxyModel->invalidate(); // Invalidate the current sorting
    }
    else
    {
        proxyModel->setDynamicSortFilter(true); // Enable sorting
        proxyModel->setSortRole(Qt::DisplayRole);
        proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive);
        proxyModel->sort(column, ascending ? Qt::AscendingOrder : Qt::DescendingOrder);
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
    ui->tableView->setModel(proxyModel);
    lastClickedSection = logicalIndex;
    ui->sortBox->setCurrentIndex(logicalIndex + 1);  // +1 because index 0 is 'Not Sorted'
}


MainWindow::~MainWindow()
{
    delete proxyModel;
    delete filterDialog;
    delete filterModel;
    delete ui;
}
