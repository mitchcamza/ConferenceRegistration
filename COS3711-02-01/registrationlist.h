#ifndef REGISTRATIONLIST_H
#define REGISTRATIONLIST_H

#include "registration.h"
#include <QObject>
#include <QList>


/**
 * @class RegistrationList
 * @brief Manages a list of conference registrations.
 *
 * The RegistrationList class provides functionality to add and query conference
 * registrations. It ensures no duplicate registrations by name and calculates
 * total fees based on registration types.
 */
class RegistrationList : public QObject
{
    Q_OBJECT

public:
    /**
     *  @brief Constructs a RegistrationList.
     *  @param parent The parent QObject, default is nullptr.
     */
    RegistrationList(QObject *parent = nullptr);

    /**
     * @brief Destructor for RegistrationList.
     * Cleans up the list of Registrations.
     */
    ~RegistrationList();

    /** @brief Adds attendee to list if their name is not on the list.
     *  @param registration The registration.
     */
    bool addRegistration(Registration* registration);

    /** @brief Returns true if the attendee (person) is already registered (by name).
     *  Returns false if the attendee's name is not on the list.
     *  @note Since a uniqueness check is only performed on names, duplicate Email addresses may exist.
     *  @param name The attendee's name.
     */
    bool isRegistered(const QString &name) const;

    /** @brief Returns the total registration fees for a type of registration
     *  @note Registration types may include "StandardRegistration", "StudentRegistration", "GuestRegistration", or "All".
     *  @param type The type of Registration.
     */
    double totalFee(const QString &type) const;

    /** @brief Returns the number of attendees that are registered for the conference from an institution.
     *  @param affiliation The affiliation (institution).
     */
    int totalRegistrations(const QString &affiliation) const;

private:
    QList<Registration*> m_AttendeeList; ///< List of registrations.
};

#endif // REGISTRATIONLIST_H
