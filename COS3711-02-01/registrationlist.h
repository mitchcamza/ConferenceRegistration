#ifndef REGISTRATIONLIST_H
#define REGISTRATIONLIST_H

#include "registration.h"

class RegistrationList
{
public:
    bool addRegistration(Registration* r);
    ~RegistrationList();
    bool isRegistered(const QString &n);
    double totalFee(const QString &t);
    int totalRegistrations(const QString &a);

private:
    QList<Registration*> m_AttendeeList;
};

#endif // REGISTRATIONLIST_H
