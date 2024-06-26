#include "guestregistration.h"

GuestRegistration::GuestRegistration(const Person &a, const QString &q)
    : Registration(a), m_Category(q)
{

}

double GuestRegistration::calculateFee() const
{
    return STANDARD_FEE * 0.1;
}

QString GuestRegistration::toString() const
{
    QString typeName = metaObject()->className();
    return Registration::toString() + QString("Type: %1\nCategory: %2\nFee: %3")
        .arg(typeName)
        .arg(m_Category)
        .arg(calculateFee());
}
