/**
 * @file standardregistration.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 * @brief Implementation file for the StandardRegistration class.
 */


#include "standardregistration.h"


/**
 * @brief Constructs a StandardRegistration object.
 * @param attendee The person attending the registration.
 * @param bookingDate The date of the registration booking.
 */
StandardRegistration::StandardRegistration(const Person &attendee, const QDate &bookingDate)
    : Registration(attendee, bookingDate)
{

}

/**
 * @brief Calculates the registration fee for a standard registration.
 * @return The registration fee.
 */
double StandardRegistration::calculateFee() const
{
    return STANDARD_FEE;
}

/**
 * @brief Converts the StandardRegistration object to a string representation.
 * @return The string representation of the StandardRegistration object.
 */
QString StandardRegistration::toString() const
{
    return Registration::toString().append(
        "Registration Fee: %1\n")
        .arg(calculateFee());
}
