#include "registrationlistwriter.h"
#include "registration.h"
#include "standardregistration.h"
#include "studentregistration.h"
#include "guestregistration.h"


#include "registrationlistwriter.h"

RegistrationListWriter::RegistrationListWriter(const QString &filename)
    : m_FileName(filename), m_FileWriter(filename)
{

}

bool RegistrationListWriter::write(const QList<Registration*> &registrations)
{
    QDomDocument doc;
    QDomElement root = doc.createElement("Registrations");
    doc.appendChild(root);

    for (const Registration *registration : registrations)
    {
        QDomElement registrationElement = createRegistrationElement(doc, registration);
        root.appendChild(registrationElement);
    }

    QString xmlString = doc.toString();
    return m_FileWriter.write(xmlString);
}

QDomElement RegistrationListWriter::createRegistrationElement(QDomDocument &doc, const Registration *registration)
{
    QDomElement registrationElement = doc.createElement("Registration");

    addCommonElements(doc, registrationElement, registration);

    if (const StandardRegistration *standardRegistration = dynamic_cast<const StandardRegistration*>(registration))
    {
        registrationElement.setAttribute("type", "Standard");

        QDomElement feeElement = doc.createElement("Fee");
        feeElement.appendChild(doc.createTextNode(QString::number(standardRegistration->calculateFee())));
        registrationElement.appendChild(feeElement);
    }

    else if (const StudentRegistration *studentRegistration = dynamic_cast<const StudentRegistration*>(registration))
    {
        registrationElement.setAttribute("type", "Student");

        QDomElement qualificationElement = doc.createElement("Qualification");
        qualificationElement.appendChild(doc.createTextNode(studentRegistration->getQualification()));
        registrationElement.appendChild(qualificationElement);

        QDomElement feeElement = doc.createElement("Fee");
        feeElement.appendChild(doc.createTextNode(QString::number(studentRegistration->calculateFee())));
        registrationElement.appendChild(feeElement);
    }

    else if (const GuestRegistration *guestRegistration = dynamic_cast<const GuestRegistration*>(registration))
    {
        registrationElement.setAttribute("type", "Guest");

        QDomElement categoryElement = doc.createElement("Category");
        categoryElement.appendChild(doc.createTextNode(guestRegistration->getCategory()));
        registrationElement.appendChild(categoryElement);

        QDomElement feeElement = doc.createElement("Fee");
        feeElement.appendChild(doc.createTextNode(QString::number(guestRegistration->calculateFee())));
        registrationElement.appendChild(feeElement);
    }

    return registrationElement;
}

void RegistrationListWriter::addCommonElements(QDomDocument &doc, QDomElement &registrationElement, const Registration *registration)
{
    const Person& attendee = registration->getAttendee();

    QDomElement nameElement = doc.createElement("Name");
    nameElement.appendChild(doc.createTextNode(attendee.getName()));
    registrationElement.appendChild(nameElement);

    QDomElement affiliationElement = doc.createElement("Affiliation");
    affiliationElement.appendChild(doc.createTextNode(attendee.getAffiliation()));
    registrationElement.appendChild(affiliationElement);

    QDomElement emailElement = doc.createElement("Email");
    emailElement.appendChild(doc.createTextNode(attendee.getEmail()));
    registrationElement.appendChild(emailElement);

    QDomElement bookingDateElement = doc.createElement("BookingDate");
    bookingDateElement.appendChild(doc.createTextNode(registration->getBookingDate().toString(Qt::ISODate)));
    registrationElement.appendChild(bookingDateElement);
}
