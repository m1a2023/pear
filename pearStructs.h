#ifndef PEARSTRUCTS_H
#define PEARSTRUCTS_H


#include <QString>
#include <QDir>
#include <filesystem>


using std::vector;


//			DIRECTORY INFORMATION
#define     pearDirInfo     pearDirectoryInformation

#define 	idfile			uint32_t
#define 	idfolder		uint32_t
#define 	dirFiles		FilesInfo
#define 	dirFolders		FoldersInfo
#define 	lastmod			lastModified

struct pearFiles
{
    uint16_t			quantity = 0;
    vector <QString> 	names;
    vector <QString> 	lastModified;
};

struct pearFolders : public pearFiles { };

struct pearDirectoryInformation
{

    pearFiles			FilesInfo;
    pearFolders 		FoldersInfo;
};

pearDirInfo infoFilesFolders(QDir);


//			STATUSBAR
#define     pearStatusbarStruct  	pearStructStatusbarUnits

#define     qfilesb     		quantityFilesStatusbar
#define     qfoldersb   		quantityFoldersStatusbar
#define     modshowsb   		modeShowStatusbar
#define     lastmodsb   		lastModifiedStatusbar
#define 	warnings			warningsStatusbar

struct pearStructStatusbarUnits
{
    QString		quantityFilesStatusbar;
    QString 	quantityFoldersStatusbar;
    QString 	modeShowStatusbar;
    QString		lastModifiedStatusbar;
    QString		warningsStatusbar;
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
