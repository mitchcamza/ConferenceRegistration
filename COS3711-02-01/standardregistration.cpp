#include "standardregistration.h"

StandardRegistration::StandardRegistration(const Person &attendee, const QDate &bookingDate)
    : Registration(attendee, bookingDate)
{

}

double StandardRegistration::calculateFee() const
{
    return STANDARD_FEE;
}

QString StandardRegistration::toString() const
{
    return Registration::toString().append(
        "Registration Fee: %1\n")
        .arg(calculateFee());
}


