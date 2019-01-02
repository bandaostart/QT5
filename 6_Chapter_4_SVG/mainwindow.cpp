#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAction *openAct = new QAction(tr("打开"), this);
    connect(openAct, SIGNAL(triggered(bool)), this, SLOT(slotOpenFile()));

    ui->menuBar->addAction(openAct);

    svgWindow = new SvgWindow;
    setCentralWidget(svgWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::slotOpenFile()
{
    QString name = QFileDialog::getOpenFileName(this, tr("打开"), ":/", "svg files(*.svg)");

    svgWindow->setFile(name);
}
