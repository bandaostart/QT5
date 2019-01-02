#include "flashitem.h"

FlashItem::FlashItem(QObject *parent) : QObject(parent)
{
    flash = true;           //为颜色切换标识赋初值

    setFlag(ItemIsMovable); //设置图元的属性， ItemIsMovable表示此图元是可以移动的，可以用鼠标进行拖拽操作

    startTimer(1000);
}


QRectF FlashItem::boundingRect() const
{
    qreal  adjust = 2;
    return QRectF(-10-adjust, -10-adjust, 43+adjust, 43+adjust);
}



void FlashItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);                     //表示闪烁图元的阴影区不绘制边线
    painter->setBrush(Qt::darkGray);                //表示闪烁图元的阴影区的阴影画刷颜色为深灰色
    painter->drawEllipse(-7, -7, 40, 40);           //绘制阴影区域

    painter->setPen(QPen(Qt::black, 0));             //设置闪烁区的椭圆边线颜色为黑色
    painter->setBrush(flash?(Qt::red):(Qt::yellow)); //颜色切换
    painter->drawEllipse(-10, -10, 40, 40);          //绘制椭圆
}

void FlashItem::timerEvent(QTimerEvent *event)
{
    flash = !flash;

    this->update();
}






























