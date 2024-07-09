#include "standardregistration.h"

StandardRegistration::StandardRegistration(const Person &attendee)
    : Registration(attendee)
{

}

double StandardRegistration::calculateFee() const
{
    return STANDARD_FEE;
}

QString StandardRegistration::toString() const
{
    return Registration::toString() + QString("Registration Fee: %1")
        .arg(calculateFee());
}


