/**
 * @file studentregistration.h
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef STUDENTREGISTRATION_H
#define STUDENTREGISTRATION_H

#include "registration.h"

#include <QDate>


/**
 * @class StudentRegistration
 * @brief The StudentRegistration class represents a registration for a student attendee.
 * @details This class inherits from the Registration class and adds additional functionality specific to student registrations.
 */
class StudentRegistration : public Registration
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a StudentRegistration object with the given attendee, booking date, and qualification.
     * @param attendee The person attending the registration.
     * @param bookingDate The date of the registration booking. Defaults to the current date.
     * @param qualification The qualification of the student. Defaults to an empty string.
     */
    StudentRegistration(const Person &attendee, const QDate &bookingDate = QDate::currentDate(), const QString &qualification = "");

    /**
     * @brief Default destructor for the StudentRegistration class.
     */
    virtual ~StudentRegistration() override = default;

    /**
     * @brief Calculates the fee for the student registration.
     * @return The fee for the student registration.
     */
    virtual double calculateFee() const override;

    /**
     * @brief Converts the StudentRegistration object to a string representation.
     * @return The string representation of the StudentRegistration object.
     */
    virtual QString toString() const override;

    /**
     * @brief Gets the qualification of the student.
     * @return The qualification of the student.
     */
    QString getQualification() const;

private:
    QString m_Qualification; /**< The qualification of the student. */
};

#endif // STUDENTREGISTRATION_H
