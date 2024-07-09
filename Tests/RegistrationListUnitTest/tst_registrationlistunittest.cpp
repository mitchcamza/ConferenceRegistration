#include <QtTest>
#include "../../COS3711-02-01/registrationmodel.h"
#include "../../COS3711-02-01/registrationlist.h"
#include "../../COS3711-02-01/person.h"
#include "../../COS3711-02-01/standardregistration.h"
#include "../../COS3711-02-01/studentregistration.h"
#include "../../COS3711-02-01/guestregistration.h"

class RegistrationListUnitTest : public QObject
{
    Q_OBJECT

private slots:
    void testAddRegistration_data();
    void testAddRegistration();
    void testIsRegistered();
    void testTotalFee();
    void testTotalRegistrations();
};

void RegistrationListUnitTest::testAddRegistration_data()
{
    QTest::addColumn<QString>("name");
    QTest::addColumn<QString>("affiliation");
    QTest::addColumn<QString>("email");
    QTest::addColumn<QString>("type");
    QTest::addColumn<bool>("expectedResult");

    // QTest::newRow("Standard Registration") << "John Doe" << "Company X" << "john.doe@example.com" << "standard" << true;
    // QTest::newRow("Duplicate Email Different Name") << "Jane Doe" << "Company X" << "john.doe@example.com" << "standard" << true;
    QTest::newRow("Duplicate Registration") << "John Doe" << "Company X" << "john.doe@example.com" << "standard" << false;
    // QTest::newRow("Student Registration") << "Student A" << "University Y" << "student.a@example.com" << "student" << true;
    // QTest::newRow("Guest Registration") << "Guest B" << "Organization Z" << "guest.b@example.com" << "guest" << true;
}

void RegistrationListUnitTest::testAddRegistration()
{
    QFETCH(QString, name);
    QFETCH(QString, affiliation);
    QFETCH(QString, email);
    QFETCH(QString, type);
    QFETCH(bool, expectedResult);

    RegistrationModel model;
    RegistrationList registrationList(model);

    // Create a Registration object based on the type
    Person attendee(name, affiliation, email);
    Registration *registration = nullptr;

    if (type == "standard")
    {
        registration = new StandardRegistration(attendee, QDate::currentDate());
    }
    else if (type == "student")
    {
        registration = new StudentRegistration(attendee, QDate::currentDate(), "Computer Science");
    }
    else if (type == "guest")
    {
        registration = new GuestRegistration(attendee, QDate::currentDate(), "VIP");
    }

    QVERIFY(registration != nullptr); // Ensure registration is created successfully
    bool result = registrationList.addRegistration(registration);
    QCOMPARE(result, expectedResult);
    if (expectedResult)
    {
        QVERIFY(registrationList.isRegistered(attendee));
    }
    else
    {
        QVERIFY(!registrationList.isRegistered(attendee));
    }
}

void RegistrationListUnitTest::testIsRegistered()
{
    RegistrationModel model;
    RegistrationList registrationList(model);

    Person attendee("John Doe", "Company X", "john.doe@example.com");
    Registration *standardRegistration = new StandardRegistration(attendee, QDate::currentDate());

    registrationList.addRegistration(standardRegistration);

    QVERIFY(registrationList.isRegistered("John Doe"));
    QVERIFY(!registrationList.isRegistered("Jane Doe"));
}

void RegistrationListUnitTest::testTotalFee()
{
    RegistrationModel model;
    RegistrationList registrationList(model);

    Person attendee1("John Doe", "Company X", "john.doe@example.com");
    Registration *standardRegistration = new StandardRegistration(attendee1, QDate::currentDate());

    Person attendee2("Jane Doe", "University Y", "jane.doe@example.com");
    Registration *studentRegistration = new StudentRegistration(attendee2, QDate::currentDate(), "BSc Computer Science");

    registrationList.addRegistration(standardRegistration);
    registrationList.addRegistration(studentRegistration);

    QCOMPARE(registrationList.totalFee("all"), Registration::STANDARD_FEE + (Registration::STANDARD_FEE * 0.5));
}

void RegistrationListUnitTest::testTotalRegistrations()
{
    RegistrationModel model;
    RegistrationList registrationList(model);

    Person attendee1("John Doe", "Company X", "john.doe@example.com");
    Registration *standardRegistration = new StandardRegistration(attendee1, QDate::currentDate());

    Person attendee2("Jane Doe", "University Y", "jane.doe@example.com");
    Registration *studentRegistration = new StudentRegistration(attendee2, QDate::currentDate(), "BSc Computer Science");

    registrationList.addRegistration(standardRegistration);
    registrationList.addRegistration(studentRegistration);

    QCOMPARE(registrationList.totalRegistrations("Company X"), 1);
    QCOMPARE(registrationList.totalRegistrations("University Y"), 1);
}

QTEST_MAIN(RegistrationListUnitTest)
#include "tst_registrationlistunittest.moc"
