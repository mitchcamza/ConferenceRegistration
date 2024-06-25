#include "registration.h"


Registration::Registration(const Person &a)
    : m_Attendee(a)
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

double Registration::calculateFee() const
{
    return 0;
}

QString Registration::toString() const
{
    return QString();
}
