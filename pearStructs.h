#ifndef PEARSTRUCTS_H
#define PEARSTRUCTS_H


#include <QString>
#include <QDir>
#include <filesystem>


using std::vector;


#define 	isPrFolder(a) a[0] == '/'

//			DIRECTORY INFORMATION
#define     pearDirInfo     pearDirectoryInformation

#define 	idfile			uint32_t
#define 	idfolder		uint32_t
#define 	dirFiles		FilesInfo
#define 	dirFolders		FoldersInfo
#define 	lastmod			lastModified

struct pearFiles
{
    idfile				id = 0;
    vector <QString> 	nameFiles;
    vector <QString> 	lastModified;
};

struct pearFolders
{
    idfolder			id = 0;
    vector <QString> 	nameFolders;
    vector <QString> 	lastModified;
};

struct pearDirectoryInformation
{

    pearFiles			FilesInfo;
    pearFolders 		FoldersInfo;
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
