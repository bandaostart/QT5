#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <QMap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //QList<QToolBar> list;         这样定义编译会出错，因为这些类（QObject及其他的子类）没有复制构造函数和赋值操作运算符
    //QList<QToolBar *> list        只能这样定义
    //QHash<QString, QList<double>> 容器类可以嵌套

    QList<QString> list;

    list << "This is a test string";
    ui->textEdit->insertPlainText(list[0]);


    QList<int> list_num;             //容器
    list_num << 1 << 2 << 3 << 4 << 5;
    QListIterator<int> i(list_num);  //迭代器

    //QListIterator<T>::hasNext() 检查当前迭代器以后是否有列表项
    //QlistIterator<T>::next()函数进行遍历,next()函数将会跳过下一个列表项
    //QlistIterator<T>::toBack()将迭代点移动到最后一个列表项的后面
    //QListIterator<T>::hasPrevious():检查当前迭代点之前是否具有列表项
    //QListIterator<T>::previous();返回前一个列表项的内容并将迭代点移动到前一个列表项之前
    //QListIterator<T>::toFront():移动迭代点到列表的前端（第一个列表项的前面）
    //QListIterator<T>::peekNext():返回下一个列表项，但不移动迭代点
    //QListIterator<T>::peekPrevious():返回前一个列表项，但不移动迭代点
    //QListIterator<T>::findNext():查找迭代点，此时迭代点位于匹配列表项的后面
    //QListIterator<T>::findPrevious():查找迭代点，向前查找
    //QListIteraotr<T>::是只读迭代器，它不能完成列表项的插入和删除操作
    //QMutableListIterator<T>::读写迭代器，包含insert() remove()函数
    for (;i.hasNext();)
    {
        ui->textEdit->insertPlainText("\r\n");
        ui->textEdit->insertPlainText(QString::number(i.next()));
    }

    QList<int> list_num2;
    QMutableListIterator<int> i2(list_num2);

    for (int j=0; j<10; j++)
    {
        i2.insert(j);
    }
    for (i2.toFront(); i2.hasNext();)
    {
        ui->textEdit->insertPlainText("\r\n");
        ui->textEdit->insertPlainText(QString::number(i2.next()));
    }

    for (i2.toBack(); i2.hasPrevious();)
    {
        if (i2.previous() % 2 == 0)
        {
            i2.remove();
        }
        else
        {
            i2.setValue(i2.peekNext()*10);
        }
    }

    for (i2.toFront(); i2.hasNext();)
    {
        ui->textEdit->insertPlainText("\r\n");
        ui->textEdit->insertPlainText(QString::number(i2.next()));
    }



    //STL标准风格的迭代器，
    QList <int> List_Num3;
    for (int j=0; j<10; j++)
    {
        List_Num3.insert(List_Num3.end(), j);
    }

    QList<int>::iterator i3;
    for (i3=List_Num3.begin(); i3!= List_Num3.end(); ++i3)
    {
        ui->textEdit->insertPlainText("\r\n");
        ui->textEdit->insertPlainText(QString::number((*i3)*100));
    }

    QList<int>::const_iterator i4;
    for (i4=List_Num3.constBegin(); i4 !=List_Num3.constEnd(); ++i4)
    {
        ui->textEdit->insertPlainText("\r\n");
        ui->textEdit->insertPlainText(QString::number((*i4)*1000));
    }


    //QMap<Key, T>, QMultiMap<Key, T>;  QMapIterator<Key, T>:只读迭代器;  QMutableMapIterator<Key, T>:读写迭代器
    //QHash<Key, T>,QMultiHash<Key, T>; QHashIterator<Key, T>:只读迭代器; QMutableHashIterator<Key, T>:读写迭代器
    QMap <QString, QString> map;

    map.insert("beijing", "111");
    map.insert("shanghai", "021");
    map.insert("nanjing", "025");


    QMutableMapIterator<QString, QString> mim(map);
    if (mim.findNext("111"))
    {
        mim.setValue("010");
    }

    //只读迭代器要在此处声明
    QMapIterator<QString, QString> im(map);
    for (;im.hasNext();)
    {
        ui->textEdit->insertPlainText("\r\n");
        ui->textEdit->insertPlainText(im.key() + " " + im.next().value());
    }


    //STL 标准风格操作
    QMap<QString, QString> map2;

    map2.insert("beijing", "111");
    map2.insert("shanghai", "021");
    map2.insert("jinan", "0531");

    QMap<QString, QString>::iterator mim2;
    mim2 = map2.find("beijing");
    if (mim2 != map2.end())
    {
        mim2.value() = "010";
    }

    QMap<QString, QString>::const_iterator im2;
    for(im2=map2.constBegin(); im2 != map2.constEnd(); ++im2)
    {
        ui->textEdit->insertPlainText("\r\n");
        ui->textEdit->insertPlainText(im2.key() + " " + im2.value());
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}






















