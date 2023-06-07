#include "removerowcommand.h"

RemoveRowCommand::RemoveRowCommand(CSVModel* modelSource, int rowSource)
    : model(modelSource), row(rowSource)
{
    for (int column = 0; column < model->columnCount(); ++column) {
        m_rowData << model->data(model->index(rowSource, column));
    }
}


void RemoveRowCommand::undo()
{
    model->insertRow(row, QModelIndex());
    for (int column = 0; column < m_rowData.size(); ++column) {
        model->setData(model->index(row, column), m_rowData.at(column));
    }
}


void RemoveRowCommand::redo()
{
    model->removeRow(row, QModelIndex());
}
