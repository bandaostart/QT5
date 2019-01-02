#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->GetTimeButton->setEnabled(false);

    connect(ui->serverNameLineEdit, SIGNAL(textChanged(QString)), this, SLOT(enableGetBtn()));
    connect(ui->portLineEdit, SIGNAL(textChanged(QString)), this, SLOT(enableGetBtn()));


    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readTime()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(showError(QAbstractSocket::SocketError)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enableGetBtn()
{
    ui->GetTimeButton->setEnabled(!ui->serverNameLineEdit->text().isEmpty() && !ui->portLineEdit->text().isEmpty());
}



void MainWindow::on_GetTimeButton_clicked()
{
    ui->GetTimeButton->setEnabled(false);
    time2u = 0;

    tcpSocket->abort();
    tcpSocket->connectToHost(ui->serverNameLineEdit->text(), ui->portLineEdit->text().toInt());
}



void MainWindow::readTime()
{
    QDataStream in(tcpSocket);

    in.setVersion(QDataStream::Qt_4_3);
    if(time2u == 0)
    {
        if (tcpSocket->bytesAvailable() < (int)sizeof(uint))
        {
            return;
        }

        in >> time2u;
    }

    ui->dateTimeEdit->setDateTime(QDateTime::fromTime_t(time2u));
    ui->GetTimeButton->setEnabled(true);
}



void MainWindow::showError(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
        case QAbstractSocket::RemoteHostClosedError:
        break;

        case QAbstractSocket::HostNotFoundError:
            QMessageBox::information(this, tr("时间服务客户端"), tr("主机不可达"));
        break;

        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::information(this, tr("时间服务客户端"), tr("连接被拒绝"));
        break;

        default:
            QMessageBox::information(this, tr("时间服务客户端"), tr("产生如下错误:%1.").arg(tcpSocket->errorString()));
        break;
    }
    ui->GetTimeButton->setEnabled(true);
}






















