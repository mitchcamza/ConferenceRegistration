/**
 * @file registrationlist.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell
 * @brief Implementation file for the RegistrationList class.
 */


#include "registrationlist.h"
#include "registrationmodel.h"

#include <QMetaEnum>
#include <QMetaObject>


RegistrationList::RegistrationList(RegistrationModel &model, QObject *parent)
    : QObject(nullptr),
    m_RegistrationModel(&model)
{
    connect(this, &RegistrationList::registrationAdded, this, &RegistrationList::on_registrationAdded);
    connect(this, &RegistrationList::registrationRemoved, this, &RegistrationList::on_registrationRemoved);
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
        emit(registrationAdded(registration));
        return true;
    }
    return false;
}


bool RegistrationList::removeRegistration(Registration *registration)
{
    if (m_AttendeeList.removeOne(registration))
    {
        emit registrationRemoved(registration);
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
    foreach (Registration *r, m_AttendeeList)
    {
        QString className = r->metaObject()->className();
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

void RegistrationList::on_registrationAdded(Registration *registration)
{
    m_RegistrationModel->addItem(registration);
}

void RegistrationList::on_registrationRemoved(Registration *registration)
{
    // TODO: Remove registration from model
}
