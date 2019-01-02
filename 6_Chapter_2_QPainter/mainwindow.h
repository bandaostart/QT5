#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "paintarea.h"
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QSpinBox>
#include <QFrame>
#include <QVariant>
#include <QPushButton>
#include <QColorDialog>
#include <QResizeEvent>

namespace Ui {
class MainWindow;
}

#define Attributes_Num     10
#define ShapeNum           0
#define PenColorNum        1
#define PenWidthNum        2
#define PenStyleNum        3
#define PenCapNum          4
#define PenJoinNum         5
#define FillRuleNum        6
#define SpreadNum          7
#define BrushColorNum      8
#define BrushStyleNum      9



typedef union
{
    QComboBox      *ComboBox;
    QSpinBox       *SpinBox;
    QPushButton    *PushButton;
}Content_t;

typedef struct
{
  QLabel    *Name[Attributes_Num];
  Content_t Content[Attributes_Num];
}Attributes_Data_t;







class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public:
     PaintArea *paintArea;

     Attributes_Data_t AttributesData;
     QGradient::Spread spread;        //辐射渐变

     QGridLayout  *rightLayout;
     QHBoxLayout  *mainLayout;
     QSize        buttionSize;

private slots:
    void ShowShape(int);
    void ShowPenWidth(int);
    void ShowPenColor();
    void ShowPenStyle(int);
    void ShowPenCap(int);
    void ShowPenJoin(int);
    void ShowSpreadStyle();
    void ShowFillRule();
    void ShowBrushColor();
    void ShowBrush(int);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
