#ifndef SERVER_H
#define SERVER_H
#include <QObject>
#include <QTcpServer>
#include <QList>
#include "tcpclientsocket.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject *parent = 0, int port = 0);
    QList<TcpClientSocket *> tcpClientSocketList;                       //用来保存与每一个客户端连接的TcpClientSocket;

signals:
    void updateServer(QString, int);

public slots:
    void updateClients(QString, int);
    void slotDisconnected(int);

protected:
    void incomingConnection(int socketDescriptor);
};

#endif // SERVER_H
