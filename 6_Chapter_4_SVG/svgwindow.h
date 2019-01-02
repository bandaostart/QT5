#ifndef SVGWINDOW_H
#define SVGWINDOW_H

#include <QScrollArea>
#include <QScrollBar>
#include <QMouseEvent>
#include "svgwidget.h"

class SvgWindow : public QScrollArea
{
    Q_OBJECT

public:
    SvgWindow(QWidget *parent = 0);

    void setFile(QString);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


 private:
    SvgWidget *svgWidget;
    QPoint    mousePressPos;
    QPoint    scrollBarValueOnMousePress;

};

#endif // SVGWINDOW_H