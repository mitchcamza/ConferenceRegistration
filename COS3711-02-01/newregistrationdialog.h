#ifndef NEWREGISTRATIONDIALOG_H
#define NEWREGISTRATIONDIALOG_H

#include <QDialog>

class QLineEdit;
class QComboBox;
class QDateEdit;
class QPushButton;
class QGridLayout;
class QGroupBox;
class QLabel;
class RegistrationList;

class NewRegistrationDialog : public QDialog
{
    Q_OBJECT
public:
    explicit NewRegistrationDialog(RegistrationList *list, QDialog *parent = nullptr);
    ~NewRegistrationDialog();

private slots:
    void on_pushButtonRegister_clicked();
    void on_pushButtonCancel_clicked();
    void on_comboBoxRegistrationType_changed();

private:
    void setupUI();
    void setupRegistrationGroup();
    void setupApplicantGroup();
    void setupButtons();
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
