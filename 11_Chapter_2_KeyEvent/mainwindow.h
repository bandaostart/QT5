#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPixmap>
#include <QImage>
#include <QPalette>
#include <QPainter>
#include <QPen>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void drawPix();
    void keyPressEvent(QKeyEvent *e);
    void paintEvent(QPaintEvent *e);

private:
    Ui::MainWindow *ui;
    QPixmap *pix;                     //作为一个绘图设备，使用双缓冲机制实现图形的绘制
    QImage  image;                    //界面中的小图标
    int     startX;                   //图标的左上顶点位置
    int     startY;
    int     width;                    //界面的宽度和高度
    int     height;
    int     step;                     //网格的大小，即移动的步进值


};

#endif // MAINWINDOW_H
