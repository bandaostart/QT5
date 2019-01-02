#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_QuXianButton_clicked();

    void on_QuXian2Button_clicked();

    void on_pushButton_3_clicked();

    void on_BrushButton_clicked();

    void on_GridButton_clicked();

    void on_DeleteButton_clicked();

    void Timer_Deal();

    void on_DontTaiButton_clicked();

private:
    Ui::MainWindow *ui;
    QwtPlotCurve *curve1;
    QwtPlotCurve *curve2;
    QwtPlotCurve *curve3;

    QTimer       *timer;
    int          timerCount;
    QVector<double>   xTimerData;
    QVector<double>   yTimerData;
};

#endif // MAINWINDOW_H
