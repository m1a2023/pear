#include    <mainwindow.h>
#include    "pearClasses.h"
#include    <QFile>

void changeRenamePattern()
{

}


bool PearSelectedItems::renameFile(const QString &oldFilePath,
                                   const QString &newFilePath)
{
    QDir directory;
    if (!directory.exists(oldFilePath))
    {
        qDebug() << "File" << oldFilePath << "doesn't exist.";
        return false;
    }

    if (directory.exists(newFilePath))
    {
        qDebug() << "File" << newFilePath << "already exists.";
    }

    if (!directory.rename(oldFilePath, newFilePath))
    {
        qDebug() << "Error" << oldFilePath
                 << "=>" << newFilePath
                 << "renaming";
        return false;
    }
    qDebug() << "Success" << oldFilePath
                 << "to" << newFilePath
                 << "renaming files.";
    return true;
}
