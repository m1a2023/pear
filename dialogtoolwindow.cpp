#include "dialogtoolwindow.h"

DialogToolwindow::DialogToolwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogToolwindow)
{
    ui->setupUi(this);

    connect(ui->lineEdit, &QLineEdit::textEdited, this, [=](const QString & text){
        MainWindow* mainWindow = qobject_cast<MainWindow *> (parent);
        if (mainWindow)
            mainWindow->prBuffer.startDirectory = text;
    });
}


DialogToolwindow::~DialogToolwindow()
{
    delete ui;
}


void DialogToolwindow::on_lineEdit_textEdited(const QString &newHomePath)
{
    //MainWindow::prBuffer.startDirectory = newHomePath;
    newStartDirectory = newHomePath;
}


void DialogToolwindow::on_pushButton_2_clicked()
{
    //prBuffer = newStartDirectory

}

