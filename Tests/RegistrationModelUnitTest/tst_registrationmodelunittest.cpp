#include <QtTest/QtTest>
#include "../../COS3711-02-01/person.h"
#include "../../COS3711-02-01/registration.h"
#include "../../COS3711-02-01/registrationlist.h"
#include "../../COS3711-02-01/registrationmodel.h"
#include "../../COS3711-02-01/studentregistration.h"

// Mock classes to simulate the registration list
class MockRegistrationList : public RegistrationList {
    Q_OBJECT
public:
    MockRegistrationList(RegistrationModel *model, QObject *parent = nullptr) : RegistrationList(*model, parent) {}

    void addMockRegistration(Registration *registration) {
        addRegistration(registration);
        emit registrationAdded(registration);
    }

    void removeMockRegistration(Registration *registration) {
        removeRegistration(registration);
        emit registrationRemoved(registration);
    }
};

class TestRegistrationModel : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();
    // void cleanupTestCase();
    void testAddItemToModel();
    void testRemoveRegistration();
    void testClear();

private:
    RegistrationModel *model;
    MockRegistrationList *list;
    Registration *mockRegistration;
};

void TestRegistrationModel::initTestCase() {
    model = new RegistrationModel();  // Create the RegistrationModel instance
    list = new MockRegistrationList(model);  // Pass the model to the RegistrationList

    // Create a mock registration to use in tests
    Person person("John Doe", "University", "john.doe@example.com");
    mockRegistration = new StudentRegistration(person, QDate::currentDate(), "Computer Science");

    // Add the mock registration to the list
    list->addMockRegistration(mockRegistration);
}

// void TestRegistrationModel::cleanupTestCase() {
//     delete model;
//     delete list;
//     delete mockRegistration;
// }

void TestRegistrationModel::testAddItemToModel() {
    // Test if the item is added to the model
    QVERIFY(model->rowCount() > 0); // Check if items are added to the model
    QCOMPARE(model->rowCount(), 1); // Check if there is exactly one item

    // Check if the data in the model matches the registration
    QCOMPARE(model->item(0, 0)->text(), QString("John Doe"));
    QCOMPARE(model->item(0, 1)->text(), QString("University"));
    QCOMPARE(model->item(0, 2)->text(), QString("john.doe@example.com"));
    QCOMPARE(model->item(0, 3)->text(), QDate::currentDate().toString());
    QCOMPARE(model->item(0, 4)->text(), QString("StudentRegistration"));
    QCOMPARE(model->item(0, 5)->text(), QString::number(mockRegistration->calculateFee()));
    QCOMPARE(model->item(0, 6)->text(), QString("Computer Science"));
    QCOMPARE(model->item(0, 7)->text(), QString("N/A"));
}

void TestRegistrationModel::testRemoveRegistration() {
    // Test if the item is removed from the model
    list->removeMockRegistration(mockRegistration);
    QCOMPARE(model->rowCount(), 0); // Check if item is removed
}

void TestRegistrationModel::testClear() {
    // Add the mock registration again
    list->addMockRegistration(mockRegistration);

    // Test if the model is cleared
    model->clear();
    QCOMPARE(model->rowCount(), 0); // Check if model is cleared
}

QTEST_MAIN(TestRegistrationModel)
#include "tst_registrationmodelunittest.moc"

