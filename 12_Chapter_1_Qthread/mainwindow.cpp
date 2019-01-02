#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//开始
void MainWindow::on_startButton_clicked()
{
    for (int i=0; i<MAXSIZE; i++)
    {
        workThread[i] = new WorkThread(i);
        connect(workThread[i], SIGNAL(sendText(QString)), this, SLOT(ReceiveText(QString)));
    }

    for (int i=0; i<MAXSIZE; i++)
    {
        workThread[i]->start();
    }
    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(true);
}

//停止
void MainWindow::on_stopButton_clicked()
{
    for (int i=0; i<MAXSIZE; i++)
    {
        workThread[i]->terminate();             //terminate()函数并不会立刻终止这个线程，该线程何时终止取决于操作系统调度策略
        workThread[i]->wait();
    }
    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(false);
}

//退出
void MainWindow::on_quitButton_clicked()
{
    ui->textEdit->clear();
}


void MainWindow::ReceiveText(QString str)
{
    mutex.lock();
    ui->textEdit->insertPlainText(str);
    ui->textEdit->insertPlainText("\n");
    ui->textEdit->moveCursor(QTextCursor::End);
    mutex.unlock();
}
