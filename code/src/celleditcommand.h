#ifndef CELLEDITCOMMAND_H
#define CELLEDITCOMMAND_H

#include "csvfiltermodel.h"
#include "csvmodel.h"
#include <QUndoCommand>

class CellEditCommand : public QUndoCommand
{
public:
    CellEditCommand(CSVModel* model, CSVFilterModel* filterModel, const QModelIndex& index, const QVariant& oldValue, const QVariant& newValue);
    void undo() override;
    void redo() override;

private:
    CSVModel* model;
    CSVFilterModel* filterModel;
    QModelIndex index;
    QVariant oldValue;
    QVariant newValue;
};

#endif// CELLEDITCOMMAND_H
