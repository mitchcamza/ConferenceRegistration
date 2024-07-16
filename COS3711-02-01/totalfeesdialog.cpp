/**
 * @file totalfeesdialog.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 * @brief Implementation file for the TotalFeesDialog class.
 * @details This file contains the implementation of the TotalFeesDialog class, which is a dialog window that displays the total fees for a selected registration type. It provides a dropdown menu to select the registration type and displays the corresponding total fees in a line edit field.
 */


#include "totalfeesdialog.h"
#include "registrationlist.h"
#include "registrationtypes.h"

#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QMetaEnum>


/**
 * @brief Constructs a TotalFeesDialog object with the given registration list.
 * @param registrationList A pointer to the RegistrationList object.
 */
TotalFeesDialog::TotalFeesDialog(RegistrationList *registrationList)
    : gridLayout(new QGridLayout(this)),
    labelRegistrationType(new QLabel("Registration Type: ", this)),
    comboBoxRegistrationType(new QComboBox(this)),
    labelTotalFees(new QLabel("Total Fees: ", this)),
    lineEditTotalFees(new QLineEdit(this)),
    pushButtonClose(new QPushButton("Close", this)),
    registrationList(registrationList)
{
    setupUI();

    connect(pushButtonClose, &QPushButton::clicked, this, &TotalFeesDialog::close);
    connect(comboBoxRegistrationType, &QComboBox::currentIndexChanged, this, &TotalFeesDialog::on_comboBoxRegistrationType_currentIndexChanged);
    
    // Display default selection
    on_comboBoxRegistrationType_currentIndexChanged();
}

/**
 * @brief Slot function that is called when the registration type is changed.
 */
void TotalFeesDialog::on_comboBoxRegistrationType_currentIndexChanged()
{
    QString typeString = comboBoxRegistrationType->currentText();
    double totalFee = registrationList->totalFee(typeString);
    lineEditTotalFees->setText(QString("%1").arg(totalFee));
}

/**
 * @brief Sets up the user interface of the dialog window.
 */
void TotalFeesDialog::setupUI()
{
    setWindowTitle("Total Fees");
    resize(312, 100);
    setModal(true);

    QMetaEnum metaEnum = QMetaEnum::fromType<RegistrationTypes::Type>();
    for (int i = 0; i < metaEnum.keyCount(); ++i)
    {
        comboBoxRegistrationType->addItem(metaEnum.key(i));
    }

    lineEditTotalFees->setEnabled(false);

    gridLayout->addWidget(labelRegistrationType, 0, 0);
    gridLayout->addWidget(comboBoxRegistrationType, 0, 1);
    gridLayout->addWidget(labelTotalFees, 1, 0);
    gridLayout->addWidget(lineEditTotalFees, 1, 1);
    gridLayout->addWidget(pushButtonClose, 2, 0, 1, 4);
}
