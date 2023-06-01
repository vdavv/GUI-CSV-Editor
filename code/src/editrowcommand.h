#ifndef EDITROWCOMMAND_H
#define EDITROWCOMMAND_H

#include <QUndoCommand>
#include "csvmodel.h"

class EditRowCommand : public QUndoCommand
{
public:
    EditRowCommand(CSVModel* model, int row, const QStringList& oldData, const QStringList& newData);
    void undo() override;
    void redo() override;

private:
    CSVModel* m_model;
    int m_row;
    QStringList m_oldData;
    QStringList m_newData;
};

#endif // EDITROWCOMMAND_H
