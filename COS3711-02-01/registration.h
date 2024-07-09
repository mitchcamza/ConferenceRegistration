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

    virtual ~Registration() = default;
    Person getAttendee() const;
    QDate getBookingDate() const;
    virtual double calculateFee() const = 0;
    virtual QString toString() const;

    void setBookingDate(const QDate &newBookingDate);

protected:
    Registration(const Person &attendee, const QDate &bookingDate);

private:
    Person m_Attendee;
    QDate m_BookingDate;
};

#endif // REGISTRATION_H
