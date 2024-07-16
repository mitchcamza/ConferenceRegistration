/**
 * @file totalregistereddialog.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell
 * @brief Implementation file for the TotalRegisteredDialog class.
 */


#include "totalregistereddialog.h"
#include "registrationlist.h"

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


/**
 * @brief Constructs a TotalRegisteredDialog object.
 * @param registrationList Pointer to the RegistrationList object.
 */
TotalRegisteredDialog::TotalRegisteredDialog(RegistrationList *registrationList)
    : gridLayout(new QGridLayout(this)),
    labelAffiliation(new QLabel("Affiliation", this)),
    lineEditAffiliation(new QLineEdit(this)),
    labelTotalAttendees(new QLabel("Total Attendees: ", this)),
    lineEditTotalAttendees(new QLineEdit(this)),
    registrationList(registrationList),
    pushButtonClose(new QPushButton("Close", this))
{
    setupUI();

    connect(pushButtonClose, &QPushButton::clicked, this, &TotalRegisteredDialog::close);
    connect(lineEditAffiliation, &QLineEdit::textChanged, this, &TotalRegisteredDialog::on_lineEditAffiliation_textChanged);
}

/**
 * @brief Calculates the total number of attendees for a given affiliation.
 */
void TotalRegisteredDialog::on_lineEditAffiliation_textChanged()
{
    QString affiliation = lineEditAffiliation->text();
    int totalAttendees = registrationList->totalRegistrations(affiliation);
    lineEditTotalAttendees->setText(QString("%1").arg(totalAttendees));
}

/**
 * @brief Sets up the user interface for the dialog.
 */
void TotalRegisteredDialog::setupUI()
{
    setWindowTitle("Total Attendees from Affiliation");
    resize(312, 100);
    setModal(true);

    lineEditTotalAttendees->setEnabled(false);

    gridLayout->addWidget(labelAffiliation, 0, 0);
    gridLayout->addWidget(lineEditAffiliation, 0, 1);
    gridLayout->addWidget(labelTotalAttendees, 1, 0);
    gridLayout->addWidget(lineEditTotalAttendees, 1, 1);
    gridLayout->addWidget(pushButtonClose, 2, 0, 1, 4);
}
