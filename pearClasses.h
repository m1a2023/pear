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
    void 		showStatusbarQuantityFilesFolders(uint16_t countFiles, uint16_t countFolders);

};


#endif // PEARCLASSES_H
