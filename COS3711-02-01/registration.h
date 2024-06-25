#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "person.h"

#include <QDate>
#include <QString>


class Registration
{
public:
    const double STANDARD_FEE = 100.00;

    Registration(Person a);
    Person getAttendee() const;
    QDate getBookingDate() const;
    virtual double calculateFee() const;
    virtual QString toString() const;

private:
    Person m_Attendee;
    QDate m_BookingDate;
};

#endif // REGISTRATION_H
