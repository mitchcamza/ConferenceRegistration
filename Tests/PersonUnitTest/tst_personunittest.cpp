#include <QTest>

#include "../../COS3711-02-01/person.h"

class PersonUnitTest : public QObject
{
    Q_OBJECT

public:
    PersonUnitTest();
    ~PersonUnitTest();

private slots:
    void test_case1();
    void testConstructor();
    void testToString();
    void testConstructorEmptyStrings();
    void testConstructorSpecialCharacters();
    void testToStringEmptyStrings();
    void testToStringSpecialCharacters();
};

PersonUnitTest::PersonUnitTest() {}

PersonUnitTest::~PersonUnitTest() {}

void PersonUnitTest::test_case1() {}

void PersonUnitTest::testConstructor()
{
    QString name = "John Doe";
    QString affiliation = "Company X";
    QString email = "john.doe@example.com";

    Person person(name, affiliation, email);

    QCOMPARE(person.getName(), name);
    QCOMPARE(person.getAffiliation(), affiliation);
    QCOMPARE(person.getEmail(), email);
}

void PersonUnitTest::testToString()
{
    QString name = "John Doe";
    QString affiliation = "Company X";
    QString email = "john.doe@example.com";

    Person person(name, affiliation, email);

    QString expectedString = QString("Name: %1\nAffiliation: %2\nEmail: %3").arg(name).arg(affiliation).arg(email);
    QCOMPARE(person.toString(), expectedString);
}

void PersonUnitTest::testConstructorEmptyStrings()
{
    QString name = "";
    QString affiliation = "";
    QString email = "";

    Person person(name, affiliation, email);

    QCOMPARE(person.getName(), name);
    QCOMPARE(person.getAffiliation(), affiliation);
    QCOMPARE(person.getEmail(), email);
}

void PersonUnitTest::testConstructorSpecialCharacters()
{
    QString name = "John Doe & Sons";
    QString affiliation = "Company X, Ltd.";
    QString email = "john.doe@example.com";

    Person person(name, affiliation, email);

    QCOMPARE(person.getName(), name);
    QCOMPARE(person.getAffiliation(), affiliation);
    QCOMPARE(person.getEmail(), email);
}

void PersonUnitTest::testToStringEmptyStrings()
{
    QString name = "";
    QString affiliation = "";
    QString email = "";

    Person person(name, affiliation, email);

    QString expectedString = QString("Name: %1\nAffiliation: %2\nEmail: %3").arg(name).arg(affiliation).arg(email);
    QCOMPARE(person.toString(), expectedString);
}

void PersonUnitTest::testToStringSpecialCharacters()
{
    QString name = "John Doe & Sons";
    QString affiliation = "Company X, Ltd.";
    QString email = "john.doe@example.com";

    Person person(name, affiliation, email);

    QString expectedString = QString("Name: %1\nAffiliation: %2\nEmail: %3").arg(name).arg(affiliation).arg(email);
    QCOMPARE(person.toString(), expectedString);
}


QTEST_MAIN(PersonUnitTest)
#include "tst_personunittest.moc"
