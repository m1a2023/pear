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
    prBuffer.udispdir = inputPath;					//copying PATH into buffer

    ui->ListWidget->clear(); 						//clear a previous file output

    prDirInfo = infoFilesFolders(inputPath);	 	//fill the pearDirInfo

    prStatusbar.showSbQuantFileFolder (
                prDirInfo.FilesInfo.quantity,
                prDirInfo.FoldersInfo.quantity
        );

    prStatusbar.dirExistStatusbarShow(QDir(inputPath));

    switch (SIGNAL_LISTWIDGET)
    {
    case DEFAULT_LISTWIDGET_OUTPUT:
        for (indexer i = 0; i < prDirInfo.dirFolders.names.size(); i++)
            ui->ListWidget->addItem(prDirInfo.dirFolders.names[i]);

        for (indexer i = 0; i < prDirInfo.dirFiles.names.size(); i++)
            ui->ListWidget->addItem(prDirInfo.dirFiles.names[i]);

        break;

    case ONLYFOLDERS_LISTWIDGET_OUTPUT:
        for (indexer i = 0; i < prDirInfo.dirFolders.names.size(); i++)
            ui->ListWidget->addItem(prDirInfo.dirFolders.names[i]);
//        _foreach( (indexer),	(prDirInfo.dirFolders.names)	)
//        {
//            ui->ListWidget->addItem(prDirInfo.dirFolders.names[indexer]);
//        }
//        break;

    case ONLYFILES_LISTWIDGET_OUTPUT:
        for (indexer i = 0; i < prDirInfo.dirFiles.names.size(); i++)
            ui->ListWidget->addItem(prDirInfo.dirFiles.names[i]);

        break;
    }

    showStatusbar();

    prStatusbar.cleanWarnings();

    foreach (QListWidgetItem* item, ui->ListWidget->selectedItems())
    {
        //prSelItems.selectedItems.push_back(item->text());
        ui->ListWidgetRenaming->addItem(item);
    }
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

}

