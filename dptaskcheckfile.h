#ifndef DPTASKPARAMCHECKFILE_H
#define DPTASKPARAMCHECKFILE_H

#include "dptask.h"

class DPTaskCheckFile : public DPTask
{
public:
    DPTaskCheckFile();
    DPTaskCheckFile(const QString &taskName, const int secs);

    bool execute();
};

#endif // DPTASKPARAMCHECKFILE_H
