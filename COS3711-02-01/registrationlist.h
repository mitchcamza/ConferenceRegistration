/**
 * @file registrationlist.h
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef REGISTRATIONLIST_H
#define REGISTRATIONLIST_H

#include "registration.h"


#include <QObject>
#include <QList>

class RegistrationModel;
class RegistrationTypes;


/**
 * @class RegistrationList
 * @brief Manages a list of conference registrations.
 * @details The RegistrationList class provides functionality to add and query conference registrations. It ensures no duplicate email addresses exist, unless they are associated with different names. It also calculates total fees based on registration types, as well as the number of attendees registered from a specific institution/affiliation.
 */
class RegistrationList : public QObject
{
    Q_OBJECT

public:
    /**
     *  @brief Constructs a RegistrationList.
     *  @param model The RegistrationModel object.
     *  @param parent The parent QObject, default is nullptr.
     */
    RegistrationList(RegistrationModel &model, QObject *parent = nullptr);

    /**
     * @brief Destructor for RegistrationList.
     * Cleans up the list of Registrations.
     */
    ~RegistrationList();

    /** 
     * @brief Adds a registration to the list if the attendee's name is not already on the list.
     * @param registration The registration to be added.
     * @return true if the registration was added successfully, false otherwise.
     */
    bool addRegistration(Registration* registration);

    /** 
     * @brief Removes the selected registration from the list.
     * @param registration The registration to be removed.
     * @return true if the registration was removed successfully, false otherwise.
     */
    bool removeRegistration(Registration *registration);

    /** 
     * @brief Checks if an attendee with the given name is already registered.
     * @param name The name of the attendee.
     * @return true if the attendee is already registered, false otherwise.
     */
    bool isRegistered(const QString &name) const;

    /** 
     * @brief Checks if an attendee is already registered.
     * @param person The Person object representing the attendee.
     * @return true if the attendee is already registered, false otherwise.
     */
    bool isRegistered(const Person &person) const;

    /** 
     * @brief Calculates the total registration fees for a given type of registration.
     * @param typeString The type of registration.
     * @return The total registration fees for the given type.
     */
    double totalFee(const QString &typeString) const;

    /** 
     * @brief Returns the number of attendees registered for the conference from a specific institution.
     * @param affiliation The affiliation (institution).
     * @return The number of registrations from the specified institution.
     */
    int totalRegistrations(const QString &affiliation) const;

    /**
     * @brief Returns the list of attendees.
     * @return The list of attendees.
     */
    QList<Registration *> getAttendeeList() const;

signals:
    /**
     * @brief Signal emitted when a registration is added to the list.
     * @param registration The added registration.
     */
    void registrationAdded(Registration *registration);

    /**
     * @brief Signal emitted when a registration is removed from the list.
     * @param registration The removed registration.
     */
    void registrationRemoved(Registration *registration);

private slots:
    void on_registrationAdded(Registration *registration);
    void on_registrationRemoved(Registration *registration);

private:
    QList<Registration*> m_AttendeeList; ///< List of registrations.
    RegistrationModel *m_RegistrationModel;
};

#endif // REGISTRATIONLIST_H
