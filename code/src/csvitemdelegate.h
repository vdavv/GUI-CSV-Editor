#ifndef CSVITEMDELEGATE_H
#define CSVITEMDELEGATE_H

#include <QStyledItemDelegate>
#include "csvmodel.h"
#include "celleditcommand.h"
#include <QUndoStack>

class CSVItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    CSVItemDelegate(CSVModel *model, QUndoStack *undoStack, QObject *parent = nullptr);

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

private:
    CSVModel *m_model;
    QUndoStack *m_undoStack;
};

#endif // CSVITEMDELEGATE_H
