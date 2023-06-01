#include "csvmodel.h"
#include "QtCore/qregularexpression.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>

CSVModel::CSVModel(QObject *parent) : QAbstractTableModel(parent) {}


QVector<int> m_columnIndices;
QStringList m_headerData;


bool CSVModel::loadCSV(const QString &filepath, const QVector<int> &columns) {
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file" << filepath;
        return false;
    }
    m_columnIndices = columns;
    QTextStream stream(&file);
    bool firstRow = true;
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
        if (firstRow) {  // This is header row
            m_headerData = selectedColumns;
            firstRow = false;
        } else {
            m_data.append(selectedColumns);
        }
    }
    return true;
}


QVariant CSVModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal && section < m_headerData.size()) {
        return m_headerData[section];
    } else {
        return QAbstractTableModel::headerData(section, orientation, role);
    }
}



bool CSVModel::saveCSV(const QString &filepath) {
    QFile file(filepath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing" << filepath;
        return false;
    }

    QTextStream stream(&file);

    // Save the header data first
    QStringList adjustedHeader;
    for (const QString &headerCell : m_headerData) {
        adjustedHeader << "\"" + headerCell + "\"";
    }
    stream << adjustedHeader.join(",") << "\n";//столб краш????

    for (const QStringList &row : m_data) {
        QStringList adjustedRow;
        bool firstCellQuoted = true;
        for (const QString &cell : row) {
            if (firstCellQuoted){
                firstCellQuoted = false;
                adjustedRow << "\"" + cell + "\"";
                continue;
            }
            adjustedRow << cell;
        }
        stream << adjustedRow.join(",") << "\n";
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


QVariant CSVModel::convertStringToNumber(const QVariant& str) const {
    bool ok = false;

    // First, try to convert to an int
    int intValue = str.toInt(&ok);
    if (ok) {
        return QVariant(intValue); // а кутэ краш????
    }

    // If that fails, try to convert to a double
    double doubleValue = str.toDouble(&ok);
    if (ok) {
        return QVariant(doubleValue);
    }

    // If all else fails, return 0
    return QVariant(0);
}



bool CSVModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (!index.isValid() || role != Qt::EditRole) {
        return false;
    }

    if (index.column() != 0)
        m_data[index.row()][index.column()] = convertStringToNumber(value).toString();
    else
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
    return m_headerData;
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


void CSVModel::clear() {
    beginRemoveRows(QModelIndex(), 0, rowCount());
    m_data.clear();
    endRemoveRows();
}
