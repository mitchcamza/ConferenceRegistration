#include <QTest>
#include "../../COS3711-02-01/COS3711-02-01/standardregistration.h"
#include "../../COS3711-02-01/COS3711-02-01/person.h"

class StandardRegistrationUnitTest : public QObject
{
    Q_OBJECT

private slots:
    void testConstructor();
    void testCalculateFee();
    void testToString();
    void testEdgeCasePastDate();
    void testEdgeCaseFutureDate();
    void testSpecialCharacters();
};

void StandardRegistrationUnitTest::testConstructor()
{
    Person attendee("John Doe", "Company X", "john.doe@example.com");
    QDate bookingDate = QDate::currentDate();

    StandardRegistration standardRegistration(attendee, bookingDate);

    QCOMPARE(standardRegistration.getAttendee().getName(), attendee.getName());
    QCOMPARE(standardRegistration.getAttendee().getAffiliation(), attendee.getAffiliation());
    QCOMPARE(standardRegistration.getAttendee().getEmail(), attendee.getEmail());
    QCOMPARE(standardRegistration.getBookingDate(), bookingDate);
}

void StandardRegistrationUnitTest::testCalculateFee()
{
    Person attendee("John Doe", "Company X", "john.doe@example.com");
    QDate bookingDate = QDate::currentDate();

    StandardRegistration standardRegistration(attendee, bookingDate);

    QCOMPARE(standardRegistration.calculateFee(), Registration::STANDARD_FEE);
}

void StandardRegistrationUnitTest::testToString()
{
    Person *attendee = new Person("John & Jane Doe", "Company & Co.", "john.doe@example.com");
    QDate bookingDate = QDate::currentDate();

    Registration *standardRegistration = new StandardRegistration(*attendee, bookingDate);

    QString expectedString = QString(
                                 "Registration Type: %1\n"
                                 "Name: %2\n"
                                 "Affiliation: %3\n"
                                 "Email: %4\n"
                                 "Booking Date: %5\n"
                                 "Registration Fee: %6"
                                 )
                                 .arg(standardRegistration->metaObject()->className())
                                 .arg(attendee->getName())
                                 .arg(attendee->getAffiliation())
                                 .arg(attendee->getEmail())
                                 .arg(bookingDate.toString())
                                 .arg(Registration::STANDARD_FEE);

    QCOMPARE(standardRegistration->toString(), expectedString);
}

void StandardRegistrationUnitTest::testEdgeCasePastDate()
{
    Person attendee("John Doe", "Company X", "john.doe@example.com");
    QDate pastDate = QDate::currentDate().addYears(-1);

    StandardRegistration standardRegistration(attendee, pastDate);

    QCOMPARE(standardRegistration.getBookingDate(), pastDate);
}

void StandardRegistrationUnitTest::testEdgeCaseFutureDate()
{
    Person attendee("John Doe", "Company X", "john.doe@example.com");
    QDate futureDate = QDate::currentDate().addYears(1);

    StandardRegistration standardRegistration(attendee, futureDate);

    QCOMPARE(standardRegistration.getBookingDate(), futureDate);
}

void StandardRegistrationUnitTest::testSpecialCharacters()
{
    Person *attendee = new Person("John & Jane Doe", "Company & Co.", "john.doe@example.com");
    QDate bookingDate = QDate::currentDate();

    Registration *standardRegistration = new StandardRegistration(*attendee, bookingDate);

    QString expectedString = QString(
                                 "Registration Type: %1\n"
                                 "Name: %2\n"
                                 "Affiliation: %3\n"
                                 "Email: %4\n"
                                 "Booking Date: %5\n"
                                 "Registration Fee: %6"
                                 )
                                 .arg(standardRegistration->metaObject()->className())
                                 .arg(attendee->getName())
                                 .arg(attendee->getAffiliation())
                                 .arg(attendee->getEmail())
                                 .arg(bookingDate.toString())
                                 .arg(Registration::STANDARD_FEE);

    QCOMPARE(standardRegistration->toString(), expectedString);
}

QTEST_MAIN(StandardRegistrationUnitTest)

#include "tst_standardregistrationunittest.moc"
