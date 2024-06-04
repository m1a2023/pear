#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//     	INCLUDES
#include 	"ui_mainwindow.h"
#include 	<QMainWindow>
#include 	<QMessageBox>
#include 	"patternSettings.h"
#include     <QDebug>
#include     <QFileDialog>

#include 	"pearSignals.h"
#include    	"pearClasses.h"
#include 	"pearStructs.h"
#include 	<iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
//		current directory information
    PearDirectory		prDirectory;
//		statusbar showing information
    PearStatusbar   	    prStatusbar;
//		string buffer
    pearBuffer      	    prBuffer;
//		signal for List Widget
    pearSignal			SIGNAL_LISTWIDGET;
//		selected files
    PearSelectedItems 	prSelItems;
//		signal for Rename Pattern
    pearSignal			SIGNAL_RENAMEPATTERN;

private slots:
//		MY FUNCTIONS
    void showStatusbar();
    void setDefaultSignals();
    void setDefaultValue();

//    	QT FUNCTUONS
    void on_labelDirectoryPath_textChanged(const QString &arg1);
    void on_radioButton_clicked();
    void on_radioButton_showFolders_clicked();
    void on_radioButton_showFiles_clicked();
    void on_toolButton_clicked();
    void on_pushButtonClearAllRenFiles_clicked();
    void on_pushButtonSelectAllDirFiles_clicked();
    void on_ListWidget_doubleClicked(const QModelIndex &index);
    void on_ListWidgetRenaming_doubleClicked(const QModelIndex &index);
    void on_changeRenamingPattern_textEdited(const QString &arg1);

    void on_acceptRenaming_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

