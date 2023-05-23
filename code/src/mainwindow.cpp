#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    if (!m_model.loadCSV("/Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/data/MetroHealth83.csv", {1,2,3,4,6,7,8,9,13,14})) {
        QMessageBox::critical(this, "Error", "Failed to load CSV file.");
        return;
    }

    ui->tableView->setModel(&m_model);
}

MainWindow::~MainWindow() {
    delete ui;
}
