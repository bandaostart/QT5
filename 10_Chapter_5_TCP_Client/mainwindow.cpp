#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    status = false;
    port   = 5555;

    ui->portlineEdit->setText(QString::number(port));
    ui->addrlineEdit->setText(tr("127.0.0.1"));
    ui->namelineEdit->setText(tr("Joly"));

    serverIP  = new QHostAddress();
    tcpSocket = new QTcpSocket(this);

    ui->sendButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}



//发送按键
void MainWindow::on_sendButton_clicked()
{
    if (ui->lineEdit->text() == "")
    {
        return;
    }

    QString msg = userName + ":" + ui->lineEdit->text();
    tcpSocket->write(msg.toLatin1(), msg.length());
    ui->lineEdit->clear();
}


//进入按键
void MainWindow::on_enterButton_clicked()
{
    if (!status)
    {
        QString ip = ui->addrlineEdit->text();
        if (!serverIP->setAddress(ip))
        {
            QMessageBox::information(this, tr("error"), tr("server ip address error"));

            return;
        }

        if (ui->namelineEdit->text() == "")
        {
            QMessageBox::information(this, tr("error"), tr("User name error!"));

            return;
        }

        userName  = ui->namelineEdit->text();

        connect(tcpSocket, SIGNAL(connected()), this, SLOT(slotConnected()));
        connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(slotDisconnected()));
        connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));

        tcpSocket->connectToHost(*serverIP, port);

        status = true;
    }
    else
    {
        int length = 0;
        QString msg = userName + tr(":Leave Chat Room");
        if ((length = tcpSocket->write(msg.toLatin1(), msg.length())) != msg.length())
        {
            return;
        }

        disconnect(tcpSocket, SIGNAL(connected()), this, SLOT(slotConnected()));
        disconnect(tcpSocket, SIGNAL(disconnected()), this, SLOT(slotDisconnected()));
        disconnect(tcpSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
        tcpSocket->disconnectFromHost();

        status = false;
    }
}



void MainWindow::slotConnected()
{
    ui->sendButton->setEnabled(true);

    ui->enterButton->setText(tr("离开"));

    int length = 0;
    QString msg = userName + tr(":Enter Chat Room");
    if ((length = tcpSocket->write(msg.toLatin1(),  msg.length())) != msg.length())
    {
        return;
    }
}


void MainWindow::slotDisconnected()
{
    ui->sendButton->setEnabled(false);
    ui->enterButton->setText(tr("进入聊天室"));
}



void MainWindow::dataReceived()
{
    QByteArray datagram;

    datagram.resize(tcpSocket->bytesAvailable());
    tcpSocket->read(datagram.data(), datagram.size());

    QString msg = datagram.data();

    ui->listWidget->addItem(msg.left(datagram.size()));
}


















