#include "dptaskoutput.h"

#include <QDebug>
#include <QDate>

DPTaskOutput::DPTaskOutput() : DPTask()
{
}

DPTaskOutput::DPTaskOutput(const QString &taskName, const int secs) : DPTask(taskName, secs)
{
}


void DPTaskOutput::execute()
{
    qDebug() << "Task: " << this->getTaskName();
    qDebug() << "Date: " << QDate::currentDate();
    qDebug() << "Date: " << this->getTaskParametersAsString();
}
