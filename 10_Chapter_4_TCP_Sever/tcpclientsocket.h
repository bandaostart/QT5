#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT                                                        //创建信号和槽的关系

public:
    TcpClientSocket(QObject *parent = 0);

signals:
    void updateClients(QString, int);
    void disconnected(int);

protected slots:
    void dateReceived();
    void slotDiscoonected();
};

#endif // TCPCLIENTSOCKET_H
