#include "butterfly.h"

const static double PI=3.14116;

Butterfly::Butterfly(QObject *parent) : QObject(parent)
{
    up = true;                                     //给标志蝴蝶翅膀位置的变量赋初始化值

    pix_up.load(":/image/up.png");
    pix_down.load(":/image/down.png");

    startTimer(100);                               //设定定时器时间间隔为100毫秒
}


//为图元限定区域范围，所有继承自QGraphicsItem的自定义图元都必须实现此函数
QRectF Butterfly::boundingRect() const
{
    qreal adjust = 2;                              //qreal相当于float

    return QRectF(-pix_up.width()/2-adjust, -pix_up.height()/2-adjust, pix_up.width()+adjust*2, pix_up.height()+adjust*2);
}


//重绘函数
void Butterfly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (up)
    {
        painter->drawPixmap(boundingRect().topLeft(), pix_up);
        up = !up;
    }
    else
    {
        painter->drawPixmap(boundingRect().topLeft(), pix_down);
        up = !up;
    }
}


void Butterfly::timerEvent(QTimerEvent *event)
{
    //边界控制
    qreal edgex       = scene()->sceneRect().right()+boundingRect().width()/2;     //右边界
    qreal edgetop     = scene()->sceneRect().top() + boundingRect().height()/2;    //上边界
    qreal edgebottom  = scene()->sceneRect().bottom()+boundingRect().height()/2;    //下边界

    if (pos().x() >= edgex)
    {
        setPos(scene()->sceneRect().left(), pos().y());          //若超过了左边界，水平移到右边界
    }

    if (pos().y() <= edgetop)
    {
        setPos(pos().x(), scene()->sceneRect().bottom());          //若超过了上边界，水平移到下边界
    }

    if (pos().y() >= edgebottom)
    {
        setPos(pos().x(), scene()->sceneRect().top());           //若超过了下边界，水平移到上边界
    }

    angle += (qrand()%10)/20.0;
    qreal dx = fabs(sin(angle*PI)*10.0);
    qreal dy = (qrand()%20 - 10.0);



    setPos(mapToParent(dx, dy));                                 //dx, dy完成蝴蝶随机飞行的路径，且dx dy是相对于蝴蝶的坐标系而言的
                                                                 //因此应使用mapToParent()函数映射为场景的坐标
}
