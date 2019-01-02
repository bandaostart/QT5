#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <QObject>
#include <QTcpServer>
#include "timethread.h"
#include "mainwindow.h"

class MainWindow;
class TimeServer : public QTcpServer
{
    Q_OBJECT

public:
    TimeServer(QObject *parent);
    MainWindow *mainWindow;

protected:
    void incomingConnection(int socketDescriptor);   //重写此虚函数，这个函数在TCP服务端有新的连接是被调用
};

#endif // TIMESERVER_H
