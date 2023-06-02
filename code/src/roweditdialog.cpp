#include "roweditdialog.h"
#include "ui_roweditdialog.h"

RowEditDialog::RowEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RowEditDialog)
{
    ui->setupUi(this);
}


RowEditDialog::~RowEditDialog()
{
    delete ui;
}


void RowEditDialog::setRowData(const QStringList &rowData)
{
    if (rowData.size() != 9) {
        qWarning() << "Unexpected data size: " << rowData.size();
        return;
    }
    ui->lineEdit_1->setText(rowData[0]);
    ui->lineEdit_2->setText(rowData[1]);
    ui->lineEdit_3->setText(rowData[2]);
    ui->lineEdit_4->setText(rowData[3]);
    ui->lineEdit_5->setText(rowData[4]);
    ui->lineEdit_6->setText(rowData[5]);
    ui->lineEdit_7->setText(rowData[6]);
    ui->lineEdit_8->setText(rowData[7]);
    ui->lineEdit_9->setText(rowData[8]);
}


QStringList RowEditDialog::rowData() const
{
    QStringList data;
    data << ui->lineEdit_1->text();
    data << ui->lineEdit_2->text();
    data << ui->lineEdit_3->text();
    data << ui->lineEdit_4->text();
    data << ui->lineEdit_5->text();
    data << ui->lineEdit_6->text();
    data << ui->lineEdit_7->text();
    data << ui->lineEdit_8->text();
    data << ui->lineEdit_9->text();
    return data;
}
