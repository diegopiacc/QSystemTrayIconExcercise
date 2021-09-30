#ifndef DPTASKEXECUTOR_H
#define DPTASKEXECUTOR_H

#include <QObject>

class DPTask;
class QTimer;

class DPTaskExecutor : public QObject
{
    Q_OBJECT
public:
    explicit DPTaskExecutor(QObject *parent = nullptr);
    DPTask* task;
    QTimer* taskTimer;

public slots:
    void execute();

};

#endif // DPTASKEXECUTOR_H
