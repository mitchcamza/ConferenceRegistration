#include <QtTest>
#include "../../COS3711-02-01/registrationlist.h"
#include "../../COS3711-02-01/person.h"
#include "../../COS3711-02-01/standardregistration.h"
#include "../../COS3711-02-01/studentregistration.h"
#include "../../COS3711-02-01/guestregistration.h"

class RegistrationListUnitTest : public QObject
{
    Q_OBJECT

private slots:
    void testAddRegistration();
    void testIsRegistered();
    void testTotalFee();
    void testTotalRegistrations();
};

void RegistrationListUnitTest::testAddRegistration()
{
    RegistrationList registrationList;

    Person attendee("John Doe", "Company X", "john.doe@example.com");
    Registration *standardRegistration = new StandardRegistration(attendee, QDate::currentDate());

    QVERIFY(registrationList.addRegistration(standardRegistration));
    QVERIFY(registrationList.isRegistered("John Doe"));
}

void RegistrationListUnitTest::testIsRegistered()
{
    RegistrationList registrationList;

    Person attendee("John Doe", "Company X", "john.doe@example.com");
    Registration *standardRegistration = new StandardRegistration(attendee, QDate::currentDate());

    registrationList.addRegistration(standardRegistration);

    QVERIFY(registrationList.isRegistered("John Doe"));
    QVERIFY(!registrationList.isRegistered("Jane Doe"));
}

void RegistrationListUnitTest::testTotalFee()
{
    RegistrationList registrationList;

    Person attendee1("John Doe", "Company X", "john.doe@example.com");
    Registration *standardRegistration = new StandardRegistration(attendee1, QDate::currentDate());

    Person attendee2("Jane Doe", "University Y", "jane.doe@example.com");
    Registration *studentRegistration = new StudentRegistration(attendee2, "BSc Computer Science");

    registrationList.addRegistration(standardRegistration);
    registrationList.addRegistration(studentRegistration);

    QCOMPARE(registrationList.totalFee("all"), Registration::STANDARD_FEE + (Registration::STANDARD_FEE * 0.5));
}

void RegistrationListUnitTest::testTotalRegistrations()
{
    RegistrationList registrationList;

    Person attendee1("John Doe", "Company X", "john.doe@example.com");
    Registration *standardRegistration = new StandardRegistration(attendee1, QDate::currentDate());

    Person attendee2("Jane Doe", "University Y", "jane.doe@example.com");
    Registration *studentRegistration = new StudentRegistration(attendee2, "BSc Computer Science");

    registrationList.addRegistration(standardRegistration);
    registrationList.addRegistration(studentRegistration);

    QCOMPARE(registrationList.totalRegistrations("Company X"), 1);
    QCOMPARE(registrationList.totalRegistrations("University Y"), 1);
}

QTEST_MAIN(RegistrationListUnitTest)
#include "tst_registrationlistunittest.moc"
