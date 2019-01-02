#include "svgwidget.h"

SvgWidget::SvgWidget(QWidget *parent) : QSvgWidget(parent)
{
    //用于图片显示尺寸的确定
    render = this->renderer();
}



//鼠标滚轮事件
void SvgWidget::wheelEvent(QWheelEvent *event)
{
    const double diff = 0.1;                                //diff的值表示每次滚轮滚动一定的值，图片大小改变的比例

    QSize size   = render->defaultSize();                   //改行代码及下面两行代码用于获取图片显示区的尺寸大小
    int   width  = size.width();
    int   height = size.height();

    if (event->delta() > 0)                                 //获取滚轮滚动的距离值，通过此值来判断滚轮滚动的方向 大于0 滚轮向前 小于 0滚轮向后
    {
        width  = int(this->width()+this->width()*diff);
        height = int(this->height()+this->height()*diff);
    }
    else
    {
        width  = int (this->width() - this->width()*diff);
        height = int (this->height() - this->height()*diff);
    }

    resize(width, height);                                 //重新定义大小
}
