#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QString>

class FileWriter
{
public:
    explicit FileWriter(const QString &fileName);
    bool write(const QString &contents) const;

private:
    QString m_FileName;
};

#endif // FILEWRITER_H
