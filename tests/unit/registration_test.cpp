/**
 * @file registration_test.cpp
 * @brief Unit tests for Registration subclasses
 */

#include "person.h"
#include "registration.h"
#include "standardregistration.h"
#include "studentregistration.h"
#include "guestregistration.h"
#include <gtest/gtest.h>
#include <QDate>
#include <QString>

/**
 * @brief Test fixture for Registration class tests
 */
class RegistrationTest : public ::testing::Test {
protected:
    void SetUp() override {
        testDate = QDate(2024, 7, 15);
        testPerson = new Person("John Doe", "MIT", "john@mit.edu");
    }

    void TearDown() override {
        delete testPerson;
    }

    QDate testDate;
    Person* testPerson;
};

// ============================================================================
// StandardRegistration Tests
// ============================================================================

/**
 * @brief Test StandardRegistration construction
 */
TEST_F(RegistrationTest, StandardRegistrationConstruction) {
    StandardRegistration reg(*testPerson, testDate);

    EXPECT_EQ(reg.getAttendee().getName(), "John Doe");
    EXPECT_EQ(reg.getAttendee().getAffiliation(), "MIT");
    EXPECT_EQ(reg.getAttendee().getEmail(), "john@mit.edu");
    EXPECT_EQ(reg.getBookingDate(), testDate);
}

/**
 * @brief Test StandardRegistration fee calculation
 */
TEST_F(RegistrationTest, StandardRegistrationFeeCalculation) {
    StandardRegistration reg(*testPerson, testDate);

    double fee = reg.calculateFee();

    EXPECT_DOUBLE_EQ(fee, 100.0);
    EXPECT_DOUBLE_EQ(fee, Registration::STANDARD_FEE);
}

/**
 * @brief Test StandardRegistration toString
 */
TEST_F(RegistrationTest, StandardRegistrationToString) {
    StandardRegistration reg(*testPerson, testDate);

    QString result = reg.toString();

    EXPECT_TRUE(result.contains("John Doe"));
    EXPECT_TRUE(result.contains("MIT"));
    EXPECT_TRUE(result.contains("john@mit.edu"));
    EXPECT_TRUE(result.contains("100"));
}

/**
 * @brief Test StandardRegistration with current date default
 */
TEST_F(RegistrationTest, StandardRegistrationDefaultDate) {
    StandardRegistration reg(*testPerson);

    // Should use QDate::currentDate() as default
    EXPECT_TRUE(reg.getBookingDate().isValid());
}

// ============================================================================
// StudentRegistration Tests
// ============================================================================

/**
 * @brief Test StudentRegistration construction with qualification
 */
TEST_F(RegistrationTest, StudentRegistrationConstruction) {
    StudentRegistration reg(*testPerson, testDate, "Bachelor's Degree");

    EXPECT_EQ(reg.getAttendee().getName(), "John Doe");
    EXPECT_EQ(reg.getQualification(), "Bachelor's Degree");
}

/**
 * @brief Test StudentRegistration fee calculation (50% discount)
 */
TEST_F(RegistrationTest, StudentRegistrationFeeCalculation) {
    StudentRegistration reg(*testPerson, testDate, "Master's Degree");

    double fee = reg.calculateFee();

    EXPECT_DOUBLE_EQ(fee, 50.0);
    EXPECT_DOUBLE_EQ(fee, Registration::STANDARD_FEE * 0.5);
}

/**
 * @brief Test StudentRegistration with empty qualification
 */
TEST_F(RegistrationTest, StudentRegistrationEmptyQualification) {
    StudentRegistration reg(*testPerson, testDate, "");

    EXPECT_EQ(reg.getQualification(), "");
    EXPECT_DOUBLE_EQ(reg.calculateFee(), 50.0);
}

/**
 * @brief Test StudentRegistration toString includes qualification
 */
TEST_F(RegistrationTest, StudentRegistrationToString) {
    StudentRegistration reg(*testPerson, testDate, "PhD");

    QString result = reg.toString();

    EXPECT_TRUE(result.contains("John Doe"));
    EXPECT_TRUE(result.contains("PhD"));
    EXPECT_TRUE(result.contains("50"));
}

// ============================================================================
// GuestRegistration Tests
// ============================================================================

/**
 * @brief Test GuestRegistration construction with category
 */
TEST_F(RegistrationTest, GuestRegistrationConstruction) {
    GuestRegistration reg(*testPerson, testDate, "Speaker");

    EXPECT_EQ(reg.getAttendee().getName(), "John Doe");
    EXPECT_EQ(reg.getCategory(), "Speaker");
}

/**
 * @brief Test GuestRegistration fee calculation (10% of standard)
 */
TEST_F(RegistrationTest, GuestRegistrationFeeCalculation) {
    GuestRegistration reg(*testPerson, testDate, "VIP");

    double fee = reg.calculateFee();

    EXPECT_DOUBLE_EQ(fee, 10.0);
    EXPECT_DOUBLE_EQ(fee, Registration::STANDARD_FEE * 0.1);
}

/**
 * @brief Test GuestRegistration with empty category
 */
TEST_F(RegistrationTest, GuestRegistrationEmptyCategory) {
    GuestRegistration reg(*testPerson, testDate, "");

    EXPECT_EQ(reg.getCategory(), "");
    EXPECT_DOUBLE_EQ(reg.calculateFee(), 10.0);
}

/**
 * @brief Test GuestRegistration toString includes category
 */
TEST_F(RegistrationTest, GuestRegistrationToString) {
    GuestRegistration reg(*testPerson, testDate, "Keynote");

    QString result = reg.toString();

    EXPECT_TRUE(result.contains("John Doe"));
    EXPECT_TRUE(result.contains("Keynote"));
    EXPECT_TRUE(result.contains("10"));
}

// ============================================================================
// Booking Date Tests
// ============================================================================

/**
 * @brief Test setting booking date on registration
 */
TEST_F(RegistrationTest, SetBookingDate) {
    StandardRegistration reg(*testPerson, testDate);
    QDate newDate(2024, 8, 20);

    reg.setBookingDate(newDate);

    EXPECT_EQ(reg.getBookingDate(), newDate);
}

/**
 * @brief Test registration with invalid date
 */
TEST_F(RegistrationTest, RegistrationWithInvalidDate) {
    QDate invalidDate; // Default constructor creates invalid date
    StandardRegistration reg(*testPerson, invalidDate);

    EXPECT_FALSE(reg.getBookingDate().isValid());
}

/**
 * @brief Test registration with boundary dates
 */
TEST_F(RegistrationTest, RegistrationWithBoundaryDates) {
    // Test with very old date
    QDate oldDate(1900, 1, 1);
    StandardRegistration reg1(*testPerson, oldDate);
    EXPECT_EQ(reg1.getBookingDate(), oldDate);

    // Test with future date
    QDate futureDate(2100, 12, 31);
    StandardRegistration reg2(*testPerson, futureDate);
    EXPECT_EQ(reg2.getBookingDate(), futureDate);
}

// ============================================================================
// Fee Calculation Consistency Tests
// ============================================================================

/**
 * @brief Verify fee ratios between registration types
 */
TEST_F(RegistrationTest, FeeCalculationRatios) {
    StandardRegistration standard(*testPerson, testDate);
    StudentRegistration student(*testPerson, testDate, "BSc");
    GuestRegistration guest(*testPerson, testDate, "Guest");

    double standardFee = standard.calculateFee();
    double studentFee = student.calculateFee();
    double guestFee = guest.calculateFee();

    // Student fee should be 50% of standard
    EXPECT_DOUBLE_EQ(studentFee, standardFee * 0.5);
    
    // Guest fee should be 10% of standard
    EXPECT_DOUBLE_EQ(guestFee, standardFee * 0.1);
    
    // Student fee should be 5x guest fee
    EXPECT_DOUBLE_EQ(studentFee, guestFee * 5.0);
}

/**
 * @brief Test that fees are always positive
 */
TEST_F(RegistrationTest, FeesArePositive) {
    StandardRegistration standard(*testPerson, testDate);
    StudentRegistration student(*testPerson, testDate, "MSc");
    GuestRegistration guest(*testPerson, testDate, "VIP");

    EXPECT_GT(standard.calculateFee(), 0.0);
    EXPECT_GT(student.calculateFee(), 0.0);
    EXPECT_GT(guest.calculateFee(), 0.0);
}
