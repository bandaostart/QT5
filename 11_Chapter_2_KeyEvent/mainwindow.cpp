#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("键盘事件"));
    this->setAutoFillBackground(true);

    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, Qt::white);
    this->setPalette(palette);

    this->setMinimumSize(512, 256);
    this->setMaximumSize(512, 256);

    width  = this->size().width();
    height = this->size().height();

    pix = new QPixmap(width, height);
    pix->fill(Qt::white);

    image.load(":image/image.png");

    startX = 100;
    startY = 100;

    step = 20;

    drawPix();

    resize(512,256);


}

MainWindow::~MainWindow()
{
    delete ui;
}

//实现在QPixmap对象上绘制图像
void MainWindow::drawPix()
{
    //重新刷新pix对象为白色底色
    pix->fill(Qt::white);

    //创建一个QPainter对象，并指定pix为绘图设备，创建一个QPen对象，设置画笔的线型为Qt::DotLine，用于绘网格
    QPainter *painter = new QPainter;
    QPen     pen(Qt::DotLine);

    //按照步进值的间隔绘制纵向的网格线
    for (int i=step; i<width; i=i+step)
    {
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(i, 0), QPoint(i, height));
        painter->end();
    }

    //按照步进值的间隔绘制横向的网格线
    for(int j=step; j<height; j=j+step)
    {
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(0,j), QPoint(width, j));
        painter->end();
    }

    //绘制小图标
    painter->begin(pix);
    painter->drawImage(QPoint(startX, startY), image);
    painter->end();
}


//鼠标按键处理
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    //判断是否按下Ctrl键
    if (e->modifiers() == Qt::ControlModifier)
    {
        if (e->key() == Qt::Key_Left)
        {
            startX = (startX-1<0) ? startX : (startX-1);
        }

        if (e->key() == Qt::Key_Right)
        {
            startX = (startX+1+image.width()>width) ? startX : startX+1;
        }

        if(e->key() == Qt::Key_Up)
        {
            startY = (startY-1<0) ? startY : startY-1;
        }

        if (e->key() == Qt::Key_Down)
        {
            startY = (startY+1+image.height()>height) ? startY : startY+1;
        }
    }
    else
    {
        startX  = startX-startX%step;
        startY  = startY-startY%step;
        if (e->key() == Qt::Key_Left)
        {
            startX = (startX-step<0) ? startX : startX-step;
        }

        if (e->key() == Qt::Key_Right)
        {
            startX = (startX+step+image.width()>width) ? startX : startX+step;
        }

        if (e->key() == Qt::Key_Up)
        {
            startY = (startY-step < 0) ? startY : startY-step;
        }

        if (e->key() == Qt::Key_Down)
        {
            startY = (startY+step+image.height()>height)? startY:startY+step;
        }

        if (e->key() == Qt::Key_Home)
        {
            startX = 0;
            startY = 0;
        }

        if (e->key() == Qt::Key_End)
        {
            startX = width-image.width();
            startY = height-image.height();
        }

    }

    drawPix();
    update();
}



//重绘事件
void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(QPoint(0, 0), *pix);
    painter.end();
}
























































