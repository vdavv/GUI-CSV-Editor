#ifndef CSVMODEL_H
#define CSVMODEL_H

#include <QAbstractTableModel>

class CSVModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit CSVModel(QObject *parent = nullptr);
    bool loadCSV(const QString &filepath, const QVector<int> &columns);
    // bool loadCSV(const QString &filepath);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QList<QStringList> m_data;
};

#endif // CSVMODEL_H
