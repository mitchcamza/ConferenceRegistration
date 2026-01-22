/**
 * @file registrationlistreader.h
 * @author Mitch Campbell
 * @date 2024-07-16
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef REGISTRATIONLISTREADER_H
#define REGISTRATIONLISTREADER_H

#include "filereader.h"
#include "registration.h"

#include <QDomDocument>
#include <QList>
#include <QXmlStreamReader>


/**
 * @class RegistrationListReader
 * @brief The RegistrationListReader class reads a list of registrations from an XML file.
 * @details This class reads a list of registrations from an XML file and returns a list of Registration objects.
 */
class RegistrationListReader
{
public:
    /**
     * @brief Constructs a RegistrationListReader object with the specified file name.
     * @param fileName The name of the XML file to read.
     */
    explicit RegistrationListReader(const QString &fileName);

    /**
     * @brief Reads the list of registrations from the XML file.
     * @return A list of Registration objects.
     */
    QList<Registration*> read();

private:
    /**
     * @brief Parses a registration element from the XML document.
     * @param element The XML element to parse.
     * @return A Registration object.
     */
    Registration *parseRegistrationElement(const QDomElement &element);

private:
    QString m_FileName;         /**< The name of the XML file to read. */
    FileReader m_FileReader;    /**< The file reader object. */
};

#endif // REGISTRATIONLISTREADER_H
