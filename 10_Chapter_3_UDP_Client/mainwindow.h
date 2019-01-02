#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QHostAddress>
#include <QTimer>

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
    void Udp_ReceiveData();
    void Udp_SendData();

    void on_pushButton_clicked();

    void on_ClearButton_clicked();

private:
    Ui::MainWindow *ui;
    int        port;
    bool       isStarted;
    QTimer     *timer;
    QUdpSocket *udpSocket;
    QUdpSocket *RecvSocket;
};

#endif // MAINWINDOW_H
