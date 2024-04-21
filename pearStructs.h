#ifndef PEARSTRUCTS_H
#define PEARSTRUCTS_H


#include <QString>
#include <QDir>
#include <filesystem>


using std::vector;

//			DIRECTORY INFORMATION
#define     pearDirInfo     pearDirectoryInformation

struct pearDirectoryInformation
{
    uint32_t         quantFiles		= 0;
    uint32_t         quantFolders	= 0;
    vector <QString> DirFiles;
    vector <QString> DirFolders;
};

struct pearFiles
{
    vector <QString> nameFiles;
    vector <QString> lastModified;
};

struct pearFolders
{
    vector <QString> nameFolders;
    vector <QString> lastModified;
};

pearDirInfo infoFilesFolders(QDir);


//			STATUSBAR
#define     pearStatus  pearStatusbarInformation

#define     qfilesb     quantityFilesStatusbar
#define     qfoldersb   quantityFoldersStatusbar
#define     modshowsb   modeShowStatusbar
#define     lastmodsb   lastModifiedStatusbar

struct pearStatusbarInformation
{
    QString		quantityFilesStatusbar;
    QString 	quantityFoldersStatusbar;
    QString 	modeShowStatusbar;
    QString		lastModifiedStatusbar;
};

//			BUFFER
#define     udispdir    updateDisplayDirectory
#define     prevDir     previousDirectory

struct pearBuffer
{
    QString     startDirectory = "/";
    QString     updateDisplayDirectory;
};

#endif // PEARSTRUCTS_H
