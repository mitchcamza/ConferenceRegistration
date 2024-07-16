#include "filereader.h"

#include <QFile>
#include <QTextStream>


FileReader::FileReader(const QString &fileName)
    : m_FileName(fileName)
{

}

QString FileReader::read() const
{
    QFile file(m_FileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        return QString();
    }

    QTextStream in(&file);
    QString contents = in.readAll();
    file.close();

    return contents;
}
