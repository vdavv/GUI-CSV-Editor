#include "addrowcommand.h"

AddRowCommand::AddRowCommand(CSVModel* model, const QStringList &rowData, int row, QUndoCommand *parent)
    : QUndoCommand(parent), m_model(model), m_rowData(rowData), m_row(row)
{
    setText(QObject::tr("Add Row"));
}

void AddRowCommand::undo()
{
    m_model->removeRow(m_row, QModelIndex());
}

void AddRowCommand::redo()
{
    m_model->insertRow(m_row, QModelIndex());
    for(int column = 0; column < m_model->columnCount(); column++) {
        QModelIndex index = m_model->index(m_row, column);
        m_model->setData(index, m_rowData.at(column));
    }
}
