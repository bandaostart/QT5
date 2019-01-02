#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWidget = new QWidget(this);

    //左侧
    UserNameLabel       = new QLabel(tr("用户名： "));
    UserNameLineEdit    = new QLineEdit();
    NameLabel           = new QLabel(tr("姓名： "));
    NameLineEdit        = new QLineEdit();
    SexLabel            = new QLabel(tr("性别： "));
    SexComboBox         = new QComboBox;
    SexComboBox->addItem(tr("女"));
    SexComboBox->addItem(tr("男"));
    DepartmentLabel     = new QLabel(tr("部门： "));
    DepartmentTextEdit  = new QTextEdit;
    AgeLabel            = new QLabel(tr("年龄： "));
    AgeLineEdit         = new QLineEdit;
    OtherLabel          = new QLabel(tr("备注： "));
    OtherLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);             //设置控件风格

    LeftLayout          = new QGridLayout();
    LeftLayout->addWidget(UserNameLabel, 0, 0);
    LeftLayout->addWidget(UserNameLineEdit, 0, 1);

    LeftLayout->addWidget(NameLabel, 1, 0);
    LeftLayout->addWidget(NameLineEdit, 1, 1);

    LeftLayout->addWidget(SexLabel, 2, 0);
    LeftLayout->addWidget(SexComboBox, 2, 1);

    LeftLayout->addWidget(DepartmentLabel, 3, 0);
    LeftLayout->addWidget(DepartmentTextEdit, 3, 1);

    LeftLayout->addWidget(AgeLabel, 4, 0);
    LeftLayout->addWidget(AgeLineEdit, 4, 1);

    LeftLayout->addWidget(OtherLabel, 5, 0, 1, 2);

    LeftLayout->setColumnStretch(0, 1);                                   //设置两列的占比
    LeftLayout->setColumnStretch(1, 3);


    //右侧
    HeadLabel = new QLabel(tr("头像： "));
    HeadIconLabel = new QLabel(tr("图片"));

    UpdateHeadBtn = new QPushButton(tr("更新"));

    TopRightLayout = new QHBoxLayout();
    TopRightLayout->setSpacing(20);                                       //设置各个控件之间的间距
    TopRightLayout->addWidget(HeadLabel);
    TopRightLayout->addWidget(HeadIconLabel);
    TopRightLayout->addWidget(UpdateHeadBtn);

    IntroductionLabel = new QLabel(tr("个人说明"));
    IntroductionTextEdit = new QTextEdit;

    RightLayout = new QVBoxLayout();
    RightLayout->setMargin(10);                                           //设置对话框边距
    RightLayout->addLayout(TopRightLayout);
    RightLayout->addWidget(IntroductionLabel);
    RightLayout->addWidget(IntroductionTextEdit);


    //底部
    OkBtn       = new QPushButton(tr("确定"));
    CancelBtn   = new QPushButton(tr("取消"));

    ButtomLayout = new QHBoxLayout();
    ButtomLayout->addStretch();
    ButtomLayout->addWidget(OkBtn);
    ButtomLayout->addWidget(CancelBtn);


    //总体布局
    QGridLayout *mainLayout = new QGridLayout(MainWidget);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addLayout(LeftLayout, 0, 0);
    mainLayout->addLayout(RightLayout, 0, 1);
    mainLayout->addLayout(ButtomLayout,1, 0, 1, 2);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);              //设置最优化显示，并且设置用户无法改变大小

    MainWidget->setLayout(mainLayout);

    this->setCentralWidget(MainWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}
