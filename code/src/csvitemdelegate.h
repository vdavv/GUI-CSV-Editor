#ifndef CSVITEMDELEGATE_H
#define CSVITEMDELEGATE_H

#include "csvfiltermodel.h"
#include "csvmodel.h"
#include <QStyledItemDelegate>
#include <QUndoStack>

class CSVItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    CSVItemDelegate(CSVModel* modelSource, CSVFilterModel* filterModel, QUndoStack* undoStackSource, QObject* parent = nullptr);

    void setModelData(QWidget* editor, QAbstractItemModel* modelSource, const QModelIndex& index) const override;

private:
    CSVModel* model;
    CSVFilterModel* filterModel;
    QUndoStack* undoStack;
};

#endif// CSVITEMDELEGATE_H
