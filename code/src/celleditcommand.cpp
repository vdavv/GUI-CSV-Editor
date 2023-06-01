#include "celleditcommand.h"

CellEditCommand::CellEditCommand(CSVModel* model, const QModelIndex &index, const QVariant &oldValue, const QVariant &newValue)
    : m_model(model), m_index(index), m_oldValue(oldValue), m_newValue(newValue)
{
}

void CellEditCommand::undo()
{
    m_model->setData(m_index, m_oldValue);
}

void CellEditCommand::redo()
{
    m_model->setData(m_index, m_newValue);
}
