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
    //copying PATH into buffer
    prBuffer.updateDisplayDirectory = inputPath;

    //clear a previous file output
    ui->ListWidget->clear();

    //set a next directory
    QDir currentDirectory = inputPath;

    prDirInfo = infoFilesFolders(currentDirectory);

    switch (SIGNAL_LISTWIDGET) 	//NOTE
    {							//make it easier
    case DEFAULT_LISTWIDGET_OUTPUT:
        foreach (QString folder, prDirInfo.DirFolders)
            ui->ListWidget->addItem(folder);
        foreach (QString file, prDirInfo.DirFiles)
            ui->ListWidget->addItem(file);

        break;

    case ONLYFOLDERS_LISTWIDGET_OUTPUT:
        foreach (QString folder, prDirInfo.DirFolders)
            ui->ListWidget->addItem(folder);

        break;

    case ONLYFILES_LISTWIDGET_OUTPUT:
        foreach (QString file, prDirInfo.DirFiles)
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

