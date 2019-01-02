#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSplitter>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置字体
    QFont font("ZYSong18030", 12);
    this->setFont(font);

    //设置主窗口分割
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal, this);
    QTextEdit *textLeft     = new QTextEdit(QObject::tr("Left Widget"), splitterMain);
    textLeft->setAlignment(Qt::AlignCenter);

    //设置右分割窗体
    QSplitter *splitterRight = new QSplitter(Qt::Vertical, splitterMain);
    QTextEdit *textUp        = new QTextEdit(QObject::tr("Top Widget"), splitterRight);
    textUp->setAlignment(Qt::AlignCenter);

    QTextEdit *textBottom    = new QTextEdit(QObject::tr("Bottom Widget"), splitterRight);
    textBottom->setAlignment(Qt::AlignCenter);

    //设置拉伸比例
    splitterMain->setStretchFactor(1,1);


    this->setCentralWidget(splitterMain);


}

MainWindow::~MainWindow()
{
    delete ui;
}
