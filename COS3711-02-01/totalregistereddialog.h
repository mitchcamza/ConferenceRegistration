#ifndef TOTALREGISTEREDDIALOG_H
#define TOTALREGISTEREDDIALOG_H

#include <QDialog>

class QGridLayout;
class QLabel;
class QLineEdit;
class QPushButton;
class RegistrationList;

class TotalRegisteredDialog : public QDialog
{
    Q_OBJECT
public:
    TotalRegisteredDialog(RegistrationList *registrationList);

private slots:
    void calculateTotalAttendeesEvent();

private:
    void setupUI();


    QGridLayout *gridLayout;
    QLabel *labelAffiliation;
    QLineEdit *lineEditAffiliation;
    QLabel *labelTotalAttendees;
    QLineEdit *lineEditTotalAttendees;
    QPushButton *pushButtonClose;
    RegistrationList *registrationList;

};

#endif // TOTALREGISTEREDDIALOG_H
