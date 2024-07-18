/**
 * @file registrationmodel.h
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef REGISTRATIONMODEL_H
#define REGISTRATIONMODEL_H

#include <QStandardItemModel>

class Registration;


/**
 * @class RegistrationModel
 * @brief The RegistrationModel class is a custom model that extends QStandardItemModel.
 * @details This class provides additional functionality for managing Registration objects in a model. It allows adding, removing, and sorting registrations, as well as updating the data in the model.
 */
class RegistrationModel : public QStandardItemModel
{
    Q_OBJECT
public:
    /**
     * @brief Constructs a RegistrationModel object.
     * @param parent The parent object.
     */
    explicit RegistrationModel(QObject *parent = nullptr);

    /**
     * @brief Sets the data for the specified index in the model.
     * @param index The index of the item to set the data for.
     * @param value The new value for the item.
     * @param role The role for which the data is being set (default is Qt::EditRole).
     * @return true if the data was successfully set, false otherwise.
     */
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    /**
     * @brief Sorts the model based on the specified column and order.
     * @param column The column to sort by.
     * @param order The sort order (default is Qt::AscendingOrder).
     */
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;

    /**
     * @brief Adds a Registration object to the model.
     * @param registration The Registration object to add.
     */
    void addItem(Registration *registration);

    /**
     * @brief Removes the Registration at the specified row from the model.
     * @param row The row of the Registration to remove.
     */
    void removeRegistration(int row);

    /**
     * @brief Clears the model, removing all Registrations.
     */
    void clear();

signals:
    /**
     * @brief Signal emitted when the data in the model is updated.
     * @param index The index of the updated data.
     */
    void dataUpdated(const QModelIndex &index);

private:
    /**
     * @brief Sets the headers for the model.
     */
    void setHeaders();

    /**
     * @brief Initializes the model.
     */
    void initializeModel();
};

#endif // REGISTRATIONMODEL_H
