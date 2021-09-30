#include "dptaskparam.h"

DPTaskParam::DPTaskParam()
{
    _value = "TEST";
}

DPTaskParam::DPTaskParam(const QString &value)
{
    _value = value;
}

QString DPTaskParam::value() const
{
    return _value;
}

void DPTaskParam::setValue(const QString &value)
{
    _value = value;
}
