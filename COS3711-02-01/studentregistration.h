#ifndef STUDENTREGISTRATION_H
#define STUDENTREGISTRATION_H

#include "registration.h"

class StudentRegistration : public Registration
{
    Q_OBJECT

public:
    StudentRegistration(const Person &attendee, const QString &qualification);
    virtual ~StudentRegistration() override = default;
    virtual double calculateFee() const override;
    virtual QString toString() const override;
    QString getQualification() const;

private:
    QString m_Qualification;
};

#endif // STUDENTREGISTRATION_H
