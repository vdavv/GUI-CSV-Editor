#ifndef CSVMODEL_H
#define CSVMODEL_H

#include <QAbstractTableModel>
#include <QString>
#include <QStringList>

class CSVModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit CSVModel(QObject* parent = nullptr);

    bool loadCSV(const QString& filepath, const QVector<int>& columns);
    bool saveCSV(const QString& filepath);
    void clear();
    bool removeRow(int row, const QModelIndex& parent);
    bool insertRow(int row, const QModelIndex& parent);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    QStringList getRowData(int row) const;
    QStringList getHeaderData() const;
    QVariant convertStringToNumber(const QVariant& str) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;


private:
    QList<QStringList> modelData;
    QStringList modelHeaderData;
};

#endif// CSVMODEL_H
