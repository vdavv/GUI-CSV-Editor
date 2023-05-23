#include "csvmodel.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>

CSVModel::CSVModel(QObject *parent) : QAbstractTableModel(parent) {}

bool CSVModel::loadCSV(const QString &filepath) {
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file" << filepath;
        return false;
    }

    QTextStream stream(&file);
    while (!stream.atEnd()) {
        const QStringList row = stream.readLine().split(",");
        m_data.append(row);
    }

    return true;
}

int CSVModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return m_data.size();
}

int CSVModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    if (m_data.isEmpty()) {
        return 0;
    } else {
        return m_data.first().size();
    }
}

QVariant CSVModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    if (index.row() >= m_data.size() || index.row() < 0) {
        return QVariant();
    }

    return m_data.at(index.row()).at(index.column());
}
