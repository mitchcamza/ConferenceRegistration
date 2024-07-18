/**
 * @file registrationlistreader.cpp
 * @author Mitch Campbell
 * @date 2024-07-16
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#include "guestregistration.h"
#include "person.h"
#include "registrationlistreader.h"
#include "standardregistration.h"
#include "studentregistration.h"

#include <QDomNodeList>
#include <QFile>
#include <QString>


RegistrationListReader::RegistrationListReader(const QString &fileName)
    : m_FileName(fileName), m_FileReader(fileName)
{

}


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


Registration *RegistrationListReader::parseRegistrationElement(const QDomElement &element)
{
    QString type = element.attribute("type", "");

    QString name, affiliation, email;
    QDate bookingDate;
    QString qualification;
    QString category;

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
        qualification = qualificationNodes.at(0).toElement().text();
    }

    QDomNodeList categoryNodes = element.elementsByTagName("category");
    if (!categoryNodes.isEmpty())
    {
        category = categoryNodes.at(0).toElement().text();
    }

    Person attendee(name, affiliation, email);

    if (type == "standard")
    {
        return new StandardRegistration(attendee, bookingDate);
    }
    else if (type == "student")
    {
        return new StudentRegistration(attendee, bookingDate, qualification);
    }
    else if (type == "guest")
    {
        return new GuestRegistration(attendee, bookingDate, category);
    }
    else
    {
        qWarning() << "Unknown registration type:" << type;
    }
    return nullptr;
}
