#include "filterdialog.h"
#include "ui_filterdialog.h"

FilterDialog::FilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterDialog)
{
    ui->setupUi(this);
    // Connect the Apply button clicked signal to the on_applyButton_clicked slot
    // connect(ui->applyButton, &QPushButton::clicked, this, &FilterDialog::on_applyButton_clicked);
}

FilterDialog::~FilterDialog()
{
    delete ui;
}

//void FilterDialog::on_applyButton_clicked()
//{
//    // Apply filters here, or emit a signal to the MainWindow to apply the filters
//    // For example:
//    // emit filtersApplied(getCityFilter(), ...);
//}

// Getter functions implementation
// QString FilterDialog::getCityFilter() const
// {
//     return ui->cityLineEdit->text();
// }
// ...
