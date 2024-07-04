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
    QString typeName = metaObject()->className();
    return Registration::toString() + QString("Registration Type: %1\nFee: %2")
        .arg(typeName)
        .arg(calculateFee());
}

QString StudentRegistration::getQualification() const
{
    return m_Qualification;
}
