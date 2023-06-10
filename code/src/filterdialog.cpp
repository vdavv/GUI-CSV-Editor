#include "filterdialog.h"
#include "ui_filterdialog.h"
#include <QDebug>

FilterDialog::FilterDialog(QWidget* parent) : QDialog(parent),
    ui(new Ui::FilterDialog)
{
    ui->setupUi(this);

    doubleValidator.setNotation(QDoubleValidator::StandardNotation);
}


FilterDialog::~FilterDialog()
{
    delete ui;
}


QString FilterDialog::getStateFilter() const
{
    return stateFilter;
}


QMap<int, QPair<double, double>> FilterDialog::getFilterMap() const
{
    return filterMap;
}


void FilterDialog::translateUi(int lang)
{
    switch (lang)
    {
    case 1:
        ui->filterApplyButton->setText("Применить");
        ui->filterResetButton->setText("Сбросить");
        setWindowTitle("Фильтрация");
        return;
    default:
        ui->filterApplyButton->setText("Apply");
        ui->filterResetButton->setText("Reset");
        setWindowTitle("Filter");
        return;
    }
}


void FilterDialog::on_filterApplyButton_clicked()
{
    stateFilter = ui->stateChoiceLineEdit->text();

    // Collect all the filters from the min/max line edits
    QStringList columnNames = {"ratemds", "numhospitals", "ratebeds", "nummedicare", "pctchangemedicare", "medicarerate", "numretired", "ssinum"};
    for (int i = 0; i < columnNames.size(); ++i)
    {
        QLineEdit* minEdit = findChild<QLineEdit*>(columnNames[i] + "Min");
        QLineEdit* maxEdit = findChild<QLineEdit*>(columnNames[i] + "Max");

        if (minEdit && maxEdit)
        {
            QString minStr = minEdit->text();
            QString maxStr = maxEdit->text();
            if (!minStr.toDouble())
                minEdit->clear();
            if (!maxStr.toDouble())
                maxEdit->clear();
            double min = minStr.isEmpty() ? -std::numeric_limits<double>::infinity() : minStr.toDouble();
            double max = maxStr.isEmpty() ? std::numeric_limits<double>::infinity() : maxStr.toDouble();

            filterMap[i + 1] = qMakePair(min, max);// i+1 because we're skipping the state column
        }
    }

    emit filterChanged();
    this->close();
}


void FilterDialog::on_filterResetButton_clicked()
{
    stateFilter = "";
    ui->stateChoiceLineEdit->clear();

    QStringList columnNames = {"ratemds", "numhospitals", "ratebeds", "nummedicare", "pctchangemedicare", "medicarerate", "numretired", "ssinum"};
    for (int i = 0; i < columnNames.size(); ++i)
    {
        QLineEdit* minEdit = findChild<QLineEdit*>(columnNames[i] + "Min");
        QLineEdit* maxEdit = findChild<QLineEdit*>(columnNames[i] + "Max");

        if (minEdit && maxEdit)
        {
            minEdit->clear();
            maxEdit->clear();
            QString minStr = minEdit->text();
            QString maxStr = maxEdit->text();
            double min = minStr.isEmpty() ? -std::numeric_limits<double>::infinity() : minStr.toDouble();
            double max = maxStr.isEmpty() ? std::numeric_limits<double>::infinity() : maxStr.toDouble();

            filterMap[i + 1] = qMakePair(min, max);// i+1 because we're skipping the state column
        }
    }

    emit filterChanged();
    this->close();
}
