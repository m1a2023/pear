#ifndef PEARCLASSES_H
#define PEARCLASSES_H

#include 	"pearStructs.h"
#include 	<QListWidget>


//			DIRECTORY INFO
#define 	PrDir		PearDirectory

class PearDirectory : public pearDirectoryInformation
{
public:
    void		showFiles(QListWidget* widget);
    void		showFolders(QListWidget* widget);
    void 		getDirectoryInformation(const QDir);
    void		clearDirectoryInformation();
};

//			STATUSBAR
#define 	dirExistStatusbarShow		directoryExistsStatusbarShowing
#define 	showSbQuantFileFolder		showStatusbarQuantityFilesFolders
//
class 	PearStatusbar : public pearStatusbarUnits
{
public:
    QString 	getTextStatusbar() const;
    bool 		directoryExistsStatusbarShowing(const QDir);
    void 		cleanWarnings();
    void 		showStatusbarQuantityFilesFolders(uint16_t countFiles,
                                                  uint16_t countFolders);
};


//			SELECTED FILES
#define 	countSelItems		countSelectedItems

class PearSelectedItems
{
public:
    uint16_t			countSelectedItems = 0;
    vector <QString>	selectedItems;

public:
    Bool 	fileAlreadyExistsInSelectedItems(const QString &newItem);
    void	deleteAllItems();
    void	showFiles(pearFiles, QListWidget*);
    void	showFolders(pearFolders, QListWidget*);
    Bool 	addItem(const QString &newItem);
};


#endif // PEARCLASSES_H
