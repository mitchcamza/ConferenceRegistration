/**
 * @file totalfeesdialog.h
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef TOTALFEESDIALOG_H
#define TOTALFEESDIALOG_H

#include <QDialog>

class QGridLayout;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;
class RegistrationList;


/**
 * @class TotalFeesDialog
 * @brief The TotalFeesDialog class represents a dialog window for calculating and displaying total fees.
 * @details This class inherits from QDialog and provides a user interface for calculating and displaying the total fees based on the selected registration type. It also allows the user to close the dialog window.
 */
class TotalFeesDialog : public QDialog
{
    Q_OBJECT
public:
    /**
     * @brief Constructs a TotalFeesDialog object with the given registration list.
     * @param registrationList A pointer to the RegistrationList object.
     */
    TotalFeesDialog(RegistrationList *registrationList);

private slots:
    /**
     * @brief Slot function that is called when the registration type is changed.
     */
    void on_comboBoxRegistrationType_currentIndexChanged();

private:
    /**
     * @brief Sets up the user interface of the dialog window.
     */
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
