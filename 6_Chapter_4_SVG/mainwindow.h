#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "svgwindow.h"
#include <QFileDialog>
#include <QAction>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void slotOpenFile();



private:
    Ui::MainWindow *ui;

    SvgWindow *svgWindow;
};

#endif // MAINWINDOW_H
