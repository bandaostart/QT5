#include "svgwindow.h"

SvgWindow::SvgWindow(QWidget *parent) : QScrollArea(parent)
{
    svgWidget = new SvgWidget;

    this->setWidget(svgWidget);                           //使svgWidget成为svgWindow的子窗体
}



//当主窗口对文件进行选择或修改时，将调用setFile函数设置新的文件
void SvgWindow::setFile(QString fileName)
{
    svgWidget->load(fileName);                            //将新的SVG文件加载到svgWidget中进行显示

    QSvgRenderer *render = svgWidget->renderer();

    svgWidget->resize(render->defaultSize());             //使svgWidget窗体按SVG图片的默认尺寸进行显示
}



//鼠标按下事件
void SvgWindow::mousePressEvent(QMouseEvent *event)
{
    mousePressPos = event->pos();

    //hori可获得水平滑动条 vert可获得垂直滑动条
    scrollBarValueOnMousePress.rx() = horizontalScrollBar()->value();
    scrollBarValueOnMousePress.ry() = verticalScrollBar()->value();

    event->accept();
}


//鼠标键按下并拖拽鼠标时触发鼠标移动事件
void SvgWindow::mouseMoveEvent(QMouseEvent *event)
{
    //对水平滑动条的新位置进行设置
    horizontalScrollBar()->setValue(scrollBarValueOnMousePress.x()-event->pos().x()+mousePressPos.x());

    //对垂直滑动条的新位置进行设置
    verticalScrollBar()->setValue(scrollBarValueOnMousePress.y()-event->pos().y() + mousePressPos.y());

    horizontalScrollBar()->update();

    verticalScrollBar()->update();

    event->accept();
}



