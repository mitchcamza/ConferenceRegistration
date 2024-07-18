/** 
 * @file person.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell
 */


#include "person.h"


Person::Person(const QString &name, const QString &affiliation, const QString &email)
    : m_Name(name), m_Affiliation(affiliation), m_Email(email)
{

}


QString Person::getName() const
{
    return m_Name;
}


QString Person::getAffiliation() const
{
    return m_Affiliation;
}


QString Person::getEmail() const
{
    return m_Email;
}


QString Person::toString() const
{
    return QString("Name: %1\nAffiliation: %2\nEmail: %3").arg(m_Name).arg(m_Affiliation).arg(m_Email);
}
