#ifndef TOTALFEESDIALOG_H
#define TOTALFEESDIALOG_H

#include <QDialog>

class QGridLayout;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;
class RegistrationList;

class TotalFeesDialog : public QDialog
{
    Q_OBJECT
public:
    TotalFeesDialog(RegistrationList *registrationList);

private slots:
    void calculateTotalFeesEvent();

private:
    void setupUI();


    QGridLayout *gridLayout;
    QLabel *labelRegistrationType;
    QComboBox *comboBoxRegistrationType;
    QLabel *labelTotalFees;
    QLineEdit *lineEditTotalFees;
    QPushButton *pushButtonClose;
    RegistrationList *registrationList;
};

#endif // TOTALFEESDIALOG_H
