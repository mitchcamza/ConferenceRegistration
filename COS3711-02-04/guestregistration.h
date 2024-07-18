/**
 * @file guestregistration.h
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef GUESTREGISTRATION_H
#define GUESTREGISTRATION_H

#include "registration.h"


/**
 * @class GuestRegistration
 * @brief The GuestRegistration class represents a registration for a guest attendee.
 * @details This class inherits from the Registration class and adds additional functionality specific to guest registrations. It provides methods to calculate the registration fee and convert the registration details to a string format.
 * @see Registration
 */
class GuestRegistration : public Registration
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a GuestRegistration object with the given attendee, booking date, and category.
     * @param attendee The person attending the event.
     * @param bookingDate The date of the booking. Defaults to the current date.
     * @param category The category of the guest registration.
     */
    GuestRegistration(const Person &attendee, const QDate &bookingDate = QDate::currentDate(), const QString &category = "");

    /**
     * @brief Default destructor for the GuestRegistration class.
     */
    virtual ~GuestRegistration() override = default;

    /**
     * @brief Calculates the registration fee for the guest registration.
     * @return The calculated registration fee.
     */
    virtual double calculateFee() const override;

    /**
     * @brief Converts the guest registration details to a string format.
     * @return The guest registration details as a string.
     */
    virtual QString toString() const override;

    /**
     * @brief Gets the category of the guest registration.
     * @return The category of the guest registration.
     */
    QString getCategory() const;

private:
    QString m_Category; /**< The category of the guest registration. */
};

#endif // GUESTREGISTRATION_H
