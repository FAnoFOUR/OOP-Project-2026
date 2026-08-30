#ifndef FILEREADER_H
#define FILEREADER_H

#include <QtXml>
#include <QJsonObject>
#include <string>

class TaskListManager;

class FileReader{
public:
    virtual ~FileReader();
    virtual TaskListManager* read(const std::string& filePath);
};

#endif
