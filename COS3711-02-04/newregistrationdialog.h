/**
 * @file newregistrationdialog.h
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef NEWREGISTRATIONDIALOG_H
#define NEWREGISTRATIONDIALOG_H

#include <QDialog>

class QComboBox;
class QDateEdit;
class QGridLayout;
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;
class RegistrationList;


/**
 * @class NewRegistrationDialog
 * @brief The NewRegistrationDialog class represents a dialog for creating a new registration.
 * @details This class inherits from QDialog and provides functionality for creating a new registration by allowing the user to input various registration details such as registration type, booking date, name, affiliation, email, student qualification, and guest category. The class also provides slots for handling button clicks and combobox changes, as well as private helper methods for setting up the user interface and updating the registration form based on the selected registration type.
 */
class NewRegistrationDialog : public QDialog
{
    Q_OBJECT
public:
    /**
     * @brief Constructs a NewRegistrationDialog object.
     * @param list A pointer to the RegistrationList object.
     * @param parent The parent widget of the dialog.
     */
    explicit NewRegistrationDialog(RegistrationList *list, QDialog *parent = nullptr);

    /**
     * @brief Destroys the NewRegistrationDialog object.
     */
    ~NewRegistrationDialog();

private slots:
    /**
     * @brief Slot for handling the click event of the Register button.
     */
    void on_pushButtonRegister_clicked();

    /**
     * @brief Slot for handling the click event of the Cancel button.
     */
    void on_pushButtonCancel_clicked();

    /**
     * @brief Slot for handling the change event of the Registration Type combobox.
     */
    void on_comboBoxRegistrationType_changed();

private:
    /**
     * @brief Sets up the user interface of the dialog.
     */
    void setupUI();

    /**
     * @brief Sets up the registration group box.
     */
    void setupRegistrationGroup();

    /**
     * @brief Sets up the applicant group box.
     */
    void setupApplicantGroup();

    /**
     * @brief Sets up the buttons.
     */
    void setupButtons();

    /**
     * @brief Updates the registration form based on the selected registration type.
     */
    void updateRegistrationFormBasedOnRegistrationType();

private:
    QComboBox *comboBoxRegistrationType;
    QDateEdit *dateEditBookingDate;
    QLineEdit *lineEditName;
    QLineEdit *lineEditAffiliation;
    QLineEdit *lineEditEmail;
    QLineEdit *lineEditStudentQualification;
    QLineEdit *lineEditGuestCategory;
    QPushButton *pushButtonRegister;
    QPushButton *pushButtonCancel;
    QGridLayout *mainLayout;
    QGridLayout *gridLayoutApplicant;
    QGroupBox *groupBoxRegistration;
    QGroupBox *groupBoxApplicant;
    QLabel *labelStudentQualification;
    QLabel *labelGuestCategory;
    RegistrationList *registrationList;
};

#endif // NEWREGISTRATIONDIALOG_H
