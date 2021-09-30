#include "dptaskcheckfile.h"

#include <QFileInfo>
#include <QDebug>
#include <QDate>

DPTaskCheckFile::DPTaskCheckFile() : DPTask()
{
}

DPTaskCheckFile::DPTaskCheckFile(const QString &taskName, const int secs) : DPTask(taskName, secs)
{
}

void DPTaskCheckFile::execute()
{
    qDebug() << "Task: " << this->getTaskName();
    qDebug() << "Date: " << QDate::currentDate();
    if(this->_params.count() < 1) {
        qDebug() << " Could not find expected parameter!";
        return;
    }
    QString fileName = this->_params[0].value();
    QFileInfo check_file(fileName);
    bool exists = check_file.exists() && check_file.isFile();
    qDebug() << "File " << fileName << (exists? " DOES" : " DOES NOT") << " exist";

}
