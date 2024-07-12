/**
 * @file studentregistration.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#include "studentregistration.h"


/**
 * @brief Constructor for the StudentRegistration class.
 * 
 * @param attendee The person attending the registration.
 * @param bookingDate The date of the booking.
 * @param qualification The qualification of the student.
 */
StudentRegistration::StudentRegistration(const Person &attendee, const QDate &bookingDate, const QString &qualification)
    : Registration(attendee, QDate::currentDate()),
    m_Qualification(qualification)
{

}

/**
 * @brief Calculates the fee for the student registration.
 * 
 * @return The calculated fee.
 */
double StudentRegistration::calculateFee() const
{
    return STANDARD_FEE * 0.5;
}

/**
 * @brief Converts the student registration object to a string representation.
 * 
 * @return The string representation of the student registration.
 */
QString StudentRegistration::toString() const
{
    return Registration::toString().append(
        "Qualification: %1\n"
        "Registration Fee: %2\n")
        .arg(m_Qualification)
        .arg(calculateFee());
}

/**
 * @brief Gets the qualification of the student.
 * 
 * @return The qualification of the student.
 */
QString StudentRegistration::getQualification() const
{
    return m_Qualification;
}
