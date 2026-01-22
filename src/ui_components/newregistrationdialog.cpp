/**
 * @file newregistrationdialog.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell
 */


#include "newregistrationdialog.h"
#include "registrationfactory.h"
#include "registrationlist.h"

#include <QComboBox>
#include <QDateEdit>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>


NewRegistrationDialog::NewRegistrationDialog(RegistrationList *list, QDialog *parent)
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
    pushButtonCancel(new QPushButton("Cancel")),
    labelStudentQualification(new QLabel("Student Qualification: ")),
    labelGuestCategory(new QLabel("Guest Category: ")),
    registrationList(list)
{
    setupUI();
    setupInputValidation();

    // Connect signals and slots
    connect(pushButtonRegister, &QPushButton::clicked, this, &NewRegistrationDialog::on_pushButtonRegister_clicked);
    connect(pushButtonCancel, &QPushButton::clicked, this, &NewRegistrationDialog::on_pushButtonCancel_clicked);
    connect(comboBoxRegistrationType, &QComboBox::currentIndexChanged, this, &NewRegistrationDialog::on_comboBoxRegistrationType_changed);
}


NewRegistrationDialog::~NewRegistrationDialog()
{

}


void NewRegistrationDialog::on_pushButtonRegister_clicked()
{
    // Collect registration details
    QString type = comboBoxRegistrationType->currentText();
    QString name = lineEditName->text().toUpper();
    QString affiliation = lineEditAffiliation->text().toUpper();
    QString email = lineEditEmail->text().toUpper();
    QString qualification = lineEditStudentQualification->text().toUpper();
    QString category = lineEditGuestCategory->text();
    QString additionalInfo = qualification + category;
    QDate bookingDate = dateEditBookingDate->date();

    if (!isValidInput(type, name, affiliation, email, qualification, category))
    {
        return;
    }

    RegistrationFactory &factory = RegistrationFactory::getInstance();
    Registration *registration = factory.createRegistration(type, name, affiliation, email, bookingDate, additionalInfo);

    this->close();

    if (registration)
    {
        if (registrationList->addRegistration(registration))
        {
            QMessageBox::information(this, "Registration Added", "Registration added successfully.");
        }
        else
        {
            QMessageBox::warning(this, "Registration Failed", "A registration with this email address and name already exists.");
        }
    }
    else
    {
        QMessageBox::warning(this, "Registration Failed", "Could not add registration. Check that the registration details are correct.");
    }
}


void NewRegistrationDialog::on_pushButtonCancel_clicked()
{
    this->close();
}


void NewRegistrationDialog::updateRegistrationFormBasedOnRegistrationType()
{
    QString registrationType = comboBoxRegistrationType->currentText().toLower();

    labelStudentQualification->setProperty("registrationType", QVariantMap{
        { "standard", false },
        { "student", true },
        { "guest", false }
    });

    lineEditStudentQualification->setProperty("registrationType", QVariantMap{
        { "standard", false },
        { "student", true },
        { "guest", false }
    });

    labelGuestCategory->setProperty("registrationType", QVariantMap{
        { "standard", false },
        { "student", false },
        { "guest", true }
    });

    lineEditGuestCategory->setProperty("registrationType", QVariantMap{
        { "standard", false },
        { "student", false },
        { "guest", true }
    });

    // Enable or disable fields, depending on registration type
    QList<QWidget*> widgets = { labelStudentQualification, lineEditStudentQualification, labelGuestCategory, lineEditGuestCategory };
    for (QWidget* widget : widgets)
    {
        QVariantMap properties = widget->property("registrationType").toMap();
        if (properties.contains(registrationType))
        {
            widget->setVisible(properties.value(registrationType).toBool());
        }
        else
        {
            widget->setVisible(false);  // Default state if the registration type is not found
        }
    }

    // Clear line edits after updating their states
    lineEditStudentQualification->clear();
    lineEditGuestCategory->clear();
}


void NewRegistrationDialog::setupInputValidation()
{
    QRegularExpression nameRegEx("[A-Za-z\\s]+");
    QRegularExpressionValidator *nameValidator = new QRegularExpressionValidator(nameRegEx, this);
    lineEditName->setValidator(nameValidator);

    QRegularExpression affiliationRegEx("[A-Za-z0-9\\s]+");
    QRegularExpressionValidator *affiliationValidator = new QRegularExpressionValidator(affiliationRegEx, this);
    lineEditAffiliation->setValidator(affiliationValidator);

    QRegularExpression emailRegEx("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}");
    QRegularExpressionValidator *emailValidator = new QRegularExpressionValidator(emailRegEx, this);
    lineEditEmail->setValidator(emailValidator);

    QRegularExpression qualificationRegEx("[A-Za-z\\s]+");
    QRegularExpressionValidator *qualificationValidator = new QRegularExpressionValidator(qualificationRegEx, this);
    lineEditStudentQualification->setValidator(qualificationValidator);

    QRegularExpression categoryRegEx("[A-Za-z\\s]+");
    QRegularExpressionValidator *categoryValidator = new QRegularExpressionValidator(categoryRegEx, this);
    lineEditGuestCategory->setValidator(categoryValidator);
}


bool NewRegistrationDialog::isValidInput(const QString &type, const QString &name, const QString &affiliation, const QString &email, const QString &qualification, const QString &category)
{
    if (name.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Name cannot be empty");
        return false;
    }

    if (affiliation.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Affiliation cannot be empty");
        return false;
    }

    if (email.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Email address cannot be empty");
        return false;
    }

    if (!(email.contains("@") && email.contains(".")))
    {
        QMessageBox::warning(this, "Input Error", "Email format is incorrect.");
        return false;
    }

    if (type.toLower() == "student" && qualification.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Student qualification cannot be empty.");
        return false;
    }

    if (type.toLower() == "guest" && category.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Guest category cannot be empty.");
        return false;
    }

    return true;
}


void NewRegistrationDialog::on_comboBoxRegistrationType_changed()
{
    updateRegistrationFormBasedOnRegistrationType();
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
    lineEditStudentQualification->setToolTip("Selects the applicant's qualification. Only applicable to student registrations.");
    gridLayoutApplicant->addWidget(labelStudentQualification, 3, 0);
    gridLayoutApplicant->addWidget(lineEditStudentQualification, 3, 1);

    // Guest Category
    lineEditGuestCategory->setToolTip("Selects the applicant's category. Only applicable to guests.");
    gridLayoutApplicant->addWidget(labelGuestCategory, 4, 0);
    gridLayoutApplicant->addWidget(lineEditGuestCategory, 4, 1);

    groupBoxApplicant->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    groupBoxApplicant->setLayout(gridLayoutApplicant);
    mainLayout->addWidget(groupBoxApplicant, 1, 0);

    updateRegistrationFormBasedOnRegistrationType();
}


void NewRegistrationDialog::setupButtons()
{
    mainLayout->addWidget(pushButtonRegister, 2, 0);
    mainLayout->addWidget(pushButtonCancel, 3, 0);
    pushButtonRegister->setToolTip("Registers new applicant.");
    pushButtonCancel->setToolTip("Cancels registration and returns to main application window.");
    pushButtonRegister->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    pushButtonCancel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}


