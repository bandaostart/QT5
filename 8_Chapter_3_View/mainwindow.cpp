#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createAction();
    createMenu();
    setupModel();
    setupView();

    resize(600, 600);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//创建action
void MainWindow::createAction()
{
    openAct = new QAction(tr("打开"), this);
    connect(openAct, SIGNAL(triggered(bool)), this, SLOT(slotOpen()));
}

//创建菜单
void MainWindow::createMenu()
{
    fileMenu = new QMenu(tr("文件"), this);
    fileMenu->addAction(openAct);
    ui->menuBar->addMenu(fileMenu);
}

//创建一个model
void MainWindow::setupModel()
{
    model = new QStandardItemModel(4, 4, this);
    model->setHeaderData(0, Qt::Horizontal, tr("部门"));
    model->setHeaderData(1, Qt::Horizontal, tr("男"));
    model->setHeaderData(2, Qt::Horizontal, tr("女"));
    model->setHeaderData(3, Qt::Horizontal, tr("退休"));
}

//设置视图
void MainWindow::setupView()
{
    table = new QTableView;                                                 //新建一个QTableView对象

    table->setModel(model);                                                 //为QTableView对象设置相同的Model

    QItemSelectionModel *selsectionModel = new QItemSelectionModel(model);  //新建一个QItemSelectionModel对象作为QTableView对象使用的选择模型
    table->setSelectionModel(selsectionModel);
                                                                            //连接选择模型的selectionChanged()信号与QTableView对象的selectionChanged()槽函数
                                                                            //以便使自定义的HistogramView对象中的选择变化能够反映到QTableView对象的显示中
    connect(selsectionModel, SIGNAL(selectionChanged(QItemSelection, ItemSelection)), table, SLOT(selectionChanged(QItemSelection,QItemSelection)));

    splitter = new QSplitter;
    splitter->setOrientation(Qt::Vertical);

    splitter->addWidget(table);

    this->setCentralWidget(splitter);

}



//槽函数文件打开标准对话框
void MainWindow::slotOpen()
{
    QString name;

    name = QFileDialog::getOpenFileName(this, tr("打开"), ".", "histogramfiles(*.txt)");

    if (!name.isEmpty())
    {
        openFile(name);
    }
}

//完成打开所选的文件内容
void MainWindow::openFile(QString path)
{
    if (!path.isEmpty())
    {
        QFile file(path);

        if (file.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream stream(&file);
            QString line;

            model->removeRows(0, model->rowCount(QModelIndex()), QModelIndex());
            int row = 0;

            do
            {
                line = stream.readLine();
                if (!line.isEmpty())
                {
                    model->insertRows(row, 1, QModelIndex());
                    QStringList pieces = line.split(",", QString::SkipEmptyParts);
                    model->setData(model->index(row, 0, QModelIndex()), pieces.value(0));
                    model->setData(model->index(row, 1, QModelIndex()), pieces.value(1));
                    model->setData(model->index(row, 2, QModelIndex()), pieces.value(2));
                    model->setData(model->index(row, 3, QModelIndex()), pieces.value(3));
                    row++;
                }
            }while(!line.isEmpty());

            file.close();
        }
    }
}















