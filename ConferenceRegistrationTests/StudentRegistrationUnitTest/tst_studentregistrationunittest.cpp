#include <QtTest>
#include "../../COS3711-02-01/studentregistration.h"
#include "../../COS3711-02-01/person.h"

class StudentRegistrationUnitTest : public QObject
{
    Q_OBJECT

private slots:
    void testConstructor();
    void testCalculateFee();
    void testToString();
    void testGetQualification();
    void testConstructorSpecialCharacters();
};

void StudentRegistrationUnitTest::testConstructor()
{
    Person attendee("Jane Doe", "University X", "jane.doe@example.com");
    QString qualification = "BSc Computer Science";

    StudentRegistration studentRegistration(attendee, qualification);

    QCOMPARE(studentRegistration.getAttendee().getName(), attendee.getName());
    QCOMPARE(studentRegistration.getAttendee().getAffiliation(), attendee.getAffiliation());
    QCOMPARE(studentRegistration.getAttendee().getEmail(), attendee.getEmail());
    QCOMPARE(studentRegistration.getQualification(), qualification);
}

void StudentRegistrationUnitTest::testCalculateFee()
{
    Person attendee("Jane Doe", "University X", "jane.doe@example.com");
    QString qualification = "BSc Computer Science";

    StudentRegistration studentRegistration(attendee, qualification);

    QCOMPARE(studentRegistration.calculateFee(), Registration::STANDARD_FEE * 0.5);
}

void StudentRegistrationUnitTest::testToString()
{
    Person attendee("Jane Doe", "University X", "jane.doe@example.com");
    QString qualification = "BSc Computer Science";
    QDate bookingDate = QDate::currentDate();

    Registration *studentRegistration = new StudentRegistration(attendee, qualification);

    QString expectedString = QString(
        "Registration Type: %1\n"
        "Name: %2\n"
        "Affiliation: %3\n"
        "Email: %4\n"
        "Booking Date: %5\n"
        "Qualification: %6\n"
        "Registration Fee: %7\n")
        .arg(studentRegistration->metaObject()->className())
        .arg(attendee.getName())
        .arg(attendee.getAffiliation())
        .arg(attendee.getEmail())
        .arg(bookingDate.toString())
        .arg(qualification)
        .arg(Registration::STANDARD_FEE * 0.5);

    QCOMPARE(studentRegistration->toString(), expectedString);
}

void StudentRegistrationUnitTest::testGetQualification()
{
    Person attendee("Jane Doe", "University X", "jane.doe@example.com");
    QString qualification = "BSc Computer Science";

    StudentRegistration studentRegistration(attendee, qualification);

    QCOMPARE(studentRegistration.getQualification(), qualification);
}

void StudentRegistrationUnitTest::testConstructorSpecialCharacters()
{
    Person attendee("Jane & John Doe", "University X & Co.", "jane.doe@example.com");
    QString qualification = "BSc & MSc Computer Science";

    StudentRegistration studentRegistration(attendee, qualification);

    QCOMPARE(studentRegistration.getAttendee().getName(), attendee.getName());
    QCOMPARE(studentRegistration.getAttendee().getAffiliation(), attendee.getAffiliation());
    QCOMPARE(studentRegistration.getAttendee().getEmail(), attendee.getEmail());
    QCOMPARE(studentRegistration.getQualification(), qualification);
}

QTEST_MAIN(StudentRegistrationUnitTest)
#include "tst_studentregistrationunittest.moc"
