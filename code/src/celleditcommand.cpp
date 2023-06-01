#include "celleditcommand.h"

CellEditCommand::CellEditCommand(CSVModel* model, const QModelIndex &index, const QVariant &oldValue, const QVariant &newValue)
    : model(model), index(index), oldValue(oldValue), newValue(newValue)
{
}

void CellEditCommand::undo()
{
    model->setData(index, oldValue);
}

void CellEditCommand::redo()
{
    model->setData(index, newValue);
}
