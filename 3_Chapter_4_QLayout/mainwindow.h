#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>

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
    Ui::MainWindow *ui;

    QWidget *MainWidget;
    QLabel  *UserNameLabel;
    QLabel  *NameLabel;
    QLabel  *SexLabel;
    QLabel  *DepartmentLabel;
    QLabel  *AgeLabel;
    QLabel  *OtherLabel;
    QLineEdit *UserNameLineEdit;
    QLineEdit *NameLineEdit;
    QComboBox *SexComboBox;
    QTextEdit *DepartmentTextEdit;
    QLineEdit *AgeLineEdit;
    QGridLayout *LeftLayout;

    QLabel  *HeadLabel;
    QLabel  *HeadIconLabel;
    QPushButton *UpdateHeadBtn;
    QHBoxLayout *TopRightLayout;

    QLabel      *IntroductionLabel;
    QTextEdit   *IntroductionTextEdit;
    QVBoxLayout *RightLayout;

    QPushButton  *OkBtn;
    QPushButton  *CancelBtn;
    QHBoxLayout  *ButtomLayout;
};

#endif // MAINWINDOW_H



























