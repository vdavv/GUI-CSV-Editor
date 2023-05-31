#include "filterdialog.h"
#include "ui_filterdialog.h"
#include <QDebug>

FilterDialog::FilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterDialog)
{
    ui->setupUi(this);

    // Initialize double validator
    m_doubleValidator.setNotation(QDoubleValidator::StandardNotation);
}

FilterDialog::~FilterDialog()
{
    delete ui;
}

QString FilterDialog::getStateFilter() const
{
    return m_stateFilter;
}

QMap<int, QPair<double, double>> FilterDialog::getFilterMap() const
{
    return m_filterMap;
}


void FilterDialog::on_filterApplyButton_clicked()
{
    m_stateFilter = ui->stateChoiceLineEdit->text();

    // Collect all the filters from the min/max line edits
    QStringList columnNames = {"ratemds", "numhospitals", "ratebeds", "nummedicare", "pctchangemedicare", "medicarerate", "numretired", "ssinum"};
    for (int i = 0; i < columnNames.size(); ++i) {
        QLineEdit *minEdit = findChild<QLineEdit*>(columnNames[i] + "Min");
        QLineEdit *maxEdit = findChild<QLineEdit*>(columnNames[i] + "Max");

        if (minEdit && maxEdit) {
            QString minStr = minEdit->text();
            QString maxStr = maxEdit->text();
            if (!minStr.toDouble())
                minEdit->clear();
            if(!maxStr.toDouble())
                maxEdit->clear();
            double min = minStr.isEmpty() ? -std::numeric_limits<double>::infinity() : minStr.toDouble();
            double max = maxStr.isEmpty() ? std::numeric_limits<double>::infinity() : maxStr.toDouble();

            m_filterMap[i+1] = qMakePair(min, max); // i+1 because we're skipping the state column
        }
    }

    emit filterChanged();
    this->close();
}


void FilterDialog::on_filterResetButton_clicked()
{
    m_stateFilter = "";
    ui->stateChoiceLineEdit->clear();

    QStringList columnNames = {"ratemds", "numhospitals", "ratebeds", "nummedicare", "pctchangemedicare", "medicarerate", "numretired", "ssinum"};
    for (int i = 0; i < columnNames.size(); ++i) {
        QLineEdit *minEdit = findChild<QLineEdit*>(columnNames[i] + "Min");
        QLineEdit *maxEdit = findChild<QLineEdit*>(columnNames[i] + "Max");

        if (minEdit && maxEdit) {
            minEdit->clear();
            maxEdit->clear();
            QString minStr = minEdit->text();
            QString maxStr = maxEdit->text();
            double min = minStr.isEmpty() ? -std::numeric_limits<double>::infinity() : minStr.toDouble();
            double max = maxStr.isEmpty() ? std::numeric_limits<double>::infinity() : maxStr.toDouble();

            m_filterMap[i+1] = qMakePair(min, max); // i+1 because we're skipping the state column
        }
    }

    emit filterChanged();
    this->close();
}
