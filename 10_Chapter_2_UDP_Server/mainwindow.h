#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QHostAddress>

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
    void on_pushButton_clicked();
    void Udp_ReceiveData();

    void on_ClearButton_clicked();

private:
    Ui::MainWindow *ui;
    int        port;
    bool       isStarted;
    QUdpSocket *udpSocket;
};

#endif // MAINWINDOW_H
