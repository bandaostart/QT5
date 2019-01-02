#include "timeserver.h"


TimeServer::TimeServer(QObject *parent): QTcpServer(parent)
{
    mainWindow = (MainWindow *)parent;
}


void TimeServer::incomingConnection(int socketDescriptor)
{
    TimeThread *thread = new TimeThread(socketDescriptor, 0);

    connect(thread, SIGNAL(finished()), mainWindow, SLOT(slotShow()));
    //将上述创建的线程结束消息函数finished()关联到线程自身的槽函数deleteLater（）用于结束线程，此操作中，因为信号是在同一个线程中的，
    //所以使用了直接连接方式，故最后一个参数可以省略而使用Qt的自动连接选择方式
    //由于工作线程中存在网络上网络时间，所以不能被外界线程销毁，这里使用了延迟销毁韩式deleteLater（）保证由工作线程自身销毁
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()), Qt::DirectConnection);

    //启动上述创建的线程
    thread->start();
}
