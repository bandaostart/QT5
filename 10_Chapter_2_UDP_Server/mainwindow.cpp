#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    port        = 5555;
    isStarted   = false;
    udpSocket   = new QUdpSocket(this);

    this->setWindowTitle(tr("UDP Server"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (!isStarted)
    {
        ui->pushButton->setText(tr("Stop"));
        isStarted = true;

        udpSocket->bind(QHostAddress::LocalHost, port);
        connect(udpSocket, SIGNAL(readyRead()), this, SLOT(Udp_ReceiveData()));
    }
    else
    {
        ui->pushButton->setText(tr("Start"));
        isStarted = false;

        disconnect(udpSocket, SIGNAL(readyRead()), this, SLOT(Udp_ReceiveData()));
        udpSocket->close();
    }
}

//udp数据接收
void MainWindow::Udp_ReceiveData()
{
    QHostAddress sender;
    quint16      senderport;

    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;

        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderport);
        ui->textEdit->insertPlainText(tr("Rx: "));
        ui->textEdit->insertPlainText(QString(datagram) + "; Sender IP: "+ sender.toString() + ";Port: " + QString("%1").arg(senderport)  +"\n");
        ui->textEdit->moveCursor(QTextCursor::End);
    }

    QString text = "I am Server";
    QByteArray datagram = text.toLocal8Bit();
    udpSocket->writeDatagram(datagram.data(), datagram.size(), sender, senderport);
}


void MainWindow::on_ClearButton_clicked()
{
    ui->textEdit->clear();
}
