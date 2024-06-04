#include    "mainwindow.h"
#include    <QIcon>
#include    <QApplication>

int main(int argc, char *argv[])
{
    QApplication pearApplication(argc, argv);
    pearApplication.setWindowIcon(QIcon(":/pearIconv0.2.png"));
    MainWindow mainWindowPear;
    mainWindowPear.show();
    return pearApplication.exec();
}
