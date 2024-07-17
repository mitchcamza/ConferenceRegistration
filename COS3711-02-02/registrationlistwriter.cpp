/**
 * @file registrationlistwriter.cpp
 * @author Mitch Campbell
 * @date 2024-07-15
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#include "registrationlistwriter.h"
#include "registration.h"
#include "standardregistration.h"
#include "studentregistration.h"
#include "guestregistration.h"
#include "registrationlistwriter.h"


/**
 * @brief Construct a new Registration List Writer:: Registration List Writer object
 * @param filename
 */
RegistrationListWriter::RegistrationListWriter(const QString &filename)
    : m_FileName(filename), m_FileWriter(filename)
{

}

/**
 * @brief Write the list of registrations to the XML file.
 * @param registrations The list of registrations to write.
 * @return True if the write operation was successful, false otherwise.
 */
bool RegistrationListWriter::write(const QList<Registration*> registrations)
{
    QDomDocument doc;
    QDomElement root = doc.createElement("registrationlist");
    doc.appendChild(root);

    for (const Registration *registration : registrations)
    {
        QDomElement registrationElement = createRegistrationElement(doc, registration);
        root.appendChild(registrationElement);
    }

    QString xmlString = doc.toString();
    return m_FileWriter.write(xmlString);
}

/**
 * @brief Create a registration element for the given registration.
 * @param doc The QDomDocument to create the element with.
 * @param registration The registration to create the element for.
 * @return The QDomElement representing the registration.
 */
QDomElement RegistrationListWriter::createRegistrationElement(QDomDocument &doc, const Registration *registration)
{
    QDomElement registrationElement = doc.createElement("registration");
    addCommonElements(doc, registrationElement, registration);

    if (const StandardRegistration *standardRegistration = qobject_cast<const StandardRegistration*>(registration))
    {
        registrationElement.setAttribute("type", "standard");

        QDomElement feeElement = doc.createElement("registrationfee");
        feeElement.appendChild(doc.createTextNode(QString::number(standardRegistration->calculateFee())));
        registrationElement.appendChild(feeElement);
    }

    else if (const StudentRegistration *studentRegistration = qobject_cast<const StudentRegistration*>(registration))
    {
        registrationElement.setAttribute("type", "student");

        QDomElement qualificationElement = doc.createElement("qualification");
        qualificationElement.appendChild(doc.createTextNode(studentRegistration->getQualification()));
        registrationElement.appendChild(qualificationElement);

        QDomElement feeElement = doc.createElement("registrationfee");
        feeElement.appendChild(doc.createTextNode(QString::number(studentRegistration->calculateFee())));
        registrationElement.appendChild(feeElement);
    }

    else if (const GuestRegistration *guestRegistration = qobject_cast<const GuestRegistration*>(registration))
    {
        registrationElement.setAttribute("type", "guest");

        QDomElement categoryElement = doc.createElement("category");
        categoryElement.appendChild(doc.createTextNode(guestRegistration->getCategory()));
        registrationElement.appendChild(categoryElement);

        QDomElement feeElement = doc.createElement("registrationfee");
        feeElement.appendChild(doc.createTextNode(QString::number(guestRegistration->calculateFee())));
        registrationElement.appendChild(feeElement);
    }

    return registrationElement;
}

/**
 * @brief Add common elements to the registration element.
 * @param doc The QDomDocument to create the elements with.
 * @param registrationElement The registration element to add the common elements to.
 * @param registration The registration to add the common elements for.
 */
void RegistrationListWriter::addCommonElements(QDomDocument &doc, QDomElement &registrationElement, const Registration *registration)
{
    const Person& attendee = registration->getAttendee();

    QDomElement attendeeElement = doc.createElement("attendee");

    QDomElement nameElement = doc.createElement("name");
    nameElement.appendChild(doc.createTextNode(attendee.getName()));
    attendeeElement.appendChild(nameElement);

    QDomElement affiliationElement = doc.createElement("affiliation");
    affiliationElement.appendChild(doc.createTextNode(attendee.getAffiliation()));
    attendeeElement.appendChild(affiliationElement);

    QDomElement emailElement = doc.createElement("email");
    emailElement.appendChild(doc.createTextNode(attendee.getEmail()));
    attendeeElement.appendChild(emailElement);

    registrationElement.appendChild(attendeeElement);

    QDomElement bookingDateElement = doc.createElement("bookingdate");
    bookingDateElement.appendChild(doc.createTextNode(registration->getBookingDate().toString(Qt::ISODate)));
    registrationElement.appendChild(bookingDateElement);
}
