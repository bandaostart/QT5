#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    port = 5555;
    ui->lineEdit->setText(QString::number(port));
}

MainWindow::~MainWindow()
{
    delete ui;
}



//创建聊天室
void MainWindow::on_pushButton_clicked()
{
    server = new Server(this, port);
    connect(server, SIGNAL(updateServer(QString,int)), this, SLOT(updateServer(QString,int)));
    ui->pushButton->setEnabled(false);
}


//用于更新服务器上的信息显示
void MainWindow::updateServer(QString msg, int length)
{
    ui->listWidget->addItem(msg.left(length));
}
