/**
 * @file registration.h
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "person.h"

#include <QDate>
#include <QString>


/**
 * @class Registration
 * @brief The Registration class represents a registration for an event.
 * @details This class is an abstract base class that provides common functionality for event registrations. It contains information about the attendee, booking date, and fee calculation.
 */
class Registration : public QObject
{
    Q_OBJECT

public:
    static constexpr double STANDARD_FEE = 100.00;

    /**
     * @brief Destructor.
     */
    virtual ~Registration() = default;

    /**
     * @brief Get the attendee associated with the registration.
     * @return The attendee.
     */
    Person getAttendee() const;

    /**
     * @brief Get the booking date of the registration.
     * @return The booking date.
     */
    QDate getBookingDate() const;

    /**
     * @brief Calculate the fee for the registration.
     * @return The calculated fee.
     *
     * This is a pure virtual function that must be implemented by derived classes.
     */
    virtual double calculateFee() const = 0;

    /**
     * @brief Convert the registration information to a string representation.
     * @return The string representation of the registration.
     */
    virtual QString toString() const;

    /**
     * @brief Set the booking date of the registration.
     * @param newBookingDate The new booking date.
     */
    void setBookingDate(const QDate &newBookingDate);

protected:
    /**
     * @brief Constructor.
     * @param attendee The attendee associated with the registration.
     * @param bookingDate The booking date of the registration.
     */
    Registration(const Person &attendee, const QDate &bookingDate);

private:
    Person m_Attendee;      /**< The attendee associated with the registration. */
    QDate m_BookingDate;    /**< The booking date of the registration. */
};

#endif // REGISTRATION_H
