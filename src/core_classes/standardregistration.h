/**
 * @file standardregistration.h
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef STANDARDREGISTRATION_H
#define STANDARDREGISTRATION_H

#include "registration.h"


/**
 * @class StandardRegistration
 * @brief The StandardRegistration class represents a standard registration for an event.
 * @details This class inherits from the Registration class and provides additional functionality specific to standard registrations.
 */
class StandardRegistration : public Registration
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a StandardRegistration object with the given attendee and booking date.
     * @param attendee The person attending the event.
     * @param bookingDate The date of the booking. Defaults to the current date.
     */
    StandardRegistration(const Person &attendee, const QDate &bookingDate = QDate::currentDate());

    /**
     * @brief Destroys the StandardRegistration object.
     */
    virtual ~StandardRegistration() override = default;

    /**
     * @brief Calculates the fee for the standard registration.
     * @return The fee for the standard registration.
     */
    virtual double calculateFee() const override;

    /**
     * @brief Returns a string representation of the StandardRegistration object.
     * @return A string representation of the StandardRegistration object.
     */
    virtual QString toString() const override;
};

#endif // STANDARDREGISTRATION_H
