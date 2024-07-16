/**
 * @file filewriter.h
 * @author Mitch Campbell
 * @date 2024-07-15
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QString>


/**
 * @class FileWriter
 * @brief The FileWriter class provides functionality to write data to a file.
 * @details This class provides a simple interface to write data to a file. It takes a file name as input and provides a write method to write data to the file.
 */
class FileWriter
{
public:
    /**
     * @brief Construct a new File Writer object
     * @param fileName The name of the file to write to.
     */
    explicit FileWriter(const QString &fileName);

    /**
     * @brief Write the contents to the file.
     * @param contents The contents to write to the file.
     * @return True if the write operation was successful, false otherwise.
     */
    bool write(const QString &contents) const;

private:
    QString m_FileName;
};

#endif // FILEWRITER_H
