#include "newregistrationdialog.h"

#include <QGridLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>
#include <QLabel>

NewRegistrationDialog::NewRegistrationDialog(QDialog *parent)
    : QDialog(parent),
    comboBoxRegistrationType(new QComboBox()),
    dateEditBookingDate(new QDateEdit(QDate::currentDate())),
    lineEditName(new QLineEdit()),
    lineEditAffiliation(new QLineEdit()),
    lineEditEmail(new QLineEdit()),
    pushButtonRegister(new QPushButton("Register")),
    pushButtonCancel(new QPushButton("Cancel"))
{
    setWindowTitle("New Registration");
    setupUI();
}

NewRegistrationDialog::~NewRegistrationDialog()
{

}

void NewRegistrationDialog::addRegistration()
{
    // TODO: Handle adding registration to the RegistrationList
}

void NewRegistrationDialog::setupUI()
{
    // Add a grid layout
    QGridLayout *gridLayout = new QGridLayout();
    setLayout(gridLayout);

    // Create additional widgets
    QLabel *labelName = new QLabel("Name: ");
    QLabel *labelEmail = new QLabel("Email: ");
    QLabel *labelRegistrationType = new QLabel("Type: ");
    QLabel *labelAffiliation = new QLabel("Affiliation: ");
    QLabel *labelBookingDate = new QLabel("Booking Date: ");

    // Add widgets to the grid layout
    gridLayout->addWidget(labelName, 0, 0);
    gridLayout->addWidget(lineEditName, 0, 1);
    gridLayout->addWidget(labelEmail, 1, 0);
    gridLayout->addWidget(lineEditEmail, 1, 1);
    gridLayout->addWidget(labelRegistrationType, 2, 0);
    gridLayout->addWidget(comboBoxRegistrationType, 2, 1);
    gridLayout->addWidget(labelAffiliation, 3, 0);
    gridLayout->addWidget(lineEditAffiliation, 3, 1);
    gridLayout->addWidget(labelBookingDate, 4, 0);
    gridLayout->addWidget(dateEditBookingDate, 4, 1);
    gridLayout->addWidget(pushButtonRegister, 5, 0, 1, 2);
    gridLayout->addWidget(pushButtonCancel, 6, 0, 1, 2);

    // Configure widgets
    dateEditBookingDate->setCalendarPopup(true);
    dateEditBookingDate->setMinimumDate(QDate::currentDate());
}
