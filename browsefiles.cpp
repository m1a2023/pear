#include	"pearStructs.h"
#include    "pearSignals.h"
#include 	"pearClasses.h"


//			DIRECTORY INFORMATION
pearDirInfo infoFilesFolders(QDir directory)
{
    pearDirInfo     dirInfo;
    indexer			garbageIndexer = 0;

    //calculate count files and folders
    foreach (QFileInfo fileInfo, directory.entryInfoList())
    {
        fileInfo.isFile()
                ? dirInfo.dirFiles.quantity++
                : dirInfo.dirFolders.quantity++
                ;
    }

    foreach (QFileInfo fileInfo, directory.entryInfoList())
    {
        if (fileInfo.isFile())
        {
            dirInfo.dirFiles.names.push_back(fileInfo.fileName());
            dirInfo.dirFiles.lastmod.push_back(fileInfo.lastModified().toString());
        }
        else {
            if (garbageIndexer++ < 2);

            else
            {
                dirInfo.dirFolders.names.push_back("/" + fileInfo.fileName());
                dirInfo.dirFolders.lastmod.push_back(fileInfo.lastModified().toString());
            }
        }
    }


    //delete first two wrong folders
    dirInfo.dirFolders.quantity -= 2;

    return dirInfo;
}


//			SELECTED ITEMS
#define 	fileExistsInSelectedItems		fileAlreadyExistrsInSelectedItems

Bool PearSelectedItems::fileAlreadyExistsInSelectedItems
                                (const QString &newItem)
{
    Bool 	fileExists = TRUE;

    for (indexer i = 0; i < selectedItems.size(); i++)
    {
        newItem == selectedItems[i]
                ? 	fileExists *= FALSE
                : 	fileExists *= TRUE
                ;
    }
    return 	fileExists;
}


Bool PearSelectedItems::addItem(const QString &newItem)
{
    Bool fileExists;


    if ((fileExists = fileAlreadyExistsInSelectedItems(newItem)))
    {
        countSelItems++;
        selectedItems.push_back(newItem);
    }


    return fileExists;
}


void PearSelectedItems::deleteAllItems()
{
    for (indexer i = 0; i < countSelItems; i++)
    {
        selectedItems.pop_back();
    }

    countSelItems = 0;
}
