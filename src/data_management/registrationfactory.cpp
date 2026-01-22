/**
 * @file registrationfactory.cpp
 * @author Mitch Campbell
 * @date 2024-07-17
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#include "guestregistration.h"
#include "person.h"
#include "registration.h"
#include "registrationfactory.h"
#include "standardregistration.h"
#include "studentregistration.h"

#include <QDate>


RegistrationFactory &RegistrationFactory::getInstance()
{
    static RegistrationFactory registrationFactoryInstance;
    return registrationFactoryInstance;
}

Registration *RegistrationFactory::createRegistration(const QString &type, const QString &name, const QString &affiliation, const QString &email, const QDate &bookingDate, const QString &additionalInfo)
{
    Person attendee(name, affiliation, email);

    if (type.toLower() == "standard")
    {
        return new StandardRegistration(attendee, bookingDate);
    }
    else if (type.toLower() == "student")
    {
        return new StudentRegistration(attendee, bookingDate, additionalInfo);
    }
    else if (type.toLower() == "guest")
    {
        return new GuestRegistration(attendee, bookingDate, additionalInfo);
    }
    else
    {
        return nullptr;
    }
}

RegistrationFactory::RegistrationFactory() {}
