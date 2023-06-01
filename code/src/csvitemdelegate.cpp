#include "csvitemdelegate.h"
#include "celleditcommand.h"

CSVItemDelegate::CSVItemDelegate(CSVModel *modelSource, QUndoStack *undoStackSource, QObject *parent)
    : QStyledItemDelegate(parent), model(modelSource), undoStack(undoStackSource)
{
}

void CSVItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *modelSource, const QModelIndex &index) const
{
    QVariant oldValue = modelSource->data(index);
    QStyledItemDelegate::setModelData(editor, modelSource, index);
    QVariant newValue = modelSource->data(index);

    if (oldValue != newValue) {
        auto* command = new CellEditCommand(model, index, oldValue, newValue);
        undoStack->push(command);
    }
}
