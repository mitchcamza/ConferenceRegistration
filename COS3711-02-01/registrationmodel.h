#ifndef REGISTRATIONMODEL_H
#define REGISTRATIONMODEL_H

#include <QStandardItemModel>

class Registration;
class RegistrationList;

class RegistrationModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit RegistrationModel(QObject *parent = nullptr);
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
    void addItem(Registration *registration);
    void removeRegistration(int row);
    void clear();

signals:
    void dataUpdated(const QModelIndex &index);

private:
    void setHeaders();
    void initializeModel();
};

#endif // REGISTRATIONMODEL_H
