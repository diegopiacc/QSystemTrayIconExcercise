#ifndef DPTASKTABLEMODEL_H
#define DPTASKTABLEMODEL_H

#include "dptask.h"

#include <QAbstractTableModel>
#include <QList>

class DPTaskTableModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    QList<DPTask> _taskList;

public:
    DPTaskTableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void append(const DPTask &t);
};

#endif // DPTASKTABLEMODEL_H
