#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&timer, SIGNAL(timeout()), this, SLOT(Timer_Deal()));
    timer.start(1000);

    ui->lcdNumber->setDigitCount(8);
    ui->lcdNumber->display("00:00:00");
    
    //×èÈûÑÓÊ±
    QTime _Timer = QTime::currentTime();
    QTime _NowTimer;
    do{
        _NowTimer=QTime::currentTime();
    }while (_Timer.msecsTo(_NowTimer)<=1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Timer_Deal()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    ui->lcdNumber->display(text);
}
