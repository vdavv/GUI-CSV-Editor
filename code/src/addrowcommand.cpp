#include "addrowcommand.h"

AddRowCommand::AddRowCommand(CSVModel* modelSource, const QStringList &rowDataSource, int rowSource, QUndoCommand *parent)
    : QUndoCommand(parent), model(modelSource), rowData(rowDataSource), row(rowSource)
{
    setText(QObject::tr("Add Row"));
}

void AddRowCommand::undo()
{
    model->removeRow(row, QModelIndex());
}

void AddRowCommand::redo()
{
    model->insertRow(row, QModelIndex());
    for(int column = 0; column < model->columnCount(); column++) {
        QModelIndex index = model->index(row, column);
        model->setData(index, rowData.at(column));
    }
}
