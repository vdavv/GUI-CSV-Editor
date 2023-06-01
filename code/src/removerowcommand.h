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
    CSVModel* m_model;
    int m_row;
    QList<QVariant> m_rowData;
};

#endif // REMOVEROWCOMMAND_H
