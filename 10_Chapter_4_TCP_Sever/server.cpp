#include "server.h"

Server::Server(QObject *parent, int port) :QTcpServer(parent)
{
    //QHostAddress::Null                       //表示一个空地址
    //QHostAddress::LocalHost                  //表示本地地址
    //QHostAddress::Broadcast                  //表示广播地址255,255,255,255
    //QHostAddress::Any                        //表示IPV4的任意地址0.0.0.0
    //QHostAddress::AnyIPv6                    //表示IPV6的任意地址

    listen(QHostAddress::Any, port);           //在指定的端口对任意地址进行监听
}

//当出现一个新的连接是，QTcpServer触发该函数，参数socketDescriptor指定了连接socket的描述符
void Server::incomingConnection(int socketDescriptor)
{
    //创建一个新的TcpClientSocket与客户端通信
    TcpClientSocket *tcpClientSocket = new TcpClientSocket(this);

    //连接TcpClientSocket的updateClients信号
    connect(tcpClientSocket, SIGNAL(updateClients(QString,int)), this, SLOT(updateClients(QString,int)));

    //连接TcpClientSocket的disconnected信号
    connect(tcpClientSocket, SIGNAL(disconnected(int)), this, SLOT(slotDisconnected(int)));

    //将新创建的TcpClientSocket的套接字描述符指定为参数
    tcpClientSocket->setSocketDescriptor(socketDescriptor);

    tcpClientSocketList.append(tcpClientSocket);
}



//将任意客户端发来的信息进行广播，保证聊天室的所有客户均能看到其他人的发言
void Server::updateClients(QString msg, int length)
{
    //发送updateServer信号，用来通知服务器对话框跟新相应的显示状态
    emit updateServer(msg, length);

    //实现信息的广播
    for(int i=0; i<tcpClientSocketList.count(); i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        QString str = "Admin: Receive";
        if (item->write(str.toLatin1(), str.length()) != length)
        {
            continue;
        }
    }
}



//断开TcpClientSocket对象删除的功能
void Server::slotDisconnected(int descriptor)
{
    for (int i=0; i<tcpClientSocketList.count(); i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);

        if (item->socketDescriptor() == descriptor)
        {
            tcpClientSocketList.removeAt(i);

            return;
        }
    }

    return;
}





































