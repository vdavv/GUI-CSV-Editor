#ifndef EDITROWCOMMAND_H
#define EDITROWCOMMAND_H

#include "csvmodel.h"
#include <QUndoCommand>

class EditRowCommand : public QUndoCommand
{
public:
    EditRowCommand(CSVModel* modelSource, int row, const QStringList& oldDataSource, const QStringList& newDataSource);
    void undo() override;
    void redo() override;

private:
    CSVModel* model;
    int row;
    QStringList oldData;
    QStringList newData;
};

#endif// EDITROWCOMMAND_H
