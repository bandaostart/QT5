#ifndef STARTITEM_H
#define STARTITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

class StartItem : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    StartItem();
    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPixmap pix;
};

#endif // STARTITEM_H
