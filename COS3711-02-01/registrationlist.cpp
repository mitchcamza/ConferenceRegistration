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


/**
 * @brief Constructs a RegistrationList object.
 * @param model The RegistrationModel object.
 * @param parent The parent QObject.
 */
RegistrationList::RegistrationList(RegistrationModel &model, QObject *parent)
    : QObject(nullptr),
    m_RegistrationModel(&model)
{
    connect(this, &RegistrationList::registrationAdded, this, &RegistrationList::on_registrationAdded);
    connect(this, &RegistrationList::registrationRemoved, this, &RegistrationList::on_registrationRemoved);
}

/**
 * @brief Destroys the RegistrationList object and frees the memory.
 */
RegistrationList::~RegistrationList()
{
    qDeleteAll(m_AttendeeList);
    m_AttendeeList.clear();
}

/**
 * @brief Adds a registration to the list.
 * @param registration The Registration object to add.
 * @return True if the registration was added successfully, false otherwise.
 */
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

/**
 * @brief Removes a registration from the list.
 * @param registration The Registration object to remove.
 * @return True if the registration was removed successfully, false otherwise.
 */
bool RegistrationList::removeRegistration(Registration *registration)
{
    if (m_AttendeeList.removeOne(registration))
    {
        emit registrationRemoved(registration);
        return true;
    }
    return false;
}

/**
 * @brief Checks if a person with the given name is already registered.
 * @param name The name of the person.
 * @return True if the person is already registered, false otherwise.
 */
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

/**
 * @brief Checks if a person is already registered.
 * @param person The Person object to check.
 * @return True if the person is already registered, false otherwise.
 */
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

/**
 * @brief Calculates the total fee for registrations of a specific type.
 * @param typeString The type of registration as a string.
 * @return The total fee for registrations of the specified type.
 */
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

/**
 * @brief Calculates the total number of registrations for a specific affiliation.
 * @param affiliation The affiliation to count registrations for.
 * @return The total number of registrations for the specified affiliation.
 */
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

/**
 * @brief Returns the list of attendees.
 * @return The list of attendees.
 */
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
