/**
 * @file registration.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell
 * @brief Implementation file for the Registration class.
 * @details This file contains the implementation of the Registration class, which represents a registration for an event.
 */


#include "registration.h"


/**
 * @brief Constructs a Registration object with the given attendee and booking date.
 * @param attendee The person attending the registration.
 * @param bookingDate The date of the registration (default: current date).
 */
Registration::Registration(const Person &attendee, const QDate &bookingDate)
    : QObject(nullptr), m_Attendee(attendee), m_BookingDate(bookingDate)
{

}

/**
 * @brief Sets the booking date of the registration.
 * @param newBookingDate The new booking date to be set.
 */
void Registration::setBookingDate(const QDate &newBookingDate)
{
    m_BookingDate = newBookingDate;
}

/**
 * @brief Gets the attendee of the registration.
 * @return The attendee of the registration.
 */
Person Registration::getAttendee() const
{
    return m_Attendee;
}

/**
 * @brief Gets the booking date of the registration.
 * @return The booking date of the registration.
 */
QDate Registration::getBookingDate() const
{
    return m_BookingDate;
}

/**
 * @brief Converts the Registration object to a string representation.
 * @return The string representation of the Registration object.
 */
QString Registration::toString() const
{
    QString typeName = metaObject()->className();
    return QString("Registration Type: %1\n"
                   "%2\n"
                   "Booking Date: %3\n")
        .arg(typeName)
        .arg(m_Attendee.toString())
        .arg(m_BookingDate.toString());
}
