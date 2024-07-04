#include "registration.h"


Registration::Registration(const Person &attendee)
    : QObject(nullptr), m_Attendee(attendee), m_BookingDate(QDate::currentDate())
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
    QString typeName = metaObject()->className();
    return QString("Registration Type: %1\nAttendee: %2\nBooking Date: %3")
        .arg(typeName)
        .arg(m_Attendee.toString())
        .arg(m_BookingDate.toString());
}
