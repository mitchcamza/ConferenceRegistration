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
    QString typeName = metaObject()->className();
    return Registration::toString() + QString("Type: %1\nCategory: %2\nFee: %3")
        .arg(typeName)
        .arg(m_Category)
        .arg(calculateFee());
}

QString GuestRegistration::getCategory() const
{
    return m_Category;
}
