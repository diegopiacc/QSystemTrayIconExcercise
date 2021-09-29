#ifndef DPTASKPARAMOUTPUT_H
#define DPTASKPARAMOUTPUT_H

#include <QString>

#include "dptask.h"

class DPTaskOutput : public DPTask
{
private:
    QString _msg;

public:
    DPTaskOutput();
    DPTaskOutput(const QString &taskName, const int secs);

    bool execute();
};

#endif // DPTASKPARAMOUTPUT_H
