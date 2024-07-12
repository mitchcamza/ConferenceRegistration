/**
 * @file registrationtypes.cpp
 * @author Mitch Campbell 
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell 2024
 * @brief Implementation file for the RegistrationTypes class.
 * @details This file contains the implementation of the RegistrationTypes class, which provides utility functions for working with the RegistrationTypes::Type enum.
 */

#include "registrationtypes.h"

#include <QMetaEnum>

RegistrationTypes::RegistrationTypes(QObject *parent)
    : QObject{parent}
{}

QString RegistrationTypes::toString(Type type)
{
    /**
     * @brief Converts the given RegistrationTypes::Type enum value to a string representation.
     * @param type The RegistrationTypes::Type enum value to convert.
     * @return The string representation of the enum value.
     */
    QMetaEnum metaEnum = QMetaEnum::fromType<Type>();
    return QString(metaEnum.valueToKey(type));
}

RegistrationTypes::Type RegistrationTypes::fromString(const QString &str)
{
    /**
     * @brief Converts the given string representation to a RegistrationTypes::Type enum value.
     * @param str The string representation to convert.
     * @return The RegistrationTypes::Type enum value.
     */
    QMetaEnum metaEnum = QMetaEnum::fromType<Type>();
    return static_cast<Type>(metaEnum.keyToValue(str.toUtf8().constData()));
}
