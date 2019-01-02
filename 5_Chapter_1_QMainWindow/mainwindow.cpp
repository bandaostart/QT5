#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建主显示区域
    CreatMainArea();

    //创建actions
    CreatActions();

    //创建menus
    CreatMenus();

    //创建工具栏
    CreatToolBars();


}

MainWindow::~MainWindow()
{
    delete ui;
}





//创建Actions
void MainWindow::CreatActions()
{
    //文件菜单项action
    filesActions[OpenFileActionNum] = new QAction(QIcon(":/image/open.png"), tr("打开"), this);
    filesActions[OpenFileActionNum]->setShortcut(tr("Ctrl+O"));
    filesActions[OpenFileActionNum]->setStatusTip(tr("打开一个文件"));
    connect(filesActions[OpenFileActionNum], SIGNAL(triggered()), this, SLOT(ShowOpenFile()));

    filesActions[NewFileActionNum] = new QAction(QIcon(":/image/new.png"), tr("新建"), this);
    filesActions[NewFileActionNum]->setShortcut(tr("Ctrl+N"));
    filesActions[NewFileActionNum]->setStatusTip(tr("新建一个文件"));
    connect(filesActions[NewFileActionNum], SIGNAL(triggered()), this, SLOT(ShowNewFile()));

    filesActions[PrintTextActionNum] = new QAction(QIcon(":/image/printText.png"), tr("打印文本"), this);
    filesActions[PrintTextActionNum]->setStatusTip(tr("打印一个文件"));
    connect(filesActions[PrintTextActionNum], SIGNAL(triggered()), this, SLOT(ShowPrintText()));

    filesActions[PrintImageActionNum] = new QAction(QIcon(":/image/printImage.png"), tr("打印图像"), this);
    filesActions[PrintImageActionNum]->setStatusTip(tr("打印一幅图片"));
    connect(filesActions[PrintImageActionNum], SIGNAL(triggered()), this, SLOT(ShowPrintImage()));

    filesActions[ExitActionNum] = new QAction(QIcon(":/image/new.png"), tr("退出"), this);
    filesActions[ExitActionNum]->setShortcut(tr("Ctrl+Q"));
    filesActions[ExitActionNum]->setStatusTip(tr("退出程序"));
    connect(filesActions[ExitActionNum], SIGNAL(triggered()), this, SLOT(close()));

    //编辑菜单项action
    editActions[CopyActionNum] = new QAction(QIcon(":/image/copy.png"), tr("复制"), this);
    editActions[CopyActionNum]->setShortcut(tr("Ctrl+C"));
    editActions[CopyActionNum]->setStatusTip(tr("复制文件"));
    connect(editActions[CopyActionNum], SIGNAL(triggered()), textEdit, SLOT(copy()));

    editActions[CutActionNum] = new QAction(QIcon(":/image/cut.png"), tr("剪切"), this);
    editActions[CutActionNum]->setShortcut(tr("Ctrl+X"));
    editActions[CutActionNum]->setStatusTip(tr("剪切文件"));
    connect(editActions[CutActionNum], SIGNAL(triggered()), textEdit, SLOT(cut()));

    editActions[PasteActionNum] = new QAction(QIcon(":/image/paste.png"), tr("粘贴"), this);
    editActions[PasteActionNum]->setShortcut(tr("Ctrl+V"));
    editActions[PasteActionNum]->setStatusTip(tr("粘贴文件"));
    connect(editActions[PasteActionNum], SIGNAL(triggered()), textEdit, SLOT(paste()));

    editActions[AboutActionNum] = new QAction(tr("关于"), this);
    //connect(editActions[AboutActionNum], SIGNAL(triggered()), this, SLOT(Qapplication::aboutQt()));

    editActions[ZoomInActionNum] = new QAction(QIcon(":/image/zoomin.png"), tr("放大"), this);
    editActions[ZoomInActionNum]->setStatusTip(tr("放大一张图片"));
    connect(editActions[ZoomInActionNum], SIGNAL(triggered()), this, SLOT(ShowZoomIn()));

    editActions[ZoomOutActionNum] = new QAction(QIcon(":/image/zoomout.png"), tr("缩小"), this);
    editActions[ZoomOutActionNum]->setStatusTip(tr("缩小一张图片"));
    connect(editActions[ZoomOutActionNum], SIGNAL(triggered()), this, SLOT(ShowZoomOut()));

    //旋转菜单项action
    rotateActions[Rotate90ActionNum] = new QAction(QIcon(":/image/rotate90.png"), tr("旋转90°"), this);
    rotateActions[Rotate90ActionNum]->setStatusTip(tr("旋转一幅图片90°"));
    connect(rotateActions[Rotate90ActionNum], SIGNAL(triggered()), this, SLOT(ShowRotate90()));

    rotateActions[Rotate180ActionNum] = new QAction(QIcon(":/image/rotate180.png"), tr("旋转180°"), this);
    rotateActions[Rotate180ActionNum]->setStatusTip(tr("旋转一幅图片180°"));
    connect(rotateActions[Rotate180ActionNum], SIGNAL(triggered()), this, SLOT(ShowRotate180()));

    rotateActions[Rotate270ActionNum] = new QAction(QIcon(":/image/rotate270.png"), tr("旋转270°"), this);
    rotateActions[Rotate270ActionNum]->setStatusTip(tr("旋转一幅图片270°"));
    connect(rotateActions[Rotate270ActionNum], SIGNAL(triggered()), this, SLOT(ShowRotate270()));

    //镜像菜单项
    mirrorActions[MirrorVerticalActionNum] = new QAction(QIcon(":/image/mirrorVertical.png"), tr("纵向镜像"), this);
    mirrorActions[MirrorVerticalActionNum]->setStatusTip(tr("对一张图做纵向镜像"));
    connect(mirrorActions[MirrorVerticalActionNum], SIGNAL(triggered()), this, SLOT(ShowMirrorVertical()));

    mirrorActions[MirrorHorizontalActionNum] = new QAction(QIcon(":/image/mirrorHorizontal.png"), tr("横向镜像"), this);
    mirrorActions[MirrorHorizontalActionNum]->setStatusTip(tr("对一张图做横向镜像"));
    connect(mirrorActions[MirrorHorizontalActionNum], SIGNAL(triggered()), this, SLOT(ShowMirrorHorizontal()));

    //操作菜单项action
    OperateActions[undoActionNum] = new QAction(QIcon(":/image/undo.png"), tr("撤销"), this);
    connect(OperateActions[undoActionNum], SIGNAL(triggered()), textEdit, SLOT(undo()));

    OperateActions[redoActionNum] = new QAction(QIcon(":/image/redo.png"), tr("重做"), this);
    connect(OperateActions[redoActionNum], SIGNAL(triggered()), textEdit, SLOT(redo()));


    //字体菜单项
    fontLabel      = new QLabel(tr("字体"));
    fontComboBox   = new QFontComboBox;
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);
    connect(fontComboBox, SIGNAL(activated(QString)), this, SLOT(ShowFontComboBox(QString)));

    fontSizeLabel    = new QLabel(tr("字号"));
    fontSizeComboBox = new QComboBox;
    QFontDatabase  db;
    foreach (int size, db.standardSizes())
    {
        fontSizeComboBox->addItem(QString::number(size));
    }
    fontSizeComboBox->setCurrentIndex(4);
    connect(fontSizeComboBox, SIGNAL(activated(QString)), this, SLOT(ShowFontSizeComboBox(QString)));

    FontButtons[boldButtonNum]   =  new QToolButton;
    FontButtons[boldButtonNum]->setIcon(QIcon(":/image/bold.png"));
    FontButtons[boldButtonNum]->setCheckable(true);
    connect(FontButtons[boldButtonNum], SIGNAL(clicked()), this, SLOT(ShowFontBoldBtn()));

    FontButtons[italicButtonNum] =  new QToolButton;
    FontButtons[italicButtonNum]->setIcon(QIcon(":/image/italic.png"));
    FontButtons[italicButtonNum]->setCheckable(true);
    connect(FontButtons[italicButtonNum], SIGNAL(clicked()), this, SLOT(ShowFontItalicBtn()));

    FontButtons[underlineButtonNum] =  new QToolButton;
    FontButtons[underlineButtonNum]->setIcon(QIcon(":/image/underline.png"));
    FontButtons[underlineButtonNum]->setCheckable(true);
    connect(FontButtons[underlineButtonNum], SIGNAL(clicked()), this, SLOT(ShowFontUnderLineBtn()));

    FontButtons[colorButtonNum]     =  new QToolButton;
    FontButtons[colorButtonNum]->setIcon(QIcon(":/image/color.png"));
    connect(FontButtons[colorButtonNum], SIGNAL(clicked()), this, SLOT(ShowFontColorBtn()));

    //排序菜单
    listLabel    = new QLabel(tr("排序"));
    listComboBox = new QComboBox;
    listComboBox->addItem("Standard");
    listComboBox->addItem("QTextListFormat::ListDisc");
    listComboBox->addItem("QTextListFormat::ListCircle");
    listComboBox->addItem("QTextListFormat::ListSquare");
    listComboBox->addItem("QTextListFormat::ListDecimal");
    listComboBox->addItem("QTextListFormat::ListLowerAlpha");
    listComboBox->addItem("QTextListFormat::ListUpperAlpha");
    listComboBox->addItem("QTextListFormat::ListLowerRoman");
    listComboBox->addItem("QTextListFormat::ListUpperRoman");
    connect(listComboBox, SIGNAL(activated(int)), this, SLOT(ShowList(int)));
    connect(textEdit->document(), SIGNAL(undoAvailable(bool)), OperateActions[undoActionNum], SLOT(setEnabled(bool)));
    connect(textEdit->document(), SIGNAL(redoAvailable(bool)), OperateActions[redoActionNum], SLOT(setEnabled(bool)));

    listActionGrp = new QActionGroup(this);
    ListAction[listLeftActionNum]   = new QAction(QIcon(":/image/left.png"), tr("左对齐"),listActionGrp);
    ListAction[listLeftActionNum]->setCheckable(true);
    ListAction[listRightActionNum]   = new QAction(QIcon(":/image/right.png"), tr("右对齐"),listActionGrp);
    ListAction[listRightActionNum]->setCheckable(true);
    ListAction[listCenterActionNum]  = new QAction(QIcon(":/image/center.png"), tr("居中"),listActionGrp);
    ListAction[listCenterActionNum]->setCheckable(true);
    ListAction[listJustifyActionNum] = new QAction(QIcon(":/image/justify.png"), tr("两端对齐"),listActionGrp);
    ListAction[listJustifyActionNum]->setCheckable(true);
    connect(listActionGrp, SIGNAL(triggered(QAction*)), this, SLOT(ShowAlignment(QAction*)));
}



//创建菜单项
void MainWindow::CreatMenus()
{
    //文件菜单
    fileMenu = ui->menuBar->addMenu(tr("文件"));
    for (int i=0; i<FileActionNums; i++)
    {
        fileMenu->addAction(filesActions[i]);
        if (i == 3)
        {
            fileMenu->addSeparator();
        }
    }

    //编辑 缩放菜单
    zoomMenu = ui->menuBar->addMenu(tr("编辑"));
    for (int i=0; i<EditActionsNums; i++)
    {
        zoomMenu->addAction(editActions[i]);
        if (i == 3)
        {
            zoomMenu->addSeparator();
        }
    }

    //旋转菜单
    rotateMenu = ui->menuBar->addMenu(tr("旋转"));
    for (int i=0; i<RotateActionNums; i++)
    {
        rotateMenu->addAction(rotateActions[i]);
    }


    //镜像菜单
    mirrorMenu = ui->menuBar->addMenu(tr("镜像"));
    for (int i=0; i<MirrorActionNums; i++)
    {
        mirrorMenu->addAction(mirrorActions[i]);
    }
}


//创建工具栏
void MainWindow::CreatToolBars()
{
    //文件菜单
    fileTool = ui->mainToolBar;
    fileTool->setToolTip("File");
    fileTool->setAllowedAreas(Qt::TopToolBarArea | Qt::LeftToolBarArea);      //设置停靠区域
    fileTool->setMovable(false);                                              //设置是否可以移动
    fileTool->addAction(filesActions[0]);
    fileTool->addAction(filesActions[1]);
    fileTool->addAction(filesActions[2]);
    fileTool->addAction(filesActions[3]);

    //编辑 缩放菜单
    zoomTool = this->addToolBar("Edit");
    zoomTool->addAction(editActions[0]);
    zoomTool->addAction(editActions[1]);
    zoomTool->addAction(editActions[2]);
    zoomTool->addSeparator();
    zoomTool->addAction(editActions[4]);
    zoomTool->addAction(editActions[5]);

    //旋转菜单
    rotateTool = this->addToolBar("rotate");
    rotateTool->addAction(rotateActions[0]);
    rotateTool->addAction(rotateActions[1]);
    rotateTool->addAction(rotateActions[2]);


    //撤销重做
    doToolBar = this->addToolBar("doEdit");
    doToolBar->addAction(OperateActions[0]);
    doToolBar->addAction(OperateActions[1]);

    //字体工具栏
    fontToolBar = this->addToolBar("Font");
    fontToolBar->addWidget(fontLabel);
    fontToolBar->addWidget(fontComboBox);
    fontToolBar->addWidget(fontSizeLabel);
    fontToolBar->addWidget(fontSizeComboBox);
    fontToolBar->addSeparator();
    for (int i=0; i<FontButtonNums; i++)
    {
        fontToolBar->addWidget(FontButtons[i]);
        if (i == 2)
        {
            fontToolBar->addSeparator();
        }
    }

    //排版工具栏
    listToolBar = addToolBar("list");
    listToolBar->addWidget(listLabel);
    listToolBar->addWidget(listComboBox);
    listToolBar->addSeparator();
    listToolBar->addActions(listActionGrp->actions());
}


//创建主显示区域
void MainWindow::CreatMainArea()
{
    imageLabel = new QLabel();
    imageLabel->setScaledContents(true);           //让图片随着QLabel的大小变化而变化
    if (img.load(":/image/image.png"))
    {
        imageLabel->setPixmap(QPixmap::fromImage(img));
    }

    textEdit = new QTextEdit();
    QTextCharFormat fmt;
    fmt.setFontFamily(tr("宋体"));
    fmt.setFontPointSize(10);
    textEdit->setCurrentCharFormat(fmt);
    textEdit->insertPlainText(tr("文本编辑常用到的类：QTextEdit、QTextDocument、QTextCharFormat、QTextCursor、QTextBlock、QTextList、QTextFrame、QTextTable、QTextBlockFormat、QTextListFormat、QTextFrameFormat、QTextTableFormat等\r\n\n"));
    textEdit->insertPlainText(tr("用QTextEdit作为输入文本的容器，在它里面输入的可编辑文本由QTextDocument作为载体\r\n\n"));
    textEdit->insertPlainText(tr("用QTextBlock、QTextList、QTextFrame QTextTable表示QTextDocument的元素，为QTextDocument的不同表现形式\r\n\n"));
    textEdit->insertPlainText(tr("用QTextCharFormat、QTextBlockFormat、QTextListFormat、QTextFrameFormat来描述每种元素的格式\r\n\n"));
    QTextImageFormat imageFormat;
    imageFormat.setName(":/image/guaxi.jpg");
    QTextCursor cursor;
    cursor.insertImage(imageFormat);

    connect(textEdit, SIGNAL(currentCharFormatChanged(QTextCharFormat)), this, SLOT(ShowCurrentFormatChanged(QTextCharFormat)));
    connect(textEdit, SIGNAL(cursorPositionChanged()), this, SLOT(ShowCursorPositionChanged()));


    QGridLayout *mainlayout = new QGridLayout(ui->centralWidget);
    mainlayout->addWidget(imageLabel,0, 0, 1, 1);
    mainlayout->addWidget(textEdit,0,1,2,1);

    QSpacerItem *verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    mainlayout->addItem(verticalSpacer, 1, 0, 1, 1);


}


/*槽函数----------------------------------------------------------------------------------------------------------------*/
//新建
void MainWindow::ShowNewFile()
{
    MainWindow *newMainWindow = new MainWindow;
    newMainWindow->show();
}

//打开
void MainWindow::ShowOpenFile()
{
    QString fileName = "";

    fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
    {
        textEdit->clear();

        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream textStream(&file);
            while (!textStream.atEnd())
            {
                textEdit->append(textStream.readLine());
            }
        }
    }
}

//打印文本
void MainWindow::ShowPrintText()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer,this);

    if (printDialog.exec())
    {
        QTextDocument *doc = textEdit->document();
        doc->print(&printer);
    }
}


//打印图片
void MainWindow::ShowPrintImage()
{
    QPrinter printer;                                      //创建一个QPrinter对象
    QPrintDialog printDialog(&printer, this);              //获得打印机配置并把参数传送给QPrinter

    if (printDialog.exec())                                //是否执行打印
    {
        QPainter painter(&printer);                        //创建一个QPainter对象，并指定绘图设备为一个QPrinter对象
        QRect    rect = painter.viewport();                //获取QPainter对象的视口举行区域
        QSize    size = img.size();                        //获得图像的大小

        size.scale(rect.size(), Qt::KeepAspectRatio);      //按照图形的比例大小重新设置视口矩形区域
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());

        painter.setWindow(img.rect());                     //设置QPainter窗口大小为图像的大小
        painter.drawImage(0,0,img);                        //打印图像
    }
}


//图片放大
void MainWindow::ShowZoomIn()
{
    if (img.isNull())
    {
        return ;
    }

    QMatrix martix;                                  //声明一个QMatrix类的实例，按照两倍比例对水平和垂直方向进行放大，并将当前显示的图形按照
    martix.scale(2, 2);                              //该坐标矩阵进行转换
    if ((img.width() <= (ui->centralWidget->width()/2)) && (img.height() <= ui->centralWidget->height()/2))
    {
        img = img.transformed(martix);
        imageLabel->setPixmap(QPixmap::fromImage(img));  //重新设置显示图形
    }
}


//图片缩小
void MainWindow::ShowZoomOut()
{
    if (img.isNull())
    {
        return ;
    }

    QMatrix martix;                                      //声明一个QMatrix类的实例，按照两倍比例对水平和垂直方向进行放大，并将当前显示的图形按照
    martix.scale(0.5, 0.5);                              //该坐标矩阵进行转换

    if ((img.width() >= 24) && (img.width() >= 24))
    {
        img = img.transformed(martix);
        imageLabel->setPixmap(QPixmap::fromImage(img));  //重新设置显示图形
    }
}

//旋转90
void MainWindow::ShowRotate90()
{
    if (img.isNull())
    {
        return;
    }

    QMatrix matrix;
    matrix.rotate(90);

    img = img.transformed(matrix);
    imageLabel->setPixmap(QPixmap::fromImage(img));
}

//旋转180
void MainWindow::ShowRotate180()
{
    if (img.isNull())
    {
        return;
    }

    QMatrix matrix;
    matrix.rotate(180);

    img = img.transformed(matrix);
    imageLabel->setPixmap(QPixmap::fromImage(img));
}

//旋转1270
void MainWindow::ShowRotate270()
{
    if (img.isNull())
    {
        return;
    }

    QMatrix matrix;
    matrix.rotate(270);

    img = img.transformed(matrix);
    imageLabel->setPixmap(QPixmap::fromImage(img));
}


//垂直镜像
void MainWindow::ShowMirrorVertical()
{
    if(img.isNull())
    {
        return;
    }

    img = img.mirrored(false, true);
    imageLabel->setPixmap(QPixmap::fromImage(img));
}



//水平镜像
void MainWindow::ShowMirrorHorizontal()
{
    if(img.isNull())
    {
        return;
    }

    img = img.mirrored(true, false);
    imageLabel->setPixmap(QPixmap::fromImage(img));
}



//字体选择
void MainWindow::ShowFontComboBox(QString font)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(font);                          //选择的字体名称给QTextCharFormat

    QTextCursor cursor = textEdit->textCursor();       //将新的格式运用到光标选区内的字符, 获得编辑框中的光标
    if (!cursor.hasSelection())                        //若光标没有高亮选区则将光标所在处的词作为选区
    {
        cursor.select(QTextCursor::WordUnderCursor);
    }
    cursor.mergeCharFormat(fmt);                       //将字体格式应用到光标所在处的字符上
    textEdit->mergeCurrentCharFormat(fmt);             //将格式应用到选区内的所有字符上
}


//字号选择
void MainWindow::ShowFontSizeComboBox(QString fontSize)
{
    QTextCharFormat fmt;

    fmt.setFontPointSize(fontSize.toFloat());
    textEdit->mergeCurrentCharFormat(fmt);
}



//字体加粗
void MainWindow::ShowFontBoldBtn()
{
    QTextCharFormat fmt;
    fmt = textEdit->currentCharFormat();

    fmt.setFontWeight(FontButtons[boldButtonNum]->isChecked() ? QFont::Bold : QFont::Normal);
    textEdit->mergeCurrentCharFormat(fmt);
}


//字体倾斜
void MainWindow::ShowFontItalicBtn()
{
    QTextCharFormat fmt;
    fmt = textEdit->currentCharFormat();

    fmt.setFontItalic(FontButtons[italicButtonNum]->isChecked());
    textEdit->mergeCurrentCharFormat(fmt);
}


//下划线
void MainWindow::ShowFontUnderLineBtn()
{
    QTextCharFormat fmt;
    fmt = textEdit->currentCharFormat();

    fmt.setFontUnderline(FontButtons[underlineButtonNum]->isChecked());
    textEdit->mergeCurrentCharFormat(fmt);
}


//字体颜色
void MainWindow::ShowFontColorBtn()
{
    QColor color = QColorDialog::getColor(Qt::red, this);

    if (color.isValid())
    {
        QTextCharFormat fmt;
        fmt = textEdit->currentCharFormat();

        fmt.setForeground(color);
        textEdit->mergeCurrentCharFormat(fmt);
    }
}


//光标处的字体改变是实时更新到工具栏
void MainWindow::ShowCurrentFormatChanged(QTextCharFormat fmt)
{
    fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));

    fontSizeComboBox->setCurrentIndex(fontSizeComboBox->findText(QString::number(fmt.fontPointSize())));

    FontButtons[boldButtonNum]->setChecked(fmt.font().bold());
    FontButtons[italicButtonNum]->setChecked(fmt.fontItalic());
    FontButtons[underlineButtonNum]->setChecked(fmt.fontUnderline());
}


//字体对齐方式
void MainWindow::ShowAlignment(QAction *act)
{
    if (act == ListAction[listLeftActionNum])
    {
        textEdit->setAlignment(Qt::AlignLeft);
    }

    if (act == ListAction[listRightActionNum])
    {
        textEdit->setAlignment(Qt::AlignRight);
    }


    if (act == ListAction[listCenterActionNum])
    {
        textEdit->setAlignment(Qt::AlignCenter);
    }

    if (act == ListAction[listJustifyActionNum])
    {
        textEdit->setAlignment(Qt::AlignJustify);
    }
}



//光标处的文字排版改变是实时更新到工具栏
void MainWindow::ShowCursorPositionChanged()
{
   switch (textEdit->alignment())
   {
       case Qt::AlignLeft:
            ListAction[listLeftActionNum]->setChecked(true);
       break;

       case Qt::AlignRight:
            ListAction[listRightActionNum]->setChecked(true);
       break;

       case Qt::AlignCenter:
             ListAction[listCenterActionNum]->setChecked(true);
       break;

       case Qt::AlignJustify:
            ListAction[listJustifyActionNum]->setChecked(true);
       break;
   }
}


//文本排序
//QTextListFormat用于描述文本排序格式，QTextListFormat包含两个基本的属性;一个为QTextListFormat::style表示文本采用哪种排序方式，另一个为
//QTextListFormat::indent，表示排序后的缩进值,若要实现文本排序的功能则只需设置好QTexitListFormat的两个属性,并将整个格式通过QTextCursor类
//应用到文本中即可
void MainWindow::ShowList(int index)
{
    //获取编辑框的cursor指针
    QTextCursor cursor = textEdit->textCursor();

    //设置style属性
    if (index != 0)
    {
        QTextListFormat::Style style = QTextListFormat::ListDisc;
        switch (index)
        {
            default:
            case 1:
                style = QTextListFormat::ListDisc;
            break;

            case 2:
                style = QTextListFormat::ListCircle;
            break;

            case 3:
                style = QTextListFormat::ListSquare;
            break;

            case 4:
                style = QTextListFormat::ListDecimal;
            break;

            case 5:
                style = QTextListFormat::ListLowerAlpha;
            break;

            case 6:
                style = QTextListFormat::ListUpperAlpha;
            break;

            case 7:
                style = QTextListFormat::ListLowerRoman;
            break;

            case 8:
                style = QTextListFormat::ListUpperRoman;
            break;
        }




        //设置缩进值,并将格式设置到光标所在的文本处
        cursor.beginEditBlock();;

        QTextBlockFormat blockFmt = cursor.blockFormat();
        QTextListFormat  listFmt;

        if (cursor.currentList())
        {
            listFmt = cursor.currentList()->format();
        }
        else
        {
            listFmt.setIndent(blockFmt.indent()+1);
            blockFmt.setIndent(0);
            cursor.setBlockFormat(blockFmt);
        }
        listFmt.setStyle(style);
        cursor.createList(listFmt);

        cursor.endEditBlock();
    }
    else
    {
        QTextBlockFormat bfmt;

        bfmt.setObjectIndex(-1);
        cursor.mergeBlockFormat(bfmt);
    }


}



































