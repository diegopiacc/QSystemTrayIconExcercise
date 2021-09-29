#include "dptaskcheckfile.h"

DPTaskCheckFile::DPTaskCheckFile()
{

}

DPTaskCheckFile::DPTaskCheckFile(const QString &taskName, const int secs) : DPTask(taskName, secs)
{

}

bool DPTaskCheckFile::execute()
{
    bool ok = true;


    return ok;
}
