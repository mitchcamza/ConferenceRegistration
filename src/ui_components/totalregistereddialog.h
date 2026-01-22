/**
 * @file totalregistereddialog.h
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef TOTALREGISTEREDDIALOG_H
#define TOTALREGISTEREDDIALOG_H

#include <QDialog>

class QGridLayout;
class QLabel;
class QLineEdit;
class QPushButton;
class RegistrationList;


/**
 * @class TotalRegisteredDialog
 * @brief The TotalRegisteredDialog class represents a dialog window that displays the total number of registered attendees.
 * @details This class inherits from QDialog and provides functionality to calculate and display the total number of registered attendees. It includes UI elements such as labels, line edits, and buttons for user interaction.
 */
class TotalRegisteredDialog : public QDialog
{
    Q_OBJECT
public:
    /**
     * @brief Constructs a TotalRegisteredDialog object.
     * @param registrationList A pointer to the RegistrationList object that contains the list of registered attendees.
     */
    TotalRegisteredDialog(RegistrationList *registrationList);

private slots:
    /**
     * @brief Slot function triggered when the "Calculate Total Attendees" button is clicked.
     * @details This function calculates the total number of registered attendees and updates the UI accordingly.
     */
    void on_lineEditAffiliation_textChanged();

private:
    /**
     * @brief Sets up the user interface of the dialog.
     * @details This function creates and configures the necessary UI elements such as labels, line edits, and buttons.
     */
    void setupUI();


    QGridLayout *gridLayout; /**< The layout manager for the dialog's UI elements. */
    QLabel *labelAffiliation; /**< The label for the affiliation field. */
    QLineEdit *lineEditAffiliation; /**< The line edit for entering the affiliation. */
    QLabel *labelTotalAttendees; /**< The label for displaying the total number of attendees. */
    QLineEdit *lineEditTotalAttendees; /**< The line edit for displaying the total number of attendees. */
    QPushButton *pushButtonClose; /**< The button for closing the dialog. */
    RegistrationList *registrationList; /**< A pointer to the RegistrationList object. */
};

#endif // TOTALREGISTEREDDIALOG_H
