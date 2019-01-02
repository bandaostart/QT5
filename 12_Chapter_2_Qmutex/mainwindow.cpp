#include "mainwindow.h"
#include "ui_mainwindow.h"

const int DataSize   = 1000;
const int BufferSize = 80;
int       buffer[BufferSize];         //首先生产者向buffer中写入数据，直到它到达终点，然后从起点重新开始覆盖已经存在的数据

QSemaphore freeBytes(BufferSize);     //freeBytes信号量控制可被生产者填充的缓冲区部分，被初始化为BufferSize(80), 表示程序一开始有BufferSize个缓冲区单元可被填充
QSemaphore usedBytes(0);              //usedBytes信号量控制可被消费者读取的缓冲区部分，被初始化为0，表示程序一开始时缓冲区中没有数据可供读取


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    producer = new Producer;
    consumer = new Consumer;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ReceiveText(QString str)
{
    ui->textEdit->insertPlainText(str);
    ui->textEdit->insertPlainText("\n");
}




void MainWindow::on_startButton_clicked()
{
   if ( !producer->isRunning())
   {
        producer->start();
   }

   if (!consumer->isRunning())
   {
        consumer->start();
        connect(consumer, SIGNAL(sendText(QString)), this, SLOT(ReceiveText(QString)));
   }
}

void MainWindow::on_stopButton_clicked()
{
    producer->terminate();
    producer->wait();

    disconnect(consumer, SIGNAL(sendText(QString)), this, SLOT(ReceiveText(QString)));
    consumer->terminate();
    consumer->wait();
}

void MainWindow::on_quitButton_clicked()
{
    ui->textEdit->clear();
}






//生产者
Producer::Producer()
{

}

void Producer::run()
{
    for (int i=0; i<DataSize; i++)
    {
        freeBytes.acquire();                       //生产者线程首先获取一个空闲单元，如果此时缓冲区被消费者尚未读取的数据填满
                                                   //对此函数的调用就会阻塞，直到消费者读取了这些数据
                                                   //acquire(n)函数用于获取n个资源，当没有足够的资源时调用者将被阻塞直到足够的可用资源
        buffer[i%BufferSize] = (i%BufferSize);     //一旦生产者获取了某个空闲单元，就使用当前的缓冲区单元序号填写这个缓冲区单元
        usedBytes.release();                       //调用该函数将可用资源加1，表示消费者此时可以读取这个刚刚填写的单元
                                                   //release(n)函数用于释放n个资源
    }
}



//消费者
Consumer::Consumer()
{

}


void Consumer::run()
{
    QString str = "";
    for (int i=1; i<DataSize; i++)
    {
        usedBytes.acquire();                         //消费者线程首先获取一个可被读取的单元，如果缓冲区中没有包含任何可以读取的数据
                                                     //对此函数的调用就会阻塞，直到生产者生产了一些数据

        str += QString("%1").arg(buffer[i%BufferSize], 2, 10, QLatin1Char(' '));
        str += " ";
        if ((i%15 == 0) && (i != 0))
        {
            str += "\n";
            emit sendText(str);
            str = "";
        }

        freeBytes.release();
    }
}


























