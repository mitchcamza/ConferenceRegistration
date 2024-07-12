/** 
 * @file person.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell
 * @brief Implementation file for the Person class.
 * @details This file contains the implementation of the Person class, which represents a person attending an event.
 */


#include "person.h"


/**
 * @brief Constructs a Person object with the given name, affiliation, and email.
 * 
 * @param name The name of the person.
 * @param affiliation The affiliation of the person.
 * @param email The email address of the person.
 */
Person::Person(const QString &name, const QString &affiliation, const QString &email)
    : m_Name(name), m_Affiliation(affiliation), m_Email(email)
{

}

/**
 * @brief Gets the name of the person.
 * 
 * @return The name of the person.
 */
QString Person::getName() const
{
    return m_Name;
}

/**
 * @brief Gets the affiliation of the person.
 * 
 * @return The affiliation of the person.
 */
QString Person::getAffiliation() const
{
    return m_Affiliation;
}

/**
 * @brief Gets the email address of the person.
 * 
 * @return The email address of the person.
 */
QString Person::getEmail() const
{
    return m_Email;
}

/**
 * @brief Converts the Person object to a string representation.
 * 
 * @return A string representation of the Person object.
 */
QString Person::toString() const
{
    return QString("Name: %1\nAffiliation: %2\nEmail: %3").arg(m_Name).arg(m_Affiliation).arg(m_Email);
}
