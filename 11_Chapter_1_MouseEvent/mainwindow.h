#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMouseEvent>
#include <QLabel>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);


private:
    Ui::MainWindow *ui;
    QLabel *statusLabel;
    QLabel *mousePosLabel;
};

#endif // MAINWINDOW_H
