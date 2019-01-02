#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->label->setText("&Age");                          //& Qlabel设置快捷键 Alt+A
    ui->label->setBuddy(ui->lineEdit);                   //设置和QLable伙伴关系

    ui->label_2->setText("&Open");                       //快捷键 Alt+O
    ui->label_2->setBuddy(ui->lineEdit_2);

}

MainWindow::~MainWindow()
{
    delete ui;
}
