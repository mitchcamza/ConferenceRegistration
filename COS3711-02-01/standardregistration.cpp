#include "standardregistration.h"

StandardRegistration::StandardRegistration(const Person &a)
    : Registration(a)
{

}

double StandardRegistration::calculateFee() const
{
    return STANDARD_FEE;
}

QString StandardRegistration::toString() const
{
    return QString();
}


