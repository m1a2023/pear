#include	"pearStructs.h"
#include    "pearSignals.h"
#include 	"pearClasses.h"
#include 	"mainwindow.h"

//			DIRECTORY INFORMATION
#define			getDirInfo		getDirectoryInformation

void PearDirectory::getDirectoryInformation(QDir directory)
{
    indexer			garbageIndexer = 0;

    foreach (QFileInfo fileInfo, directory.entryInfoList())
    {
        if (fileInfo.isFile())
        {
            FilesInfo.files.push_back(fileInfo);
            FilesInfo.quantity++;
        }
        else {
            if (garbageIndexer++ < 2);
            else
            {
                FoldersInfo.files.push_back(fileInfo);
                FoldersInfo.quantity++;
            }
        }
    }
    qDebug() << "Directory information was received.";
}


void PearDirectory::clearDirectoryInformation()
{
    FilesInfo 	= { 0, { } };
    FoldersInfo = { 0, { } };

    qDebug() << "Directory Information was cleared.";
}


pearFiles PearDirectory::mergeFiles()
{
    pearFiles allFiles;

    foreach (QFileInfo folder, FoldersInfo.files)
    {
        allFiles.files.push_back(folder);
        allFiles.quantity++;
    }

    foreach (QFileInfo file, FilesInfo.files)
    {
        allFiles.files.push_back(file);
        allFiles.quantity++;
    }

    return allFiles;
}


void PearDirectory::showFiles(QListWidget* widget)
{
    for (indexer i = 0; i < dirFiles.files.size(); i++)
        widget->addItem(FilesInfo.files[i].fileName());
}


void PearDirectory::showFolders(QListWidget* widget)
{
    for (indexer i = 0; i < dirFolders.files.size(); i++)
        widget->addItem("/" + FoldersInfo.files[i].fileName());
}


void PearDirectory::showFilesAndFolders(QListWidget* widget)
{
    showFolders(widget);
    showFiles(widget);
}


//			SELECTED ITEMS
#define 	fileExistsInSelectedItems		fileAlreadyExistrsInSelectedItems

Bool PearSelectedItems::fileAlreadyExistsInSelectedItems
                                (const QFileInfo newItem)
{
    Bool fileExists = TRUE;

    for (indexer i = 0; i < quantity; i++)
    {
       newItem.fileName() != files[i].fileName()
                ? 	fileExists *= TRUE
                : 	fileExists *= FALSE
                ;

       if (fileExists == FALSE) return fileExists;
    }
    return fileExists;
}


void PearSelectedItems::addItem(const QFileInfo newItem)
{
    if (fileAlreadyExistsInSelectedItems(newItem))
    {
        files.push_back(newItem);
        quantity++;
    }
}


void PearSelectedItems::addAllItems(const vector <QFileInfo> newItems)
{
    foreach (QFileInfo item, newItems)
        addItem(item);
}


void PearSelectedItems::addAllItems(const vector<QFileInfo> newFileItems,
                                    const vector<QFileInfo> newFolderItems)
{
    foreach (QFileInfo file, newFileItems)
        addItem(file);

    foreach (QFileInfo folder, newFolderItems)
        addItem(folder);
}


void PearSelectedItems::display(QListWidget *widget)
{
    foreach (QFileInfo file, files)
        widget->addItem(file.isDir()
                            ? "/" + file.fileName()
                            : file.fileName());
    qDebug() << "Selected items were shown.";
}


void PearSelectedItems::showCountItems(QLabel * label)
{
    label->setText("Files for renaming: " +
                    QString::number(quantity));
}


void PearSelectedItems::showFiles(pearAbstractFile  prFiles,
                                  QListWidget* 	    widget)
{
    for (indexer i = 0; i < prFiles.files.size(); i++)
    {
        widget->addItem(prFiles.files[i].fileName());
        addItem(prFiles.files[i]);
    }
}


void PearSelectedItems::showFolders(pearAbstractFile prFolders,
                                    QListWidget*	 widget)
{
    for (indexer i = 0; i < prFolders.files.size(); i++)
    {
        widget->addItem(prFolders.files[i].fileName());
        addItem(prFolders.files[i]);
    }
}


QFileInfo PearSelectedItems::searchItemByName(const QString &name)
{
    foreach (QFileInfo fileInfo, files)
    {
        if (fileInfo.fileName() == name)
            return fileInfo;
    }
}


void PearSelectedItems::deleteItem(const indexer index)
{
    if (fileAlreadyExistsInSelectedItems(files[index]))
        files.erase(files.begin() + index);
}


void PearSelectedItems::deleteAllItems()
{
    foreach (QFileInfo file, files)
    {
        files.pop_back();
    }
    quantity = 0;
}


//			SIGNALS
void MainWindow::setDefaultSignals()
{
    SIGNAL_LISTWIDGET 		= DEFAULT_LISTWIDGET_OUTPUT;
    SIGNAL_RENAMEPATTERN	= USE_NUMBERS_IN_PATTERN;
}


void MainWindow::setDefaultValue()
{
    setDefaultSignals();

    prStatusbar.modshowsb	= "default view";
    ui->ListWidget->clear();
    on_labelDirectoryPath_textChanged(prBuffer.startDir);
}
