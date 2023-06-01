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
    CSVModel* m_model;
    QModelIndex m_index;
    QVariant m_oldValue;
    QVariant m_newValue;
};

#endif // CELLEDITCOMMAND_H
