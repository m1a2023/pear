#include	"pearStructs.h"
#include    "pearSignals.h"


//			DIRECTORY INFORMATION
pearDirInfo infoFilesFolders(QDir directory)
{
    pearDirInfo     dirInfo;
    indexer			garbageIndexer = 0;

    //calculate count files and folders
    foreach (QFileInfo fileInfo, directory.entryInfoList())
    {
        fileInfo.isFile()
                ? dirInfo.dirFiles.id++
                : dirInfo.dirFolders.id++
                ;
    }

    foreach (QFileInfo fileInfo, directory.entryInfoList())
    {
        if (fileInfo.isFile())
        {
            dirInfo.dirFiles.nameFiles.push_back(fileInfo.fileName());
            dirInfo.dirFiles.lastmod.push_back(fileInfo.lastModified().toString());
        }
        else {
            if (garbageIndexer++ < 2);

            else
            {
                dirInfo.dirFolders.nameFolders.push_back("/" + fileInfo.fileName());
                dirInfo.dirFolders.lastmod.push_back(fileInfo.lastModified().toString());
            }
        }
    }

    //delete first two wrong folders
    dirInfo.dirFolders.id -= 2;

    return dirInfo;
}

