#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void on_fileButton_clicked();
    void on_colorButton_clicked();

    void on_fontButton_clicked();

    void on_inputButton_clicked();

    void on_itemButton_clicked();

    void on_intButton_clicked();

    void on_doubleButton_clicked();

    void on_questionButton_clicked();

    void on_informationButton_clicked();

    void on_warningButton_clicked();

    void on_criticalButton_clicked();

    void on_aboutButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
