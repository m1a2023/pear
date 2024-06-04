#ifndef PEARSTRUCTS_H
#define PEARSTRUCTS_H


#include 	<QString>
#include 	<QDir>
#include 	<QFileInfo>
#include 	<QListWidget>
#include 	<QLabel>

using std::vector;


//			DIRECTORY INFORMATION
#define     pearDirInfo     pearDirectoryInformation
#define 	    lastmod			lastModified
#define 	    dirFiles		    FilesInfo
#define 	    dirFolders		FoldersInfo

struct pearAbstractFile
{
    uint16_t			    quantity = 0;
    vector <QFileInfo>	files;
};

struct pearFiles : public pearAbstractFile { };

struct pearFolders : public pearAbstractFile { };

struct pearDirectoryInformation
{
    pearFiles		FilesInfo;
    pearFolders 		FoldersInfo;
};


//			STATUSBAR
#define     pearStatusbar  	pearStatusbarUnits

#define     qfilesb     	quantityFilesStatusbar
#define     qfoldersb   	quantityFoldersStatusbar
#define     modshowsb   	modeShowStatusbar
#define     lastmodsb       lastModifiedStatusbar
#define 	warnings        warningsStatusbar
#define     qselfilesb      quantitySelectedFilesStatusbar

struct pearStatusbarUnits
{
    QString		quantityFilesStatusbar;
    QString 	quantityFoldersStatusbar;
    QString 	modeShowStatusbar;
    QString		lastModifiedStatusbar;
    QString		warningsStatusbar;
    //new, not used
    QString     quantitySelectedFilesStatusbar;
};

//			BUFFER
#define     udispdir    	updateDisplayDirectory
#define     startDir     	startDirectory

struct pearBuffer
{
    QString     startDirectory = "/";
    QString     updateDisplayDirectory;
    QString     renamePattern = "file";
};


//			BOOL

#define 	Bool		uint8_t

enum
{
    FALSE,
    TRUE
};

#endif // PEARSTRUCTS_H
