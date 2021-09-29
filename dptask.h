#ifndef DPTASK_H
#define DPTASK_H

#include <QList>
#include <QString>

#include "dptaskparam.h"


class DPTask
{
public:
    DPTask();
    DPTask(const QString &taskName, const int secs);

    QString getTaskName();

    int getTaskPeriod();
    QString getTaskPeriodAsString();

    //virtual bool execute();

private:

    /**
     * @brief _taskName : Human readable name of the task
     */
    QString _taskName;

    /**
     * @brief _secondsPeriod : number of seconds between the execution of task instances
     */
    int _secondsPeriod;

    /**
     * @brief params : customizable, extra parameters (task dependant)
     */
    QList<DPTaskParam> _params;

};

#endif // DPTASK_H
