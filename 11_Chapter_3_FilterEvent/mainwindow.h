#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include <QEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>

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
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::MainWindow *ui;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;

    QLabel *stateLabel;

    QImage image1;
    QImage image2;
    QImage image3;

};

#endif // MAINWINDOW_H
