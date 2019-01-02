#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Widget = new QWidget(this);

    this->setWindowTitle(tr("StackedWidget"));
    List = new QListWidget(Widget);
    List->insertItem(0, tr("Window1"));
    List->insertItem(1, tr("Window2"));
    List->insertItem(2, tr("Window3"));

    Label1 = new QLabel(tr("WindowTest1"));
    Label2 = new QLabel(tr("WindowTest2"));
    Label3 = new QLabel(tr("WindowTest3"));

    Stack = new QStackedWidget(Widget);
    Stack->addWidget(Label1);
    Stack->addWidget(Label2);
    Stack->addWidget(Label3);

    QHBoxLayout *mainLayout = new QHBoxLayout(Widget);
    mainLayout->setMargin(5);                                 //设定对话框的边距为5
    mainLayout->setSpacing(5);                                //设置各个控件之间的间距为5
    mainLayout->addWidget(List);                              //设定可伸缩控件
    mainLayout->addWidget(Stack, 0, Qt::AlignHCenter);
    mainLayout->setStretchFactor(List, 1);
    mainLayout->setStretchFactor(Stack, 3);

    connect(List, SIGNAL(currentRowChanged(int)), Stack, SLOT(setCurrentIndex(int)));

    this->setCentralWidget(Widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
