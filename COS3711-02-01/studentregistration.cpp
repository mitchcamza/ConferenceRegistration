#include "studentregistration.h"

StudentRegistration::StudentRegistration(const Person &attendee, const QString &qualification)
    : Registration(attendee), m_Qualification(qualification)
{

}

double StudentRegistration::calculateFee() const
{
    return STANDARD_FEE * 0.5;
}

QString StudentRegistration::toString() const
{
    return Registration::toString() + QString("Registration Fee: %1")
        .arg(calculateFee());
}

QString StudentRegistration::getQualification() const
{
    return m_Qualification;
}
