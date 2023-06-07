#ifndef CSVFILTERMODEL_H
#define CSVFILTERMODEL_H

#include <QSortFilterProxyModel>
#include <QMap>
#include <QPair>
#include <QVector>

class CSVFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit CSVFilterModel(QObject *parent = nullptr);

    void setStateFilter(const QString &state);
    void setFilterMap(const QMap<int, QPair<double, double>> &filterMap);

    void refreshFilter();
    QString extractState(const QString& cityState) const;

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;

private:
    QString modelStateFilter;
    QMap<int, QPair<double, double>> modelFilterMap;
    bool isUpdatingFilter;
};

#endif // CSVFILTERMODEL_H
