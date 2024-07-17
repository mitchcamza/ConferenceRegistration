/**
 * @file registrationlistwriter.h
 * @author Mitch Campbell
 * @date 2024-07-15
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef REGISTRATIONLISTWRITER_H
#define REGISTRATIONLISTWRITER_H

#include "registration.h"
#include "filewriter.h"

#include <QDomDocument>

class QString;


/**
 * @class RegistrationListWriter
 * @brief The RegistrationListWriter class provides functionality to write a list of registrations to an XML file.
 * @details This class provides a method to write a list of registrations to an XML file. It takes a file name as input and provides a write method to write the registrations to the file.
 */
class RegistrationListWriter
{
public:
    /**
     * @brief Construct a new Registration List Writer:: Registration List Writer object
     * @param fileName The name of the file to write to.
     */
    RegistrationListWriter(const QString &fileName);

    /**
     * @brief Write the list of registrations to the XML file.
     * @param registrations The list of registrations to write.
     * @return True if the write operation was successful, false otherwise.
     */
    bool write(const QList<Registration*> registrations);

private:
    /**
     * @brief Create a Registration Element object
     * @param doc 
     * @param registration 
     * @return QDomElement 
     */
    QDomElement createRegistrationElement(QDomDocument &doc, const Registration *registration);

    /**
     * @brief Add Common Elements object
     * @param doc 
     * @param regElem 
     * @param registration 
     */
    void addCommonElements(QDomDocument &doc, QDomElement &regElem, const Registration *registration);

private:
    QString m_FileName;         /**< The name of the file to write to. */
    FileWriter m_FileWriter;    /**< The FileWriter object to write to the file. */
};

#endif // REGISTRATIONLISTWRITER_H
