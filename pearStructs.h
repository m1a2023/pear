#ifndef PEARSTRUCTS_H
#define PEARSTRUCTS_H


#include <QString>
#include <QDir>
#include <filesystem>


//			DIRECTORY INFORMATION
#define     pearDirInfo     pearDirectoryInformation

using std::vector;

struct pearDirectoryInformation
{
    uint32_t         quantFiles		= 0;
    uint32_t         quantFolders	= 0;
    vector <QString> DirFiles;
    vector <QString> DirFolders;
};


pearDirInfo infoFilesFolders(QDir);


//			STATUSBAR
#define     pearStatus  pearStatusbarInformation

#define     qfilesb     quantityFilesStatusbar
#define     qfoldersb   quantityFoldersStatusbar
#define     modshowsb   modeShowStatusbar

struct pearStatusbarInformation
{
    QString		quantityFilesStatusbar;
    QString 	quantityFoldersStatusbar;
    QString 	modeShowStatusbar;
};

//			BUFFER
#define     udispdir    updateDisplayDirectory
#define     prevDir     previousDirectory

struct pearBuffer
{
    QString     updateDisplayDirectory;
    QString     previousDirectory;
};

#endif // PEARSTRUCTS_H
