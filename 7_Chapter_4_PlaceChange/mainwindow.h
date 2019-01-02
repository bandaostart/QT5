#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "pixitem.h"
#include <math.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void CreatControlFrame();

private:
    Ui::MainWindow *ui;
    int     angle;
    qreal   scaleValue;
    qreal   shearValue;
    qreal   translateValue;

    QGraphicsView *view;
    QFrame        *ctrlFrame;
    PixItem       *pixItem;
public slots:
    void slotRotate(int);
    void slotScale(int);
    void slotShear(int);
    void slotTranslate(int);

};

#endif // MAINWINDOW_H
