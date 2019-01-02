#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    //画板窗体
    paintArea = new PaintArea;


    //属性设置
    rightLayout = new QGridLayout();
    for (int i=0; i<Attributes_Num; i++)
    {
        AttributesData.Name[i] = new QLabel;
        rightLayout->addWidget(AttributesData.Name[i], i, 0);

        switch (i)
        {
            case ShapeNum:
            {
                AttributesData.Name[i]->setText(tr("形状"));
                AttributesData.Content[i].ComboBox = new QComboBox;
                //addItem()函数可以插入与文本相对应的具体数据，通常为枚举类型数据
                AttributesData.Content[i].ComboBox->addItem(tr("Line"),       PaintArea::Line);
                AttributesData.Content[i].ComboBox->addItem(tr("Rectangle"),  PaintArea::Rectangle);
                AttributesData.Content[i].ComboBox->addItem(tr("RoundeRect"), PaintArea::RoundRect);
                AttributesData.Content[i].ComboBox->addItem(tr("Ellipse"),    PaintArea::Ellipse);
                AttributesData.Content[i].ComboBox->addItem(tr("Polygon"),    PaintArea::Polygon);
                AttributesData.Content[i].ComboBox->addItem(tr("Polyline"),   PaintArea::Polyline);
                AttributesData.Content[i].ComboBox->addItem(tr("Points"),     PaintArea::Points);
                AttributesData.Content[i].ComboBox->addItem(tr("Arc"),        PaintArea::Arc);
                AttributesData.Content[i].ComboBox->addItem(tr("Path"),       PaintArea::Path);
                AttributesData.Content[i].ComboBox->addItem(tr("Text"),       PaintArea::Text);
                AttributesData.Content[i].ComboBox->addItem(tr("Pixmap"),     PaintArea::Pixmap);
                connect(AttributesData.Content[i].ComboBox, SIGNAL(activated(int)), this, SLOT(ShowShape(int)));
                rightLayout->addWidget(AttributesData.Content[i].ComboBox, i, 1);


                break;
            }

            case PenColorNum:
            {
                AttributesData.Name[i]->setText(tr("画笔颜色"));
                AttributesData.Content[i].PushButton = new QPushButton;
                AttributesData.Content[i].PushButton->setAutoFillBackground(false);
                AttributesData.Content[i].PushButton->setPalette(QPalette(QPalette::Window, Qt::blue));

                buttionSize = QSize(158, 20);
                AttributesData.Content[i].PushButton->setIconSize(buttionSize);
                QPixmap pix(buttionSize);
                pix.fill(QColor(AttributesData.Content[i].PushButton->palette().color(QPalette::Window)));
                AttributesData.Content[i].PushButton->setIcon(QIcon(pix));

                connect(AttributesData.Content[i].PushButton, SIGNAL(clicked(bool)), this, SLOT(ShowPenColor()));
                rightLayout->addWidget(AttributesData.Content[i].PushButton, i, 1);


                break;
            }

            case PenWidthNum:
            {
                AttributesData.Name[i]->setText(tr("画笔宽度"));
                AttributesData.Content[i].SpinBox = new QSpinBox;
                AttributesData.Content[i].SpinBox->setRange(0,20);
                connect(AttributesData.Content[i].SpinBox, SIGNAL(valueChanged(int)), this, SLOT(ShowPenWidth(int)));
                rightLayout->addWidget(AttributesData.Content[i].SpinBox, i, 1);


                break;
            }

            case PenStyleNum:
            {
                AttributesData.Name[i]->setText(tr("画笔风格"));
                //static_cast强制类型转换
                AttributesData.Content[i].ComboBox = new QComboBox;
                AttributesData.Content[i].ComboBox->addItem(tr("DashLine"),       static_cast<int>(Qt::DashLine));
                AttributesData.Content[i].ComboBox->addItem(tr("DotLine"),        static_cast<int>(Qt::DotLine));
                AttributesData.Content[i].ComboBox->addItem(tr("DashDotLine"),    static_cast<int>(Qt::DashDotLine));
                AttributesData.Content[i].ComboBox->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));
                AttributesData.Content[i].ComboBox->addItem(tr("CustomDashLine"), static_cast<int>(Qt::CustomDashLine));
                connect(AttributesData.Content[i].ComboBox, SIGNAL(activated(int)), this, SLOT(ShowPenStyle(int)));
                rightLayout->addWidget(AttributesData.Content[i].ComboBox, i, 1);

                break;
            }

            case PenCapNum:
            {
                AttributesData.Name[i]->setText(tr("画笔顶帽"));
                AttributesData.Content[i].ComboBox = new QComboBox;
                AttributesData.Content[i].ComboBox->addItem(tr("SquareCap"),       (Qt::SquareCap));
                AttributesData.Content[i].ComboBox->addItem(tr("FlatCap"),         (Qt::FlatCap));
                AttributesData.Content[i].ComboBox->addItem(tr("RoundCap"),        (Qt::RoundCap));
                connect(AttributesData.Content[i].ComboBox, SIGNAL(activated(int)), this, SLOT(ShowPenCap(int)));
                rightLayout->addWidget(AttributesData.Content[i].ComboBox, i, 1);

                break;
            }

            case PenJoinNum:
            {
                AttributesData.Name[i]->setText(tr("画笔连接点"));
                AttributesData.Content[i].ComboBox = new QComboBox;
                AttributesData.Content[i].ComboBox->addItem(tr("BevelJoin"),       (Qt::BevelJoin));
                AttributesData.Content[i].ComboBox->addItem(tr("MiterJoin"),       (Qt::MiterJoin));
                AttributesData.Content[i].ComboBox->addItem(tr("RoundJoin"),       (Qt::RoundJoin));
                connect(AttributesData.Content[i].ComboBox, SIGNAL(activated(int)), this, SLOT(ShowPenJoin(int)));
                rightLayout->addWidget(AttributesData.Content[i].ComboBox, i, 1);

                break;
            }

            case FillRuleNum:
            {
                AttributesData.Name[i]->setText(tr("填充模式"));
                AttributesData.Content[i].ComboBox = new QComboBox;
                AttributesData.Content[i].ComboBox->addItem(tr("Odd Even"),        (Qt::OddEvenFill));
                AttributesData.Content[i].ComboBox->addItem(tr("Winding"),         (Qt::WindingFill));
                connect(AttributesData.Content[i].ComboBox, SIGNAL(activated(int)), this, SLOT(ShowFillRule()));
                rightLayout->addWidget(AttributesData.Content[i].ComboBox, i, 1);

                break;
            }

            case SpreadNum:
            {
                AttributesData.Name[i]->setText(tr("展铺效果"));
                AttributesData.Content[i].ComboBox = new QComboBox;
                AttributesData.Content[i].ComboBox->addItem(tr("PadSpread"),       (QGradient::PadSpread));
                AttributesData.Content[i].ComboBox->addItem(tr("RepeatSpread"),    (QGradient::RepeatSpread));
                AttributesData.Content[i].ComboBox->addItem(tr("ReflectSpread"),   (QGradient::ReflectSpread));
                connect(AttributesData.Content[i].ComboBox, SIGNAL(activated(int)), this, SLOT(ShowSpreadStyle()));
                rightLayout->addWidget(AttributesData.Content[i].ComboBox, i, 1);

                break;
            }

            case BrushColorNum:
            {
                AttributesData.Name[i]->setText(tr("画刷颜色"));
                AttributesData.Content[i].PushButton = new QPushButton;
                AttributesData.Content[i].PushButton->setAutoFillBackground(false);
                AttributesData.Content[i].PushButton->setPalette(QPalette(Qt::Window, Qt::red));

                buttionSize = QSize(158, 20);
                AttributesData.Content[i].PushButton->setIconSize(buttionSize);
                QPixmap pix(buttionSize);
                pix.fill(QColor(AttributesData.Content[i].PushButton->palette().color(QPalette::Window)));
                AttributesData.Content[i].PushButton->setIcon(QIcon(pix));

                connect(AttributesData.Content[i].PushButton, SIGNAL(clicked(bool)), this, SLOT(ShowBrushColor()));
                rightLayout->addWidget(AttributesData.Content[i].PushButton, i, 1);

                break;
            }

            case BrushStyleNum:
            {
                AttributesData.Name[i]->setText(tr("画刷风格"));
                AttributesData.Content[i].ComboBox = new QComboBox;
                AttributesData.Content[i].ComboBox->addItem(tr("SolidPattern"),         static_cast<int>(Qt::SolidPattern));
                AttributesData.Content[i].ComboBox->addItem(tr("Dense1Pattern"),        static_cast<int>(Qt::Dense1Pattern));
                AttributesData.Content[i].ComboBox->addItem(tr("Dense2Pattern"),        static_cast<int>(Qt::Dense2Pattern));
                AttributesData.Content[i].ComboBox->addItem(tr("Dense3Pattern"),        static_cast<int>(Qt::Dense3Pattern));
                AttributesData.Content[i].ComboBox->addItem(tr("Dense4Pattern"),        static_cast<int>(Qt::Dense4Pattern));
                AttributesData.Content[i].ComboBox->addItem(tr("Dense5Pattern"),        static_cast<int>(Qt::Dense5Pattern));
                AttributesData.Content[i].ComboBox->addItem(tr("Dense6Pattern"),        static_cast<int>(Qt::Dense6Pattern));
                AttributesData.Content[i].ComboBox->addItem(tr("Dense7Pattern"),        static_cast<int>(Qt::Dense7Pattern));
                AttributesData.Content[i].ComboBox->addItem(tr("HorPattern"),           static_cast<int>(Qt::HorPattern));
                AttributesData.Content[i].ComboBox->addItem(tr("VerPattern"),           static_cast<int>(Qt::VerPattern));
                AttributesData.Content[i].ComboBox->addItem(tr("CrossPattern"),         static_cast<int>(Qt::CrossPattern));
                AttributesData.Content[i].ComboBox->addItem(tr("BDiagPattern"),         static_cast<int>(Qt::BDiagPattern));
                AttributesData.Content[i].ComboBox->addItem(tr("FDiagPattern"),         static_cast<int>(Qt::FDiagPattern));
                AttributesData.Content[i].ComboBox->addItem(tr("DiagCrossPattern"),     static_cast<int>(Qt::DiagCrossPattern));
                AttributesData.Content[i].ComboBox->addItem(tr("LinearGradientPattern"),static_cast<int>(Qt::LinearGradientPattern));
                AttributesData.Content[i].ComboBox->addItem(tr("ConicalGradientPattern"),static_cast<int>(Qt::ConicalGradientPattern));
                AttributesData.Content[i].ComboBox->addItem(tr("RadialGradientPattern"), static_cast<int>(Qt::RadialGradientPattern));
                AttributesData.Content[i].ComboBox->addItem(tr("TexturePattern"),        static_cast<int>(Qt::TexturePattern));
                connect(AttributesData.Content[i].ComboBox, SIGNAL(activated(int)), this, SLOT(ShowBrush(int)));
                rightLayout->addWidget(AttributesData.Content[i].ComboBox, i, 1);

                break;
            }
        }
    }


    //整体布局
    QHBoxLayout *mainLayout = new QHBoxLayout(ui->centralWidget);
    mainLayout->addWidget(paintArea);
    mainLayout->addLayout(rightLayout);
    mainLayout->setStretchFactor(paintArea, 1);
    mainLayout->setStretchFactor(rightLayout, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//显示形状
void MainWindow::ShowShape(int value)
{
    PaintArea::Shape shape = PaintArea::Shape(AttributesData.Content[ShapeNum].ComboBox->itemData(value, Qt::UserRole).toInt());

    paintArea->setShape(shape);
}


//设置pen宽度
void MainWindow::ShowPenWidth(int value)
{
    QColor color = AttributesData.Content[PenColorNum].PushButton->palette().color(QPalette::Window);
    Qt::PenStyle    style = Qt::PenStyle(AttributesData.Content[PenStyleNum].ComboBox->itemData(AttributesData.Content[PenStyleNum].ComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenCapStyle   cap = Qt::PenCapStyle(AttributesData.Content[PenCapNum].ComboBox->itemData(AttributesData.Content[PenCapNum].ComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(AttributesData.Content[PenJoinNum].ComboBox->itemData(AttributesData.Content[PenJoinNum].ComboBox->currentIndex(), Qt::UserRole).toInt());

    paintArea->setPen(QPen(color, value, style, cap, join));
}

//设置pen颜色
void MainWindow:: ShowPenColor()
{
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue));
    AttributesData.Content[PenColorNum].PushButton->setPalette(QPalette(QPalette::Window, color));
    QPixmap pix(buttionSize);
    pix.fill(QColor(AttributesData.Content[PenColorNum].PushButton->palette().color(QPalette::Window)));   //为pix填充当前遍历的颜色
    AttributesData.Content[PenColorNum].PushButton->setIcon(QIcon(pix));

    int value = AttributesData.Content[PenWidthNum].SpinBox->value();

    Qt::PenStyle    style = Qt::PenStyle(AttributesData.Content[PenStyleNum].ComboBox->itemData(AttributesData.Content[PenStyleNum].ComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenCapStyle   cap = Qt::PenCapStyle(AttributesData.Content[PenCapNum].ComboBox->itemData(AttributesData.Content[PenCapNum].ComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(AttributesData.Content[PenJoinNum].ComboBox->itemData(AttributesData.Content[PenJoinNum].ComboBox->currentIndex(), Qt::UserRole).toInt());


    paintArea->setPen(QPen(color, value, style, cap, join));
}

//设置pen风格
void MainWindow::ShowPenStyle(int styleValue)
{
    QColor color = AttributesData.Content[PenColorNum].PushButton->palette().color(QPalette::Window);

    int value = AttributesData.Content[PenWidthNum].SpinBox->value();

    Qt::PenStyle    style = Qt::PenStyle(AttributesData.Content[PenStyleNum].ComboBox->itemData(styleValue, Qt::UserRole).toInt());
    Qt::PenCapStyle   cap = Qt::PenCapStyle(AttributesData.Content[PenCapNum].ComboBox->itemData(AttributesData.Content[PenCapNum].ComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(AttributesData.Content[PenJoinNum].ComboBox->itemData(AttributesData.Content[PenJoinNum].ComboBox->currentIndex(), Qt::UserRole).toInt());


    paintArea->setPen(QPen(color, value, style, cap, join));
}


//设置pen顶帽
void MainWindow::ShowPenCap(int capValue)
{
    QColor color = AttributesData.Content[PenColorNum].PushButton->palette().color(QPalette::Window);

    int value = AttributesData.Content[PenWidthNum].SpinBox->value();

    Qt::PenStyle    style = Qt::PenStyle(AttributesData.Content[PenStyleNum].ComboBox->itemData(AttributesData.Content[PenStyleNum].ComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenCapStyle   cap = Qt::PenCapStyle(AttributesData.Content[PenCapNum].ComboBox->itemData(capValue, Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(AttributesData.Content[PenJoinNum].ComboBox->itemData(AttributesData.Content[PenJoinNum].ComboBox->currentIndex(), Qt::UserRole).toInt());


    paintArea->setPen(QPen(color, value, style, cap, join));
}


//设置pen连接点
void MainWindow::ShowPenJoin(int joinValue)
{
    QColor color = AttributesData.Content[PenColorNum].PushButton->palette().color(QPalette::Window);

    int value = AttributesData.Content[PenWidthNum].SpinBox->value();

    Qt::PenStyle    style = Qt::PenStyle(AttributesData.Content[PenStyleNum].ComboBox->itemData(AttributesData.Content[PenStyleNum].ComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenCapStyle   cap = Qt::PenCapStyle(AttributesData.Content[PenCapNum].ComboBox->itemData(AttributesData.Content[PenCapNum].ComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(AttributesData.Content[PenJoinNum].ComboBox->itemData(joinValue, Qt::UserRole).toInt());


    paintArea->setPen(QPen(color, value, style, cap, join));
}


//设置展铺效果
void MainWindow::ShowSpreadStyle()
{
    spread = QGradient::Spread(AttributesData.Content[SpreadNum].ComboBox->itemData(AttributesData.Content[SpreadNum].ComboBox->currentIndex(), Qt::UserRole).toInt());
}



//设置填充区域
void MainWindow::ShowFillRule()
{
    Qt::FillRule rule = Qt::FillRule(AttributesData.Content[FillRuleNum].ComboBox->itemData(AttributesData.Content[FillRuleNum].ComboBox->currentIndex(), Qt::UserRole).toInt());
    paintArea->setFillRule(rule);
}

//设置brush颜色
void MainWindow::ShowBrushColor()
{
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue));
    AttributesData.Content[BrushColorNum].PushButton->setPalette(QPalette(QPalette::Window, color));
    QPixmap pix(buttionSize);
    pix.fill(QColor(AttributesData.Content[BrushColorNum].PushButton->palette().color(QPalette::Window)));   //为pix填充当前遍历的颜色
    AttributesData.Content[BrushColorNum].PushButton->setIcon(QIcon(pix));

    ShowBrush(AttributesData.Content[BrushStyleNum].ComboBox->currentIndex());
}


void MainWindow::ShowBrush(int value)
{
    QColor color = AttributesData.Content[BrushColorNum].PushButton->palette().color(QPalette::Window);
    Qt::BrushStyle style = Qt::BrushStyle(AttributesData.Content[BrushStyleNum].ComboBox->itemData(value, Qt::UserRole).toInt());

    if (style == Qt::LinearGradientPattern)
    {
        QLinearGradient linearGradient(0,0, 400, 400);
        linearGradient.setColorAt(0.0, Qt::white);
        linearGradient.setColorAt(0.2, color);
        linearGradient.setColorAt(1.0, Qt::black);
        linearGradient.setSpread(spread);
        paintArea->setBrush(linearGradient);
    }else if (style == Qt::RadialGradientPattern)
    {
        QRadialGradient radialGradient(200, 200, 150, 150, 100);
        radialGradient.setColorAt(0.0, Qt::white);
        radialGradient.setColorAt(0.2, color);
        radialGradient.setColorAt(1.0, Qt::black);
        radialGradient.setSpread(spread);
        paintArea->setBrush(radialGradient);
    }else if (style == Qt::ConicalGradientPattern)
    {
        QConicalGradient conicalGradient(200, 200, 30);
        conicalGradient.setColorAt(0.0, Qt::white);
        conicalGradient.setColorAt(0.2, color);
        conicalGradient.setColorAt(1.0, Qt::black);
        conicalGradient.setSpread(spread);
        paintArea->setBrush(conicalGradient);
    }else if(style == Qt::TexturePattern)
    {
        paintArea->setBrush(QBrush(QPixmap(":/imag/image.png")));
    }
    else
    {
        paintArea->setBrush(QBrush(color, style));
    }
}


