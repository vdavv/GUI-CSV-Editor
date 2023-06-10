#ifndef ROWEDITDIALOG_H
#define ROWEDITDIALOG_H

#include "ui_roweditdialog.h"
#include <QDialog>
#include <QLineEdit>
#include <QStringList>

class RowEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RowEditDialog(QWidget *parent = nullptr, int lang = 0);
    ~RowEditDialog();
    void setRowData(const QStringList &rowData);
    QStringList rowData() const;

private:
    QList<QLineEdit*> m_lineEdits;
    Ui::RowEditDialog *ui;
};

#endif // ROWEDITDIALOG_H
