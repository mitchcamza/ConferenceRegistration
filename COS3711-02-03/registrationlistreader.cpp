#include "registrationlistreader.h"
#include "person.h"

#include <QString>
#include <QFile>


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

    QXmlStreamReader xml(xmlContent);

    while (!xml.atEnd() && !xml.hasError())
    {
        QXmlStreamReader::TokenType token = xml.readNext();

        if (token == QXmlStreamReader::StartElement)
        {
            if (xml.name() == QString("registration"))
            {
                Registration *registration = parseRegistrationElement(xml);
                if (registration)
                {
                    registrations.append(registration);
                }
            }
        }
    }

    if (xml.hasError())
    {
        qWarning() << "XML error: " << xml.errorString();
    }

    return registrations;
}

Registration *RegistrationListReader::parseRegistrationElement(QXmlStreamReader &xml)
{
    QString type;
    QString name, affiliation, email;
    QDate bookingDate;
    QString qualification;
    QString category;

    while (!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == QString("registration")))
    {
        xml.readNext();

        if (xml.tokenType() == QXmlStreamReader::StartElement)
        {
            if (xml.name() == QString("type"))
            {
                type = xml.readElementText();
            }
            else if (xml.name() == QString("attendee"))
            {
                while (!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == QString("attendee")))
                {
                    xml.readNext();

                    if (xml.tokenType() == QXmlStreamReader::StartElement)
                    {
                        if (xml.name() == QString("name"))
                        {
                            name = xml.readElementText();
                        }
                        else if (xml.name() == QString("affiliation"))
                        {
                            affiliation = xml.readElementText();
                        }
                        else if (xml.name() == QString("email"))
                        {
                            email = xml.readElementText();
                        }
                    }
                }
            }
            else if (xml.name() == QString("bookingdate"))
            {
                bookingDate = QDate::fromString(xml.readElementText(), Qt::ISODate);
            }
            else if (xml.name() == QString("qualification"))
            {
                qualification = xml.readElementText();
            }
            else if (xml.name() == QString("category"))
            {
                category = xml.readElementText();
            }
        }
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

    return nullptr;
}
