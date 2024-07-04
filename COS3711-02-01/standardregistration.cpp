#include "standardregistration.h"

StandardRegistration::StandardRegistration(const Person &attendee)
    : Registration(attendee)
{

}

double StandardRegistration::calculateFee() const
{
    return STANDARD_FEE;
}

QString StandardRegistration::toString() const
{
    QString typeName = metaObject()->className();
    return Registration::toString() + QString("Type: %1\nFee: %2")
        .arg(typeName)
        .arg(calculateFee());
}


