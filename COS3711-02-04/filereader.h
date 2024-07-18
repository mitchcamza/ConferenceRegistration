/**
 * @file filereader.h
 * @author Mitch Campbell
 * @date 2024-07-16
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef FILEREADER_H
#define FILEREADER_H

#include <QString>


/**
 * @class FileReader
 * @brief The FileReader class reads the contents of a file.
 * @details This class reads the contents of a file and returns the contents as a QString.
 */
class FileReader
{
public:
    /**
     * @brief Constructs a FileReader object with the specified file name.
     * @param fileName The name of the file to read.
     */
    explicit FileReader(const QString &fileName);

    /**
     * @brief Reads the contents of the file.
     * @return The contents of the file as a QString.
     */
    QString read() const;

private:
    QString m_FileName; /**< The name of the file to read. */
};

#endif // FILEREADER_H
