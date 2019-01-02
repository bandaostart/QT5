#include "paintarea.h"

PaintArea::PaintArea(QWidget *parent) : QWidget(parent)
{
    this->setPalette(QPalette(Qt::white));
    this->setAutoFillBackground(true);
    this->setMinimumSize(400, 400);
}



void PaintArea::setShape(Shape s)
{
    shape = s;
    update();
}

void PaintArea::setPen(QPen p)
{
    pen = p;
    update();
}

void PaintArea::setBrush(QBrush b)
{
    brush = b;
    update();
}

void PaintArea::setFillRule(Qt::FillRule rule)
{
    fillRule = rule;
    update();
}


void PaintArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter p(this);
    p.setPen(pen);
    p.setBrush(brush);

    QRect rect(50, 100, 300, 200);
    static const QPoint points[4] =
    {
        QPoint(150, 150),
        QPoint(300 ,150),
        QPoint(350, 250),
        QPoint(100, 300)
    };
    int startAngle = 30*16;               //角度
    int spanAngle  = 120*16;

    QPainterPath path;
    path.addRect(150, 150, 100, 100);
    path.moveTo(100, 100);
    path.cubicTo(300, 100, 200, 200, 300, 300);
    path.cubicTo(100, 300, 200, 200, 100, 100);
    path.setFillRule(fillRule);

    switch (shape)
    {
        case Line:
            p.drawLine(rect.topLeft(), rect.bottomRight());             //直线
        break;

        case Rectangle:                                                 //长方形
            p.drawRect(rect);
        break;

        case RoundRect:
            p.drawRoundRect(rect);                                      //圆角方形
        break;

        case Ellipse:
            p.drawEllipse(rect);                                         //椭圆形
        break;

        case Polygon:
            p.drawPolygon(points, 4);                                    //多边形
        break;

        case Polyline:
            p.drawPolyline(points, 4);                                   //多边线
        break;

        case Points:
            p.drawPoints(points, 4);                                     //点
        break;

        case Arc:
            p.drawArc(rect, startAngle, spanAngle);                      //弧
        break;

        case Path:
            p.drawPath(path);                                            //路径
        break;

        case Text:
            p.drawText(rect, Qt::AlignCenter, tr("Hello QT !"));          //文字
        break;

        case Pixmap:
            p.drawPixmap(150,150,QPixmap(":/image/image.png"));       //图片
        break;


    }

}



















