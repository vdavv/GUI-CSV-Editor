#include "csvfiltermodel.h"
#include <QStandardItemModel>

CSVFilterModel::CSVFilterModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
}


void CSVFilterModel::setFilterMap(const QMap<int, QPair<double, double>> &filterMap)
{
    if (isUpdatingFilter)
        return;
    m_filterMap = filterMap;
}




bool CSVFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    auto *sourceModel = qobject_cast<QAbstractTableModel*>(this->sourceModel());
    if (!sourceModel)
        return false;

    if (!m_stateFilter.isEmpty()) {
        auto stateIndex = sourceModel->index(source_row, 1, source_parent);
        if (sourceModel->data(stateIndex).toString() != m_stateFilter)
            return false;
    }

    for (auto it = m_filterMap.begin(); it != m_filterMap.end(); ++it) {
        int column = it.key();
        double min = it.value().first;
        double max = it.value().second;

        auto index = sourceModel->index(source_row, column, source_parent);
        double value = sourceModel->data(index).toDouble();

        if (value < min || value > max)
            return false;
    }

    return true;
}


void CSVFilterModel::refreshFilter()
{
    invalidateFilter();
}


void CSVFilterModel::setStateFilter(const QString &state)
{
    qDebug() << "Setting state filter to" << state;

    m_stateFilter = state;
    // invalidateFilter();
}


