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

bool RegistrationList::addRegistration(Registration *r)
{
    // Append registration to list if it does not exist
    if (!isRegistered(r->getAttendee().getName()))
    {
        m_AttendeeList.append(r);
        return true;
    }
    return false;
}

bool RegistrationList::isRegistered(const QString &n) const
{
    foreach (Registration *r, m_AttendeeList)
    {
        if (r->getAttendee().getName() == n)
        {
            return true;
        }
    }
    return false;
}

double RegistrationList::totalFee(const QString &t) const
{
    double total = 0;
    foreach (Registration *r, m_AttendeeList)
    {
        // Calculate total fees for given registration type
        if (t == "All" || QString(r->metaObject()->className()) == t)
        {
            total += r->calculateFee();
        }
    }
    return total;
}

int RegistrationList::totalRegistrations(const QString &a) const
{
    int totalRegistrationsForAffiliation = 0;
    foreach (Registration *r, m_AttendeeList)
    {
        if (r->getAttendee().getAffiliation() == a)
        {
            totalRegistrationsForAffiliation++;
        }
    }
    return totalRegistrationsForAffiliation;
}
