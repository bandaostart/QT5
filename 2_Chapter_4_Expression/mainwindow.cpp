#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /* E?:匹配0次或1次；
     * E+：匹配1次或多次；
     * E*：匹配0次或多次；
     * E[n]：匹配n次
     * E[n,]：至少匹配n次
     * E[,m]:最多匹配m次
     * E[n,m]:至少匹配n次，最多匹配m次
   */
    /* ^:表示在字符串开头进行匹配
     * $:表示在字符串结尾进行匹配
     * \b：表示单词边界
     * \B：非单词边界
     * (?=E):表示表达式后紧随E才匹配
     * (?!E):表示表达式后不紧跟随E才匹配
    */


    //"[A-Za-z]+[A-Za-z0-9]*"
    //+：表示“[A-Za-z]”至少出现一次，可以出现多次
    //*：表示[A-Za-z0-9]可以出现零次或多次

   QRegExp  regx("[a-zA-Z0-9]+$");
   QValidator *validator = new QRegExpValidator(regx, this);

   ui->lineEdit->setValidator( validator );

}

MainWindow::~MainWindow()
{
    delete ui;
}
