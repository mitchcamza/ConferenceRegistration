#ifndef REGISTRATIONLISTREADER_H
#define REGISTRATIONLISTREADER_H

#include "registration.h"
#include "standardregistration.h"
#include "studentregistration.h"
#include "guestregistration.h"
#include "filereader.h"

#include <QList>
#include <QXmlStreamReader>


class RegistrationListReader
{
public:
    RegistrationListReader(const QString &fileName);
    QList<Registration*> read();

private:
    Registration *parseRegistrationElement(QXmlStreamReader &xml);

private:
    QString m_FileName;
    FileReader m_FileReader;
};

#endif // REGISTRATIONLISTREADER_H
