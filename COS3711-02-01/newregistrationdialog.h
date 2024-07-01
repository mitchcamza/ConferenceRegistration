#ifndef NEWREGISTRATIONDIALOG_H
#define NEWREGISTRATIONDIALOG_H

#include <QDialog>

class QLineEdit;
class QComboBox;
class QDateEdit;
class QPushButton;

class NewRegistrationDialog : public QDialog
{
    Q_OBJECT
public:
    explicit NewRegistrationDialog(QDialog *parent = nullptr);
    ~NewRegistrationDialog();

private slots:
    void addRegistration();

private:
    void setupUI();

private:
    QComboBox *comboBoxRegistrationType;
    QDateEdit *dateEditBookingDate;
    QLineEdit *lineEditName;
    QLineEdit *lineEditAffiliation;
    QLineEdit *lineEditEmail;
    QPushButton *pushButtonRegister;
    QPushButton *pushButtonCancel;
};

#endif // NEWREGISTRATIONDIALOG_H
