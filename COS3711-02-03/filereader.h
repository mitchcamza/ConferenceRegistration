#ifndef FILEREADER_H
#define FILEREADER_H

#include <QString>


class FileReader
{
public:
    explicit FileReader(const QString &fileName);
    QString read() const;

private:
    QString m_FileName;
};

#endif // FILEREADER_H
