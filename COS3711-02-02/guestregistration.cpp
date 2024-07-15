/**
 * @file guestregistration.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell 2024
 * @brief Implementation file for the GuestRegistration class.
 * @details This file contains the implementation of the GuestRegistration class, which represents a registration for a guest attendee.
 */


#include "guestregistration.h"


/**
 * @brief Constructs a GuestRegistration object with the given attendee, booking date, and category.
 * @param attendee The person attending the event.
 * @param bookingDate The date of the booking.
 * @param category The category of the guest registration.
 */
GuestRegistration::GuestRegistration(const Person &attendee, const QDate &bookingDate, const QString &category)
    : Registration(attendee, bookingDate),
    m_Category(category)
{

}

/**
 * @brief Calculates the registration fee for the guest registration.
 * @return The calculated registration fee.
 */
double GuestRegistration::calculateFee() const
{
    return STANDARD_FEE * 0.1;
}

/**
 * @brief Returns a string representation of the guest registration.
 * @return The string representation of the guest registration.
 */
QString GuestRegistration::toString() const
{
    return Registration::toString() + QString("Category: %1\nRegistration Fee: %2\n")
        .arg(m_Category)
        .arg(calculateFee());
}

/**
 * @brief Returns the category of the guest registration.
 * @return The category of the guest registration.
 */
QString GuestRegistration::getCategory() const
{
    return m_Category;
}
