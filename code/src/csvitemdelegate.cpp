#include "celleditcommand.h"
#include "csvitemdelegate.h"

CSVItemDelegate::CSVItemDelegate(CSVModel* modelSource, CSVFilterModel* filterModelSource, QUndoStack* undoStackSource, QObject* parent)
    : QStyledItemDelegate(parent), model(modelSource), filterModel(filterModelSource), undoStack(undoStackSource)
{
}


void CSVItemDelegate::setModelData(QWidget* editor, QAbstractItemModel* modelSource, const QModelIndex& index) const
{
    QVariant oldValue = modelSource->data(index);
    QStyledItemDelegate::setModelData(editor, modelSource, index);
    QVariant newValue = modelSource->data(index);

    if (oldValue != newValue)
    {
        auto* command = new CellEditCommand(model, filterModel, index, oldValue, newValue);
        undoStack->push(command);
    }
}
