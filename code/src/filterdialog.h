#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>
#include <QMap>
#include <QLineEdit>
#include <QDoubleValidator>

namespace Ui {
class FilterDialog;
}

class FilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterDialog(QWidget *parent = nullptr);
    ~FilterDialog();

    QString getStateFilter() const;
    QMap<int, QPair<double, double>> getFilterMap() const;

signals:
    void filterChanged();

private slots:
    void on_filterApplyButton_clicked();
    void on_filterResetButton_clicked();

private:
    Ui::FilterDialog *ui;
    QString m_stateFilter;
    QMap<int, QPair<double, double>> m_filterMap;
    QDoubleValidator m_doubleValidator;
};

#endif // FILTERDIALOG_H
