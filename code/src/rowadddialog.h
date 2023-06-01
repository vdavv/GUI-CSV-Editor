#ifndef ROWADDDIALOG_H
#define ROWADDDIALOG_H

#include "ui_rowadddialog.h"
#include <QDialog>
#include <QLineEdit>
#include <QStringList>

class RowAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RowAddDialog(QWidget *parent = nullptr);
    ~RowAddDialog();
    void setRowData(const QStringList &rowData);
    QStringList rowData() const;

private:
    QList<QLineEdit*> lineEdits;
    Ui::RowAddDialog *ui;
};

#endif // ROWADDDIALOG_H
