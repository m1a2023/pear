#ifndef PEARCLASSES_H
#define PEARCLASSES_H

#include 	<QString>
#include 	"pearStructs.h"


//			STATUSBAR
#define 	dirExistStatusbarShow		directoryExistsStatusbarShowing
#define 	showSbQuantFileFolder		showStatusbarQuantityFilesFolders

class 	PearStatusbar : public pearStatusbarStruct
{
public:
    QString 	getTextStatusbar() const;
    bool 		directoryExistsStatusbarShowing(const QDir);
    void 		cleanWarnings();
    void 		showStatusbarQuantityFilesFolders (
                        const uint16_t countFiles,
                        const uint16_t countFolders
                    );
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
    Bool 	addItem(const QString &newItem);
    void	deleteAllItems();
};


#endif // PEARCLASSES_H
