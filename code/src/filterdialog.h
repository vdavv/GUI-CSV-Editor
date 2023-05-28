#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>

namespace Ui {
class FilterDialog;
}

class FilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterDialog(QWidget *parent = nullptr);
    ~FilterDialog();

    // Create getter functions for each filter parameter
    // For example:
    // QString getCityFilter() const;
    // ...


private:
    Ui::FilterDialog *ui;
};

#endif // FILTERDIALOG_H
