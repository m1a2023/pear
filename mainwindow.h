#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include 	<QMainWindow>
#include 	"ui_mainwindow.h"
#include 	<QMessageBox>


//     	INCLUDES
#include 	"pearStructs.h"
#include 	"pearSignals.h"
#include	"pearClasses.h"
<<<<<<< Updated upstream

//      END INCLUDES
=======
#include 	"dialogtoolwindow.h"
>>>>>>> Stashed changes


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//		current directory information
    pearDirInfo     	prDirInfo;
//		files that will be copied
    pearFiles			prCopyFiles;
//		statusbar showing information
    PearStatusbar   	prStatusbar;
//		string buffer
    pearBuffer      	prBuffer;
//		signal for List Widget
<<<<<<< Updated upstream
    pearSignal      SIGNAL_LISTWIDGET;
//	 	vector of selected files
    PearSelItems	prSelItems;
=======
    pearSignal      	SIGNAL_LISTWIDGET;
//		selected files
    PearSelectedItems 	prSelItems;
>>>>>>> Stashed changes

private slots:
//		MY FUNCTIONS
    void showStatusbar();

//    	QT FUNCTUONS
    void on_labelDirectoryPath_textChanged(const QString &arg1);
    void on_radioButton_clicked();
    void on_radioButton_showFolders_clicked();
    void on_radioButton_showFiles_clicked();
    void on_ListWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_toolButton_clicked();
    void on_ListWidget_itemSelectionChanged();
    void on_pushButtonClearAllRenFiles_clicked();
    void on_pushButtonSelectAllDirFiles_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
