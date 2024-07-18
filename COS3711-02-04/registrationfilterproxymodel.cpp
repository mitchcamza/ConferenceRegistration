/**
 * @file registrationfilterproxymodel.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell
 */


#include "registrationfilterproxymodel.h"

#include <QRegularExpression>


RegistrationFilterProxyModel::RegistrationFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{

}


void RegistrationFilterProxyModel::setFilterText(const QString &filterText)
{
    QRegularExpression regex(filterText, QRegularExpression::CaseInsensitiveOption);
    setFilterRegularExpression(regex);
}
