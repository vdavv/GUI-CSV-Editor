#include "filterdialog.h"
#include "ui_filterdialog.h"

FilterDialog::FilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterDialog)
{
    ui->setupUi(this);
}

FilterDialog::~FilterDialog()
{
    delete ui;
}

void FilterDialog::on_applyButton_clicked()
{
    // When Apply button is clicked, we just close the dialog.
    // The MainWindow will retrieve the filter parameters using the getter functions.
    this->close();
}

// Getter functions implementation
// QString FilterDialog::getCityFilter() const
// {
//     return ui->cityLineEdit->text();
// }
// ...
