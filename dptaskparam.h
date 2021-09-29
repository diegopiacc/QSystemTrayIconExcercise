#ifndef DPTASKPARAM_H
#define DPTASKPARAM_H

#include <QString>

class DPTaskParam
{
public:
    DPTaskParam();

    QString value() const;
    void setValue(const QString &value);

private:
    QString _value;
};

#endif // DPTASKPARAM_H
