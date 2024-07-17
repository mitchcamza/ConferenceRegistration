/**
 * @file filereader.cpp
 * @author Mitch Campbell
 * @date 2024-07-16
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#include "filereader.h"

#include <QFile>
#include <QTextStream>


/**
 * @brief Constructs a FileReader object with the specified file name.
 * @param fileName The name of the file to read.
 */
FileReader::FileReader(const QString &fileName)
    : m_FileName(fileName)
{

}


/**
 * @brief Reads the contents of the file.
 * @return The contents of the file as a QString.
 */
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
