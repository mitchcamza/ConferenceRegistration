#ifndef REGISTRATIONLISTWRITER_H
#define REGISTRATIONLISTWRITER_H

#include "registration.h"
#include "filewriter.h"

#include <QDomDocument>

class QString;


class RegistrationListWriter
{
public:
    RegistrationListWriter(const QString &fileName);
    bool write(const QList<Registration*> &registrations);

private:
    QDomElement createRegistrationElement(QDomDocument &doc, const Registration *registration);
    void addCommonElements(QDomDocument &doc, QDomElement &regElem, const Registration *registration);

private:
    QString m_FileName;
    FileWriter m_FileWriter;
};

#endif // REGISTRATIONLISTWRITER_H
