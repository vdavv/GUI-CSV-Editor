#ifndef CSVITEMDELEGATE_H
#define CSVITEMDELEGATE_H

#include <QStyledItemDelegate>
#include "csvmodel.h"
#include <QUndoStack>
#include "csvfiltermodel.h"

class CSVItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    CSVItemDelegate(CSVModel *modelSource, CSVFilterModel *filterModel, QUndoStack *undoStackSource, QObject *parent = nullptr);

    void setModelData(QWidget *editor, QAbstractItemModel *modelSource, const QModelIndex &index) const override;

private:
    CSVModel *model;
    CSVFilterModel *filterModel;
    QUndoStack *undoStack;
};

#endif // CSVITEMDELEGATE_H
