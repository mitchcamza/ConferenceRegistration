#include "guestregistration.h"

GuestRegistration::GuestRegistration(const Person &attendee, const QString &category)
    : Registration(attendee), m_Category(category)
{

}

double GuestRegistration::calculateFee() const
{
    return STANDARD_FEE * 0.1;
}

QString GuestRegistration::toString() const
{
    return Registration::toString() + QString("Category: %1\nRegistration Fee: %2")
        .arg(m_Category)
        .arg(calculateFee());
}

QString GuestRegistration::getCategory() const
{
    return m_Category;
}
