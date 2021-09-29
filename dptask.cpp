#include "dptask.h"

#include <QDateTime>

DPTask::DPTask()
     : _params(QList<DPTaskParam> ())
{
        this->_taskName = QString("Dummy");
        this->_secondsPeriod = 60;

}

DPTask::DPTask(const QString & taskName, const int secs) :
    _taskName(taskName), _secondsPeriod(secs)
  , _params(QList<DPTaskParam> ())
{
}

QString DPTask::getTaskName() {
    return this->_taskName;
}


int DPTask::getTaskPeriod() {
    return this->_secondsPeriod;
}

QString DPTask::getTaskPeriodAsString() {
    return QDateTime::fromTime_t(this->_secondsPeriod).toUTC().toString("hh:mm:ss");
}


