#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    port        = 7755;
    isStarted   = false;
    udpSocket   = new QUdpSocket(this);

    timer       = new QTimer(this);
    this->setWindowTitle(tr("UDP Client"));
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

        timer->start(1000);
        connect(timer, SIGNAL(timeout()), this, SLOT(Udp_SendData()));
    }
    else
    {
        ui->pushButton->setText(tr("Start"));
        isStarted = false;

        timer->stop();
        disconnect(timer, SIGNAL(timeout()), this, SLOT(Udp_SendData()));

        disconnect(udpSocket, SIGNAL(readyRead()), this, SLOT(Udp_ReceiveData()));
        udpSocket->close();
    }
}



void MainWindow::Udp_ReceiveData()
{
    QHostAddress sender;
    quint16      senderport;
    QByteArray   datagram;
    qint64       length;

    while(udpSocket->hasPendingDatagrams())
    {
        datagram.resize(udpSocket->pendingDatagramSize());
        length = udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderport);
        if (length > 0)
        {
            ui->textEdit->insertPlainText(tr("Rx: "));
            ui->textEdit->insertPlainText(QString(datagram) + " Sender IP: "+ sender.toString() + ";Port: " + QString::number(senderport)  +"\n");
            ui->textEdit->moveCursor(QTextCursor::End);
        }
    }
}


void MainWindow::Udp_SendData()
{
    QHostAddress sender;
    sender.setAddress(QString("127.0.0.1"));
    quint16 senderport = 5555;

    QString text = "I am Client";
    QByteArray datagram = text.toLocal8Bit();
    udpSocket->writeDatagram(datagram.data(), datagram.size(), sender, senderport);
}


void MainWindow::on_ClearButton_clicked()
{
    ui->textEdit->clear();
}
