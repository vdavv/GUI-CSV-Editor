#ifndef ADDROWCOMMAND_H
#define ADDROWCOMMAND_H

#include "csvmodel.h"
#include <QStringList>
#include <QUndoCommand>

class AddRowCommand : public QUndoCommand
{
public:
    explicit AddRowCommand(CSVModel* model, const QStringList& rowData, int row, QUndoCommand* parent = nullptr);

    void undo() override;
    void redo() override;

private:
    CSVModel* model;
    QStringList rowData;
    int row;
};

#endif// ADDROWCOMMAND_H
