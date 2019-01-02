#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->fillColorList(ui->windowComboBox);
    this->fillColorList(ui->windowtextComboBox);
    this->fillColorList(ui->buttonComboBox);
    this->fillColorList(ui->buttontextComboBox);
    this->fillColorList(ui->baseComboBox);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::fillColorList(QComboBox *comBox)
{
    QStringList colorList = QColor::colorNames();                     //获取Qt所有知道名称的颜色名列表，返回一个字符串colorlist
    QString color;

    foreach (color, colorList)                                        //对颜色进行遍历
    {
        QPixmap pix(QSize(160,20));
        pix.fill(QColor(color));                                      //为pix填充当前遍历的颜色
        comBox->addItem(QIcon(pix), color);                           //添加一个条目，名称为NULL
        comBox->setIconSize(QSize(160,20));                           //设置图标尺寸
        comBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);     //设置下拉列表框的尺寸调整策略
    }

}


//window 背景色设置
void MainWindow::on_windowComboBox_activated(int index)
{
    QStringList colorList = QColor::colorNames();

    QColor color = QColor(colorList[index]);

    QPalette p = ui->centralWidget->palette();
    p.setColor(QPalette::Window, color);
    ui->centralWidget->setPalette(p);

    ui->centralWidget->setAutoFillBackground(true);
    ui->centralWidget->update();
}


//windowText颜色设置
void MainWindow::on_windowtextComboBox_activated(int index)
{
    QStringList colorList = QColor::colorNames();

    QColor color = QColor(colorList[index]);

    QPalette p = ui->centralWidget->palette();
    p.setColor(QPalette::WindowText, color);
    ui->centralWidget->setPalette(p);

    ui->centralWidget->setAutoFillBackground(true);
    ui->centralWidget->update();
}


//Button背景颜色设置
void MainWindow::on_buttonComboBox_activated(int index)
{
    QStringList colorList = QColor::colorNames();

    QColor color = QColor(colorList[index]);

    QPalette p = ui->centralWidget->palette();
    p.setColor(QPalette::Button, color);
    ui->centralWidget->setPalette(p);

    ui->OK->setAutoFillBackground(true);
    ui->Cancel->setAutoFillBackground(true);
    ui->centralWidget->update();
}

//ButtonText颜色设置
void MainWindow::on_buttontextComboBox_activated(int index)
{
    QStringList colorList = QColor::colorNames();

    QColor color = QColor(colorList[index]);

    QPalette p = ui->centralWidget->palette();
    p.setColor(QPalette::ButtonText, color);
    ui->centralWidget->setPalette(p);

    ui->centralWidget->update();
}


//Base颜色设置
void MainWindow::on_baseComboBox_activated(int index)
{
    QStringList colorList = QColor::colorNames();

    QColor color = QColor(colorList[index]);

    QPalette p = ui->centralWidget->palette();
    p.setColor(QPalette::Base, color);
    ui->centralWidget->setPalette(p);

    ui->centralWidget->update();
}
