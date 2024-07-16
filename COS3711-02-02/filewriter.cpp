/**
 * @file filewriter.cpp
 * @author Mitch Campbell
 * @date 2024-07-15
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#include "filewriter.h"

#include <QString>
#include <QFile>
#include <QTextStream>


/**
 * @brief Constructs a FileWriter object with the specified file name.
 * @param fileName The name of the file to write to.
 */
FileWriter::FileWriter(const QString &fileName)
    : m_FileName(fileName)
{

}

/**
 * @brief Writes the specified contents to the file.
 * @param contents The contents to write to the file.
 * @return True if the write operation was successful, false otherwise.
 */
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
