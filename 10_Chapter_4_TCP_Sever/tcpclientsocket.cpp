#include "tcpclientsocket.h"

//建立关联
TcpClientSocket::TcpClientSocket(QObject *parent):QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(dateReceived()));

    connect(this, SIGNAL(disconnected()), this, SLOT(slotDiscoonected()));
}


//数据接收
void TcpClientSocket::dateReceived()
{
    while(bytesAvailable() > 0)
    {
        int length = bytesAvailable();
        char buf[1024];
        read(buf, length);

        QString msg = buf;
        emit updateClients(msg, length);
    }
}


// 断开连接
void TcpClientSocket::slotDiscoonected()
{
    emit disconnected(this->socketDescriptor());
}


