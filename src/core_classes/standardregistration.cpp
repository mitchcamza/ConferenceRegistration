/**
 * @file standardregistration.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


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
