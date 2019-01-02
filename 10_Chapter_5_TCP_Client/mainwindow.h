#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostAddress>
#include <QTcpSocket>
#include <QMessageBox>
#include <QHostInfo>

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
    void slotConnected();
    void slotDisconnected();
    void dataReceived();


private slots:
    void on_sendButton_clicked();

    void on_enterButton_clicked();

private:
    Ui::MainWindow *ui;

    bool status;
    int  port;
    QHostAddress   *serverIP;
    QString        userName;
    QTcpSocket     *tcpSocket;

};

#endif // MAINWINDOW_H
