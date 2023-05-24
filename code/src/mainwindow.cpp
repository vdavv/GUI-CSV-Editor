#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QMessageBox>
#include <QMouseEvent>


const QList<int> CSVCOLUMNS = {0,1,2,3,4,5,6,7,8,9};
const QString FILEPATH = "/Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/data/MetroHealth83.csv";


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // Install event filter
    ui->tableView->verticalHeader()->installEventFilter(this);
    if (!m_model.loadCSV(FILEPATH, CSVCOLUMNS)) {
        QMessageBox::critical(this, "Error", "Failed to load CSV file.");
        return;
    }
    m_watcher.addPath(FILEPATH);
    connect(&m_watcher, &QFileSystemWatcher::fileChanged, this, &MainWindow::onFileChanged);
    ui->tableView->setModel(&m_model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Connect sectionClicked signal of the vertical header to handleRowHeaderClicked slot
    connect(ui->tableView->verticalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::handleRowHeaderClicked);

    // Connect your buttons with the slots
    connect(ui->addRowButton, &QPushButton::clicked, this, &MainWindow::AddRow);
    connect(ui->removeRowButton, &QPushButton::clicked, this, &MainWindow::RemoveRow);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::SaveCSV);
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
    int rowCount = m_model.rowCount();
    m_model.insertRow(rowCount);
}

void MainWindow::RemoveRow() {
    QItemSelectionModel *select = ui->tableView->selectionModel();

    if(select->hasSelection()) //check if has selection
    {
        m_model.removeRow(select->selectedRows().first().row());
    }
}

void MainWindow::SaveCSV() {
    if (!m_model.saveCSV(FILEPATH)) {
        QMessageBox::critical(this, "Error", "Failed to save CSV file.");
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
    m_model.loadCSV(path, CSVCOLUMNS);
}


MainWindow::~MainWindow() {
    delete ui;
}

