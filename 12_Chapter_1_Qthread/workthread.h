#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QThread>
#include <QObject>

class WorkThread : public QThread
{
    Q_OBJECT
public:
    WorkThread(int num);
protected:
    void run();

signals:
    void sendText(QString str);

private:
    int threadNum;


};

#endif // WORKTHREAD_H
