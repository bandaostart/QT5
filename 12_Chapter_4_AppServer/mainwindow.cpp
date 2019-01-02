#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    count = 0;
    timeServer = new TimeServer(this);


    if (!timeServer->listen())
    {
        QMessageBox::critical(this, tr("多线程时间服务器"),tr("无法启动服务器: %1.").arg(timeServer->errorString()));

        close();

        return;
    }
    ui->port->setText(QString::number(timeServer->serverPort()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotShow()
{
    ui->nums->setText(QString::number(++count));
}















