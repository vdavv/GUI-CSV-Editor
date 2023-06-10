#include "removerowcommand.h"

RemoveRowCommand::RemoveRowCommand(CSVModel* modelSource, int rowSource)
    : model(modelSource), row(rowSource)
{
    for (int column = 0; column < model->columnCount(); ++column) {
        mRowData << model->data(model->index(rowSource, column));
    }
}


void RemoveRowCommand::undo()
{
    model->insertRow(row, QModelIndex());
    for (int column = 0; column < mRowData.size(); ++column) {
        model->setData(model->index(row, column), mRowData.at(column));
    }
}


void RemoveRowCommand::redo()
{
    model->removeRow(row, QModelIndex());
}
