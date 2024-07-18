/**
 * @file registrationfilterproxymodel.h
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef REGISTRATIONFILTERPROXYMODEL_H
#define REGISTRATIONFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>


class RegistrationFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a RegistrationFilterProxyModel object.
     * @param parent The parent object.
     */
    explicit RegistrationFilterProxyModel(QObject *parent = nullptr);

public slots:
    /**
     * @brief Sets the filter text to be used for filtering the data.
     * @param filterText The filter text.
     */
    void setFilterText(const QString &filterText);
};

#endif // REGISTRATIONFILTERPROXYMODEL_H
