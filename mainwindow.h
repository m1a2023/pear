#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"


//      MY INCLUDES
#include 	"pearStructs.h"
#include 	"pearSignals.h"
#include	"pearClasses.h"

//      END INCLUDE


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
    pearDirInfo     prDirInfo;
//		files that will be copied
    pearFiles		prCopyFiles;
//		statusbar showing information
    PearStatusbar   prStatusbar;
//		string buffer
    pearBuffer      prBuffer;
//		signal for List Widget
    pearSignal      SIGNAL_LISTWIDGET;



private slots:
    //MY FUNCTIONS
    void showStatusbar();

    //END FUNCTIONS

    void on_labelDirectoryPath_textChanged(const QString &arg1);

    void on_radioButton_clicked();

    void on_radioButton_showFolders_clicked();

    void on_radioButton_showFiles_clicked();

    void on_ListWidget_itemDoubleClicked(QListWidgetItem *item);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
