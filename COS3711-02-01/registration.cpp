/**
 * @file registration.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell
 */


#include "registration.h"


Registration::Registration(const Person &attendee, const QDate &bookingDate)
    : QObject(nullptr), m_Attendee(attendee), m_BookingDate(bookingDate)
{

}


void Registration::setBookingDate(const QDate &newBookingDate)
{
    m_BookingDate = newBookingDate;
}


Person Registration::getAttendee() const
{
    return m_Attendee;
}


QDate Registration::getBookingDate() const
{
    return m_BookingDate;
}


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
