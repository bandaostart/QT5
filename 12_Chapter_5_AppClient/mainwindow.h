#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QMessageBox>

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
    void enableGetBtn();
    void readTime();
    void showError(QAbstractSocket::SocketError socketError);

private slots:
    void on_GetTimeButton_clicked();

private:
    Ui::MainWindow *ui;
    uint       time2u;
    QTcpSocket *tcpSocket;

};

#endif // MAINWINDOW_H
