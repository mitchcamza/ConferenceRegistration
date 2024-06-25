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
    return QString();
}
