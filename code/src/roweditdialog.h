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
    explicit RowEditDialog(QWidget *parent = nullptr);
    ~RowEditDialog();
    void setRowData(const QStringList &rowData);
    // void setData(const QStringList &data);
    QStringList rowData() const;
    // QStringList getData();

private:
    QList<QLineEdit*> m_lineEdits;
    Ui::RowEditDialog *ui;
};

#endif // ROWEDITDIALOG_H
