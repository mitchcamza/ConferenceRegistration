#ifndef STANDARDREGISTRATION_H
#define STANDARDREGISTRATION_H

#include "registration.h"

class StandardRegistration : public Registration
{
public:
    StandardRegistration(const Person &a);
    virtual double calculateFee() const override;
    virtual QString toString() const override;
};

#endif // STANDARDREGISTRATION_H
