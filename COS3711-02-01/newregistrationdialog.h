#ifndef NEWREGISTRATIONDIALOG_H
#define NEWREGISTRATIONDIALOG_H

#include <QDialog>

class QLineEdit;
class QComboBox;
class QDateEdit;
class QPushButton;
class QGridLayout;
class QGroupBox;
class QFormLayout;

class NewRegistrationDialog : public QDialog
{
    Q_OBJECT
public:
    explicit NewRegistrationDialog(QDialog *parent = nullptr);
    ~NewRegistrationDialog();

private slots:
    void on_pushButtonRegister_clicked();
    void on_pushButtonCancel_clicked();

private:
    void setupUI();
    void setupRegistrationGroup();
    void setupApplicantGroup();
    void setupButtons();

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
    QGroupBox *groupBoxRegistration;
    QGroupBox *groupBoxApplicant;
};

#endif // NEWREGISTRATIONDIALOG_H
