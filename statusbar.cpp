#include	"mainwindow.h"
#include    "pearClasses.h"


QString PearStatusbar::getTextStatusbar(void) const
{
    if (warnings.isEmpty())
        return modshowsb
                + " | Files: "	+ qfilesb
                + " | Folders: " 	+ qfoldersb
                + (lastmodsb.isEmpty()
                        ? lastmodsb
                        : " | Last Modified: " + lastmodsb
                    );
    else
        return warnings;
}


void MainWindow::showStatusbar()
{
    ui->statusbar->clearMessage();
    ui->statusbar->showMessage(prStatusbar.getTextStatusbar());
}


bool PearStatusbar::dirExistStatusbarShow(const QDir dir)
{
    dir.exists()
            ?	warnings
            :   warnings = "Directory doesn't exist"
            ;
    return warnings.isEmpty() ? true : false;
}


void PearStatusbar::cleanWarnings()
{
    warnings = "\0";
}

<<<<<<< Updated upstream
void PearStatusbar::showStatusbarQuantityFilesFolders(const uint16_t countFiles,
                                                      const uint16_t countFolders)
=======

void PearStatusbar::showStatusbarQuantityFilesFolders(uint16_t countFiles,
                                                      uint16_t countFolders)
>>>>>>> Stashed changes
{
    qfilesb 	= QString::fromStdString(
                        std::to_string(countFiles)
                    );
    qfoldersb 	= QString::fromStdString(
                        std::to_string(countFolders)
                    );
}
