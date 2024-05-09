#include	"pearStructs.h"
#include    "pearSignals.h"
#include 	"pearClasses.h"
#include 	<QLabel>


//			DIRECTORY INFORMATION
#define			getDirInfo		getDirectoryInformation

void PearDirectory::getDirectoryInformation(QDir directory)
{
    indexer			garbageIndexer = 0;

    foreach (QFileInfo fileInfo, directory.entryInfoList())
    {
        fileInfo.isFile()
                ? 	dirFiles.quantity++
                : 	dirFolders.quantity++
                ;
    }

    foreach (QFileInfo fileInfo, directory.entryInfoList())
    {
        if (fileInfo.isFile())
        {
            dirFiles.names.push_back(fileInfo.fileName());
            dirFiles.lastmod.push_back(fileInfo.lastModified().toString());
        }
        else {
            if (garbageIndexer++ < 2);

            else
            {
                dirFolders.names.push_back("/" + fileInfo.fileName());
                dirFolders.lastmod.push_back(fileInfo.lastModified().toString());
            }
        }
    }

    //delete first two wrong folders
    dirFolders.quantity -= 2;
}


void PearDirectory::clearDirectoryInformation()
{
    dirFiles = {
        0, { }, { }
    };
    dirFolders = {
        0, { }, { }
    };
}


void PearDirectory::showFiles(QListWidget*	widget)
{
    for (indexer i = 0; i < dirFiles.quantity; i++)
        widget->addItem(dirFiles.names[i]);
}


void PearDirectory::showFolders(QListWidget*	widget)
{
    for (indexer i = 0; i < dirFolders.quantity; i++)
        widget->addItem(dirFolders.names[i]);
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


void PearSelectedItems::showFiles(pearFiles		prFiles,
                                  QListWidget* 	widget)
{
    for (indexer i = 0; i < prFiles.quantity; i++)
    {
        widget->addItem(prFiles.names[i]);
        addItem(prFiles.names[i]);
    }
}


void PearSelectedItems::showFolders(pearFolders		prFolders,
                                    QListWidget*	widget)
{
    for (indexer i = 0; i < prFolders.quantity; i++)
    {
        widget->addItem(prFolders.names[i]);
        addItem(prFolders.names[i]);
    }
}


void PearSelectedItems::deleteAllItems()
{
    for (indexer i = 0; i < countSelItems; i++)
    {
        selectedItems.pop_back();
    }

    countSelItems = 0;
}
