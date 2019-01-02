#include "fileview.h"

FileView::FileView(QWidget *parent, Qt::WindowFlags f) : QDialog(parent, f)
{
    fileLineEdit    = new QLineEdit(tr("/"));
    fileListWidget  = new QListWidget;

    mainLayout  = new QVBoxLayout(this);
    mainLayout->addWidget(fileLineEdit);
    mainLayout->addWidget(fileListWidget);

    connect(fileLineEdit, SIGNAL(returnPressed()), this, SLOT(slotShow(QDir)));
    connect(fileListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(slotDirShow(QListWidgetItem*)));

    QString root = "/";
    QDir rootDir(root);
    QStringList string;
    string << "*";
    QFileInfoList list = rootDir.entryInfoList(string);
    showFileInfoList(list);
}

//显示目录下的文件
void FileView::slotShow(QDir dir)
{
    QStringList string;
    string << "*";
    QFileInfoList list = dir.entryInfoList(string, QDir::AllEntries, QDir::DirsFirst); //按照某种过滤方式获得文件
    showFileInfoList(list);
}


//实现双击进入下一级目录，或者点击"..."返回上一级目录，顶部的编辑框显示当前所在的目录路径，列表中显示该目录下的所有文件
void FileView::showFileInfoList(QFileInfoList list)
{
    fileListWidget->clear();                                          //清空列表控件
    for (int i=0; i<list.count(); i++)                                //依次从QFileInfoList对象中取出所有项，按目录和文件两种方式加入列表控件中
    {
        QFileInfo tempFileInfo = list.at(i);
        if (tempFileInfo.isDir())
        {
            QIcon icon(":/image/dir.png");
            QString fileName     = tempFileInfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(icon, fileName);
            fileListWidget->addItem(tmp);
        }
        else if (tempFileInfo.isFile())
        {
            QIcon icon(":/image/file.png");
            QString fileName     = tempFileInfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(icon, fileName);
            fileListWidget->addItem(tmp);
        }
    }
}


//根据用户的选择显示下一级目录的所有文件
void FileView::slotDirShow(QListWidgetItem *item)
{
    QString str = item->text();                      //将下一级的目录名保存在str中
    QDir    dir;
    dir.setPath(fileLineEdit->text());               //设置QDir对象的路径为当年目录路径
    dir.cd(str);                                     //根据下一级目录名重新设置QDir对象的路径
    fileLineEdit->setText(dir.absolutePath());       //刷新显示当前的目录路径
    slotShow(dir);
}























