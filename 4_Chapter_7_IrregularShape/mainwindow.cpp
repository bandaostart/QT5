#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBitmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix;
    pix.load(":/image/tools_header_feedback.png", 0, Qt::AvoidDither | Qt::ThresholdAlphaDither | Qt::ThresholdAlphaDither);
    this->resize(pix.size());                   //重新定义窗体尺寸
    this->setMask(QBitmap(pix.mask()));         //为调用它的控件增加一个遮罩，遮住所选区域以外的部分使看起来是透明的
}

MainWindow::~MainWindow()
{
    delete ui;
}
