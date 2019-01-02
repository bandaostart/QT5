#include "mainwindow.h"
#include "ui_mainwindow.h"

const int DataSize   = 1000;
const int BufferSize = 80;
int       buffer[BufferSize];             //首先生产者向buffer中写入数据，直到它到达终点，然后从起点重新开始覆盖已经存在的数据

QWaitCondition bufferEmpty;
QWaitCondition bufferFull;

QMutex mutex;                             //使用互斥量保证对线操作的原子性
int    numUsedBytes = 0;                  //变量numUsedBytes表示存在多少可用字节
int    rIndex       = 0;                  //启动两个消费线程，并且这两个线程读取同一个缓冲区，为了不重复读取，设置全局变量rIndex用于指示当前所读取缓冲区位置


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    producer  = new Producer;
    consumerA = new Consumer;
    consumerB = new Consumer;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
    producer->start();

    connect(consumerA, SIGNAL(sendText(QString)), this, SLOT(ReceiveText(QString)));
    consumerA->start();

    //connect(consumerB, SIGNAL(sendText(QString)), this, SLOT(ReceiveText(QString)));
    //consumerB->start();

}

void MainWindow::on_stopButton_clicked()
{
    producer->terminate();
    producer->wait();

    disconnect(consumerA, SIGNAL(sendText(QString)), this, SLOT(ReceiveText(QString)));
    consumerA->terminate();
    consumerA->wait();

    disconnect(consumerB, SIGNAL(sendText(QString)), this, SLOT(ReceiveText(QString)));
    consumerB->terminate();
    consumerB->wait();

}

void MainWindow::on_quitButton_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::ReceiveText(QString str)
{
    ui->textEdit->insertPlainText(str);
    ui->textEdit->insertPlainText("\n");
}





//生产者和消费者
Producer::Producer()
{

}

void Producer::run()
{
    for (int i=0; i<DataSize; i++)              //for循环中的所有语句都需要使用互斥量加以保护，以保证其操作的原子性
    {
        mutex.lock();

        if (numUsedBytes == BufferSize)         //首先检查缓冲区是否已经填满
        {
            bufferEmpty.wait(&mutex);           //如果缓冲区已经填满，则等待"缓冲区有空位", wait()函数将互斥量解锁并在等待
        }

        buffer[i%BufferSize] = numUsedBytes;    //如果缓冲区未填满，写入一个整数值
        ++numUsedBytes;                         //增加numUsedBytes变量
        bufferFull.wakeAll();                   //最后唤醒等待"缓冲区有可用数据"(bufferEmpty变量)条件为真的线程

        mutex.unlock();
    }
}


Consumer::Consumer()
{

}

void Consumer::run()
{
    QString str;

    forever
    {
        mutex.lock();

        if (numUsedBytes == 0)
        {
            bufferFull.wait(&mutex);                   //当缓冲区中无数据时，等待"缓冲区有可用数据"
        }

//        str = "ThreadID:";
//        threadId = currentThreadId();
//        str += QString("%1").arg((int)(*threadId), 10);
        str = "  rIndex:";
        str += QString::number(rIndex);
        str += "  Data:";
        str += QString::number(buffer[rIndex]);
        emit sendText(str);

        ++rIndex;
        rIndex = rIndex%BufferSize;                    //rIndex变量循环加1
        --numUsedBytes;                                //numUserBytes变量减1，即可用的数据减1
        bufferEmpty.wakeAll();                         //唤醒等待"缓冲区有空位"(bufferEmpty变量)条件的生产者线程

        mutex.unlock();
    }
}























