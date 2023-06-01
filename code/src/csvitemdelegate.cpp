#include "csvitemdelegate.h"

CSVItemDelegate::CSVItemDelegate(CSVModel *model, QUndoStack *undoStack, QObject *parent)
    : QStyledItemDelegate(parent), m_model(model), m_undoStack(undoStack)
{
}

void CSVItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QVariant oldValue = model->data(index);
    QStyledItemDelegate::setModelData(editor, model, index);
    QVariant newValue = model->data(index);

    if (oldValue != newValue) {
        auto* command = new CellEditCommand(m_model, index, oldValue, newValue);
        m_undoStack->push(command);
    }
}
