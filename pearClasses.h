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
<<<<<<< Updated upstream
    void 		showStatusbarQuantityFilesFolders (
                        const uint16_t countFiles,
                        const uint16_t countFolders
                    );
=======
    void 		showStatusbarQuantityFilesFolders(uint16_t countFiles,
                                                  uint16_t countFolders);
>>>>>>> Stashed changes
};


//			SELECTED FILES
<<<<<<< Updated upstream
#define 	PearSelItems	PearSelectedItems

class PearSelectedItems
{
private:
    vector <QString> 	selectedItems;

public:
    BOOL 		fileAlreadyExistsInSelectedItems(const QString &name);
=======
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
>>>>>>> Stashed changes
};


#endif // PEARCLASSES_H
