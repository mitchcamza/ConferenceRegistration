#include "registration.h"


Registration::Registration(const Person &a)
    : QObject(nullptr), m_Attendee(a), m_BookingDate(QDate::currentDate())
{

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
    return QString("Attendee: %1\nBooking Date: %2")
        .arg(m_Attendee.toString())
        .arg(m_BookingDate.toString());
}
