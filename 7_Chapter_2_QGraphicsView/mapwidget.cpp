#include "mapwidget.h"

MapWidget::MapWidget(QWidget *parent) : QGraphicsView(parent)
{
    readMap();                                               //读取地图描述信息

    zoom = 50;

    int width  = map.width();
    int height = map.height();

    QGraphicsScene *scene = new QGraphicsScene(this);        //新建一个 QGraphicsScene对象为主串口连接一个场景
    scene->setSceneRect(-width/2, -height/2, width, height); //限定场景的显示区域为地图的大小,坐标原点在中心点
    setScene(scene);                                         //view设置场景
    setCacheMode(CacheBackground);

    //用于地图缩放的滑动条
    QSlider *slider = new QSlider;                            //新建一个QSlider对象作为地图缩放控制
    slider->setOrientation(Qt::Vertical);
    slider->setRange(1, 100);
    slider->setTickInterval(10);
    slider->setValue(50);
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(slotZoom(int)));

    QLabel *zoominLabel = new QLabel;
    zoominLabel->setScaledContents(true);
    zoominLabel->setPixmap(QPixmap(":/image/zoomin.png"));

    QLabel *zoomoutLabel = new QLabel;
    zoomoutLabel->setScaledContents(true);
    zoomoutLabel->setPixmap(QPixmap(":/image/zoomout.png"));

    //坐标值显示区
    QLabel *label1 = new QLabel(tr("GraphicsView:"));
    label1->setAlignment(Qt::AlignRight);
    viewCoord = new QLabel;
    viewCoord->setAlignment(Qt::AlignLeft);

    QLabel *label2 = new QLabel(tr("GraphicsScene:"));
    label2->setAlignment(Qt::AlignRight);
    sceneCoord = new QLabel;
    sceneCoord->setAlignment(Qt::AlignLeft);

    QLabel *label3 = new QLabel(tr("map:"));
    label3->setAlignment(Qt::AlignRight);
    mapCoord       = new QLabel;
    mapCoord->setAlignment(Qt::AlignLeft);

    //坐标显示区布局
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(label1, 0, 0);
    gridLayout->addWidget(viewCoord, 0, 1);
    gridLayout->addWidget(label2, 1, 0);
    gridLayout->addWidget(sceneCoord, 1, 1);
    gridLayout->addWidget(label3, 2, 0);
    gridLayout->addWidget(mapCoord, 2, 1);
    gridLayout->setSizeConstraint(QLayout::SetFixedSize);

    QFrame  *coorFrame = new QFrame;
    coorFrame->setLayout(gridLayout);

    //缩放控制子布局
    QVBoxLayout *zoomLayout = new QVBoxLayout;
    zoomLayout->addWidget(zoominLabel);
    zoomLayout->addWidget(slider);
    zoomLayout->addWidget(zoomoutLabel);

    //坐标显示区域布局
    QVBoxLayout *coorLayout = new QVBoxLayout;
    coorLayout->addWidget(coorFrame);
    coorLayout->addStretch();

    //主布局
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(zoomLayout);
    mainLayout->addLayout(coorLayout);
    mainLayout->addStretch();
    mainLayout->setMargin(30);
    mainLayout->setSpacing(10);

    setLayout(mainLayout);
    setWindowTitle("Map Widget");
    setMinimumSize(600, 400);
}




//读取地图信息
void MapWidget::readMap()
{
    QString mapName;

    QFile mapFile;
    mapFile.setFileName("maps.txt");                   //maps.txt是描述地图信息的文本文件
    int   ok = mapFile.open(QIODevice::ReadOnly);      //以只读方式打开文件
    if (ok)                                            //分别读取地图的名称和四个经纬度信息
    {
        QTextStream ts(&mapFile);

        if (!ts.atEnd())
        {
            ts >> mapName;
            ts >> x1 >> y1 >> x2 >> y2;
        }

        mapFile.close();
    }

    map.load(":/image/China.jpg");                                 //将地图读到map中
}


//根据缩放滑动条的当前值，确定缩放的比例
void MapWidget::slotZoom(int value)
{
    qreal s;

    if (value > zoom)                                   //放大
    {
        s = pow(1.01, (value-zoom));
    }
    else                                                //缩小
    {
        s = pow(1/1.01, (zoom-value));
    }

    scale(s, s);

    zoom = value;
}


//以地图图片重绘场景的北京来实现地图显示
void MapWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->drawPixmap(int(sceneRect().left()), int(sceneRect().top()), map);
}



//响应鼠标移动事件,完成某点在各层坐标中的映射及显示
void MapWidget::mouseMoveEvent(QMouseEvent *event)
{
    //QGraphicsView 坐标
    QPoint viewPoint = event->pos();
    viewCoord->setText(QString::number(viewPoint.x()) + "," + QString::number(viewPoint.y()));

    //QGraphicsScene坐标
    QPointF scenePoint = mapToScene(viewPoint);
    sceneCoord->setText(QString::number(scenePoint.x()) + "," + QString::number(scenePoint.y()));

    //地图坐标（经，纬度值）
    QPointF labLon = mapToMap(scenePoint);
    mapCoord->setText(QString::number(labLon.x()) + "," + QString::number(labLon.y()));
}


//完成场景坐标到地图坐标的转换
QPointF MapWidget::mapToMap(QPointF p)
{
    QPointF latLon;

    qreal w = sceneRect().width();
    qreal h = sceneRect().height();

    qreal lon = y1-((h/2+p.y())*abs(y1-y2)/h);
    qreal lat = x1+((w/2+p.x())*abs(x1-x2)/w);

    latLon.setX(lat);
    latLon.setY(lon);

    return latLon;
}

















