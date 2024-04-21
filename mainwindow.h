#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"


//      MY INCLUDES
#include "pearStructs.h"
#include "pearSignals.h"

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

    pearDirInfo     prDirInfo;

    pearStatus   	prStatusbar;

    pearBuffer      prBuffer;

    pearSignal      SIGNAL_LISTWIDGET;

private slots:
    //MY FUNCTIONS

    //END FUNCTIONS

    void on_labelDirectoryPath_textChanged(const QString &arg1);

    void on_radioButton_clicked();

    void on_radioButton_showFolders_clicked();

    void on_radioButton_showFiles_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
