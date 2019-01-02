#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QObject>
#include <QGraphicsView>
#include <QLabel>
#include <QMouseEvent>
#include <QTextStream>
#include <QSlider>
#include <QGridLayout>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QFile>

class MapWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MapWidget(QWidget *parent = 0);

    void readMap();
    QPointF mapToMap(QPointF);

signals:

public slots:
    void slotZoom(int);
    void drawBackground(QPainter *painter, const QRectF &rect);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QPixmap map;
    qreal   zoom;
    QLabel  *viewCoord;
    QLabel  *sceneCoord;
    QLabel  *mapCoord;
    double  x1, y1;
    double  x2, y2;

};

#endif // MAPWIDGET_H
