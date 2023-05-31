#include "rowadddialog.h"
#include "ui_rowadddialog.h"

RowAddDialog::RowAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RowAddDialog)
{
    ui->setupUi(this);

    // Add line edits to list for easier management
    m_lineEdits = {ui->lineEdit_1, ui->lineEdit_2, ui->lineEdit_3, ui->lineEdit_4, ui->lineEdit_5,
                   ui->lineEdit_6, ui->lineEdit_7, ui->lineEdit_8, ui->lineEdit_9};

    // Set initial values
    ui->lineEdit_1->setText("City, State");
    for(int i = 1; i < m_lineEdits.size(); ++i) {
        m_lineEdits[i]->setText("0");
    }
}


RowAddDialog::~RowAddDialog()
{
    delete ui;
}


QStringList RowAddDialog::RowAddDialog::rowData() const
{
    QStringList rowData;

    for(QLineEdit *lineEdit : m_lineEdits) {
        rowData << lineEdit->text();
    }

    return rowData;
}
