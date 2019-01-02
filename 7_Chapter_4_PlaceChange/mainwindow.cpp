#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    angle           = 0;
    scaleValue      = 5;
    shearValue      = 5;
    translateValue  = 50;

    QGraphicsScene *scene = new QGraphicsScene;
    QPixmap *pixmap = new QPixmap(":/image/image.png");
    pixItem = new PixItem(pixmap);
    scene->addItem(pixItem);
    pixItem->setPos(0,0);
    scene->setSceneRect(-200, -200, 400, 400);

    view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400, 400);

    ctrlFrame = new QFrame;
    CreatControlFrame();

    //主窗口布局
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->setMargin(10);
    mainLayout->setSpacing(20);
    mainLayout->addWidget(view);
    mainLayout->addWidget(ctrlFrame);
    ui->centralWidget->setLayout(mainLayout);


}

MainWindow::~MainWindow()
{
    delete ui;
}


//创建主窗体右侧的控制面板
void MainWindow::CreatControlFrame()
{
    //旋转
    QSlider *rotateSlider = new QSlider;
    rotateSlider->setOrientation(Qt::Horizontal);
    rotateSlider->setRange(0, 360);
    connect(rotateSlider, SIGNAL(valueChanged(int)), this, SLOT(slotRotate(int)));

    QHBoxLayout *rotateLayout = new QHBoxLayout;
    rotateLayout->addWidget(rotateSlider);

    QGroupBox *rotateGroup = new QGroupBox(tr("Rotate"));
    rotateGroup->setLayout(rotateLayout);

    //缩放
    QSlider *scaleSlider = new QSlider;
    scaleSlider->setOrientation(Qt::Horizontal);
    scaleSlider->setRange(0, 2*scaleValue);
    scaleSlider->setValue(scaleValue);
    connect(scaleSlider, SIGNAL(valueChanged(int)), this, SLOT(slotScale(int)));

    QHBoxLayout *scaleLayout = new QHBoxLayout;
    scaleLayout->addWidget(scaleSlider);

    QGroupBox *scaleGroup = new QGroupBox(tr("Scale"));
    scaleGroup->setLayout(scaleLayout);

    //切换控制
    QSlider *shearSlider = new QSlider;
    shearSlider->setOrientation(Qt::Horizontal);
    shearSlider->setRange(0, 2*shearValue);
    shearSlider->setValue(shearValue);
    connect(shearSlider, SIGNAL(valueChanged(int)), this, SLOT(slotShear(int)));

    QHBoxLayout *shearLayout = new QHBoxLayout;
    shearLayout->addWidget(shearSlider);

    QGroupBox *shearGroup = new QGroupBox(tr("Shear"));
    shearGroup->setLayout(shearLayout);

    //位移控制
    QSlider *translateSlider = new QSlider;
    translateSlider->setOrientation(Qt::Horizontal);
    translateSlider->setRange(0, 2*translateValue);
    translateSlider->setValue(translateValue);
    connect(translateSlider, SIGNAL(valueChanged(int)), this, SLOT(slotTranslate(int)));

    QHBoxLayout *translateLayout = new QHBoxLayout;
    translateLayout->addWidget(translateSlider);

    QGroupBox *translateGroup = new QGroupBox(tr("Translate"));
    translateGroup->setLayout(translateLayout);


    //控制面板布局
    QVBoxLayout *frameLayout = new QVBoxLayout;
    frameLayout->setMargin(10);
    frameLayout->setSpacing(20);
    frameLayout->addWidget(rotateGroup);
    frameLayout->addWidget(scaleGroup);
    frameLayout->addWidget(shearGroup);
    frameLayout->addWidget(translateGroup);

    ctrlFrame->setLayout(frameLayout);
}


//旋转
void MainWindow::slotRotate(int value)
{
    view->rotate(value-angle);
    angle = value;
}

//缩放
void MainWindow::slotScale(int value)
{
    qreal s;
    if (value > scaleValue)
    {
        s = pow(1.1, (value-scaleValue));
    }
    else
    {
        s = pow(1/1.1, (scaleValue-value));
    }

    view->scale(s, s);
    scaleValue = value;
}


//图元比例切换
void MainWindow::slotShear(int value)
{
    view->shear((value-shearValue)/10.0, 0);
    shearValue = value;
}




//实现位移功能
void MainWindow::slotTranslate(int value)
{
    view->translate(value-translateValue, value-translateValue);
    translateValue = value;
}

