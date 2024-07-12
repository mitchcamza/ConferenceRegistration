/**
 * @file person.h
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef PERSON_H
#define PERSON_H

#include <QString>


/**
 * @class Person
 * @brief The Person class represents a person with a name, affiliation, and email.
 */
class Person
{
public:
    /**
     * @brief Constructs a Person object with the specified name, affiliation, and email.
     * @param name The name of the person.
     * @param affiliation The affiliation of the person.
     * @param email The email address of the person.
     */
    Person(const QString &name, const QString &affiliation, const QString &email);

    /**
     * @brief Default destructor for the Person class.
     */
    ~Person() = default;

    /**
     * @brief Returns the name of the person.
     * @return The name of the person.
     */
    QString getName() const;

    /**
     * @brief Returns the affiliation of the person.
     * @return The affiliation of the person.
     */
    QString getAffiliation() const;

    /**
     * @brief Returns the email address of the person.
     * @return The email address of the person.
     */
    QString getEmail() const;

    /**
     * @brief Returns a string representation of the person.
     * @return A string representation of the person.
     */
    QString toString() const;

private:
    QString m_Name;         ///< The name of the person.
    QString m_Affiliation;  ///< The affiliation of the person.
    QString m_Email;        ///< The email address of the person.
};

#endif // PERSON_H
