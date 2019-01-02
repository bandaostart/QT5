#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("事件过滤"));

    label1 = new QLabel;
    image1.load(":image/1.png");
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label1->setPixmap(QPixmap::fromImage(image1));

    label2 = new QLabel;
    image2.load(":image/2.png");
    label2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label2->setPixmap(QPixmap::fromImage(image2));

    label3 = new QLabel;
    image3.load(":image/3.png");
    label3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label3->setPixmap(QPixmap::fromImage(image3));

    stateLabel = new QLabel(tr("鼠标按下标志"));
    stateLabel->setAlignment(Qt::AlignHCenter);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label1);
    layout->addWidget(label2);
    layout->addWidget(label3);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(layout);
    mainLayout->addWidget(stateLabel);

    ui->centralWidget->setLayout(mainLayout);

    label1->installEventFilter(this);
    label2->installEventFilter(this);
    label3->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



//滤波事件
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == label1)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = (QMouseEvent *)event;
            if (mouseEvent->buttons() & Qt::LeftButton)
            {
                stateLabel->setText(tr("左键按下左边图片"));
            }
            else if(mouseEvent->buttons()&Qt::MidButton)
            {
                stateLabel->setText(tr("中键按下左边图片"));
            }
            else if(mouseEvent->buttons()&Qt::RightButton)
            {
                stateLabel->setText(tr("右键按下左边图片"));
            }

            QMatrix matrix;
            matrix.scale(1.8, 1.8);
            QImage tmpImg = image1.transformed(matrix);
            label1->setPixmap(QPixmap::fromImage(tmpImg));
        }

        if (event->type() == QEvent::MouseButtonRelease)
        {
            stateLabel->setText(tr("鼠标释放左边图片"));
            label1->setPixmap(QPixmap::fromImage(image1));
        }
    }
    else if (watched == label2)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = (QMouseEvent *)event;
            if (mouseEvent->buttons() & Qt::LeftButton)
            {
                stateLabel->setText(tr("左键按下中间图片"));
            }
            else if(mouseEvent->buttons()&Qt::MidButton)
            {
                stateLabel->setText(tr("中键按下中间图片"));
            }
            else if(mouseEvent->buttons()&Qt::RightButton)
            {
                stateLabel->setText(tr("右键按下中间图片"));
            }

            QMatrix matrix;
            matrix.scale(1.8, 1.8);
            QImage tmpImg = image2.transformed(matrix);
            label2->setPixmap(QPixmap::fromImage(tmpImg));
        }

        if (event->type() == QEvent::MouseButtonRelease)
        {
            stateLabel->setText(tr("鼠标释放中间图片"));
            label2->setPixmap(QPixmap::fromImage(image2));
        }
    }
    else if (watched == label3)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = (QMouseEvent *)event;
            if (mouseEvent->buttons() & Qt::LeftButton)
            {
                stateLabel->setText(tr("左键按下右边图片"));
            }
            else if(mouseEvent->buttons()&Qt::MidButton)
            {
                stateLabel->setText(tr("中键按下右边图片"));
            }
            else if(mouseEvent->buttons()&Qt::RightButton)
            {
                stateLabel->setText(tr("右键按下右边图片"));
            }

            QMatrix matrix;
            matrix.scale(1.8, 1.8);
            QImage tmpImg = image3.transformed(matrix);
            label3->setPixmap(QPixmap::fromImage(tmpImg));
        }

        if (event->type() == QEvent::MouseButtonRelease)
        {
            stateLabel->setText(tr("鼠标释放右边图片"));
            label3->setPixmap(QPixmap::fromImage(image3));
        }
    }
}






























