/**
 * @file filewriter.cpp
 * @author Mitch Campbell
 * @date 2024-07-15
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#include "filewriter.h"

#include <QFile>
#include <QString>
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
