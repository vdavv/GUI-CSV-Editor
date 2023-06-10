#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>
#include <QDoubleValidator>
#include <QLineEdit>
#include <QMap>

namespace Ui
{
class FilterDialog;
}

class FilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterDialog(QWidget* parent = nullptr);
    ~FilterDialog();

    QString getStateFilter() const;
    QMap<int, QPair<double, double>> getFilterMap() const;

public slots:
    void translateUi(int lang);

signals:
    void filterChanged();

private slots:
    void on_filterApplyButton_clicked();
    void on_filterResetButton_clicked();

private:
    Ui::FilterDialog* ui;
    QString stateFilter;
    QMap<int, QPair<double, double>> filterMap;
    QDoubleValidator doubleValidator;
};

#endif// FILTERDIALOG_H
