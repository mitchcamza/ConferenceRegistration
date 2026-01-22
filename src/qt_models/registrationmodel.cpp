/**
 * @file registrationmodel.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 * @brief Implementation file for the RegistrationModel class.
 */


#include "guestregistration.h"
#include "registration.h"
#include "registrationlist.h"
#include "registrationmodel.h"
#include "studentregistration.h"


void RegistrationModel::setHeaders()
{
    setHorizontalHeaderItem(0, new QStandardItem("Name"));
    setHorizontalHeaderItem(1, new QStandardItem("Affiliation"));
    setHorizontalHeaderItem(2, new QStandardItem("Email"));
    setHorizontalHeaderItem(3, new QStandardItem("Booking Date"));
    setHorizontalHeaderItem(4, new QStandardItem("Type"));
    setHorizontalHeaderItem(5, new QStandardItem("Fee"));
    setHorizontalHeaderItem(6, new QStandardItem("Qualification"));
    setHorizontalHeaderItem(7, new QStandardItem("Category"));
}


RegistrationModel::RegistrationModel(QObject *parent)
    : QStandardItemModel{parent}
{
    initializeModel();   // Initialize model with existing registrations
}


bool RegistrationModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool result = QStandardItemModel::setData(index, value, role);
    if (result) { emit dataUpdated(index); }
    return result;
}


void RegistrationModel::sort(int column, Qt::SortOrder order)
{
    QStandardItemModel::sort(column, order);
}


void RegistrationModel::initializeModel()
{
    this->clear();
    setHeaders();
}


void RegistrationModel::addItem(Registration *registration)
{
    QList<QStandardItem*> row;
    row.append(new QStandardItem(registration->getAttendee().getName()));
    row.append(new QStandardItem(registration->getAttendee().getAffiliation()));
    row.append(new QStandardItem(registration->getAttendee().getEmail()));
    row.append(new QStandardItem(registration->getBookingDate().toString()));
    row.append(new QStandardItem(registration->metaObject()->className()));
    row.append(new QStandardItem(QString::number(registration->calculateFee())));

    if (StudentRegistration *student = dynamic_cast<StudentRegistration*>(registration))
    {
        row.append(new QStandardItem(student->getQualification()));
    }
    else
    {
        row.append(new QStandardItem("N/A"));
    }

    if (GuestRegistration *guest = dynamic_cast<GuestRegistration*>(registration))
    {
        row.append(new QStandardItem(guest->getCategory()));
    }
    else
    {
        row.append(new QStandardItem("N/A"));
    }

    appendRow(row);
    row.clear();
}


void RegistrationModel::removeRegistration(int row)
{
    removeRow(row);
}


void RegistrationModel::clear()
{
    QStandardItemModel::clear();
    setHeaders();
}
