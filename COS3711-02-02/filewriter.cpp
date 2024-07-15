#include "filewriter.h"

#include <QString>
#include <QFile>
#include <QTextStream>


FileWriter::FileWriter(const QString &fileName)
    : m_FileName(fileName)
{

}

bool FileWriter::write(const QString &contents) const
{
    QFile file(m_FileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        return false;
    }

    QTextStream out(&file);
    out << contents;
    out.flush();
    file.close();
    return true;
}
