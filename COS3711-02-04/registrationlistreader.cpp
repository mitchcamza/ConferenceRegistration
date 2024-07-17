/**
 * @file registrationlistreader.cpp
 * @author Mitch Campbell
 * @date 2024-07-16
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#include "registrationlistreader.h"
#include "person.h"
#include "registrationfactory.h"

#include <QString>
#include <QFile>
#include <QDomNodeList>


/**
 * @brief Construct a new Registration List Reader object with the specified file name.
 * @param fileName 
 */
RegistrationListReader::RegistrationListReader(const QString &fileName)
    : m_FileName(fileName), m_FileReader(fileName)
{

}

/**
 * @brief Reads the list of registrations from the XML file.
 * @return A list of Registration objects.
 */
QList<Registration *> RegistrationListReader::read()
{
    QList<Registration*> registrations;

    QString xmlContent = m_FileReader.read();
    if (xmlContent.isEmpty())
    {
        return registrations;
    }

    QDomDocument doc;
    if (!doc.setContent(xmlContent))
    {
        qWarning() << "Failed to parse XML file.";
        return registrations;
    }

    QDomElement root = doc.documentElement();
    QDomNodeList registrationNodes = root.elementsByTagName("registration");

    for (int i = 0; i < registrationNodes.count(); i++)
    {
        QDomElement registrationElement = registrationNodes.at(i).toElement();
        Registration *registration = parseRegistrationElement(registrationElement);
        if (registration)
        {
            registrations.append(registration);
        }
    }

    return registrations;
}

/**
 * @brief Parses a registration element from the XML document.
 * @param element The XML element to parse.
 * @return A Registration object.
 */
Registration *RegistrationListReader::parseRegistrationElement(const QDomElement &element)
{
    QString type = element.attribute("type", "");

    QString name, affiliation, email;
    QDate bookingDate;
    QString additionalInfo;

    QDomNodeList attendeeNodes = element.elementsByTagName("attendee");
    if (!attendeeNodes.isEmpty())
    {
        QDomElement attendeeElement = attendeeNodes.at(0).toElement();

        QDomNodeList nameNodes = attendeeElement.elementsByTagName("name");
        if (!nameNodes.isEmpty())
        {
            name = nameNodes.at(0).toElement().text();
        }

        QDomNodeList affiliationNodes = attendeeElement.elementsByTagName("affiliation");
        if (!affiliationNodes.isEmpty())
        {
            affiliation = affiliationNodes.at(0).toElement().text();
        }

        QDomNodeList emailNodes = attendeeElement.elementsByTagName("email");
        if (!emailNodes.isEmpty())
        {
            email = emailNodes.at(0).toElement().text();
        }
    }

    QDomNodeList bookingDateNodes = element.elementsByTagName("bookingdate");
    if (!bookingDateNodes.isEmpty())
    {
        bookingDate = QDate::fromString(bookingDateNodes.at(0).toElement().text(), Qt::ISODate);
    }

    QDomNodeList qualificationNodes = element.elementsByTagName("qualification");
    if (!qualificationNodes.isEmpty())
    {
        additionalInfo = qualificationNodes.at(0).toElement().text();
    }

    QDomNodeList categoryNodes = element.elementsByTagName("category");
    if (!categoryNodes.isEmpty())
    {
        additionalInfo = categoryNodes.at(0).toElement().text();
    }

    // Use RegistrationFactory to create registrations
    RegistrationFactory &factory = RegistrationFactory::getInstance();
    Registration *registration = factory.createRegistration(type, name, affiliation, email, bookingDate, additionalInfo);

    if (!registration)
    {
        qWarning() << "Failed to create registration for type: " << type << ". Make sure that the type exists.";
    }

    return registration;
}
