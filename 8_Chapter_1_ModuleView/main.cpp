#include "mainwindow.h"
#include <QApplication>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QItemSelectionModel>

#include <QDirModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QSplitter>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDirModel   model;                                       //新建一个对象，为数据访问做准备，QDirModel的创建还可以设置过滤器，只有符合条件的文件或目录才被访问
                                                             //QDirModel类继承自QAbstracItemModel类，为访问本地文件系统提供数据模型，它提供 新建，删除，创建
                                                             //目录等一系列与文件操作相关的函数
    QTreeView   tree;                                        //三种不同的view对象
    QListView   list;
    QTableView  table;

    tree.setModel(&model);                                       //设置view对象的model为QDirModel
    list.setModel(&model);
    table.setModel(&model);

    tree.setSelectionMode(QAbstractItemView::MultiSelection);    //设置QTreeView对象的选择方式为多选
    list.setSelectionModel(tree.selectionModel());               //设置与QListView相同的对象
    table.setSelectionModel(tree.selectionModel());
                                                                 //为了实现双击QTeeView对象中的某个目录时，QList QTable显示目录下的所有文件和目录
    QObject::connect(&tree, SIGNAL(doubleClicked(QModelIndex)), &list, SLOT(setRootIndex(QModelIndex)));
    QObject::connect(&tree, SIGNAL(doubleClicked(QModelIndex)), &table, SLOT(setRootIndex(QModelIndex)));

    QSplitter *splitter = new QSplitter;
    splitter->addWidget(&tree);
    splitter->addWidget(&list);
    splitter->addWidget(&table);
    splitter->show();

    return a.exec();
}
