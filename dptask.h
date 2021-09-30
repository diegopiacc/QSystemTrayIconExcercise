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

    /**
     * @brief resetParam : Reinitialize the param list (yes, I know, for now it' only a String) qith a single string.
     * @param str : the string.
     */
    void resetParam(QString str);

    /**
     * @brief addParam : Add a parameter to the task. What for? God knows.
     * @param str
     */
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
