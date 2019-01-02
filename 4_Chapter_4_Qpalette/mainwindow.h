#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void fillColorList(QComboBox *comBox);

private slots:
    void on_windowComboBox_activated(int index);

    void on_windowtextComboBox_activated(int index);


    void on_buttonComboBox_activated(int index);

    void on_buttontextComboBox_activated(int index);

    void on_baseComboBox_activated(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
