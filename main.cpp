#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindowPear;
    mainWindowPear.show();
    return a.exec();
}
