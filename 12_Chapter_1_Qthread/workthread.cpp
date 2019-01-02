#include "workthread.h"

WorkThread::WorkThread(int num)
{
    threadNum= num;
}


void WorkThread::run()
{
    QString str;
    while(true)
    {
        str = "ThreadNum: ";
        str += QString::number(threadNum);

        emit sendText(str);
        msleep(1000);
    }
}
