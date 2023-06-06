#ifndef CELLEDITCOMMAND_H
#define CELLEDITCOMMAND_H

#include <QUndoCommand>
#include "csvmodel.h"
#include "csvfiltermodel.h"

class CellEditCommand : public QUndoCommand
{
public:
    CellEditCommand(CSVModel* model,CSVFilterModel* filterModel , const QModelIndex &index, const QVariant &oldValue, const QVariant &newValue);
    void undo() override;
    void redo() override;

private:
    CSVModel* model;
    CSVFilterModel* filterModel;
    QModelIndex index;
    QVariant oldValue;
    QVariant newValue;
};

#endif // CELLEDITCOMMAND_H
