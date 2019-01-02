#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->fileEdit->setText(tr("标准文件打开对话框"));
    ui->fileEdit->setAlignment(Qt::AlignCenter);

    ui->colorFrame->setFrameShape(QFrame::StyledPanel);
    ui->colorFrame->setFrameShadow(QFrame::Sunken);
    ui->colorFrame->setLineWidth(10);
    ui->colorFrame->setMidLineWidth(10);
    ui->colorFrame->setAutoFillBackground(true);
    ui->colorFrame->setPalette(QPalette(QColor(0,0,255)));


    ui->fontLabel->setText(tr("标准字体对话框"));
    ui->fontLabel->setAlignment(Qt::AlignCenter);
    ui->fontLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    ui->inputEdit->setText(tr("标准字符串输入对话框"));
    ui->inputEdit->setAlignment(Qt::AlignCenter);

    ui->itemEdit->setText(tr("标准条目选择对话框"));
    ui->itemEdit->setAlignment(Qt::AlignCenter);

    ui->intEdit->setText(tr("标准整形输入对话框"));
    ui->intEdit->setAlignment(Qt::AlignCenter);

    ui->doubleEdit->setText(tr("标准浮点数输入对话框"));
    ui->doubleEdit->setAlignment(Qt::AlignCenter);

    ui->questionEdit->setText(tr("标准question消息对话框"));
    ui->questionEdit->setAlignment(Qt::AlignCenter);

    ui->informationEdit->setText(tr("标准information消息对话框"));
    ui->informationEdit->setAlignment(Qt::AlignCenter);

    ui->warningEdit->setText(tr("标准warning消息对话框"));
    ui->warningEdit->setAlignment(Qt::AlignCenter);

    ui->criticalEdit->setText(tr("标准critical消息对话框"));
    ui->criticalEdit->setAlignment(Qt::AlignCenter);

    ui->aboutEdit->setText(tr("标准about消息对话框"));
    ui->aboutEdit->setAlignment(Qt::AlignCenter);

    ui->widget->setLayout(ui->gridLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//标准文件对话框
void MainWindow::on_fileButton_clicked()
{
    QString fileName;

    fileName = QFileDialog::getOpenFileName(this,  tr("Open File Dialog"), "/", tr("Image(*.png *.jpg);;Text(*.txt)") );

    ui->fileEdit->setText(fileName);
}


//标准颜色对话框
void MainWindow::on_colorButton_clicked()
{
    QColor c = QColorDialog::getColor(Qt::blue);
    if (c.isValid())
    {
        ui->colorFrame->setPalette(QPalette(c));
    }
}



//标准字体对话框
void MainWindow::on_fontButton_clicked()
{
   bool ok;

   QFont font = QFontDialog::getFont(&ok);

   if (ok)
   {
       ui->fontLabel->setFont(font);
   }
}

//标准字符串输入对话框
void MainWindow::on_inputButton_clicked()
{
    QString str = "";
    bool ok;

    str = QInputDialog::getText(this, tr("标准字符串输入对话框"), tr("请输入字符串"), QLineEdit::Normal, ui->inputEdit->text(), &ok);
    if (ok)
    {
        ui->inputEdit->setText(str);
    }
}

//标准条目选择对话框
void MainWindow::on_itemButton_clicked()
{
    QStringList SexItems;
    SexItems << tr("男") << tr("女");

    bool ok;
    QString str = QInputDialog::getItem(this, tr("标准条目输入对话框"),tr("请选择"), SexItems, 0, false, &ok);
    if (ok)
    {
        ui->itemEdit->setText(str);
    }
}

//标准int型输入对话框
void MainWindow::on_intButton_clicked()
{
    bool ok;

    int age = QInputDialog::getInt(this, tr("标准int型输入对话框"), tr("请选择"), ui->intEdit->text().toInt(), 0, 100, 1, &ok);

    if (ok)
    {
        ui->intEdit->setText(QString::number(age));
    }
}


//标准浮点数输入对话框
void MainWindow::on_doubleButton_clicked()
{
    bool ok;
    double score = QInputDialog::getDouble(this, tr("标准double类型输入对话框"), tr("请输入"), ui->doubleEdit->text().toDouble(), 0, 100, 1, &ok);
    if (ok)
    {
        ui->doubleEdit->setText(QString(tr("%1")).arg(score));
    }
}

//标准问题消息对话框
void MainWindow::on_questionButton_clicked()
{
    int state;

    state = QMessageBox::question(this, tr("Question消息框"), tr("Question"), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
    switch (state)
    {
        case QMessageBox::Ok:
            ui->questionEdit->setText("Question button /OK");
        break;

        case QMessageBox::Cancel:
            ui->questionEdit->setText("Question button/Cancel");
        break;

    }
}

//标准消息对话框
void MainWindow::on_informationButton_clicked()
{
    QMessageBox::information(this, tr("Information 消息框"), tr("这是information消息对话框，欢迎您"));
}
//警告消息框
void MainWindow::on_warningButton_clicked()
{
    int state;

    state = QMessageBox::warning(this, tr("Warning消息框"), tr("Warning"), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel, QMessageBox::Save);
    switch (state)
    {
        case QMessageBox::Save:
            ui->warningEdit->setText("Warning button /Save");
        break;

        case QMessageBox::Discard:
            ui->warningEdit->setText("Warning button /Discard");
        break;

        case QMessageBox::Cancel:
            ui->warningEdit->setText("Warning button /Cancel");
        break;

    }

}

//标准critical对话框
void MainWindow::on_criticalButton_clicked()
{
    QMessageBox::critical(this, tr("Critical 消息框"), tr("这是一个Critical消息对话框"));
}

//标准关于对话框
void MainWindow::on_aboutButton_clicked()
{
    QMessageBox::about(this, tr("About 消息框"), tr("这是一个About消息测试"));
}
