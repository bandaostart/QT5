#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QColor>
#include <QPixmap>
#include <QPoint>
#include <QPalette>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QToolButton>
#include <QColorDialog>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);


    void creatToolBar();

public slots:
    void setStyle(int);
    void setWidth(int);
    void setColor(QColor);
    void setClear();

    void ShowStyle();
    void ShowColor();

private:
    Ui::MainWindow *ui;
    QPixmap *pix;
    QPoint  startPos;
    QPoint  endPos;
    int     style;
    int     weight;
    QColor  color;


    QLabel      *styleLabel;
    QComboBox   *styleComboBox;
    QLabel      *widthLabel;
    QSpinBox    *widthSpinBox;
    QToolButton *colorBtn;
    QToolButton *clearBtn;


};

#endif // MAINWINDOW_H
























