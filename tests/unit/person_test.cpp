/**
 * @file person_test.cpp
 * @brief Unit tests for the Person class
 */

#include "person.h"
#include <gtest/gtest.h>
#include <QString>

/**
 * @brief Test fixture for Person class tests
 */
class PersonTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }

    void TearDown() override {
        // Cleanup code if needed
    }
};

/**
 * @brief Test Person construction with valid inputs
 */
TEST_F(PersonTest, ConstructorInitializesFieldsCorrectly) {
    QString name = "John Doe";
    QString affiliation = "MIT";
    QString email = "john.doe@mit.edu";

    Person person(name, affiliation, email);

    EXPECT_EQ(person.getName(), name);
    EXPECT_EQ(person.getAffiliation(), affiliation);
    EXPECT_EQ(person.getEmail(), email);
}

/**
 * @brief Test Person with empty strings
 */
TEST_F(PersonTest, HandlesEmptyStrings) {
    Person person("", "", "");

    EXPECT_EQ(person.getName(), "");
    EXPECT_EQ(person.getAffiliation(), "");
    EXPECT_EQ(person.getEmail(), "");
}

/**
 * @brief Test Person with special characters
 */
TEST_F(PersonTest, HandlesSpecialCharacters) {
    QString name = "José María";
    QString affiliation = "Université de Paris";
    QString email = "jose.maria@university.fr";

    Person person(name, affiliation, email);

    EXPECT_EQ(person.getName(), name);
    EXPECT_EQ(person.getAffiliation(), affiliation);
    EXPECT_EQ(person.getEmail(), email);
}

/**
 * @brief Test Person toString method
 */
TEST_F(PersonTest, ToStringFormatsCorrectly) {
    Person person("Alice Smith", "Stanford", "alice@stanford.edu");

    QString result = person.toString();

    EXPECT_TRUE(result.contains("Alice Smith"));
    EXPECT_TRUE(result.contains("Stanford"));
    EXPECT_TRUE(result.contains("alice@stanford.edu"));
}

/**
 * @brief Test Person with very long strings
 */
TEST_F(PersonTest, HandlesLongStrings) {
    QString longName = QString("A").repeated(500);
    QString longAffiliation = QString("B").repeated(500);
    QString longEmail = QString("C").repeated(500);

    Person person(longName, longAffiliation, longEmail);

    EXPECT_EQ(person.getName(), longName);
    EXPECT_EQ(person.getAffiliation(), longAffiliation);
    EXPECT_EQ(person.getEmail(), longEmail);
}

/**
 * @brief Test Person with whitespace strings
 */
TEST_F(PersonTest, HandlesWhitespaceStrings) {
    QString whitespace = "   ";
    Person person(whitespace, whitespace, whitespace);

    EXPECT_EQ(person.getName(), whitespace);
    EXPECT_EQ(person.getAffiliation(), whitespace);
    EXPECT_EQ(person.getEmail(), whitespace);
}
