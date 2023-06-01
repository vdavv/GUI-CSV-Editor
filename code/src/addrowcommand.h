#ifndef ADDROWCOMMAND_H
#define ADDROWCOMMAND_H

#include <QUndoCommand>
#include <QStringList>
#include "csvmodel.h"

class AddRowCommand : public QUndoCommand
{
public:
    explicit AddRowCommand(CSVModel* model, const QStringList &rowData, int row, QUndoCommand *parent = nullptr);

    void undo() override;
    void redo() override;

private:
    CSVModel* m_model;
    QStringList m_rowData;
    int m_row;
};

#endif // ADDROWCOMMAND_H
