#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_labelDirectoryPath_textChanged(prBuffer.startDirectory);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_labelDirectoryPath_textChanged(const QString &inputPath)
{
    prBuffer.updateDisplayDirectory = inputPath;	//copying PATH into buffer

    ui->ListWidget->clear(); 						//clear a previous file output

    QDir currentDirectory = inputPath; 				//set a next directory

    prDirInfo = infoFilesFolders(currentDirectory);	//fill the pearDirInfo

    switch (SIGNAL_LISTWIDGET)
    {
    case DEFAULT_LISTWIDGET_OUTPUT:
        foreach (QString folder, prDirInfo.dirFolders.nameFolders)
            ui->ListWidget->addItem(folder);
        foreach (QString file, prDirInfo.dirFiles.nameFiles)
            ui->ListWidget->addItem(file);

        break;

    case ONLYFOLDERS_LISTWIDGET_OUTPUT:
        foreach (QString folder, prDirInfo.dirFolders.nameFolders)
            ui->ListWidget->addItem(folder);

        break;

    case ONLYFILES_LISTWIDGET_OUTPUT:
        foreach (QString file, prDirInfo.dirFiles.nameFiles)
            ui->ListWidget->addItem(file);

        break;
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
    ui->ListWidgetRenaming->addItem(item);
}


void MainWindow::on_ListWidget_itemClicked(QListWidgetItem *item)
{
    item->isSelected()
        ? ui->ListWidgetRenaming->addItem(item)
        : ui->ListWidget->addItem("no");
}

