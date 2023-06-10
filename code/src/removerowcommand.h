#ifndef REMOVEROWCOMMAND_H
#define REMOVEROWCOMMAND_H

#include <QUndoCommand>
#include "csvmodel.h"

class RemoveRowCommand : public QUndoCommand
{
public:
    RemoveRowCommand(CSVModel* model, int row);
    void undo() override;
    void redo() override;

private:
    CSVModel* model;
    int row;
    QList<QVariant> mRowData;
};

#endif // REMOVEROWCOMMAND_H
