#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    on_labelDirectoryPath_textChanged(prBuffer.startDirectory);

    on_radioButton_clicked();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_labelDirectoryPath_textChanged(const QString &inputPath)
{
    prBuffer.udispdir = inputPath;					        //copying PATH into buffer

    ui->ListWidget->clear(); 						            //clear a previous file output

    prDirectory.clearDirectoryInformation();		    //clear a previous directory info

    prDirectory.getDirectoryInformation(inputPath);	//fill the pearDirInfo

    prStatusbar.showSbQuantFileFolder (
                        prDirectory.FilesInfo.quantity,
                        prDirectory.FoldersInfo.quantity
                    );

    if (prStatusbar.dirExistStatusbarShow(QDir(inputPath)))
    {
        switch (SIGNAL_LISTWIDGET)
        {
        case DEFAULT_LISTWIDGET_OUTPUT:
            prDirectory.showFolders(ui->ListWidget);
            prDirectory.showFiles(ui->ListWidget);

            break;

        case ONLYFOLDERS_LISTWIDGET_OUTPUT:
            prDirectory.showFolders(ui->ListWidget);

            break;

        case ONLYFILES_LISTWIDGET_OUTPUT:
            prDirectory.showFiles(ui->ListWidget);

            break;
        }
    }
    showStatusbar();

    prStatusbar.cleanWarnings();
}


void MainWindow::on_radioButton_clicked()
{
    SIGNAL_LISTWIDGET		= 	DEFAULT_LISTWIDGET_OUTPUT;
    prStatusbar.modshowsb 	= 	"default view";

    ui->ListWidget->clear();

    on_labelDirectoryPath_textChanged(prBuffer.udispdir);
}


void MainWindow::on_radioButton_showFolders_clicked()
{
    SIGNAL_LISTWIDGET		= ONLYFOLDERS_LISTWIDGET_OUTPUT;
    prStatusbar.modshowsb	= "mode: only folders";

    ui->ListWidget->clear();

    on_labelDirectoryPath_textChanged(prBuffer.udispdir);
}


void MainWindow::on_radioButton_showFiles_clicked()
{
    SIGNAL_LISTWIDGET		= ONLYFILES_LISTWIDGET_OUTPUT;
    prStatusbar.modshowsb	= "mode: only files";

    ui->ListWidget->clear();

    on_labelDirectoryPath_textChanged(prBuffer.udispdir);
}


void MainWindow::on_ListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    prSelItems.addItem(item->text())
        ? ui->ListWidgetRenaming->addItem(item->text())
        : ui->renamedFilesInfo->setText("file already picked");

    ui->renamedFilesInfo->setText("Files for renaming: " +
                                  QString::number(prSelItems.countSelItems));
}


void MainWindow::on_toolButton_clicked()
{
    DialogToolWindow dialogToolWindow;

    dialogToolWindow.setModal(true);
    dialogToolWindow.exec();
}

//REFACTOR
void MainWindow::on_ListWidget_itemSelectionChanged()
{

}


void MainWindow::on_pushButtonClearAllRenFiles_clicked()
{
    ui->ListWidgetRenaming->clear();

    prSelItems.deleteAllItems();

    ui->renamedFilesInfo->setText(
                        "Files for renaming: " +
                        QString::number(prSelItems.countSelectedItems)
                    );
}

//REFACTOR
void MainWindow::on_pushButtonSelectAllDirFiles_clicked()
{
    switch (SIGNAL_LISTWIDGET)
    {
    case DEFAULT_LISTWIDGET_OUTPUT:
        prSelItems.showFolders(prDirectory.dirFolders, ui->ListWidgetRenaming);
        prSelItems.showFiles(prDirectory.dirFiles, ui->ListWidgetRenaming);

        ui->renamedFilesInfo->setText(
                        "Files for renaming: " +
                        QString::number(prSelItems.countSelectedItems)
                    );
        break;

    case ONLYFOLDERS_LISTWIDGET_OUTPUT:
        prSelItems.showFolders(prDirectory.dirFolders, ui->ListWidgetRenaming);

        ui->renamedFilesInfo->setText(
                        "Files for renaming: " +
                        QString::number(prSelItems.countSelectedItems)
                    );
        break;

    case ONLYFILES_LISTWIDGET_OUTPUT:
        prSelItems.showFiles(prDirectory.dirFiles, ui->ListWidgetRenaming);

        ui->renamedFilesInfo->setText(
                        "Files for renaming: " +
                        QString::number(prSelItems.countSelectedItems)
                    );
        break;
    }

}

#include 	<filesystem>
void MainWindow::on_renamePattern_textChanged(const QString &arg1)
{
    for (indexer i = 0; i < prSelItems.countSelectedItems; i++)
    {
        //QFile::rename(prSelItems.selectedItems[i], arg1 + QString::number(i));
        //std::filesystem::rename()
    }
    ui->ListWidgetRenaming->update();
}

