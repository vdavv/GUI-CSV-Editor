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

bool CSVModel::saveCSV(const QString &filepath) {
    QFile file(filepath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing" << filepath;
        return false;
    }

    QTextStream stream(&file);
    for (const QStringList &row : m_data) {
        QStringList quotedRow;
        for (const QString &cell : row) {
            quotedRow << (cell);
        }
        stream << quotedRow.join(",") << "\n";
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
    if (!index.isValid() || (role != Qt::DisplayRole && role != Qt::EditRole)) {
        return QVariant();
    }

    if (index.row() >= m_data.size() || index.row() < 0) {
        return QVariant();
    }

    return m_data.at(index.row()).at(index.column());
}


bool CSVModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (!index.isValid() || role != Qt::EditRole) {
        return false;
    }

    m_data[index.row()][index.column()] = value.toString();
    emit dataChanged(index, index, {role});

    return true;
}

Qt::ItemFlags CSVModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

QStringList CSVModel::getRowData(int row) const {
    if (row >= 0 && row < m_data.size()) {
        return m_data.at(row);
    }
    return QStringList();
}

QStringList CSVModel::getHeaderData() const {
    // assuming m_data[0] contains the header row
    return m_data.at(0);
}



