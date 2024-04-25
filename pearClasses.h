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
#define 	PearSelItems	PearSelectedItems

class PearSelectedItems
{
private:
    vector <QString> 	selectedItems;

public:
    BOOL 		fileAlreadyExistsInSelectedItems(const QString &name);
};


#endif // PEARCLASSES_H
