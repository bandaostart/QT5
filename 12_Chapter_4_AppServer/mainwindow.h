#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "timeserver.h"

namespace Ui {
class MainWindow;
}
class TimeServer;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void slotShow();

private:
    Ui::MainWindow *ui;

    TimeServer *timeServer;
    int count;
};

#endif // MAINWINDOW_H
