#include <QtTest>
#include "../../COS3711-02-01/guestregistration.h"
#include "../../COS3711-02-01/person.h"

class GuestRegistrationUnitTest : public QObject
{
    Q_OBJECT

private slots:
    void testConstructor();
    void testCalculateFee();
    void testToString();
    void testGetCategory();
    void testConstructorSpecialCharacters();
};

void GuestRegistrationUnitTest::testConstructor()
{
    Person attendee("Alice Smith", "Company Y", "alice.smith@example.com");
    QString category = "VIP";

    GuestRegistration guestRegistration(attendee, QDate::currentDate(), category);

    QCOMPARE(guestRegistration.getAttendee().getName(), attendee.getName());
    QCOMPARE(guestRegistration.getAttendee().getAffiliation(), attendee.getAffiliation());
    QCOMPARE(guestRegistration.getAttendee().getEmail(), attendee.getEmail());
    QCOMPARE(guestRegistration.getCategory(), category);
}

void GuestRegistrationUnitTest::testCalculateFee()
{
    Person attendee("Alice Smith", "Company Y", "alice.smith@example.com");
    QString category = "VIP";

    GuestRegistration guestRegistration(attendee, QDate::currentDate(), category);

    QCOMPARE(guestRegistration.calculateFee(), Registration::STANDARD_FEE * 0.1);
}

void GuestRegistrationUnitTest::testToString()
{
    Person attendee("Alice Smith", "Company Y", "alice.smith@example.com");
    QString category = "VIP";
    QDate bookingDate = QDate::currentDate();

    Registration *guestRegistration = new GuestRegistration(attendee, QDate::currentDate(),  category);

    QString expectedString = QString(
                                 "Registration Type: %1\n"
                                 "Name: %2\n"
                                 "Affiliation: %3\n"
                                 "Email: %4\n"
                                 "Booking Date: %5\n"
                                 "Category: %6\n"
                                 "Registration Fee: %7\n")
                                 .arg(guestRegistration->metaObject()->className())
                                 .arg(attendee.getName())
                                 .arg(attendee.getAffiliation())
                                 .arg(attendee.getEmail())
                                 .arg(bookingDate.toString())
                                 .arg(category)
                                 .arg(Registration::STANDARD_FEE * 0.1);

    QCOMPARE(guestRegistration->toString(), expectedString);
}

void GuestRegistrationUnitTest::testGetCategory()
{
    Person attendee("Alice Smith", "Company Y", "alice.smith@example.com");
    QString category = "VIP";

    GuestRegistration guestRegistration(attendee, QDate::currentDate(), category);

    QCOMPARE(guestRegistration.getCategory(), category);
}

void GuestRegistrationUnitTest::testConstructorSpecialCharacters()
{
    Person attendee("Alice & Bob Smith", "Company Y & Co.", "alice.smith@example.com");
    QString category = "VIP & Special";

    GuestRegistration guestRegistration(attendee, QDate::currentDate(), category);

    QCOMPARE(guestRegistration.getAttendee().getName(), attendee.getName());
    QCOMPARE(guestRegistration.getAttendee().getAffiliation(), attendee.getAffiliation());
    QCOMPARE(guestRegistration.getAttendee().getEmail(), attendee.getEmail());
    QCOMPARE(guestRegistration.getCategory(), category);
}

QTEST_MAIN(GuestRegistrationUnitTest)
#include "tst_guestregistrationunittest.moc"
