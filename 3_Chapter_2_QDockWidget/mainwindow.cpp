#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->setWindowTitle("DockWindows");

    //设置主窗体
    QTextEdit *te = new QTextEdit(this);
    te->setText(tr("Main Window"));
    te->setAlignment(Qt::AlignCenter);
    this->setCentralWidget(te);


    //设置停靠窗口 1
    QDockWidget *dock = new QDockWidget(tr("DockWidget1"), this);
    dock->setFeatures(QDockWidget::DockWidgetMovable);                          //设置可移动
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);    //设置可停靠的区域

    QTextEdit *te1 = new QTextEdit(this);
    te1->setText(tr("Window1, The dock widget can be moved between docks by the user" ""));

    dock->setWidget(te1);
    addDockWidget(Qt::RightDockWidgetArea, dock);


    //设置停靠窗口2
    dock = new QDockWidget(tr("DockWindow2"), this);
    dock->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable);    //可关闭，可浮动
    QTextEdit *te2 = new QTextEdit(this);
    te2->setText(tr("Window2, The dock widget can be detached from the main window," "and floated as an independent window ,and can be closed"));
    dock->setWidget(te2);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    //设置停靠窗口3
    dock = new QDockWidget(tr("DockWindow3"), this);
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures);    //设置全部特性
    QTextEdit *te3 = new QTextEdit(this);
    te3->setText(tr("Window3, The dock widget can be closed, moved, and floated"));
    dock->setWidget(te3);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

MainWindow::~MainWindow()
{
    delete ui;
}
