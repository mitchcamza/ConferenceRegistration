#include "newregistrationdialog.h"

#include <QGridLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>
#include <QLabel>

NewRegistrationDialog::NewRegistrationDialog(QDialog *parent)
    : QDialog(parent),
    mainLayout(new QGridLayout(this)),
    groupBoxRegistration(new QGroupBox("Registration")),
    groupBoxApplicant(new QGroupBox("Applicant")),
    comboBoxRegistrationType(new QComboBox()),
    dateEditBookingDate(new QDateEdit(QDate::currentDate())),
    lineEditName(new QLineEdit()),
    lineEditAffiliation(new QLineEdit()),
    lineEditEmail(new QLineEdit()),
    lineEditStudentQualification(new QLineEdit()),
    lineEditGuestCategory(new QLineEdit()),
    pushButtonRegister(new QPushButton("Register")),
    pushButtonCancel(new QPushButton("Cancel"))
{
    setupUI();

    // Connect signals and slots
    connect(pushButtonRegister, &QPushButton::clicked, this, &NewRegistrationDialog::on_pushButtonRegister_clicked);
    connect(pushButtonCancel, &QPushButton::clicked, this, &NewRegistrationDialog::on_pushButtonCancel_clicked);
}

NewRegistrationDialog::~NewRegistrationDialog()
{

}

void NewRegistrationDialog::on_pushButtonRegister_clicked()
{
    // TODO: call helper function to add applicant to registration model
}

void NewRegistrationDialog::on_pushButtonCancel_clicked()
{
    this->close();
}

void NewRegistrationDialog::setupUI()
{
    this->setWindowTitle("New Registration");
    this->setWindowModality(Qt::ApplicationModal);
    this->resize(428, 400);
    this->setToolTip("Adds new attendees to registration list.");

    setupRegistrationGroup();
    setupApplicantGroup();
    setupButtons();

    setLayout(mainLayout);
}

void NewRegistrationDialog::setupRegistrationGroup()
{
    QGridLayout *gridLayoutRegistration = new QGridLayout();

    // Registration Type
    QLabel *labelRegistrationType = new QLabel("Registration Type: ");
    QStringList registrationTypes { "Standard", "Student", "Guest" };
    comboBoxRegistrationType->addItems(registrationTypes);
    comboBoxRegistrationType->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    comboBoxRegistrationType->setToolTip("Selects the type of registration.");
    gridLayoutRegistration->addWidget(labelRegistrationType, 0, 0);
    gridLayoutRegistration->addWidget(comboBoxRegistrationType, 0, 1);

    // Booking Date
    QLabel *labelBookingDate = new QLabel("Booking Date: ");
    dateEditBookingDate->setCalendarPopup(true);
    dateEditBookingDate->setMinimumDate(QDate::currentDate());
    dateEditBookingDate->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    dateEditBookingDate->setToolTip("Selects the conference date.");
    gridLayoutRegistration->addWidget(labelBookingDate, 1, 0);
    gridLayoutRegistration->addWidget(dateEditBookingDate, 1, 1);

    groupBoxRegistration->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    groupBoxRegistration->setLayout(gridLayoutRegistration);
    mainLayout->addWidget(groupBoxRegistration, 0, 0);
}

void NewRegistrationDialog::setupApplicantGroup()
{
    QGridLayout *gridLayoutApplicant = new QGridLayout();

    // Name
    QLabel *labelName = new QLabel("Name: ");
    lineEditName->setToolTip("Applicant's full name");
    gridLayoutApplicant->addWidget(labelName, 0, 0);
    gridLayoutApplicant->addWidget(lineEditName, 0, 1);

    // Affiliation
    QLabel *labelAffiliation = new QLabel("Affiliation: ");
    lineEditAffiliation->setToolTip("Applicant's affiliation or instituion");
    gridLayoutApplicant->addWidget(labelAffiliation, 1, 0);
    gridLayoutApplicant->addWidget(lineEditAffiliation, 1, 1);

    // Email
    QLabel *labelEmail = new QLabel("Email: ");
    lineEditEmail->setToolTip("Applicant's email address");
    gridLayoutApplicant->addWidget(labelEmail, 2, 0);
    gridLayoutApplicant->addWidget(lineEditEmail, 2, 1);

    // Student Qualification
    QLabel *labelStudentQualification = new QLabel("Student Qualification: ");
    lineEditStudentQualification->setToolTip("Selects the applicant's qualification. Only applicable to student registrations.");
    gridLayoutApplicant->addWidget(labelStudentQualification, 3, 0);
    gridLayoutApplicant->addWidget(lineEditStudentQualification, 3, 1);

    // Guest Category
    QLabel *labelGuestCategory = new QLabel("Guest Category: ");
    lineEditGuestCategory->setToolTip("Selects the applicant's category. Only applicable to guests.");
    gridLayoutApplicant->addWidget(labelGuestCategory, 4, 0);
    gridLayoutApplicant->addWidget(lineEditGuestCategory, 4, 1);

    groupBoxApplicant->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    groupBoxApplicant->setLayout(gridLayoutApplicant);
    mainLayout->addWidget(groupBoxApplicant, 1, 0);
}

void NewRegistrationDialog::setupButtons()
{
    mainLayout->addWidget(pushButtonRegister, 2, 0);
    mainLayout->addWidget(pushButtonCancel, 3, 0);
    pushButtonRegister->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    pushButtonCancel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}


