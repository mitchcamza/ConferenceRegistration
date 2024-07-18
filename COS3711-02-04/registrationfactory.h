/**
 * @file registrationfactory.h
 * @author Mitch Campbell
 * @date 2024-07-17
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef REGISTRATIONFACTORY_H
#define REGISTRATIONFACTORY_H


class QDate;
class QString;
class Registration;


/**
 * @class RegistrationFactory
 * @brief The RegistrationFactory class is a singleton class that is responsible for creating Registration objects.
 */
class RegistrationFactory
{
public:
    /**
     * @brief getInstance
     * @return The singleton instance of the RegistrationFactory class.
     */
    static RegistrationFactory &getInstance();

    /**
     * @brief createRegistration
     * @param type The type of registration to create.
     * @param name The name of the person registering.
     * @param affiliation The affiliation of the person registering.
     * @param email The email of the person registering.
     * @param bookingDate The date the person is registering for.
     * @param additionalInfo Additional information about the person registering.
     * @return A pointer to the created Registration object.
     */
    Registration *createRegistration(const QString &type, const QString &name, const QString &affiliation, const QString &email, const QDate &bookingDate, const QString &additionalInfo);

private:
    /**
     * @brief Construct a new Registration Factory object.
     * Marked as private to prevent instantiation.
     */
    RegistrationFactory();

    /** @brief Deleted copy constructor to prevent cloning */
    RegistrationFactory(const RegistrationFactory&) = delete;

    /** @brief Deleted assignment operator to prevent cloning */
    RegistrationFactory &operator=(const RegistrationFactory&) = delete;
};

#endif // REGISTRATIONFACTORY_H
