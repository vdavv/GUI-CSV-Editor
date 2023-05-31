#ifndef CSVFILTERMODEL_H
#define CSVFILTERMODEL_H

#include <QSortFilterProxyModel>
#include <QMap>
#include <QPair>

class CSVFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit CSVFilterModel(QObject *parent = nullptr);

    void setStateFilter(const QString &state);
    void setFilterMap(const QMap<int, QPair<double, double>> &filterMap);

    void refreshFilter();

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

private:
    QString m_stateFilter;
    QMap<int, QPair<double, double>> m_filterMap;
    bool isUpdatingFilter;
};

#endif // CSVFILTERMODEL_H
