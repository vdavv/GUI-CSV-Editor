#include "QtWidgets/qpushbutton.h"
#include "rowadddialog.h"
#include "ui_rowadddialog.h"

RowAddDialog::RowAddDialog(QWidget* parent, int lang) : QDialog(parent),
    ui(new Ui::RowAddDialog)
{
    ui->setupUi(this);
    QDialogButtonBox* buttonBox = ui->buttonBox;
    QPushButton* cancelButton = buttonBox->button(QDialogButtonBox::Cancel);
    switch (lang)
    {
    case 1:
        if (cancelButton)
            cancelButton->setText("Отменить");
        setWindowTitle("Добавить");
        break;

    default:
        if (cancelButton)
            cancelButton->setText("Cancel");
        break;
    }
    this->update();

    lineEdits = {ui->lineEdit_1, ui->lineEdit_2, ui->lineEdit_3, ui->lineEdit_4, ui->lineEdit_5,
                 ui->lineEdit_6, ui->lineEdit_7, ui->lineEdit_8, ui->lineEdit_9};

    ui->lineEdit_1->setText("City, State");
    for (int i = 1; i < lineEdits.size(); ++i)
    {
        lineEdits[i]->setText("0");
    }
}


RowAddDialog::~RowAddDialog()
{
    delete ui;
}


QStringList RowAddDialog::RowAddDialog::rowData() const
{
    QStringList rowData;

    for (QLineEdit* lineEdit: lineEdits)
    {
        rowData << lineEdit->text();
    }

    return rowData;
}
