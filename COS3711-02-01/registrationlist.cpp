#include "registrationlist.h"
#include "registrationmodel.h"
#include "registrationtypes.h"

#include <QMetaObject>
#include <QMetaEnum>


RegistrationList::RegistrationList(RegistrationModel &model, QObject *parent)
    : QObject(nullptr),
    m_RegistrationModel(&model)
{

}

RegistrationList::~RegistrationList()
{
    qDeleteAll(m_AttendeeList);
    m_AttendeeList.clear();
}

bool RegistrationList::addRegistration(Registration *registration)
{
    if (!isRegistered(registration->getAttendee()))
    {
        m_AttendeeList.append(registration);
        m_RegistrationModel->addItem(registration);
        return true;
    }
    return false;
}

bool RegistrationList::removeRegistration(Registration *registration)
{
    if (m_AttendeeList.removeOne(registration))
    {
        return true;
    }
    return false;
}

bool RegistrationList::isRegistered(const QString &name) const
{
    foreach (Registration *existingRegistration, m_AttendeeList)
    {
        if (existingRegistration->getAttendee().getName().toLower() == name.toLower())
        {
            return true;
        }
    }
    return false;
}

bool RegistrationList::isRegistered(const Person &person) const
{
    foreach (Registration *existingRegistration, m_AttendeeList)
    {
        if (existingRegistration->getAttendee().getEmail().toLower() == person.getEmail().toLower() && existingRegistration->getAttendee().getName().toLower() == person.getName().toLower())
        {
            return true;
        }
    }
    return false;
}

double RegistrationList::totalFee(const QString &typeString) const
{
    double total = 0;
    // TODO: use enum to get type
    // QMetaEnum metaEnum = QMetaEnum::fromType<RegistrationTypes::Type>();
    // RegistrationTypes::Type type = RegistrationTypes::fromString(typeString);

    foreach (Registration *r, m_AttendeeList)
    {
        QString className = r->metaObject()->className();
        // if (type == RegistrationTypes::All || className == metaEnum.valueToKey(type))
        if (typeString.toLower() == "all" || typeString.toLower() == className.toLower())
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

QList<Registration *> RegistrationList::getAttendeeList() const
{
    return m_AttendeeList;
}
