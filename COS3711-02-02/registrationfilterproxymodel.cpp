/**
 * @file registrationfilterproxymodel.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell
 * @brief Implementation file for the RegistrationFilterProxyModel class.
 * @details This file contains the implementation of the RegistrationFilterProxyModel class, which provides filtering functionality for the registration model.
 */


#include "registrationfilterproxymodel.h"

#include <QRegularExpression>


/**
 * @brief Constructs a RegistrationFilterProxyModel object.
 * @param parent The parent object.
 */
RegistrationFilterProxyModel::RegistrationFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{}

/**
 * @brief Sets the filter text for the proxy model.
 * @param filterText The filter text to be set.
 */
void RegistrationFilterProxyModel::setFilterText(const QString &filterText)
{
    QRegularExpression regex(filterText, QRegularExpression::CaseInsensitiveOption);
    setFilterRegularExpression(regex);
}
