#ifndef SVGWIDGET_H
#define SVGWIDGET_H

#include <QtSvg/QSvgWidget>
#include <QtSvg/QSvgRenderer>
#include <QScrollArea>
#include <QWheelEvent>


class SvgWidget : public QSvgWidget
{
    Q_OBJECT

public:
    SvgWidget(QWidget *parent=0);

    void wheelEvent(QWheelEvent *event);          //响应鼠标的滚轮事件，使SVG图片能够通过鼠标滚轮的滚动进行缩放

private:
    QSvgRenderer *render;

};

#endif // SVGWIDGET_H
