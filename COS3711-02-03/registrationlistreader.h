#ifndef REGISTRATIONLISTREADER_H
#define REGISTRATIONLISTREADER_H

#include "registration.h"
#include "filereader.h"

#include <QList>
#include <QXmlStreamReader>
#include <QDomDocument>


class RegistrationListReader
{
public:
    explicit RegistrationListReader(const QString &fileName);
    QList<Registration*> read();

private:
    Registration *parseRegistrationElement(const QDomElement &element);

private:
    QString m_FileName;
    FileReader m_FileReader;
};

#endif // REGISTRATIONLISTREADER_H
