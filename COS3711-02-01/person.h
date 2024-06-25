#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
public:
    Person(const QString &n, const QString &a, const QString &e);

    QString getName() const;
    QString getAffiliation() const;
    QString getEmail() const;
    QString toString() const;

private:
    QString m_Name;
    QString m_Affiliation;
    QString m_Email;
};

#endif // PERSON_H
