#include "removerowcommand.h"

RemoveRowCommand::RemoveRowCommand(CSVModel* model, int row)
    : m_model(model), m_row(row)
{
    for (int column = 0; column < m_model->columnCount(); ++column) {
        m_rowData << m_model->data(m_model->index(row, column));
    }
}

void RemoveRowCommand::undo()
{
    m_model->insertRow(m_row, QModelIndex());
    for (int column = 0; column < m_rowData.size(); ++column) {
        m_model->setData(m_model->index(m_row, column), m_rowData.at(column));
    }
}

void RemoveRowCommand::redo()
{
    m_model->removeRow(m_row, QModelIndex());
}
