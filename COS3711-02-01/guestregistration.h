#ifndef GUESTREGISTRATION_H
#define GUESTREGISTRATION_H

#include "registration.h"

class GuestRegistration : public Registration
{
public:
    GuestRegistration(const Person &a, const QString &q);
    virtual double calculateFee() const override;
    virtual QString toString() const override;

private:
    QString m_Category;
};

#endif // GUESTREGISTRATION_H
