/**
 * @file registrationtypes.cpp
 * @author Mitch Campbell 
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell 2024
 */


#include "registrationtypes.h"

#include <QMetaEnum>


RegistrationTypes::RegistrationTypes(QObject *parent)
    : QObject{parent}
{

}


QString RegistrationTypes::toString(Type type)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<Type>();
    return QString(metaEnum.valueToKey(type));
}


RegistrationTypes::Type RegistrationTypes::fromString(const QString &str)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<Type>();
    return static_cast<Type>(metaEnum.keyToValue(str.toUtf8().constData()));
}
