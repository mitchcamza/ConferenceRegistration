/**
 * @file registrationfilterproxymodel.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell
 */


#include "registrationfilterproxymodel.h"

#include <QRegularExpression>

bool RegistrationFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    if (!sourceModel()) return false;
    
    if (m_filterText.isEmpty()) return true;
    
    QRegularExpression regex(m_filterText, QRegularExpression::CaseInsensitiveOption);
    
    // Check all columns for a match
    int columnCount = sourceModel()->columnCount(sourceParent);
    for (int col = 0; col < columnCount; ++col) {
        QModelIndex index = sourceModel()->index(sourceRow, col, sourceParent);
        QString data = sourceModel()->data(index).toString();
        if (regex.match(data).hasMatch()) {
            return true;
        }
    }
    return false;
}


RegistrationFilterProxyModel::RegistrationFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{

}


void RegistrationFilterProxyModel::setFilterText(const QString &filterText)
{
    m_filterText = filterText;
    invalidateFilter();  // Trigger re-filtering
}
