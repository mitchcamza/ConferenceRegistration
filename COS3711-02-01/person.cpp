#include "person.h"

Person::Person(const QString &n, const QString &a, const QString &e)
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
    return QString();
}
