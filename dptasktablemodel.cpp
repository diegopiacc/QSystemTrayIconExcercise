#include "dptasktablemodel.h"
#include "dptask.h"

#include <QDebug>
#include <QBrush>
#include <QFont>
#include <QList>

DPTaskTableModel::DPTaskTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    qDebug() << QString("DPTaskTableModel constructor called");

}

int DPTaskTableModel::rowCount(const QModelIndex & /*parent*/) const
{
   return 2;
}

int DPTaskTableModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 3;
}

void DPTaskTableModel::append(const DPTask & t) {
   beginInsertRows({}, this->_taskList.count(), this->_taskList.count());
   this->_taskList.append(t);
   endInsertRows();
}

QVariant DPTaskTableModel::data(const QModelIndex &index, int role) const
{
    qDebug() << QString("data method called");

    int row = index.row();
    int col = index.column();
    // generate a log message when this method gets called
    qDebug() << QString("row %1, col%2, role %3")
            .arg(row).arg(col).arg(role);

    switch (role) {
    case Qt::DisplayRole:
        if (row == 0 && col == 1) return QString("<--left");
        if (row == 1 && col == 1) return QString("right-->");

        return QString("Row%1, Column%2")
                .arg(row + 1)
                .arg(col +1);
    case Qt::FontRole:
        if (row == 0 && col == 0) { //change font only for cell(0,0)
            QFont boldFont;
            boldFont.setBold(true);
            return boldFont;
        }
        break;
    case Qt::BackgroundRole:
        if (row == 1 && col == 2)  //change background only for cell(1,2)
            return QBrush(Qt::red);
        break;
    case Qt::TextAlignmentRole:
        if (row == 1 && col == 1) //change text alignment only for cell(1,1)
            return int(Qt::AlignRight | Qt::AlignVCenter);
        break;
    case Qt::CheckStateRole:
        if (row == 1 && col == 0) //add a checkbox to cell(1,0)
            return Qt::Checked;
        break;
    }
    return QVariant();
}
