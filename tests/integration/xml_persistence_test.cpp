/**
 * @file xml_persistence_test.cpp
 * @brief Integration tests for XML persistence functionality
 * @details Tests round-trip integrity, golden file fixtures, and error handling
 */

#include "registrationlistwriter.h"
#include "registrationlistreader.h"
#include "registrationfactory.h"
#include "registration.h"
#include "standardregistration.h"
#include "studentregistration.h"
#include "guestregistration.h"
#include "person.h"

#include <gtest/gtest.h>
#include <QFile>
#include <QDir>
#include <QTemporaryDir>
#include <QString>
#include <QList>
#include <QDate>
#include <cmath>

/**
 * @brief Test fixture for XML persistence integration tests
 * @details Provides temporary directory for test isolation and helper methods
 */
class XmlPersistenceTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create temporary directory for test isolation
        tempDir = new QTemporaryDir();
        ASSERT_TRUE(tempDir->isValid()) << "Failed to create temporary directory";
        
        // Get factory instance
        factory = &RegistrationFactory::getInstance();
        
        // Define fixtures path relative to test binary location
        fixturesPath = QString(FIXTURES_PATH);
    }
    
    void TearDown() override {
        delete tempDir;
    }
    
    /**
     * @brief Helper method to create a temporary file path
     */
    QString getTempFilePath(const QString& fileName) const {
        return tempDir->filePath(fileName);
    }
    
    /**
     * @brief Helper method to get fixture file path
     */
    QString getFixturePath(const QString& fileName) const {
        return fixturesPath + "/" + fileName;
    }
    
    /**
     * @brief Helper to verify registration equality
     */
    bool compareRegistrations(const Registration* reg1, const Registration* reg2) const {
        if (reg1 == nullptr || reg2 == nullptr) {
            return reg1 == reg2;
        }
        
        // Compare common properties
        if (reg1->getAttendee().getName() != reg2->getAttendee().getName()) return false;
        if (reg1->getAttendee().getAffiliation() != reg2->getAttendee().getAffiliation()) return false;
        if (reg1->getAttendee().getEmail() != reg2->getAttendee().getEmail()) return false;
        if (reg1->getBookingDate() != reg2->getBookingDate()) return false;
        
        // Compare type-specific properties
        const StandardRegistration* std1 = qobject_cast<const StandardRegistration*>(reg1);
        const StandardRegistration* std2 = qobject_cast<const StandardRegistration*>(reg2);
        if (std1 && std2) {
            return std::abs(reg1->calculateFee() - reg2->calculateFee()) < 0.01;
        }
        
        const StudentRegistration* stu1 = qobject_cast<const StudentRegistration*>(reg1);
        const StudentRegistration* stu2 = qobject_cast<const StudentRegistration*>(reg2);
        if (stu1 && stu2) {
            return stu1->getQualification() == stu2->getQualification() &&
                   std::abs(reg1->calculateFee() - reg2->calculateFee()) < 0.01;
        }
        
        const GuestRegistration* gst1 = qobject_cast<const GuestRegistration*>(reg1);
        const GuestRegistration* gst2 = qobject_cast<const GuestRegistration*>(reg2);
        if (gst1 && gst2) {
            return gst1->getCategory() == gst2->getCategory() &&
                   std::abs(reg1->calculateFee() - reg2->calculateFee()) < 0.01;
        }
        
        return false;
    }
    
    /**
     * @brief Helper to clean up registration list
     */
    void cleanupRegistrations(QList<Registration*>& registrations) {
        for (Registration* reg : registrations) {
            delete reg;
        }
        registrations.clear();
    }

protected:
    QTemporaryDir* tempDir;
    RegistrationFactory* factory;
    QString fixturesPath;
};

// ============================================================================
// Round-trip Integrity Tests
// ============================================================================

/**
 * @brief Test round-trip for single standard registration
 */
TEST_F(XmlPersistenceTest, RoundTripStandardRegistration) {
    // Create registration
    QList<Registration*> originalList;
    Registration* reg = factory->createRegistration(
        "standard", "John Doe", "MIT", "john@mit.edu", 
        QDate(2024, 7, 15), "");
    ASSERT_NE(reg, nullptr);
    originalList.append(reg);
    
    // Write to file
    QString filePath = getTempFilePath("test_standard.xml");
    RegistrationListWriter writer(filePath);
    ASSERT_TRUE(writer.write(originalList)) << "Failed to write XML file";
    
    // Verify file exists
    ASSERT_TRUE(QFile::exists(filePath)) << "XML file was not created";
    
    // Read from file
    RegistrationListReader reader(filePath);
    QList<Registration*> loadedList = reader.read();
    
    // Verify
    ASSERT_EQ(loadedList.size(), 1);
    EXPECT_TRUE(compareRegistrations(originalList[0], loadedList[0]));
    
    // Cleanup
    cleanupRegistrations(originalList);
    cleanupRegistrations(loadedList);
}

/**
 * @brief Test round-trip for single student registration
 */
TEST_F(XmlPersistenceTest, RoundTripStudentRegistration) {
    // Create registration
    QList<Registration*> originalList;
    Registration* reg = factory->createRegistration(
        "student", "Jane Smith", "Stanford", "jane@stanford.edu",
        QDate(2024, 7, 20), "PhD Candidate");
    ASSERT_NE(reg, nullptr);
    originalList.append(reg);
    
    // Write to file
    QString filePath = getTempFilePath("test_student.xml");
    RegistrationListWriter writer(filePath);
    ASSERT_TRUE(writer.write(originalList));
    
    // Read from file
    RegistrationListReader reader(filePath);
    QList<Registration*> loadedList = reader.read();
    
    // Verify
    ASSERT_EQ(loadedList.size(), 1);
    EXPECT_TRUE(compareRegistrations(originalList[0], loadedList[0]));
    
    // Cleanup
    cleanupRegistrations(originalList);
    cleanupRegistrations(loadedList);
}

/**
 * @brief Test round-trip for single guest registration
 */
TEST_F(XmlPersistenceTest, RoundTripGuestRegistration) {
    // Create registration
    QList<Registration*> originalList;
    Registration* reg = factory->createRegistration(
        "guest", "Bob Wilson", "Google", "bob@google.com",
        QDate(2024, 8, 1), "Keynote Speaker");
    ASSERT_NE(reg, nullptr);
    originalList.append(reg);
    
    // Write to file
    QString filePath = getTempFilePath("test_guest.xml");
    RegistrationListWriter writer(filePath);
    ASSERT_TRUE(writer.write(originalList));
    
    // Read from file
    RegistrationListReader reader(filePath);
    QList<Registration*> loadedList = reader.read();
    
    // Verify
    ASSERT_EQ(loadedList.size(), 1);
    EXPECT_TRUE(compareRegistrations(originalList[0], loadedList[0]));
    
    // Cleanup
    cleanupRegistrations(originalList);
    cleanupRegistrations(loadedList);
}

/**
 * @brief Test round-trip for multiple registrations of different types
 */
TEST_F(XmlPersistenceTest, RoundTripMultipleRegistrations) {
    // Create multiple registrations
    QList<Registration*> originalList;
    originalList.append(factory->createRegistration(
        "standard", "Alice Brown", "Harvard", "alice@harvard.edu",
        QDate(2024, 7, 10), ""));
    originalList.append(factory->createRegistration(
        "student", "Charlie Davis", "Yale", "charlie@yale.edu",
        QDate(2024, 7, 12), "Masters Student"));
    originalList.append(factory->createRegistration(
        "guest", "Diana Prince", "Amazon", "diana@amazon.com",
        QDate(2024, 7, 14), "VIP Guest"));
    
    // Verify all were created
    for (Registration* reg : originalList) {
        ASSERT_NE(reg, nullptr);
    }
    
    // Write to file
    QString filePath = getTempFilePath("test_multiple.xml");
    RegistrationListWriter writer(filePath);
    ASSERT_TRUE(writer.write(originalList));
    
    // Read from file
    RegistrationListReader reader(filePath);
    QList<Registration*> loadedList = reader.read();
    
    // Verify count and contents
    ASSERT_EQ(loadedList.size(), originalList.size());
    for (int i = 0; i < originalList.size(); ++i) {
        EXPECT_TRUE(compareRegistrations(originalList[i], loadedList[i])) 
            << "Registration at index " << i << " does not match";
    }
    
    // Cleanup
    cleanupRegistrations(originalList);
    cleanupRegistrations(loadedList);
}

/**
 * @brief Test round-trip with empty list
 */
TEST_F(XmlPersistenceTest, RoundTripEmptyList) {
    QList<Registration*> originalList;  // Empty list
    
    // Write to file
    QString filePath = getTempFilePath("test_empty.xml");
    RegistrationListWriter writer(filePath);
    ASSERT_TRUE(writer.write(originalList));
    
    // Read from file
    RegistrationListReader reader(filePath);
    QList<Registration*> loadedList = reader.read();
    
    // Verify empty
    EXPECT_EQ(loadedList.size(), 0);
}

// ============================================================================
// Golden File Fixture Tests
// ============================================================================

/**
 * @brief Test loading valid standard registration fixture
 */
TEST_F(XmlPersistenceTest, LoadValidStandardFixture) {
    QString fixturePath = getFixturePath("valid_standard.xml");
    ASSERT_TRUE(QFile::exists(fixturePath)) << "Fixture file does not exist: " << fixturePath.toStdString();
    
    RegistrationListReader reader(fixturePath);
    QList<Registration*> registrations = reader.read();
    
    ASSERT_EQ(registrations.size(), 1);
    EXPECT_EQ(registrations[0]->getAttendee().getName(), "John Smith");
    EXPECT_EQ(registrations[0]->getAttendee().getAffiliation(), "MIT");
    EXPECT_EQ(registrations[0]->getAttendee().getEmail(), "john.smith@mit.edu");
    EXPECT_EQ(registrations[0]->getBookingDate(), QDate(2024, 7, 15));
    
    StandardRegistration* stdReg = qobject_cast<StandardRegistration*>(registrations[0]);
    ASSERT_NE(stdReg, nullptr);
    EXPECT_DOUBLE_EQ(stdReg->calculateFee(), 100.0);
    
    cleanupRegistrations(registrations);
}

/**
 * @brief Test loading valid student registration fixture
 */
TEST_F(XmlPersistenceTest, LoadValidStudentFixture) {
    QString fixturePath = getFixturePath("valid_student.xml");
    ASSERT_TRUE(QFile::exists(fixturePath)) << "Fixture file does not exist";
    
    RegistrationListReader reader(fixturePath);
    QList<Registration*> registrations = reader.read();
    
    ASSERT_EQ(registrations.size(), 1);
    EXPECT_EQ(registrations[0]->getAttendee().getName(), "Jane Doe");
    EXPECT_EQ(registrations[0]->getAttendee().getAffiliation(), "Stanford");
    EXPECT_EQ(registrations[0]->getAttendee().getEmail(), "jane.doe@stanford.edu");
    
    StudentRegistration* stuReg = qobject_cast<StudentRegistration*>(registrations[0]);
    ASSERT_NE(stuReg, nullptr);
    EXPECT_EQ(stuReg->getQualification(), "PhD Candidate");
    EXPECT_DOUBLE_EQ(stuReg->calculateFee(), 50.0);
    
    cleanupRegistrations(registrations);
}

/**
 * @brief Test loading valid guest registration fixture
 */
TEST_F(XmlPersistenceTest, LoadValidGuestFixture) {
    QString fixturePath = getFixturePath("valid_guest.xml");
    ASSERT_TRUE(QFile::exists(fixturePath)) << "Fixture file does not exist";
    
    RegistrationListReader reader(fixturePath);
    QList<Registration*> registrations = reader.read();
    
    ASSERT_EQ(registrations.size(), 1);
    EXPECT_EQ(registrations[0]->getAttendee().getName(), "Bob Johnson");
    EXPECT_EQ(registrations[0]->getAttendee().getAffiliation(), "Google");
    
    GuestRegistration* gstReg = qobject_cast<GuestRegistration*>(registrations[0]);
    ASSERT_NE(gstReg, nullptr);
    EXPECT_EQ(gstReg->getCategory(), "Keynote Speaker");
    EXPECT_DOUBLE_EQ(gstReg->calculateFee(), 10.0);
    
    cleanupRegistrations(registrations);
}

/**
 * @brief Test loading multiple registrations from fixture
 */
TEST_F(XmlPersistenceTest, LoadValidMultipleFixture) {
    QString fixturePath = getFixturePath("valid_multiple.xml");
    ASSERT_TRUE(QFile::exists(fixturePath)) << "Fixture file does not exist";
    
    RegistrationListReader reader(fixturePath);
    QList<Registration*> registrations = reader.read();
    
    ASSERT_EQ(registrations.size(), 3);
    
    // Verify first registration (standard)
    EXPECT_EQ(registrations[0]->getAttendee().getName(), "Alice Brown");
    StandardRegistration* stdReg = qobject_cast<StandardRegistration*>(registrations[0]);
    ASSERT_NE(stdReg, nullptr);
    
    // Verify second registration (student)
    EXPECT_EQ(registrations[1]->getAttendee().getName(), "Charlie Wilson");
    StudentRegistration* stuReg = qobject_cast<StudentRegistration*>(registrations[1]);
    ASSERT_NE(stuReg, nullptr);
    EXPECT_EQ(stuReg->getQualification(), "Masters Student");
    
    // Verify third registration (guest)
    EXPECT_EQ(registrations[2]->getAttendee().getName(), "Diana Prince");
    GuestRegistration* gstReg = qobject_cast<GuestRegistration*>(registrations[2]);
    ASSERT_NE(gstReg, nullptr);
    EXPECT_EQ(gstReg->getCategory(), "VIP Guest");
    
    cleanupRegistrations(registrations);
}

// ============================================================================
// Error and Edge Case Tests
// ============================================================================

/**
 * @brief Test handling of malformed XML
 */
TEST_F(XmlPersistenceTest, HandleMalformedXml) {
    QString fixturePath = getFixturePath("malformed.xml");
    ASSERT_TRUE(QFile::exists(fixturePath)) << "Fixture file does not exist";
    
    RegistrationListReader reader(fixturePath);
    QList<Registration*> registrations = reader.read();
    
    // Should return empty list for malformed XML
    EXPECT_EQ(registrations.size(), 0);
}

/**
 * @brief Test handling of missing required name field
 */
TEST_F(XmlPersistenceTest, HandleMissingNameField) {
    QString fixturePath = getFixturePath("missing_name.xml");
    ASSERT_TRUE(QFile::exists(fixturePath)) << "Fixture file does not exist";
    
    RegistrationListReader reader(fixturePath);
    QList<Registration*> registrations = reader.read();
    
    // Current implementation allows empty names
    // Registration is created with empty name field
    ASSERT_EQ(registrations.size(), 1);
    EXPECT_EQ(registrations[0]->getAttendee().getName(), "");
    EXPECT_EQ(registrations[0]->getAttendee().getAffiliation(), "University");
    
    cleanupRegistrations(registrations);
}

/**
 * @brief Test handling of missing type attribute
 */
TEST_F(XmlPersistenceTest, HandleMissingTypeAttribute) {
    QString fixturePath = getFixturePath("missing_type.xml");
    ASSERT_TRUE(QFile::exists(fixturePath)) << "Fixture file does not exist";
    
    RegistrationListReader reader(fixturePath);
    QList<Registration*> registrations = reader.read();
    
    // Should skip registration with missing or invalid type
    EXPECT_EQ(registrations.size(), 0);
}

/**
 * @brief Test handling of empty XML file
 */
TEST_F(XmlPersistenceTest, HandleEmptyXmlFile) {
    QString fixturePath = getFixturePath("empty.xml");
    ASSERT_TRUE(QFile::exists(fixturePath)) << "Fixture file does not exist";
    
    RegistrationListReader reader(fixturePath);
    QList<Registration*> registrations = reader.read();
    
    // Should return empty list
    EXPECT_EQ(registrations.size(), 0);
}

/**
 * @brief Test handling of non-existent file
 */
TEST_F(XmlPersistenceTest, HandleNonExistentFile) {
    QString nonExistentPath = getTempFilePath("does_not_exist.xml");
    
    RegistrationListReader reader(nonExistentPath);
    QList<Registration*> registrations = reader.read();
    
    // Should return empty list for non-existent file
    EXPECT_EQ(registrations.size(), 0);
}

/**
 * @brief Test writing to read-only location fails gracefully
 */
TEST_F(XmlPersistenceTest, HandleReadOnlyLocation) {
    // Create a file and make it read-only
    QString filePath = getTempFilePath("readonly.xml");
    QFile file(filePath);
    ASSERT_TRUE(file.open(QIODevice::WriteOnly));
    file.close();
    ASSERT_TRUE(file.setPermissions(QFileDevice::ReadOwner));
    
    // Try to write - should fail gracefully
    QList<Registration*> registrations;
    registrations.append(factory->createRegistration(
        "standard", "Test Person", "Test Uni", "test@test.com",
        QDate(2024, 7, 15), ""));
    
    RegistrationListWriter writer(filePath);
    bool result = writer.write(registrations);
    
    // Writing should fail
    EXPECT_FALSE(result);
    
    cleanupRegistrations(registrations);
}

/**
 * @brief Test deterministic output (same input produces same XML)
 */
TEST_F(XmlPersistenceTest, DeterministicOutput) {
    // Create registration
    QList<Registration*> registrations;
    registrations.append(factory->createRegistration(
        "standard", "Deterministic Test", "TestU", "det@test.com",
        QDate(2024, 7, 15), ""));
    
    // Write to first file
    QString file1 = getTempFilePath("deterministic1.xml");
    RegistrationListWriter writer1(file1);
    ASSERT_TRUE(writer1.write(registrations));
    
    // Write to second file
    QString file2 = getTempFilePath("deterministic2.xml");
    RegistrationListWriter writer2(file2);
    ASSERT_TRUE(writer2.write(registrations));
    
    // Read both files
    QFile f1(file1), f2(file2);
    ASSERT_TRUE(f1.open(QIODevice::ReadOnly));
    ASSERT_TRUE(f2.open(QIODevice::ReadOnly));
    QString content1 = f1.readAll();
    QString content2 = f2.readAll();
    f1.close();
    f2.close();
    
    // Should be identical
    EXPECT_EQ(content1, content2);
    
    cleanupRegistrations(registrations);
}
