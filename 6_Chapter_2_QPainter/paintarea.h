#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QPalette>
#include <QPainterPath>




class PaintArea : public QWidget
{
    Q_OBJECT
public:
    explicit PaintArea(QWidget *parent = 0);
    enum Shape{Line, Rectangle, RoundRect, Ellipse, Polygon, Polyline, Points, Arc, Path, Text, Pixmap};

    void setShape(Shape);
    void setPen(QPen);
    void setBrush(QBrush);
    void setFillRule(Qt::FillRule);
    void paintEvent(QPaintEvent *event);

private:
    Shape        shape;
    QPen         pen;
    QBrush       brush;
    Qt::FillRule fillRule;

signals:

public slots:
};

#endif // PAINTAREA_H
