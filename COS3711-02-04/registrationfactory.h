#ifndef REGISTRATIONFACTORY_H
#define REGISTRATIONFACTORY_H


class Registration;
class QString;
class QDate;

class RegistrationFactory
{
public:
    static RegistrationFactory &getInstance();

    Registration *createRegistration(const QString &type, const QString &name, const QString &affiliation, const QString &email, const QDate &bookingDate, const QString &additionalInfo);

private:
    RegistrationFactory();
    RegistrationFactory(const RegistrationFactory&) = delete;
    RegistrationFactory &operator=(const RegistrationFactory&) = delete;
};

#endif // REGISTRATIONFACTORY_H
