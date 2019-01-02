#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QWidget         *Widget;
    QListWidget     *List;
    QStackedWidget  *Stack;
    QLabel          *Label1;
    QLabel          *Label2;
    QLabel          *Label3;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
