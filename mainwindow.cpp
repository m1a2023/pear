#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setDefaultValue();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_labelDirectoryPath_textChanged(const QString &inputPath)
{
    prBuffer.udispdir = inputPath;							//copying PATH into buffer

    ui->ListWidget->clear(); 								//clear a previous file output

    prDirectory.clearDirectoryInformation();

    prDirectory.getDirectoryInformation(inputPath);	 		//fill the pearDirInfo

    prStatusbar.setSbQuantFileFolder (
                        prDirectory.FilesInfo.quantity,
                        prDirectory.FoldersInfo.quantity
                    );

    if (prStatusbar.dirExistStatusbarShow(QDir(inputPath)))
    {
        switch (SIGNAL_LISTWIDGET)
        {
        case DEFAULT_LISTWIDGET_OUTPUT:
            prDirectory.showFilesAndFolders(ui->ListWidget);
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


void MainWindow::on_toolButton_clicked()
{
    QString newFile = QFileDialog::getOpenFileName(this, "Open File",
                                                   "", "Files(*.*)");
    QFileInfo file(newFile);

    prBuffer.udispdir = file.canonicalPath();
    ui->labelDirectoryPath->setText(prBuffer.udispdir);
    on_labelDirectoryPath_textChanged(prBuffer.udispdir);

    prSelItems.addItem(file);
    prSelItems.display(ui->ListWidgetRenaming);
}


void MainWindow::on_pushButtonClearAllRenFiles_clicked()
{
    ui->ListWidgetRenaming->clear();

    prSelItems.deleteAllItems();

    prSelItems.showCountItems(ui->renamedFilesInfo);
}


void MainWindow::on_pushButtonSelectAllDirFiles_clicked()
{
    ui->ListWidgetRenaming->clear();

    switch (SIGNAL_LISTWIDGET)
    {
    case DEFAULT_LISTWIDGET_OUTPUT:
        prSelItems.addAllItems(prDirectory.dirFolders.files,
                               prDirectory.dirFiles.files);
        break;

    case ONLYFOLDERS_LISTWIDGET_OUTPUT:
        prSelItems.addAllItems(prDirectory.dirFolders.files);
        break;

    case ONLYFILES_LISTWIDGET_OUTPUT:
        prSelItems.addAllItems(prDirectory.dirFiles.files);
        break;
    }

    prSelItems.showCountItems(ui->renamedFilesInfo);
    prSelItems.display(ui->ListWidgetRenaming);
}


void MainWindow::on_ListWidget_doubleClicked(const QModelIndex &index)
{
    QFileInfo curFile = prDirectory.mergeFiles().files[index.row()];

    prSelItems.addItem(curFile);

    ui->ListWidgetRenaming->clear();

    prSelItems.showCountItems(ui->renamedFilesInfo);
    prSelItems.display(ui->ListWidgetRenaming);
}


void MainWindow::on_ListWidgetRenaming_doubleClicked(const QModelIndex &index)
{
    prSelItems.deleteItem(index.row());
    ui->ListWidgetRenaming->clear();

    prSelItems.display(ui->ListWidgetRenaming);
}


void MainWindow::on_changeRenamingPattern_textEdited(const QString &newPattern)
{
    prBuffer.renamePattern = newPattern;
}


void MainWindow::on_acceptRenaming_clicked()
{
    prSelItems.renameFile(prSelItems.files[0].absoluteFilePath(),
                           prBuffer.udispdir + "/" + prBuffer.renamePattern);
    ui->ListWidget->clear();
    on_labelDirectoryPath_textChanged
            (prBuffer.updateDisplayDirectory);
}

