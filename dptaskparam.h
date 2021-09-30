#ifndef DPTASKPARAM_H
#define DPTASKPARAM_H

#include <QString>

/**
 * @brief The DPTaskParam class
 *
 * This class is intended to represent a generic task parameter, for the sake of this exercise it
 * is a simple encapsulation of a QString.
 */
class DPTaskParam
{
public:
    DPTaskParam();
    DPTaskParam(const QString &value);

    QString value() const;

    void setValue(const QString &value);

private:
    QString _value;
};

#endif // DPTASKPARAM_H
