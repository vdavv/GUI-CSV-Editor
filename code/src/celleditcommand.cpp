#include "celleditcommand.h"

CellEditCommand::CellEditCommand(CSVModel* model,
                                 CSVFilterModel* filterModel, const QModelIndex &index, const QVariant &oldValue, const QVariant &newValue)
    : model(model), index(index), oldValue(oldValue), newValue(newValue), filterModel(filterModel)
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
