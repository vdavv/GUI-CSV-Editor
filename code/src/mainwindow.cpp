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
const QString MainWindow::FILEPATH = "/Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/data/MetroHealth83Original.csv";


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), m_undoStack(new QUndoStack(this)), m_delegate(new CSVItemDelegate(&m_model, m_undoStack, this)) {
    ui->setupUi(this);
    // Install event filter
    ui->tableView->verticalHeader()->installEventFilter(this);
    ui->tableView->setItemDelegate(m_delegate);


    if (!m_model.loadCSV(MainWindow::FILEPATH, MainWindow::CSVCOLUMNS)) {
        QMessageBox::critical(this, "Error", "Failed to load CSV file.");
        return;
    }


    m_watcher.addPath(MainWindow::FILEPATH);
    connect(&m_watcher, &QFileSystemWatcher::fileChanged, this, &MainWindow::onFileChanged);
    ui->tableView->setModel(&m_model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);


    // Sorting using QSortFilterProxyModel
    m_proxyModel = new QSortFilterProxyModel(this);
    m_proxyModel->setSourceModel(&m_model);
    ui->tableView->setModel(m_proxyModel);


    // Creating FilterModel
    m_filterModel = new CSVFilterModel(this);
    m_filterModel->setSourceModel(&m_model);


    // Creating FilterDialog
    m_filterDialog = new FilterDialog(this);
    connect(m_filterDialog, &FilterDialog::filterChanged, this, &MainWindow::applyFilter);


    // Creating LogoWindow
    m_logoWindow = new LogoWindow(this);
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
    if (watched == ui->tableView->verticalHeader() && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        int row = ui->tableView->verticalHeader()->logicalIndexAt(mouseEvent->pos());
        handleRowHeaderClicked(row);
        return true;
    }
    return QMainWindow::eventFilter(watched, event);
}


void MainWindow::AddRow() {
    RowAddDialog dialog(this);

    // Open the dialog and check if the user clicked OK
    if(dialog.exec() == QDialog::Accepted) {
        QStringList rowData = dialog.rowData();
        QItemSelectionModel *select = ui->tableView->selectionModel();
        int selectedRow = m_model.rowCount(); // default to end of list

        if(select->hasSelection()) { // if a row is selected
            selectedRow = select->selectedRows().first().row() + 1; // get selected row
        }

        if(m_model.insertRow(selectedRow, QModelIndex())) {
            for(int column = 0; column < m_model.columnCount(); column++) {
                QModelIndex index = m_model.index(selectedRow, column);
                // m_model.setData(index, rowData.at(column));
            }
        }
        AddRowCommand *command = new AddRowCommand(&m_model, rowData, selectedRow);
        m_undoStack->push(command);
    }
}


void MainWindow::RemoveRow() {
    QItemSelectionModel *select = ui->tableView->selectionModel();

    if(select->hasSelection()) { //check if has selection
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation", "Are you sure you want to delete this row?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            // m_model.removeRow(select->selectedRows().first().row(), QModelIndex());
            int row = select->selectedRows().first().row();
            m_undoStack->push(new RemoveRowCommand(&m_model, row));
        }
    }
}


void MainWindow::SaveCSV() {
    if (!m_model.saveCSV(MainWindow::FILEPATH)) {
        QMessageBox::critical(this, "Error", "Failed to save CSV file.");
    }
}


void MainWindow::EditRow() {
    QItemSelectionModel *select = ui->tableView->selectionModel();

    if(select->hasSelection()) { //check if has selection
        // Getting the selected row number
        int row = select->selectedRows().first().row();

        // Getting current data of the row
        QStringList oldData = m_model.getRowData(row);

        // Create and setup dialog
        RowEditDialog dialog(this);
        dialog.setRowData(oldData); // use setRowData instead of setData

        // If Ok is pressed then apply changes to the model
        if (dialog.exec() == QDialog::Accepted) {
            QStringList newData = dialog.rowData(); // use rowData instead of getData
            auto* command = new EditRowCommand(&m_model, row, oldData, newData);
            m_undoStack->push(command);
//            for (int i = 0; i < newData.size(); ++i) {
//                QModelIndex index = m_model.index(row, i);
//                m_model.setData(index, newData[i]);
//            }
        }
    }
}


void MainWindow::ReloadCSV() {
    m_proxyModel->setSourceModel(nullptr); // Temporarily unset the source model
    m_model.clear(); // Clears the current data of the model
    if (!m_model.loadCSV(MainWindow::FILEPATH, MainWindow::CSVCOLUMNS)) { // Load the CSV file again
        QMessageBox::critical(this, "Error", "Failed to reload CSV file.");
    }
    m_proxyModel->setSourceModel(&m_model); // Reset the source model to the loaded data
    m_filterModel->setSourceModel(&m_model);
}


void MainWindow::handleRowHeaderClicked(int row) {
    QStringList rowData = m_model.getRowData(row);
    QStringList headerData = m_model.getHeaderData();

    QString info;
    for (int i = 0; i < rowData.size() && i < headerData.size(); i++) {
        info += QString("%1: %2").arg(headerData[i]).arg(rowData[i]) + "\n";
    }

    QMessageBox::information(this, "Row Data", info);
}


//void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
//{
//    ui->tableView->edit(index);
//}


void MainWindow::on_undoButton_clicked()
{
    m_undoStack->undo();
}


void MainWindow::on_logoButton_clicked()
{
    // Show the logo window
    m_logoWindow->show();
}


void MainWindow::onFileChanged(const QString &path) {
    m_model.loadCSV(path, MainWindow::CSVCOLUMNS);
}


void MainWindow::openHelpWindow() {
    HelpWindow* helpWindow = new HelpWindow(this);
    helpWindow->show();
}


void MainWindow::openFilterDialog() {
    m_filterDialog->show();
}


void MainWindow::applyFilter()
{
    QString stateFilter = m_filterDialog->getStateFilter();
    m_filterModel->setStateFilter(stateFilter);
    QMap<int, QPair<double, double>> filterMap = m_filterDialog->getFilterMap();

    m_filterModel->setFilterMap(filterMap);
    ui->tableView->setModel(m_filterModel);
    m_filterModel->refreshFilter();
}


void MainWindow::onSortBoxChanged(int index) {
    if (index == 0) {  // Not Sorted
        delete m_proxyModel;
        m_proxyModel = new QSortFilterProxyModel(this);
        m_proxyModel->setSourceModel(&m_model);
        ui->tableView->setModel(m_proxyModel);
    } else {
        bool reverseOrder = ui->orderButton->isChecked();  // Check the state of the radio button
        m_proxyModel->sort(index - 1, reverseOrder ? Qt::AscendingOrder : Qt::DescendingOrder);  // Pass the reverseOrder flag to sort()
        ui->tableView->setModel(m_proxyModel);
    }
}


void MainWindow::sort(int column, bool ascending) {
    // Map column to CSV model index
    column = MainWindow::CSVCOLUMNS[column - 1];

    if (column < 0) { // Not Sorted selected
        m_proxyModel->invalidate(); // Invalidate the current sorting
    } else {
        m_proxyModel->setDynamicSortFilter(true); // Enable sorting
        m_proxyModel->setSortRole(Qt::DisplayRole);
        m_proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive);
        m_proxyModel->sort(column, ascending ? Qt::AscendingOrder : Qt::DescendingOrder);
    }
}



void MainWindow::onHeaderSectionClicked(int logicalIndex) {
    bool reverseOrder = false;
    if (logicalIndex == m_lastClickedSection) {
        // If the same section is clicked twice, reverse the order
        reverseOrder = !ui->orderButton->isChecked();
        ui->orderButton->setChecked(reverseOrder);
    }
    ui->tableView->setModel(m_proxyModel);
    m_lastClickedSection = logicalIndex;
    ui->sortBox->setCurrentIndex(logicalIndex + 1);  // +1 because index 0 is 'Not Sorted'
}


MainWindow::~MainWindow() {
    delete m_proxyModel;
    delete m_filterDialog;
    delete m_filterModel;
    delete m_logoWindow;
    delete ui;
}
