#ifndef DPTASK_H
#define DPTASK_H

#include <QObject>
#include <QList>
#include <QString>

#include "dptaskparam.h"

class DPTask
{

public:
    DPTask();
    DPTask(const QString &taskName, const int secs);
    ~DPTask();

    QString getTaskName();

    int getTaskPeriod();

    /**
     * @brief getTaskPeriodAsString
     * @return
     */
    QString getTaskPeriodAsString();


    void addParam(QString str);

    /**
     * @brief getTaskParametersAsString :
     * @return a QString representation of this task parameters
     */
    QString getTaskParametersAsString();

    virtual void execute();

protected:

    /**
     * @brief _taskName : Human readable name of the task
     */
    QString _taskName;

    /**
     * @brief _secondsPeriod : number of seconds between the execution of task instances
     */
    int _secondsPeriod;

    /**
     * @brief params : customizable, extra parameters (as of v0.1, simplified)
     */
    QList<DPTaskParam> _params;


};

#endif // DPTASK_H
