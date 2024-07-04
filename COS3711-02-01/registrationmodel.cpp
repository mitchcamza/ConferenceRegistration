#include "registrationmodel.h"

#include "registration.h"
#include "standardregistration.h"
#include "studentregistration.h"
#include "guestregistration.h"


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
    setHeaders();
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

void RegistrationModel::addRegistration(Registration *registration)
{
    QList<QStandardItem*> row;
    QStandardItem *registrationTypeItem = new QStandardItem(registration->metaObject()->className());
    QStandardItem *bookingDateItem = new QStandardItem(registration->getBookingDate().toString());
    QStandardItem *nameItem = new QStandardItem(registration->getAttendee().getName());
    QStandardItem *affiliationItem = new QStandardItem(registration->getAttendee().getAffiliation());
    QStandardItem *emailItem = new QStandardItem(registration->getAttendee().getEmail());
    QStandardItem *studentQualificationItem = new QStandardItem();
    QStandardItem *guestCategoryItem = new QStandardItem();
    QStandardItem *registrationFeeItem = new QStandardItem(registration->calculateFee());

    if (StudentRegistration *studentRegistration = dynamic_cast<StudentRegistration*>(registration))
    {
        studentQualificationItem->setText(studentRegistration->getQualification());
    }

    if (GuestRegistration *guestRegistration = dynamic_cast<GuestRegistration*>(registration))
    {
        guestCategoryItem->setText(guestRegistration->getCategory());
    }

    row << nameItem
        << affiliationItem
        << emailItem
        << bookingDateItem
        << registrationTypeItem
        << registrationFeeItem
        << studentQualificationItem
        << guestCategoryItem;

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

