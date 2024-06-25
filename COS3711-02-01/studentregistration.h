#ifndef STUDENTREGISTRATION_H
#define STUDENTREGISTRATION_H

#include "registration.h"

class StudentRegistration : public Registration
{
public:
    StudentRegistration(Person a, QString q);

private:
    QString m_Qualification;
    virtual double calculateFee() const override;
    virtual QString toString() const override;
};

#endif // STUDENTREGISTRATION_H
