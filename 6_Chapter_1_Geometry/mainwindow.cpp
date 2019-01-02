#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Geometry");

    xLabel      = new QLabel(tr("函数 x():"));
    xValueLabel = new QLabel;
    yLabel      = new QLabel(tr("函数 y():"));
    yValueLabel = new QLabel;
    FrmLabel      = new QLabel(tr("函数 frameGeometry():"));
    FrmValueLabel = new QLabel;
    posLabel      = new QLabel(tr("函数 pos():"));
    posValueLabel = new QLabel;
    geoLabel      = new QLabel(tr("函数 geometry():"));
    geoValueLabel = new QLabel;
    widthLabel       = new QLabel(tr("函数 width():"));
    widthValueLabel  = new QLabel;
    heightLabel      = new QLabel(tr("函数 height():"));
    heightValueLabel = new QLabel;
    rectLabel        = new QLabel(tr("函数 rect():"));
    rectValueLabel   = new QLabel;
    sizeLabel        = new QLabel(tr("函数 size():"));
    sizeValueLabel   = new QLabel;

    imageLabel      = new QLabel;

    QImage image;
    image.load(":/image/geometry.png");
    QMatrix martix;
    martix.scale(1, 1);
    image = image.transformed(martix);
    imageLabel->setPixmap(QPixmap::fromImage(image));
    imageLabel->setMaximumWidth(image.width());
    imageTextEdit   = new QTextEdit;
    imageTextEdit->setMaximumWidth(image.width());
    imageTextEdit->setMinimumHeight(image.height());
    QTextCharFormat fmt;
    fmt.setFontFamily(tr("宋体"));
    fmt.setFontPointSize(10);
    fmt.setFontWeight(70);
    imageTextEdit->setCurrentCharFormat(fmt);
    imageTextEdit->insertPlainText(tr("1: x(), y(), pos() 函数的作用都是获得整体窗体左上角的坐标位置\r\n\n"));
    imageTextEdit->insertPlainText(tr("2: frameGeometry()获得整体窗体的坐上定点和长 宽值\r\n\n"));
    imageTextEdit->insertPlainText(tr("3: geometry()获得窗体内中央区域的左上顶点及长 宽值\r\n\n"));
    imageTextEdit->insertPlainText(tr("4: width() height() 获得的是中央区域的长 宽值\r\n\n"));
    imageTextEdit->insertPlainText(tr("5: rect() size() 获得的是中央区域的长 宽值"));


    mainLayout      = new QGridLayout(ui->centralWidget);

    mainLayout->addWidget(imageLabel, 0, 0, 4, 1);
    mainLayout->addWidget(imageTextEdit, 4, 0, 5, 1);

    mainLayout->addWidget(xLabel, 0, 1, 1, 1);
    mainLayout->addWidget(xValueLabel, 0, 2, 1, 1);

    mainLayout->addWidget(yLabel, 1, 1, 1, 1);
    mainLayout->addWidget(yValueLabel, 1, 2, 1, 1);

    mainLayout->addWidget(FrmLabel, 3, 1, 1, 1);
    mainLayout->addWidget(FrmValueLabel, 3, 2, 1, 1);

    mainLayout->addWidget(posLabel, 2, 1, 1, 1);
    mainLayout->addWidget(posValueLabel, 2, 2, 1, 1);

    mainLayout->addWidget(geoLabel, 4, 1, 1, 1);
    mainLayout->addWidget(geoValueLabel, 4, 2, 1, 1);

    mainLayout->addWidget(widthLabel, 5, 1, 1, 1);
    mainLayout->addWidget(widthValueLabel, 5, 2, 1, 1);

    mainLayout->addWidget(heightLabel, 6, 1, 1, 1);
    mainLayout->addWidget(heightValueLabel, 6, 2, 1, 1);

    mainLayout->addWidget(rectLabel, 7, 1, 1, 1);
    mainLayout->addWidget(rectValueLabel, 7, 2, 1, 1);

    mainLayout->addWidget(sizeLabel, 8, 1, 1, 1);
    mainLayout->addWidget(sizeValueLabel, 8, 2, 1, 1);

    updateLabel();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateLabel()
{
    xValueLabel->setText(QString::number(this->x()));

    yValueLabel->setText(QString::number(this->y()));

    FrmValueLabel->setText( QString::number(this->frameGeometry().x()) + ","
                          + QString::number(this->frameGeometry().y()) + ","
                          + QString::number(this->frameGeometry().width()) + ","
                          + QString::number(this->frameGeometry().height()));

    posValueLabel->setText(  QString::number(this->pos().x()) + ","
                           + QString::number(this->pos().y()));

    geoValueLabel->setText(   QString::number(this->geometry().x()) + ","
                            + QString::number(this->geometry().y()) + ","
                            + QString::number(this->geometry().width()) + ","
                            + QString::number(this->geometry().height()));

    widthValueLabel->setText(QString::number(this->width()));

    heightValueLabel->setText(QString::number(this->height()));

    rectValueLabel->setText(  QString::number(this->rect().x()) + ","
                            + QString::number(this->rect().y()) + ","
                            + QString::number(this->width()) + ","
                            + QString::number(this->height()));

    sizeValueLabel->setText(  QString::number(this->size().width()) + ","
                            + QString::number(this->size().height()));

}


void MainWindow::moveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    updateLabel();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);

    updateLabel();
}


























