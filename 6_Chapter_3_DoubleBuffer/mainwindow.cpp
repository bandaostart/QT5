#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->setAutoFillBackground(true);                                             //对窗体背景的设置
    this->setPalette(QPalette(Qt::white));
    pix = new QPixmap(ui->centralWidget->size());                                  //此QPixmap对象用来准备随时接受绘制的内容
    pix->fill(Qt::white);                                                          //填充背景色为白色
    ui->centralWidget->setMinimumSize(600,400);                                    //设置绘制区窗体的最小尺寸

    creatToolBar();

    ShowStyle();

    this->setWidth(widthSpinBox->value());                                         //初始化线宽
    this->setColor(Qt::black);                                                     //初始化颜色
}

MainWindow::~MainWindow()
{
    delete ui;
}



//创建工具栏
void MainWindow::creatToolBar()
{
    styleLabel      = new QLabel(tr("线型风格："));                   //创建线型风格控件
    styleComboBox   = new QComboBox;
    styleComboBox->addItem(tr("SloidLine"),      static_cast<int>(Qt::SolidLine));
    styleComboBox->addItem(tr("DashLine"),       static_cast<int>(Qt::DashLine));
    styleComboBox->addItem(tr("DotLine"),        static_cast<int>(Qt::DotLine));
    styleComboBox->addItem(tr("DashDotLine"),    static_cast<int>(Qt::DashDotLine));
    styleComboBox->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));
    connect(styleComboBox, SIGNAL(activated(int)), this, SLOT(setStyle(int)));


    widthLabel      = new QLabel(tr("线宽："));
    widthSpinBox    = new QSpinBox;
    widthSpinBox->setValue(5);
    connect(widthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setWidth(int)));


    colorBtn = new QToolButton;
    QPixmap  pixmap(20,20);
    pixmap.fill(Qt::black);
    colorBtn->setIcon(QIcon(pixmap));
    connect(colorBtn, SIGNAL(clicked(bool)), this, SLOT(ShowColor()));


    clearBtn = new QToolButton;
    clearBtn->setText(tr("清除"));
    clearBtn->setMinimumSize(20, 20);
    connect(clearBtn, SIGNAL(clicked(bool)), this, SLOT(setClear()));


    ui->mainToolBar->addWidget(styleLabel);
    ui->mainToolBar->addWidget(styleComboBox);
    ui->mainToolBar->addWidget(widthLabel);
    ui->mainToolBar->addWidget(widthSpinBox);
    ui->mainToolBar->addWidget(colorBtn);
    ui->mainToolBar->addWidget(clearBtn);
}


//显示风格
void MainWindow::ShowStyle()
{
    this->setStyle(styleComboBox->itemData(styleComboBox->currentIndex(), Qt::UserRole).toInt());
}


//显示颜色
void MainWindow::ShowColor()
{
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::black), this);

    if (color.isValid())
    {
        this->setColor(color);
        QPixmap p(20 ,20);
        p.fill(color);
        colorBtn->setIcon(QIcon(p));
    }
}



//设置风格
void MainWindow::setStyle(int s)
{
    style = s;
}


//设置字体宽度
void MainWindow::setWidth(int w)
{
    weight = w;
}


//设置颜色
void MainWindow::setColor(QColor c)
{
    color = c;
}


//清空
void MainWindow::setClear()
{
    QPixmap *clearPix = new QPixmap(ui->centralWidget->size());
    clearPix->fill(Qt::white);
    pix = clearPix;

    this->update();
}


//重新定义鼠标按下事件
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    startPos = event->pos();
}



//鼠标移动事件
/*mouseTracking 属性指示窗体是否追踪鼠标，默认为false（不追踪）即在至少有一个鼠标按下的前提下移动鼠标才触发
  mouseMoveEvent()事件,可以通过setMouseTracking(bool enable方法对该属性值进行设置，如果为追踪，则无论是否
  有鼠标按键按下，只要鼠标移动，就会触发mouseMoveEvent()事件*/
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPainter *painter = new QPainter;                           //新建一个QPainter对象

    QPen pen;                                                   //新建一个QPen对象
    pen.setStyle((Qt::PenStyle)style);                          //设置画笔的线型
    pen.setWidth(weight);                                       //设置画笔的线宽值
    pen.setColor(color);                                        //设置画笔的颜色

    painter->begin(pix);                                        //相当于把painter绘制到图片中
    painter->setPen(pen);                                       //将QPen对象应用到绘制对象中
    painter->drawLine(startPos, event->pos());                  //绘制从startPos到鼠标当前位置的直线
    painter->end();
    startPos = event->pos();                                    //更新鼠标的当前位置，为下次绘制做准备

    //painter->begin(pix) painter->end();以QPixmap对象为QPainterDevice参数绘制，构造一个QPainter对象时，就立即
    //开始对绘画设备进行绘制，此构造QPainter对象是短期的，如应定义在QWidget::paintEvent()中，并只能调用一次，此构造函数
    //调用开始于begin()函数，并且在QPainter的析构函数中自动调用end()函数，由于当一个QPainter对象的初始化失败时gouz 函数
    //不能提供反馈信息，所以在绘制外部设备时应使用begin()和end()，如打印机等外围设备




    this->update();                                             //重绘绘制区窗体
}


//窗口大小调整事件
void MainWindow::resizeEvent(QResizeEvent *)
{
    if ((ui->centralWidget->height() > pix->height()) || (ui->centralWidget->width() > pix->width()))
    {
        QPixmap *newPix = new QPixmap(ui->centralWidget->size());

        newPix->fill(Qt::white);

        QPainter p(newPix);
        p.drawPixmap(QPoint(0, 0), *pix);
        pix = newPix;
    }
}





//重绘事件
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.drawPixmap(QPoint(0, 0), *pix);
}


