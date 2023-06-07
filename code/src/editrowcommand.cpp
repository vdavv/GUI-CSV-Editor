#include "editrowcommand.h"

EditRowCommand::EditRowCommand(CSVModel* modelSource, int rowSource, const QStringList& oldDataSource, const QStringList& newDataSource)
    : model(modelSource), row(rowSource), oldData(oldDataSource), newData(newDataSource)
{
}


void EditRowCommand::undo()
{
    for (int column = 0; column < oldData.size(); ++column)
    {
        model->setData(model->index(row, column), oldData.at(column));
    }
}


void EditRowCommand::redo()
{
    for (int column = 0; column < newData.size(); ++column)
    {
        model->setData(model->index(row, column), newData.at(column));
    }
}
