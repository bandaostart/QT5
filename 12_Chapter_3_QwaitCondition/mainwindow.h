#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>
#include <stdio.h>

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
    Consumer *consumerA;
    Consumer *consumerB;
};




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
