#include "dptaskoutput.h"

DPTaskOutput::DPTaskOutput()
{

}

DPTaskOutput::DPTaskOutput(const QString &taskName, const int secs) : DPTask(taskName, secs)
{

}


bool DPTaskOutput::execute()
{
    bool ok = true;


    return ok;
}
