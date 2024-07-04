#ifndef GUESTREGISTRATION_H
#define GUESTREGISTRATION_H

#include "registration.h"

class GuestRegistration : public Registration
{
    Q_OBJECT

public:
    GuestRegistration(const Person &attendee, const QString &category);
    virtual ~GuestRegistration() override = default;
    virtual double calculateFee() const override;
    virtual QString toString() const override;
    QString getCategory() const;

private:
    QString m_Category;
};

#endif // GUESTREGISTRATION_H
