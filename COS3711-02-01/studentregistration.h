#ifndef STUDENTREGISTRATION_H
#define STUDENTREGISTRATION_H

#include "registration.h"

class StudentRegistration : public Registration
{
    Q_OBJECT

public:
    StudentRegistration(const Person &a, const QString &q);
    virtual double calculateFee() const override;
    virtual QString toString() const override;

private:
    QString m_Qualification;
};

#endif // STUDENTREGISTRATION_H
