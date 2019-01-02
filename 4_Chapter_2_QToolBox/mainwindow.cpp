#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBox>
#include <QVBoxLayout>
#include <QToolButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->toolBox->setItemText(0, tr("我的好友"));
    ui->toolBox->setItemText(1, tr("陌生人"));
    ui->toolBox->setCurrentIndex(1);

    QToolButton *Toolbutton1 = new QToolButton(ui->toolBox->widget(0));
    Toolbutton1->setText(tr("张三"));                                          //按钮名称
    Toolbutton1->setIcon(QPixmap(":/image/read_settings.png"));               //按钮图标
    Toolbutton1->setIconSize(QPixmap(":/image/read_settings.png").size());    //按钮大小
    Toolbutton1->setAutoRaise(true);                                          //当鼠标离开时，按钮自动恢复为弹出状态
    Toolbutton1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);            //设置图标位置

    QToolButton *Toolbutton2 = new QToolButton(ui->toolBox->widget(1));
    Toolbutton2->setText(tr("李四"));                                          //按钮名称
    Toolbutton2->setIcon(QPixmap(":/image/network_perspective_selected.png"));               //按钮图标
    Toolbutton2->setIconSize(QPixmap(":/image/network_perspective_selected.png").size());    //按钮大小
    Toolbutton2->setAutoRaise(true);                                          //当鼠标离开时，按钮自动恢复为弹出状态
    Toolbutton2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);            //设置图标位置





    QVBoxLayout *boxlayout = new QVBoxLayout();
    boxlayout->addWidget(ui->toolBox);
    ui->centralWidget->setLayout(boxlayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
