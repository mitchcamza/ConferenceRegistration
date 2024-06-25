#include "studentregistration.h"

StudentRegistration::StudentRegistration(const Person &a, const QString &q)
    : Registration(a), m_Qualification(q)
{

}

double StudentRegistration::calculateFee() const
{
    return STANDARD_FEE * 0.5;
}

QString StudentRegistration::toString() const
{
    return QString();
}
