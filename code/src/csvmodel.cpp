#include "csvmodel.h"
#include "QtCore/qregularexpression.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>

CSVModel::CSVModel(QObject *parent) : QAbstractTableModel(parent) {}


QVector<int> m_columnIndices;


bool CSVModel::loadCSV(const QString &filepath, const QVector<int> &columns) {
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file" << filepath;
        return false;
    }
    m_columnIndices = columns;

    QTextStream stream(&file);
    while (!stream.atEnd()) {
        QRegularExpression re("(\"[^\"]*\"|[^,]*),?");
        QRegularExpressionMatchIterator it = re.globalMatch(stream.readLine());
        QStringList row;
        while(it.hasNext()) {
            QRegularExpressionMatch match = it.next();
            QString cell = match.captured(1);
            cell.remove('"');
            row.append(cell);
        }

        QStringList selectedColumns;
        for (int column : columns) {
            if (column < row.size()) {
                selectedColumns.append(row[column]);
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
    bool firstRow = true;
    for (const QStringList &row : m_data) {
        QStringList adjustedRow;
        bool firstCellQuoted = true;
        for (const QString &cell : row) {
            if (firstCellQuoted || firstRow){
                firstCellQuoted = false;
                adjustedRow << "\"" + cell + "\"";
                continue;
            }
            adjustedRow << cell;
        }
        stream << adjustedRow.join(",") << "\n";
        firstRow = false;
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

bool CSVModel::removeRow(int row, const QModelIndex &parent) {
    Q_UNUSED(parent)
    if (row < 0 || row >= m_data.size())
        return false;

    beginRemoveRows(QModelIndex(), row, row);
    m_data.removeAt(row);
    endRemoveRows();
    return true;
}


bool CSVModel::insertRow(int row, const QModelIndex &parent) {
    beginInsertRows(parent, row, row);

    QStringList newRow;
    for(int i = 0; i < columnCount(); i++) {
        if(i == 0) {
            newRow.append("city, state");
        } else {
            newRow.append("0");
        }
    }
    m_data.insert(row, newRow);

    endInsertRows();
    return true;
}




