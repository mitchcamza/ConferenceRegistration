/**
 * @file guestregistration.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell 2024
 * @brief Implementation file for the GuestRegistration class.
 * @details This file contains the implementation of the GuestRegistration class, which represents a registration for a guest attendee.
 */


#include "guestregistration.h"


GuestRegistration::GuestRegistration(const Person &attendee, const QDate &bookingDate, const QString &category)
    : Registration(attendee, bookingDate),
    m_Category(category)
{

}


double GuestRegistration::calculateFee() const
{
    return STANDARD_FEE * 0.1;
}


QString GuestRegistration::toString() const
{
    return Registration::toString() + QString("Category: %1\nRegistration Fee: %2\n")
        .arg(m_Category)
        .arg(calculateFee());
}


QString GuestRegistration::getCategory() const
{
    return m_Category;
}
