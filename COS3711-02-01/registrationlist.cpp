#include "registrationlist.h"
#include <QMetaObject>


RegistrationList::RegistrationList(QObject *parent)
    : QObject(nullptr)
{

}

RegistrationList::~RegistrationList()
{
    qDeleteAll(m_AttendeeList);
    m_AttendeeList.clear();
}

bool RegistrationList::addRegistration(Registration *registration)
{    
    // If email address is already registered, only add new registration if names differ
    foreach (Registration *existingRegistration, m_AttendeeList)
    {
        if (!(existingRegistration->getAttendee().getEmail() == registration->getAttendee().getEmail() && existingRegistration->getAttendee().getName() == registration->getAttendee().getName()))
        {
            m_AttendeeList.append(registration);
            return true;
        }
    }
    return false;
}

bool RegistrationList::isRegistered(const QString &name) const
{
    foreach (Registration *r, m_AttendeeList)
    {
        if (r->getAttendee().getName() == name)
        {
            return true;
        }
    }
    return false;
}

double RegistrationList::totalFee(const QString &type) const
{
    double total = 0;
    foreach (Registration *r, m_AttendeeList)
    {
        // Calculate total fees for given registration type
        if (type.toLower() == "all" || QString(r->metaObject()->className()) == type)
        {
            total += r->calculateFee();
        }
    }
    return total;
}

int RegistrationList::totalRegistrations(const QString &affiliation) const
{
    int totalRegistrationsForAffiliation = 0;
    foreach (Registration *r, m_AttendeeList)
    {
        if (r->getAttendee().getAffiliation().toLower() == affiliation.toLower())
        {
            totalRegistrationsForAffiliation++;
        }
    }
    return totalRegistrationsForAffiliation;
}
