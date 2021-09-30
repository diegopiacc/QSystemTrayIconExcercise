#include "dptaskexecutor.h"
#include "dptask.h"

#include <QDebug>

DPTaskExecutor::DPTaskExecutor(QObject *parent) : QObject(parent)
{

}

void DPTaskExecutor::execute()
{
    qDebug() << "Task: " << this->task->getTaskName();
    //task->execute();
}
