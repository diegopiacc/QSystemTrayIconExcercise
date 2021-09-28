#include "dptask.h"

DPTask::DPTask()
     : _params(QList<DPTaskParam> ())
{
        this->_taskName = QString("Dummy");
        this->_secondsPeriod = 60;

}

DPTask::DPTask(const QString & taskName) :
      _taskName{taskName}
    , _params(QList<DPTaskParam> ())

{
    this->_secondsPeriod = 60;
}

DPTask::DPTask(const QString & taskName, const int secs) :
    _taskName{taskName}, _secondsPeriod{secs}
  , _params(QList<DPTaskParam> ())
{
}

QString DPTask::getTaskName() {
    return this->_taskName;
}
