#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Qt5::WindowFlags枚举类型
    //Qt::Widget: QWidget构造函数的默认值，如果新的窗口部件没有父窗口部件，则它是一个独立的窗口，否则就是一个子窗口部件
    //Qt::Window: 无论是否有父窗口部件，新窗口部件都是一个窗口，通常有一个窗口边框和一个标题栏
    //Qt::Dialog: 新窗口部件是一个对话框，
    //Qt::Sheet:  新窗口部件是一个macintosh表单
    //Qt::Drawer: 新窗口部件是一个Macintosh抽屉(drawer)
    //Qt::Popup:  新窗口部件是一个弹出式顶层窗口
    //Qt::Tool:   新窗口部件是一个工具窗口
    //Qt::ToolTip:新窗口部件是一个提示窗口，没有标题栏和窗口边框
    //Qt::SplashScreen:新窗口部件是一个欢迎窗口
    //Qt::Desktop:新窗口部件是桌面
    //Qt::SubWindow:新窗口部件是一个子窗口
    //Qt::MSWindowsFiredSizeDialogHint:为Windows系统上的窗口装饰一个窄的对话框边框，通常这个提示用于固定大小的对话框
    //Qt::MSWindowOwnDC:为Windows系统上的窗口添加自身的显示上下文菜单
    //Qt::X11BypassWindowManagerHint:完全忽视窗口管理器，产生一个无窗口边框的窗口
    //Qt::FramelessWindowHint:产生一个无窗口边框的窗口，用户无法移动和改变它的大小
    //Qt::CustomizwWindowHint:关闭默认的窗口标题提示
    //Qt::WindowTitleHint:为窗口装饰一个标题栏
    //Qt::WindowSystemMenuHint:为窗口添加一个窗口系统菜单，并尽可能地添加一个关闭按钮
    //Qt::WindowMinimizeButtonHint:为窗口添加一个最小化按钮
    //Qt::WindowMaximizeButtonHint:为窗口添加一个最大化按钮
    //Qt::WindowMinMaxButtonsHint:为窗口添加一个最小 一个最大按钮
    //Qt::WindowContextHelpButtonHint:为窗口添加一个上下文帮助按钮
    //Qt::WindowStaysOnTopHint:告知窗口系统，该窗口停留在所有窗口上面
    //Qt::WindowType_Mask:一个用于提取窗口标识中的窗口类型部分的掩码
    this->setWindowFlags(Qt::WindowContextHelpButtonHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}
