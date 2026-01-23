/**
 * @file registrationfactory_test.cpp
 * @brief Unit tests for RegistrationFactory class
 */

#include "registrationfactory.h"
#include "registration.h"
#include "standardregistration.h"
#include "studentregistration.h"
#include "guestregistration.h"
#include "person.h"
#include <gtest/gtest.h>
#include <QDate>
#include <QString>
#include <vector>

/**
 * @brief Test fixture for RegistrationFactory tests
 */
class RegistrationFactoryTest : public ::testing::Test {
protected:
    void SetUp() override {
        factory = &RegistrationFactory::getInstance();
        testDate = QDate(2024, 7, 15);
        name = "Jane Doe";
        affiliation = "Stanford";
        email = "jane@stanford.edu";
    }

    void TearDown() override {
        // Factory is a singleton, no cleanup needed
    }

    RegistrationFactory* factory;
    QDate testDate;
    QString name;
    QString affiliation;
    QString email;
};

// ============================================================================
// Singleton Pattern Tests
// ============================================================================

/**
 * @brief Test that getInstance returns the same instance
 */
TEST_F(RegistrationFactoryTest, SingletonInstanceConsistency) {
    RegistrationFactory& instance1 = RegistrationFactory::getInstance();
    RegistrationFactory& instance2 = RegistrationFactory::getInstance();

    EXPECT_EQ(&instance1, &instance2);
}

// ============================================================================
// StandardRegistration Creation Tests
// ============================================================================

/**
 * @brief Test creating StandardRegistration with lowercase type
 */
TEST_F(RegistrationFactoryTest, CreateStandardRegistrationLowercase) {
    Registration* reg = factory->createRegistration(
        "standard", name, affiliation, email, testDate, "");

    ASSERT_NE(reg, nullptr);
    EXPECT_EQ(reg->getAttendee().getName(), name);
    EXPECT_EQ(reg->getAttendee().getAffiliation(), affiliation);
    EXPECT_EQ(reg->getAttendee().getEmail(), email);
    EXPECT_EQ(reg->getBookingDate(), testDate);
    EXPECT_DOUBLE_EQ(reg->calculateFee(), 100.0);

    // Verify it's actually a StandardRegistration
    StandardRegistration* stdReg = dynamic_cast<StandardRegistration*>(reg);
    ASSERT_NE(stdReg, nullptr);

    delete reg;
}

/**
 * @brief Test creating StandardRegistration with uppercase type
 */
TEST_F(RegistrationFactoryTest, CreateStandardRegistrationUppercase) {
    Registration* reg = factory->createRegistration(
        "STANDARD", name, affiliation, email, testDate, "");

    ASSERT_NE(reg, nullptr);
    EXPECT_DOUBLE_EQ(reg->calculateFee(), 100.0);

    delete reg;
}

/**
 * @brief Test creating StandardRegistration with mixed case
 */
TEST_F(RegistrationFactoryTest, CreateStandardRegistrationMixedCase) {
    Registration* reg = factory->createRegistration(
        "StAnDaRd", name, affiliation, email, testDate, "");

    ASSERT_NE(reg, nullptr);
    EXPECT_DOUBLE_EQ(reg->calculateFee(), 100.0);

    delete reg;
}

// ============================================================================
// StudentRegistration Creation Tests
// ============================================================================

/**
 * @brief Test creating StudentRegistration with qualification
 */
TEST_F(RegistrationFactoryTest, CreateStudentRegistrationWithQualification) {
    QString qualification = "Bachelor's Degree";
    Registration* reg = factory->createRegistration(
        "student", name, affiliation, email, testDate, qualification);

    ASSERT_NE(reg, nullptr);
    EXPECT_EQ(reg->getAttendee().getName(), name);
    EXPECT_DOUBLE_EQ(reg->calculateFee(), 50.0);

    // Verify it's actually a StudentRegistration and has qualification
    StudentRegistration* studentReg = dynamic_cast<StudentRegistration*>(reg);
    ASSERT_NE(studentReg, nullptr);
    EXPECT_EQ(studentReg->getQualification(), qualification);

    delete reg;
}

/**
 * @brief Test creating StudentRegistration without qualification
 */
TEST_F(RegistrationFactoryTest, CreateStudentRegistrationWithoutQualification) {
    Registration* reg = factory->createRegistration(
        "student", name, affiliation, email, testDate, "");

    ASSERT_NE(reg, nullptr);
    EXPECT_DOUBLE_EQ(reg->calculateFee(), 50.0);

    StudentRegistration* studentReg = dynamic_cast<StudentRegistration*>(reg);
    ASSERT_NE(studentReg, nullptr);
    EXPECT_EQ(studentReg->getQualification(), "");

    delete reg;
}

/**
 * @brief Test creating StudentRegistration with case variations
 */
TEST_F(RegistrationFactoryTest, CreateStudentRegistrationCaseInsensitive) {
    Registration* reg1 = factory->createRegistration(
        "STUDENT", name, affiliation, email, testDate, "MSc");
    Registration* reg2 = factory->createRegistration(
        "StUdEnT", name, affiliation, email, testDate, "PhD");

    ASSERT_NE(reg1, nullptr);
    ASSERT_NE(reg2, nullptr);
    EXPECT_DOUBLE_EQ(reg1->calculateFee(), 50.0);
    EXPECT_DOUBLE_EQ(reg2->calculateFee(), 50.0);

    delete reg1;
    delete reg2;
}

// ============================================================================
// GuestRegistration Creation Tests
// ============================================================================

/**
 * @brief Test creating GuestRegistration with category
 */
TEST_F(RegistrationFactoryTest, CreateGuestRegistrationWithCategory) {
    QString category = "Speaker";
    Registration* reg = factory->createRegistration(
        "guest", name, affiliation, email, testDate, category);

    ASSERT_NE(reg, nullptr);
    EXPECT_EQ(reg->getAttendee().getName(), name);
    EXPECT_DOUBLE_EQ(reg->calculateFee(), 10.0);

    // Verify it's actually a GuestRegistration and has category
    GuestRegistration* guestReg = dynamic_cast<GuestRegistration*>(reg);
    ASSERT_NE(guestReg, nullptr);
    EXPECT_EQ(guestReg->getCategory(), category);

    delete reg;
}

/**
 * @brief Test creating GuestRegistration without category
 */
TEST_F(RegistrationFactoryTest, CreateGuestRegistrationWithoutCategory) {
    Registration* reg = factory->createRegistration(
        "guest", name, affiliation, email, testDate, "");

    ASSERT_NE(reg, nullptr);
    EXPECT_DOUBLE_EQ(reg->calculateFee(), 10.0);

    GuestRegistration* guestReg = dynamic_cast<GuestRegistration*>(reg);
    ASSERT_NE(guestReg, nullptr);
    EXPECT_EQ(guestReg->getCategory(), "");

    delete reg;
}

/**
 * @brief Test creating GuestRegistration with case variations
 */
TEST_F(RegistrationFactoryTest, CreateGuestRegistrationCaseInsensitive) {
    Registration* reg1 = factory->createRegistration(
        "GUEST", name, affiliation, email, testDate, "VIP");
    Registration* reg2 = factory->createRegistration(
        "GuEsT", name, affiliation, email, testDate, "Keynote");

    ASSERT_NE(reg1, nullptr);
    ASSERT_NE(reg2, nullptr);
    EXPECT_DOUBLE_EQ(reg1->calculateFee(), 10.0);
    EXPECT_DOUBLE_EQ(reg2->calculateFee(), 10.0);

    delete reg1;
    delete reg2;
}

// ============================================================================
// Invalid Type Tests
// ============================================================================

/**
 * @brief Test creating registration with invalid type returns nullptr
 */
TEST_F(RegistrationFactoryTest, CreateWithInvalidTypeReturnsNull) {
    Registration* reg = factory->createRegistration(
        "invalid", name, affiliation, email, testDate, "");

    EXPECT_EQ(reg, nullptr);
}

/**
 * @brief Test creating registration with empty type returns nullptr
 */
TEST_F(RegistrationFactoryTest, CreateWithEmptyTypeReturnsNull) {
    Registration* reg = factory->createRegistration(
        "", name, affiliation, email, testDate, "");

    EXPECT_EQ(reg, nullptr);
}

/**
 * @brief Test creating registration with gibberish type returns nullptr
 */
TEST_F(RegistrationFactoryTest, CreateWithGibberishTypeReturnsNull) {
    Registration* reg1 = factory->createRegistration(
        "xyz123", name, affiliation, email, testDate, "");
    Registration* reg2 = factory->createRegistration(
        "standard123", name, affiliation, email, testDate, "");
    Registration* reg3 = factory->createRegistration(
        "studen", name, affiliation, email, testDate, "");

    EXPECT_EQ(reg1, nullptr);
    EXPECT_EQ(reg2, nullptr);
    EXPECT_EQ(reg3, nullptr);
}

// ============================================================================
// Edge Cases and Boundary Tests
// ============================================================================

/**
 * @brief Test creating registration with empty person details
 */
TEST_F(RegistrationFactoryTest, CreateWithEmptyPersonDetails) {
    Registration* reg = factory->createRegistration(
        "standard", "", "", "", testDate, "");

    ASSERT_NE(reg, nullptr);
    EXPECT_EQ(reg->getAttendee().getName(), "");
    EXPECT_EQ(reg->getAttendee().getAffiliation(), "");
    EXPECT_EQ(reg->getAttendee().getEmail(), "");
    EXPECT_DOUBLE_EQ(reg->calculateFee(), 100.0);

    delete reg;
}

/**
 * @brief Test creating registration with special characters in names
 */
TEST_F(RegistrationFactoryTest, CreateWithSpecialCharacters) {
    QString specialName = "José María O'Connor";
    QString specialAffiliation = "Université de Montréal";
    QString specialEmail = "jose.maria@université.ca";

    Registration* reg = factory->createRegistration(
        "standard", specialName, specialAffiliation, specialEmail, testDate, "");

    ASSERT_NE(reg, nullptr);
    EXPECT_EQ(reg->getAttendee().getName(), specialName);
    EXPECT_EQ(reg->getAttendee().getAffiliation(), specialAffiliation);
    EXPECT_EQ(reg->getAttendee().getEmail(), specialEmail);

    delete reg;
}

/**
 * @brief Test creating registration with invalid date
 */
TEST_F(RegistrationFactoryTest, CreateWithInvalidDate) {
    QDate invalidDate;  // Invalid date

    Registration* reg = factory->createRegistration(
        "standard", name, affiliation, email, invalidDate, "");

    ASSERT_NE(reg, nullptr);
    EXPECT_FALSE(reg->getBookingDate().isValid());

    delete reg;
}

/**
 * @brief Test creating registration with very long strings
 */
TEST_F(RegistrationFactoryTest, CreateWithLongStrings) {
    QString longName = QString("A").repeated(1000);
    QString longAffiliation = QString("B").repeated(1000);
    QString longEmail = QString("C").repeated(1000);
    QString longInfo = QString("D").repeated(1000);

    Registration* reg = factory->createRegistration(
        "student", longName, longAffiliation, longEmail, testDate, longInfo);

    ASSERT_NE(reg, nullptr);
    EXPECT_EQ(reg->getAttendee().getName(), longName);
    EXPECT_EQ(reg->getAttendee().getAffiliation(), longAffiliation);
    EXPECT_EQ(reg->getAttendee().getEmail(), longEmail);

    StudentRegistration* studentReg = dynamic_cast<StudentRegistration*>(reg);
    ASSERT_NE(studentReg, nullptr);
    EXPECT_EQ(studentReg->getQualification(), longInfo);

    delete reg;
}

// ============================================================================
// Multiple Creation Tests
// ============================================================================

/**
 * @brief Test creating multiple registrations of different types
 */
TEST_F(RegistrationFactoryTest, CreateMultipleRegistrationTypes) {
    Registration* reg1 = factory->createRegistration(
        "standard", "Alice", "MIT", "alice@mit.edu", testDate, "");
    Registration* reg2 = factory->createRegistration(
        "student", "Bob", "Harvard", "bob@harvard.edu", testDate, "BSc");
    Registration* reg3 = factory->createRegistration(
        "guest", "Charlie", "Yale", "charlie@yale.edu", testDate, "Speaker");

    ASSERT_NE(reg1, nullptr);
    ASSERT_NE(reg2, nullptr);
    ASSERT_NE(reg3, nullptr);

    EXPECT_DOUBLE_EQ(reg1->calculateFee(), 100.0);
    EXPECT_DOUBLE_EQ(reg2->calculateFee(), 50.0);
    EXPECT_DOUBLE_EQ(reg3->calculateFee(), 10.0);

    delete reg1;
    delete reg2;
    delete reg3;
}

/**
 * @brief Test creating same registration type multiple times
 */
TEST_F(RegistrationFactoryTest, CreateSameTypeMultipleTimes) {
    std::vector<Registration*> registrations;

    for (int i = 0; i < 10; ++i) {
        Registration* reg = factory->createRegistration(
            "standard", name, affiliation, email, testDate, "");
        ASSERT_NE(reg, nullptr);
        registrations.push_back(reg);
    }

    // All should be valid and have same fee
    for (Registration* reg : registrations) {
        EXPECT_DOUBLE_EQ(reg->calculateFee(), 100.0);
        delete reg;
    }
}
