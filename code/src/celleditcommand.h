#ifndef CELLEDITCOMMAND_H
#define CELLEDITCOMMAND_H

#include <QUndoCommand>
#include "csvmodel.h"

class CellEditCommand : public QUndoCommand
{
public:
    CellEditCommand(CSVModel* model, const QModelIndex &index, const QVariant &oldValue, const QVariant &newValue);
    void undo() override;
    void redo() override;

private:
    CSVModel* model;
    QModelIndex index;
    QVariant oldValue;
    QVariant newValue;
};

#endif // CELLEDITCOMMAND_H
