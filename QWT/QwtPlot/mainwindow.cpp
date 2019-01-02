#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //设置大小
    int width  = this->width()-10;
    int height = this->height()-50;
    ui->qwtPlot->move(0, 0);
    ui->qwtPlot->resize(width, height);

    //设置标题名称
    QwtText qwtText;
    qwtText.setText(QObject::trUtf8("QwtPlot"));         //设置标题名称

    QFont   font;                                        //设置字体
    font.setBold(true);                                  //设置粗体
    font.setItalic(true);                                //设置协调
    qwtText.setFont(font);

    qwtText.setColor(QColor(255,0,0));                   //设置字体颜色
    QBrush  brush(QColor(0,0,255));
    qwtText.setBackgroundBrush(brush);                   //设置标题背景色
    ui->qwtPlot->setTitle(qwtText);


    //设置坐标控制（左右前后）;使能坐标显示
    //参数含义:1,坐标轴；2，坐标最大值；3，坐标最小值；4，步进值
    ui->qwtPlot->setAxisScale(QwtPlot::yLeft,0,100,10);
    ui->qwtPlot->setAxisScale(QwtPlot::xBottom,0,100,10);
    ui->qwtPlot->setAxisScale(QwtPlot::yRight,0,100,10);
    ui->qwtPlot->setAxisScale(QwtPlot::xTop,0,100,10);

    ui->qwtPlot->enableAxis(QwtPlot::yLeft, true);
    ui->qwtPlot->enableAxis(QwtPlot::xBottom, true);
    ui->qwtPlot->enableAxis(QwtPlot::yRight,true);
    ui->qwtPlot->enableAxis(QwtPlot::xTop,true);


    //给每个坐标设置标题
    ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,QObject::trUtf8("Left"));
    ui->qwtPlot->setAxisTitle(QwtPlot::yRight,QObject::trUtf8("Right"));
    ui->qwtPlot->setAxisTitle(QwtPlot::xBottom,QObject::trUtf8("Bottom"));
    ui->qwtPlot->setAxisTitle(QwtPlot::xTop,QObject::trUtf8("Top"));


    //改写坐标标题字体
    QFont titleFont("宋体", 12);
    ui->qwtPlot->setAxisFont(QwtPlot::xBottom, titleFont);

    //新建显示条目
    curve1 = new QwtPlotCurve("Curve 1");
    curve2 = new QwtPlotCurve("Curve 2");
    curve3 = new QwtPlotCurve("Curve 3");


    //定时器
    for(int i=0; i<100; i++)
    {
      xTimerData.push_back(0);
      yTimerData.push_back(0);
    }
    timer = new QTimer(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//基本曲线
void MainWindow::on_QuXianButton_clicked()
{
    //数据x,y值保存
    QVector<double>   xData;
    QVector<double>   yData;

    for(int i=0; i<100; i++)
    {
      xData.push_back(0);
      yData.push_back(0);
    }
    for(int i =0;i<100;i++)
    {
        xData[i] = i;
        yData[i] = 20*sin(i*3.1415/10) + 50;
    }

    //创建曲线条目,并添加数据
    curve1->setData(xData, yData);

    //把曲线附加到qwtPlot上进行显示
    curve1->attach(ui->qwtPlot);

    ui->qwtPlot->replot();
    ui->qwtPlot->show();
}

//两个曲线
void MainWindow::on_QuXian2Button_clicked()
{
    //数据x,y值保存
    QVector<double>   xData;
    QVector<double>   yData;

    for(int i=0; i<100; i++)
    {
      xData.push_back(0);
      yData.push_back(0);
    }
    for(int i =0;i<100;i++)
    {
        xData[i] = i;
        yData[i] = 10*sin(i*3.1415/10) + 20;
    }

    //创建曲线条目,并添加数据
    curve2->setData(xData, yData);

    //把曲线附加到qwtPlot上进行显示
    curve2->attach(ui->qwtPlot);

    ui->qwtPlot->replot();
    ui->qwtPlot->show();
}


//设置画笔
void MainWindow::on_pushButton_3_clicked()
{
    //设置画笔
    QPen pen1 = QPen(QColor(255,0,0),2,Qt::SolidLine);
    curve1->setPen(pen1);

    //设置画笔
    QPen pen2 = QPen(QColor(0,0,255),2,Qt::DotLine);
    curve2->setPen(pen2);

    //设置画笔
    QPen pen3 = QPen(QColor(255,0,0),1,Qt::SolidLine);
    curve3->setPen(pen3);
}

//设置画刷
void MainWindow::on_BrushButton_clicked()
{
    //设置填充画刷
    QBrush brush1(QColor(128,128,128));
    curve1->setBrush(brush1);

    //设置填充画刷
    QBrush brush2(QColor(192,192,192));
    curve2->setBrush(brush2);
}

//设置网格
void MainWindow::on_GridButton_clicked()
{
    QwtPlotGrid* grid = new QwtPlotGrid();
    QPen pen = QPen(QColor(222,222,222),1);

    grid->setPen(pen);

    grid->attach(ui->qwtPlot);
}


//删除曲线
void MainWindow::on_DeleteButton_clicked()
{
    curve1->detach();

    curve2->detach();

    curve3->detach();

    ui->qwtPlot->replot();
}


//定时器
void MainWindow::Timer_Deal()
{
    timerCount++;
    if (timerCount >= 100)
    {
        timerCount = 0;
    }

    yTimerData.erase(yTimerData.begin(),yTimerData.begin()+1);
    yTimerData.push_back(20*sin(timerCount*3.1415/10) + 50);

    //创建曲线条目,并添加数据
    curve3->setData(xTimerData, yTimerData);

    //把曲线附加到qwtPlot上进行显示
    curve3->attach(ui->qwtPlot);

    ui->qwtPlot->replot();
}


//动态曲线
void MainWindow::on_DontTaiButton_clicked()
{
    for(int i=0;i<100;i++)
    {
        xTimerData[i] = i;
        yTimerData[i] = 20*sin(i*3.1415/10) + 50;
        timerCount    = i;
    }

    //创建曲线条目,并添加数据
    curve3->setData(xTimerData, yTimerData);

    //把曲线附加到qwtPlot上进行显示
    curve3->attach(ui->qwtPlot);

    ui->qwtPlot->replot();

    connect(timer, SIGNAL(timeout()), this, SLOT(Timer_Deal()));
    timer->start(100);
}
