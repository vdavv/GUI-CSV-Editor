#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QMessageBox>
#include <QMouseEvent>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    if (!m_model.loadCSV("/Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/data/MetroHealth83.csv", {1,2,3,4,6,7,8,9,13,14})) {
        QMessageBox::critical(this, "Error", "Failed to load CSV file.");
        return;
    }

    ui->tableView->setModel(&m_model);
    // Connect sectionClicked signal of the vertical header to handleRowHeaderClicked slot
    connect(ui->tableView->verticalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::handleRowHeaderClicked);

}


bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == m_view->verticalHeader() && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        int row = m_view->verticalHeader()->logicalIndexAt(mouseEvent->pos());
        handleRowHeaderClicked(row);
    }
    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::handleRowHeaderClicked(int row)
{
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
//    QStringList rowData = m_model.getRowData(index.row());
//    QStringList headerData = m_model.getHeaderData(); // this method is assumed to be present in CSVModel

//    QString info;
//    for (int i = 0; i < rowData.size() && i < headerData.size(); i++) {
//        info += QString("%1: %2").arg(headerData[i]).arg(rowData[i]) + "\n";
//    }

//    QMessageBox::information(this, "Row Data", info);
//}



MainWindow::~MainWindow() {
    delete ui;
}
