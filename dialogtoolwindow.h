#ifndef DIALOGTOOLWINDOW_H
#define DIALOGTOOLWINDOW_H

#include 	<QDialog>
#include 	"ui_dialogtoolwindow.h"
#include	"mainwindow.h"

#define		DialogToolWindow		DialogToolwindow

namespace Ui {
class DialogToolwindow;
}

class DialogToolwindow : public QDialog
{
    Q_OBJECT

public:
    explicit DialogToolwindow(QWidget *parent = nullptr);
    ~DialogToolwindow();
//		for a new start directory
    QString 		newStartDirectory;

private slots:
    void on_lineEdit_textEdited(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::DialogToolwindow *ui;
};

#endif // DIALOGTOOLWINDOW_H
