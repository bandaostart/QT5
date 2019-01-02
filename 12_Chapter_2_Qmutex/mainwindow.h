#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>
#include <QMutexLocker>
#include <QThread>
#include <stdio.h>
#include <QCoreApplication>
#include <QSemaphore>

//前置类型声明只能作为指针或者引用，不能定义类的对象，所以也不能调用对象中的方法
class Producer;
class Consumer;

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void ReceiveText(QString str);

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_quitButton_clicked();

private:
    Ui::MainWindow *ui;

    Producer *producer;
    Consumer *consumer;
};




class KEY
{
public:
    KEY() {key = 0;}
    int creatKey() {mutex.lock(); ++key; return key; mutex.unlock();}           //使用mutex进行互斥操作，但是unlock()却在return之后
    int value()    {mutex.lock();        return key; mutex.unlock();}           //从而导致unlock()操作永远无法执行

private:
    int    key;
    QMutex mutex;
};



class NewKEY
{
public:
    NewKEY() {key = 0;}
    int creatKey() { QMutexLocker locker(&mutex); ++key; return key;}           //QMutexLocker类可以简化互斥量的处理
    int value()    { QMutexLocker locker(&mutex);        return key;}           //lokcer()函数作为局部变量会在函数退出时结束其作用域，从而自动对互斥量mutex解锁

private:
    int    key;
    QMutex mutex;
};




//信号量的生产者和消费者
class Producer: public QThread
{
    Q_OBJECT

public:
    Producer();
    void run();
};


class Consumer: public QThread
{
    Q_OBJECT

public:
    Consumer();
    void run();

signals:
    void sendText(QString str);

};















































#endif // MAINWINDOW_H
