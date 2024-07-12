/**
 * @file registrationtypes.h
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef REGISTRATIONTYPES_H
#define REGISTRATIONTYPES_H

#include <QObject>


/**
 * @class RegistrationTypes
 * @brief The RegistrationTypes class represents the different types of registration.
 * @details This class is derived from QObject and provides an enumeration of registration types. It also provides static methods to convert between the enumeration values and their string representations.
 */
class RegistrationTypes : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a RegistrationTypes object.
     * @param parent The parent object.
     */
    explicit RegistrationTypes(QObject *parent = nullptr);

    /**
     * @brief The Type enumeration represents the different types of registration.
     */
    enum Type { All, StandardRegistration, StudentRegistration, GuestRegistration };
    Q_ENUM(Type)

    /**
     * @brief Converts the given registration type to its string representation.
     * @param type The registration type.
     * @return The string representation of the registration type.
     */
    static QString toString(Type type);

    /**
     * @brief Converts the given string representation to its corresponding registration type.
     * @param str The string representation of the registration type.
     * @return The registration type.
     */
    static Type fromString(const QString &str);
};

#endif // REGISTRATIONTYPES_H
