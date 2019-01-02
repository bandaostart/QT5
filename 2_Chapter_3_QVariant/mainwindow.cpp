#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QVariant类类似于C++的联合(union)数据类型，能够保存很多Qt类型的值，包括QColor, QBrush等
    //也能够存放Qt的容器类型的值

    QVariant V(709);                      //声明一个变量并初始化为int
    QVariant W("How are You!");           //声明一个变量并初始化为一个字符串

    QMap<QString, QVariant> map;
    map["int"]     = 709;
    map["double"]  = 709.709;
    map["string"]  = "How Are You!";
    map["color"]   = QColor(255, 0, 0);

    //qDebug() :调用相应的转换函数并输出
    qDebug() <<map["int"]    << map["int"].toInt();
    qDebug() <<map["double"] << map["double"].toDouble();
    qDebug() <<map["string"] << map["string"].toString();
    qDebug() <<map["color"]  << map["color"].value<QColor>();


    //QVariant::type枚举的变量
    //QVariant::Invalid 无效类型
    //QVariant::Region Bitmap Bool Brush Size Char Color Cursor Date DateTime Double Font Icon
    //Time Line Palette List SizePolicy String Map StringList Point Pen Pixmap Rect Image
    //QVariant::UserType 用户自定义类型



}

MainWindow::~MainWindow()
{
    delete ui;
}
