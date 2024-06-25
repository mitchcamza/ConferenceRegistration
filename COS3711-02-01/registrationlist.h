#ifndef REGISTRATIONLIST_H
#define REGISTRATIONLIST_H

#include "registration.h"

class RegistrationList
{
public:
    bool addRegistration(Registration* r);
    ~RegistrationList();
    bool isRegistered(QString n);
    double totalFee(QString t);
    int totalRegistrations(QString a);

private:
    QList<Registration*> m_AttendeeList;
};

#endif // REGISTRATIONLIST_H
