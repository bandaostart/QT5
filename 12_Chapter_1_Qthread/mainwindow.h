#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QMutex>
#include "workthread.h"

namespace Ui {
class MainWindow;
}

#define MAXSIZE                     5

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_quitButton_clicked();

    void ReceiveText(QString str);

private:
    Ui::MainWindow *ui;

    QMutex mutex;
    WorkThread *workThread[MAXSIZE];
};

#endif // MAINWINDOW_H
