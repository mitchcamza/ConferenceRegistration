#ifndef STANDARDREGISTRATION_H
#define STANDARDREGISTRATION_H

#include "registration.h"

class StandardRegistration : public Registration
{
    Q_OBJECT

public:
    StandardRegistration(const Person &attendee);
    virtual ~StandardRegistration() override = default;
    virtual double calculateFee() const override;
    virtual QString toString() const override;
};

#endif // STANDARDREGISTRATION_H
