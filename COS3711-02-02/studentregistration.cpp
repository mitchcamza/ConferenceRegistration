/**
 * @file studentregistration.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#include "studentregistration.h"


StudentRegistration::StudentRegistration(const Person &attendee, const QDate &bookingDate, const QString &qualification)
    : Registration(attendee, QDate::currentDate()),
    m_Qualification(qualification)
{

}


double StudentRegistration::calculateFee() const
{
    return STANDARD_FEE * 0.5;
}


QString StudentRegistration::toString() const
{
    return Registration::toString().append(
        "Qualification: %1\n"
        "Registration Fee: %2\n")
        .arg(m_Qualification)
        .arg(calculateFee());
}


QString StudentRegistration::getQualification() const
{
    return m_Qualification;
}
