#include <QtTest/QtTest>

#include "../../COS3711-02-01/person.h"
#include "../../COS3711-02-01/registration.h"
#include "../../COS3711-02-01/standardregistration.h"
#include "../../COS3711-02-01/studentregistration.h"
#include "../../COS3711-02-01/guestregistration.h"
#include "../../COS3711-02-01/registrationlist.h"
#include "../../COS3711-02-01/registrationmodel.h"

// Mock classes to simulate the registration list
class MockRegistrationList : public RegistrationList {
    Q_OBJECT
public:
    MockRegistrationList(QObject *parent = nullptr) : RegistrationList(parent) {}
    void addRegistration(Registration *registration)  {
        emit listUpdated();
    }
};


class TestRegistrationModel : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testAddItemToModel();
    void testRemoveRegistration();
    void testClear();

private:
    RegistrationModel *model;
};

void TestRegistrationModel::initTestCase() {
    model = new RegistrationModel();
}

void TestRegistrationModel::cleanupTestCase() {
    delete model;
}

void TestRegistrationModel::testAddItemToModel() {
    model->addItemToModel();
    QVERIFY(model->rowCount() > 0); // Check if items are added to the model
}

void TestRegistrationModel::testRemoveRegistration() {
    model->removeRegistration(0);
    QVERIFY(model->rowCount() == 0); // Assuming one item was present and removed
}

void TestRegistrationModel::testClear() {
    model->clear();
    QVERIFY(model->rowCount() == 0); // Check if model is cleared
}

QTEST_MAIN(TestRegistrationModel)
#include "tst_registrationmodelunittest.moc"
