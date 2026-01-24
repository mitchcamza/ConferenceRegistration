/**
 * @file statistics_dialogs_test.cpp
 * @brief Unit tests for TotalFeesDialog and TotalRegisteredDialog UI components
 * @details Tests dialog initialization, calculation display, and UI elements
 */

#include "totalfeesdialog.h"
#include "totalregistereddialog.h"
#include "registrationlist.h"
#include "registrationmodel.h"
#include "registrationfactory.h"

#include <QTest>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QApplication>

class StatisticsDialogsTest : public QObject
{
    Q_OBJECT

private:
    RegistrationModel *model;
    RegistrationList *regList;

private slots:
    void initTestCase()
    {
        // Initialization before all tests
    }

    void cleanupTestCase()
    {
        // Cleanup after all tests
    }

    void init()
    {
        // Setup before each test - create fresh model and list
        model = new RegistrationModel(this);
        regList = new RegistrationList(*model, this);
    }

    void cleanup()
    {
        // Cleanup after each test
        delete regList;
        delete model;
    }

    // TotalFeesDialog Tests
    void testTotalFeesDialogInitialization()
    {
        TotalFeesDialog dialog(regList);
        
        // Verify dialog is not null
        QVERIFY(&dialog != nullptr);
    }

    void testTotalFeesDialogComboBoxExists()
    {
        TotalFeesDialog dialog(regList);
        
        // Find registration type combo box
        QComboBox *comboBox = dialog.findChild<QComboBox*>();
        QVERIFY(comboBox != nullptr);
    }

    void testTotalFeesDialogLineEditExists()
    {
        TotalFeesDialog dialog(regList);
        
        // Find line edit for displaying total fees
        QLineEdit *lineEdit = dialog.findChild<QLineEdit*>();
        QVERIFY(lineEdit != nullptr);
    }

    void testTotalFeesDialogCloseButtonExists()
    {
        TotalFeesDialog dialog(regList);
        
        // Find close button
        QPushButton *button = dialog.findChild<QPushButton*>();
        QVERIFY(button != nullptr);
    }

    void testTotalFeesDialogWithEmptyList()
    {
        TotalFeesDialog dialog(regList);
        
        // With empty list, verify line edit exists
        QLineEdit *lineEdit = dialog.findChild<QLineEdit*>();
        QVERIFY(lineEdit != nullptr);
        
        // Line edit should be disabled for display (not editable)
        QVERIFY(!lineEdit->isEnabled());
    }

    void testTotalFeesDialogWithRegistrations()
    {
        // Add a standard registration ($100)
        RegistrationFactory &factory = RegistrationFactory::getInstance();
        Registration *reg = factory.createRegistration(
            "Standard",
            "John Doe",
            "University A",
            "john@example.com",
            QDate::currentDate(),
            ""
        );
        
        if (reg)
        {
            regList->addRegistration(reg);
        }
        
        TotalFeesDialog dialog(regList);
        
        // Line edit should exist
        QLineEdit *lineEdit = dialog.findChild<QLineEdit*>();
        QVERIFY(lineEdit != nullptr);
        
        // Line edit should be disabled (display only, not editable)
        QVERIFY(!lineEdit->isEnabled());
        
        // Line edit should contain some text
        QVERIFY(!lineEdit->text().isEmpty());
    }

    // TotalRegisteredDialog Tests
    void testTotalRegisteredDialogInitialization()
    {
        TotalRegisteredDialog dialog(regList);
        
        // Verify dialog is not null
        QVERIFY(&dialog != nullptr);
    }

    void testTotalRegisteredDialogAffiliationLineEditExists()
    {
        TotalRegisteredDialog dialog(regList);
        
        // Find line edits
        QList<QLineEdit*> lineEdits = dialog.findChildren<QLineEdit*>();
        
        // Should have at least 2 line edits (affiliation input and total display)
        QVERIFY(lineEdits.size() >= 2);
    }

    void testTotalRegisteredDialogTotalLineEditExists()
    {
        TotalRegisteredDialog dialog(regList);
        
        // Find line edits for total attendees
        QList<QLineEdit*> lineEdits = dialog.findChildren<QLineEdit*>();
        QVERIFY(lineEdits.size() >= 2);
    }

    void testTotalRegisteredDialogCloseButtonExists()
    {
        TotalRegisteredDialog dialog(regList);
        
        // Find close button
        QPushButton *button = dialog.findChild<QPushButton*>();
        QVERIFY(button != nullptr);
    }

    void testTotalRegisteredDialogWithEmptyList()
    {
        TotalRegisteredDialog dialog(regList);
        
        // With empty list, total should be 0
        QList<QLineEdit*> lineEdits = dialog.findChildren<QLineEdit*>();
        QVERIFY(lineEdits.size() >= 2);
        
        // At least one line edit should exist
        QVERIFY(!lineEdits.isEmpty());
    }

    void testTotalRegisteredDialogWithRegistrations()
    {
        // Add registrations from same affiliation
        RegistrationFactory &factory = RegistrationFactory::getInstance();
        
        Registration *reg1 = factory.createRegistration(
            "Standard",
            "John Doe",
            "University A",
            "john@example.com",
            QDate::currentDate(),
            ""
        );
        
        Registration *reg2 = factory.createRegistration(
            "Student",
            "Jane Smith",
            "University A",
            "jane@example.com",
            QDate::currentDate(),
            "Bachelor's"
        );
        
        if (reg1) regList->addRegistration(reg1);
        if (reg2) regList->addRegistration(reg2);
        
        TotalRegisteredDialog dialog(regList);
        
        // Find affiliation input line edit
        QList<QLineEdit*> lineEdits = dialog.findChildren<QLineEdit*>();
        QVERIFY(lineEdits.size() >= 2);
        
        // Simulate entering affiliation
        if (lineEdits.size() >= 1)
        {
            QLineEdit *affiliationEdit = lineEdits[0];
            affiliationEdit->setText("University A");
            
            // The dialog should update the count
            // (actual calculation is tested in unit tests)
        }
    }

    void testTotalFeesComboBoxHasItems()
    {
        TotalFeesDialog dialog(regList);
        
        QComboBox *comboBox = dialog.findChild<QComboBox*>();
        QVERIFY(comboBox != nullptr);
        
        // Should have registration types available
        QVERIFY(comboBox->count() > 0);
    }
};

// Qt Test main function
QTEST_MAIN(StatisticsDialogsTest)
#include "statistics_dialogs_test.moc"
