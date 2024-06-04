#ifndef PEARCLASSES_H
#define PEARCLASSES_H

#include 	"pearStructs.h"

//			DIRECTORY INFO
#define 	PrDir		PearDirectory

class PearDirectory : public pearDirectoryInformation
{
public:
    void		    showFiles(QListWidget* widget);
    void		    showFolders(QListWidget* widget);
    void 		    getDirectoryInformation(const QDir);
    void		    clearDirectoryInformation();
    pearFiles	    mergeFiles();
    void 		    showFilesAndFolders(QListWidget *);
};

//			STATUSBAR
#define 	dirExistStatusbarShow		directoryExistsStatusbarShowing
#define 	setSbQuantFileFolder	    setStatusbarQuantityFilesFolders

class 	PearStatusbar : public pearStatusbarUnits
{
public:
    QString 	getTextStatusbar() const;
    bool 		directoryExistsStatusbarShowing(const QDir);
    void 		cleanWarnings();
    void 		setStatusbarQuantityFilesFolders(uint16_t countFiles,
                                                 uint16_t countFolders);
};


//			SELECTED FILES

class PearSelectedItems : public pearAbstractFile
{
public:
    Bool	 	    fileAlreadyExistsInSelectedItems(const QFileInfo newItem);
    void		    deleteAllItems();
    void		    showFiles(pearAbstractFile, QListWidget *);
    void		    showFolders(pearAbstractFile, QListWidget *);
    void 		    addItem(const QFileInfo newItem);
    QFileInfo 	    searchItemByName(const QString &);
    void 		    deleteItem(const indexer);
    void 		    addAllItems(const vector <QFileInfo>);
    void 		    addAllItems(const vector <QFileInfo>,
                                const vector <QFileInfo>);
    void 		    display(QListWidget *);
    void 		    showCountItems(QLabel *);
    bool 		    renameFile(const QString &oldName,
                               const QString &newName);

};


#endif // PEARCLASSES_H
