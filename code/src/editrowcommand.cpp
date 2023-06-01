#include "editrowcommand.h"

EditRowCommand::EditRowCommand(CSVModel* model, int row, const QStringList& oldData, const QStringList& newData)
    : m_model(model), m_row(row), m_oldData(oldData), m_newData(newData)
{
}

void EditRowCommand::undo()
{
    for (int column = 0; column < m_oldData.size(); ++column) {
        m_model->setData(m_model->index(m_row, column), m_oldData.at(column));
    }
}

void EditRowCommand::redo()
{
    for (int column = 0; column < m_newData.size(); ++column) {
        m_model->setData(m_model->index(m_row, column), m_newData.at(column));
    }
}
