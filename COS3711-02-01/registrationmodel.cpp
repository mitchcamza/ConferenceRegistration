/**
 * @file registrationmodel.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 * @brief Implementation file for the RegistrationModel class.
 */


#include "registrationmodel.h"
#include "guestregistration.h"
#include "registration.h"
#include "registrationlist.h"
#include "studentregistration.h"


/**
 * @brief Sets the headers for the registration model.
 */
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

/**
 * @brief Constructs a RegistrationModel object.
 * @param parent The parent object.
 */
RegistrationModel::RegistrationModel(QObject *parent)
    : QStandardItemModel{parent}
{
    initializeModel();   // Initialize model with existing registrations
}

/**
 * @brief Sets the data for the specified index in the model.
 * @param index The index of the item.
 * @param value The new value for the item.
 * @param role The role of the item.
 * @return True if the data was set successfully, false otherwise.
 */
bool RegistrationModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool result = QStandardItemModel::setData(index, value, role);
    if (result) { emit dataUpdated(index); }
    return result;
}

/**
 * @brief Sorts the model based on the specified column and order.
 * @param column The column to sort by.
 * @param order The sort order.
 */
void RegistrationModel::sort(int column, Qt::SortOrder order)
{
    QStandardItemModel::sort(column, order);
}

/**
 * @brief Initializes the model by clearing it and setting the headers.
 */
void RegistrationModel::initializeModel()
{
    this->clear();
    setHeaders();
}

/**
 * @brief Adds a registration item to the model.
 * @param registration The registration item to add.
 */
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

/**
 * @brief Removes a registration item from the model.
 * @param row The row index of the item to remove.
 */
void RegistrationModel::removeRegistration(int row)
{
    removeRow(row);
}

/**
 * @brief Clears the model by removing all items and setting the headers.
 */
void RegistrationModel::clear()
{
    QStandardItemModel::clear();
    setHeaders();
}
