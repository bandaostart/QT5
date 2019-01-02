#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("鼠标事件"));

    //用于显示鼠标移动是的实时位置
    statusLabel = new QLabel;
    statusLabel->setText(tr("当前位置"));
    statusLabel->setFixedWidth(100);

    //用于显示鼠标按下或释放是的位置
    mousePosLabel = new QLabel;
    mousePosLabel->setText(tr(""));
    mousePosLabel->setFixedWidth(100);

    //添加状态栏控件
    this->statusBar()->addPermanentWidget(statusLabel);
    this->statusBar()->addPermanentWidget(mousePosLabel);

    //设置窗体追踪鼠标，如果为false为不追踪，在此情况下至少有一个鼠标按下时才响应鼠标移动事件
    this->setMouseTracking(true);

    resize(400, 200);

}

MainWindow::~MainWindow()
{
    delete ui;
}


//鼠标按下事件响应函数
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    //x()和y()方法可以获得鼠标相对于接收事件的窗体位置，globalX()和gloablY()方法可以获得鼠标相对应窗口系统的位置
    QString str = "(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")";

    if (e->button() == Qt::LeftButton)
    {
        this->statusBar()->showMessage(tr("左键")+str);
    }
    else if(e->button() == Qt::RightButton)
    {
        this->statusBar()->showMessage(tr("右键")+str);
    }
    else if(e->button() == Qt::MidButton)
    {
        this->statusBar()->showMessage(tr("中键")+str);
    }
}


//鼠标移动事件
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    mousePosLabel->setText("(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")");
}


//鼠标松开事件
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    QString str = "(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")";
    this->statusBar()->showMessage(tr("释放在： ") + str, 3000);
}


void MainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
}






















