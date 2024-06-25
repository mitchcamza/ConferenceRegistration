#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "person.h"

#include <QDate>
#include <QString>


class Registration
{
protected:
    // Constructor marked protected to ensure that only derived classes can call it
    Registration(const Person &a);

public:
    static constexpr double STANDARD_FEE = 100.00;

    Person getAttendee() const;
    QDate getBookingDate() const;
    virtual double calculateFee() const = 0;
    virtual QString toString() const = 0;

private:
    Person m_Attendee;
    QDate m_BookingDate;
};

#endif // REGISTRATION_H
