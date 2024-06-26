#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "person.h"

#include <QDate>
#include <QString>


class Registration : public QObject
{
    Q_OBJECT

public:
    static constexpr double STANDARD_FEE = 100.00;

    Person getAttendee() const;
    QDate getBookingDate() const;
    virtual double calculateFee() const = 0;
    virtual QString toString() const;

protected:
    // Protected constructor to prevent direct instantiation
    Registration(const Person &a);

private:
    Person m_Attendee;
    QDate m_BookingDate;
};

#endif // REGISTRATION_H
