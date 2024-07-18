/**
 * @file totalfeesdialog.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#include "registrationlist.h"
#include "registrationtypes.h"
#include "totalfeesdialog.h"

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMetaEnum>
#include <QPushButton>


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


void TotalFeesDialog::on_comboBoxRegistrationType_currentIndexChanged()
{
    QString typeString = comboBoxRegistrationType->currentText();
    double totalFee = registrationList->totalFee(typeString);
    lineEditTotalFees->setText(QString("%1").arg(totalFee));
}


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
