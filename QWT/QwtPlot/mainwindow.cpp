#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //���ô�С
    int width  = this->width()-10;
    int height = this->height()-50;
    ui->qwtPlot->move(0, 0);
    ui->qwtPlot->resize(width, height);

    //���ñ�������
    QwtText qwtText;
    qwtText.setText(QObject::trUtf8("QwtPlot"));         //���ñ�������

    QFont   font;                                        //��������
    font.setBold(true);                                  //���ô���
    font.setItalic(true);                                //����Э��
    qwtText.setFont(font);

    qwtText.setColor(QColor(255,0,0));                   //����������ɫ
    QBrush  brush(QColor(0,0,255));
    qwtText.setBackgroundBrush(brush);                   //���ñ��ⱳ��ɫ
    ui->qwtPlot->setTitle(qwtText);


    //����������ƣ�����ǰ��;ʹ��������ʾ
    //��������:1,�����᣻2���������ֵ��3��������Сֵ��4������ֵ
    ui->qwtPlot->setAxisScale(QwtPlot::yLeft,0,100,10);
    ui->qwtPlot->setAxisScale(QwtPlot::xBottom,0,100,10);
    ui->qwtPlot->setAxisScale(QwtPlot::yRight,0,100,10);
    ui->qwtPlot->setAxisScale(QwtPlot::xTop,0,100,10);

    ui->qwtPlot->enableAxis(QwtPlot::yLeft, true);
    ui->qwtPlot->enableAxis(QwtPlot::xBottom, true);
    ui->qwtPlot->enableAxis(QwtPlot::yRight,true);
    ui->qwtPlot->enableAxis(QwtPlot::xTop,true);


    //��ÿ���������ñ���
    ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,QObject::trUtf8("Left"));
    ui->qwtPlot->setAxisTitle(QwtPlot::yRight,QObject::trUtf8("Right"));
    ui->qwtPlot->setAxisTitle(QwtPlot::xBottom,QObject::trUtf8("Bottom"));
    ui->qwtPlot->setAxisTitle(QwtPlot::xTop,QObject::trUtf8("Top"));


    //��д�����������
    QFont titleFont("����", 12);
    ui->qwtPlot->setAxisFont(QwtPlot::xBottom, titleFont);

    //�½���ʾ��Ŀ
    curve1 = new QwtPlotCurve("Curve 1");
    curve2 = new QwtPlotCurve("Curve 2");
    curve3 = new QwtPlotCurve("Curve 3");


    //��ʱ��
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

//��������
void MainWindow::on_QuXianButton_clicked()
{
    //����x,yֵ����
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

    //����������Ŀ,���������
    curve1->setData(xData, yData);

    //�����߸��ӵ�qwtPlot�Ͻ�����ʾ
    curve1->attach(ui->qwtPlot);

    ui->qwtPlot->replot();
    ui->qwtPlot->show();
}

//��������
void MainWindow::on_QuXian2Button_clicked()
{
    //����x,yֵ����
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

    //����������Ŀ,���������
    curve2->setData(xData, yData);

    //�����߸��ӵ�qwtPlot�Ͻ�����ʾ
    curve2->attach(ui->qwtPlot);

    ui->qwtPlot->replot();
    ui->qwtPlot->show();
}


//���û���
void MainWindow::on_pushButton_3_clicked()
{
    //���û���
    QPen pen1 = QPen(QColor(255,0,0),2,Qt::SolidLine);
    curve1->setPen(pen1);

    //���û���
    QPen pen2 = QPen(QColor(0,0,255),2,Qt::DotLine);
    curve2->setPen(pen2);

    //���û���
    QPen pen3 = QPen(QColor(255,0,0),1,Qt::SolidLine);
    curve3->setPen(pen3);
}

//���û�ˢ
void MainWindow::on_BrushButton_clicked()
{
    //������仭ˢ
    QBrush brush1(QColor(128,128,128));
    curve1->setBrush(brush1);

    //������仭ˢ
    QBrush brush2(QColor(192,192,192));
    curve2->setBrush(brush2);
}

//��������
void MainWindow::on_GridButton_clicked()
{
    QwtPlotGrid* grid = new QwtPlotGrid();
    QPen pen = QPen(QColor(222,222,222),1);

    grid->setPen(pen);

    grid->attach(ui->qwtPlot);
}


//ɾ������
void MainWindow::on_DeleteButton_clicked()
{
    curve1->detach();

    curve2->detach();

    curve3->detach();

    ui->qwtPlot->replot();
}


//��ʱ��
void MainWindow::Timer_Deal()
{
    timerCount++;
    if (timerCount >= 100)
    {
        timerCount = 0;
    }

    yTimerData.erase(yTimerData.begin(),yTimerData.begin()+1);
    yTimerData.push_back(20*sin(timerCount*3.1415/10) + 50);

    //����������Ŀ,���������
    curve3->setData(xTimerData, yTimerData);

    //�����߸��ӵ�qwtPlot�Ͻ�����ʾ
    curve3->attach(ui->qwtPlot);

    ui->qwtPlot->replot();
}


//��̬����
void MainWindow::on_DontTaiButton_clicked()
{
    for(int i=0;i<100;i++)
    {
        xTimerData[i] = i;
        yTimerData[i] = 20*sin(i*3.1415/10) + 50;
        timerCount    = i;
    }

    //����������Ŀ,���������
    curve3->setData(xTimerData, yTimerData);

    //�����߸��ӵ�qwtPlot�Ͻ�����ʾ
    curve3->attach(ui->qwtPlot);

    ui->qwtPlot->replot();

    connect(timer, SIGNAL(timeout()), this, SLOT(Timer_Deal()));
    timer->start(100);
}
