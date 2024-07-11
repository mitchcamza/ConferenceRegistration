#include "totalfeesdialog.h"
#include "registrationlist.h"
#include "registrationtypes.h"

#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QMetaEnum>

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
    connect(comboBoxRegistrationType, &QComboBox::currentIndexChanged, this, &TotalFeesDialog::calculateTotalFeesEvent);

    calculateTotalFeesEvent();
}

void TotalFeesDialog::calculateTotalFeesEvent()
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

    QMetaObject::connectSlotsByName(this);
}
