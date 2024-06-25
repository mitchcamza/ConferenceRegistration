#include "person.h"

Person::Person(const QString &n, const QString &a, const QString &e)
    : m_Name(n), m_Affiliation(a), m_Email(e)
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
