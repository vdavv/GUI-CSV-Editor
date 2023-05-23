#include "csvmodel.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>

CSVModel::CSVModel(QObject *parent) : QAbstractTableModel(parent) {}

bool CSVModel::loadCSV(const QString &filepath, const QVector<int> &columns) {
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file" << filepath;
        return false;
    }

    QTextStream stream(&file);
    while (!stream.atEnd()) {
        QStringList row = stream.readLine().split(",");
        QStringList selectedColumns;
        for (int column : columns) {
            if (column < row.size()) {
                // Remove double quotes from the string
                QString text = row[column];
                text.remove('"');
                selectedColumns.append(text);
            }
        }
        m_data.append(selectedColumns);
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
