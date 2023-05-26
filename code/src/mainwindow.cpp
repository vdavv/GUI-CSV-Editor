#include "mainwindow.h"
#include "roweditdialog.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QMessageBox>
#include <QMouseEvent>


const QVector<int> MainWindow::CSVCOLUMNS = {0, 1, 2, 3, 4, 5, 6, 7, 8};
const QString MainWindow::FILEPATH = "/Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/data/MetroHealth83Original.csv";


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // Install event filter
    ui->tableView->verticalHeader()->installEventFilter(this);
    if (!m_model.loadCSV(MainWindow::FILEPATH, MainWindow::CSVCOLUMNS)) {
        QMessageBox::critical(this, "Error", "Failed to load CSV file.");
        return;
    }
    m_watcher.addPath(MainWindow::FILEPATH);
    connect(&m_watcher, &QFileSystemWatcher::fileChanged, this, &MainWindow::onFileChanged);
    ui->tableView->setModel(&m_model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Connect sectionClicked signal of the vertical header to handleRowHeaderClicked slot
    connect(ui->tableView->verticalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::handleRowHeaderClicked);

    // Connect your buttons with the slots
    connect(ui->addRowButton, &QPushButton::clicked, this, &MainWindow::AddRow);
    connect(ui->removeRowButton, &QPushButton::clicked, this, &MainWindow::RemoveRow);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::SaveCSV);
    connect(ui->editRowButton, &QPushButton::clicked, this, &MainWindow::EditRow);
    connect(ui->reloadButton, &QPushButton::clicked, this, &MainWindow::ReloadCSV);

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
    QItemSelectionModel *select = ui->tableView->selectionModel();
    int selectedRow = m_model.rowCount(); // default to end of list

    if(select->hasSelection()) { // if a row is selected
        selectedRow = select->selectedRows().first().row() + 1; // get selected row
    }

    if(m_model.insertRow(selectedRow, QModelIndex())) {
        for(int column = 0; column < m_model.columnCount(); column++) {
            QModelIndex index = m_model.index(selectedRow, column);
            if (column == 0) {
                m_model.setData(index, "City, State");
            } else {
                m_model.setData(index, 0);
            }
        }
    }
}


void MainWindow::RemoveRow() {
    QItemSelectionModel *select = ui->tableView->selectionModel();

    if(select->hasSelection()) { //check if has selection
        m_model.removeRow(select->selectedRows().first().row(), QModelIndex());
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
        QStringList rowData = m_model.getRowData(row);

        // Create and setup dialog
        RowEditDialog dialog(this);
        dialog.setRowData(rowData); // use setRowData instead of setData

        // If Ok is pressed then apply changes to the model
        if (dialog.exec() == QDialog::Accepted) {
            QStringList newData = dialog.rowData(); // use rowData instead of getData
            for (int i = 0; i < newData.size(); ++i) {
                QModelIndex index = m_model.index(row, i);
                m_model.setData(index, newData[i]);
            }
        }
    }
}


void MainWindow::ReloadCSV() {
    m_model.clear(); // Clears the current data of the model
    if (!m_model.loadCSV(MainWindow::FILEPATH, MainWindow::CSVCOLUMNS)) { // Load the CSV file again
        QMessageBox::critical(this, "Error", "Failed to reload CSV file.");
    }
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

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    ui->tableView->edit(index);
}

void MainWindow::onFileChanged(const QString &path) {
    m_model.loadCSV(path, MainWindow::CSVCOLUMNS);
}


MainWindow::~MainWindow() {
    delete ui;
}

