#include "dptask.h"

#include <QDateTime>
#include <QDebug>

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

DPTask::~DPTask()
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

void DPTask::addParam(QString str)
{
    DPTaskParam p(str);
    this->_params.append(p);
}

QString DPTask::getTaskParametersAsString()
{
    QString ret("");
    int n = this->_params.count();
    for( int i=0; i<n; ++i ) {
        ret += this->_params[i].value();
        if(i<n-1) {
            // still not the last element
            ret += "~";
        }
    }

    return ret;
}

void DPTask::execute()
{
    qDebug() << "DPTask - generic virtual execute";
}


