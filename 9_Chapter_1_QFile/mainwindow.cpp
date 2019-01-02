#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



//常规打开文件方式
void MainWindow::on_QFile_clicked()
{
    QFile file;

    file.setFileName("Log.txt");

    if (file.open(QIODevice::ReadOnly))
    {
        QString str;

        str = file.readLine();
        ui->textEdit->setText(str);

        file.close();
    }
}

//Qtextstream打开方式
void MainWindow::on_QTextSteam_clicked()
{
    QFile file;
    file.setFileName("Log.txt");

    //Truncate表示将原来文件中的内容请，输出时将格式设置为左对齐，占10个字符位置
    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&file);
        out << QObject::tr("score:") << qSetFieldWidth(10) << left << 90 <<endl;

        file.close();
    }
}


//bin文件
void MainWindow::on_Bin_clicked()
{
    QFile file("binary.data");
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QDataStream out(&file);                                //将数据序列化
    out << QString(tr("周何俊 "));
    out << QDate::fromString("1994/09/25", "yyyy/MM/dd");
    out << (qint32)19;
    file.close();

    file.setFileName("binary.data");
    if (!file.open(QIODevice::ReadOnly))
    {

    }
    else
    {
        QDataStream in(&file);
        QString     name;
        QDate       birthday;
        qint32      age;
        in >> name >> birthday >> age;

        ui->textEdit->clear();
        ui->textEdit->insertPlainText(name + "; ");
        ui->textEdit->insertPlainText(birthday.toString("yyyy/MM/dd") + "; ");
        ui->textEdit->insertPlainText(QString::number(age));

        file.close();
    }
}


//文件目录
void MainWindow::on_QDir_clicked()
{
    QDir dir(QDir::currentPath());

    ui->textEdit->clear();
    foreach (QFileInfo fileInfo, dir.entryInfoList(QDir::Files)) //QDir::Files设置过滤方式只显示文件
    {
        ui->textEdit->insertPlainText(QString("%1").arg(fileInfo.fileName(), -30)+ QString::number(fileInfo.size()) + "Byte\n");
    }
}


//文件系统
void MainWindow::on_FileSys_clicked()
{
    fileView.show();
}

//文件信息
void MainWindow::on_FileInfo_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("打开"), "/", "files(*)");
    QFileInfo info(fileName);

    ui->textEdit->clear();

    ui->textEdit->insertPlainText(QString("%1").arg(tr("Name："), -20));
    ui->textEdit->insertPlainText(QString("%1").arg(fileName)+"\n");

    qint64 size = info.size();
    ui->textEdit->insertPlainText(QString("%1").arg(tr("Size："), -20));
    ui->textEdit->insertPlainText(QString("%1").arg(size)+"Byte\n");

    QDateTime created = info.created();
    ui->textEdit->insertPlainText(QString("%1").arg(tr("CreatedTime:"), -20));
    ui->textEdit->insertPlainText(QString("%1").arg(created.toString())+"\n");

    QDateTime lastModified = info.lastModified();
    ui->textEdit->insertPlainText(QString("%1").arg(tr("LastModifiedTime:"), -20));
    ui->textEdit->insertPlainText(QString("%1").arg(lastModified.toString())+"\n");

    QDateTime lastRead = info.lastRead();
    ui->textEdit->insertPlainText(QString("%1").arg(tr("LastReadTime:"), -20));
    ui->textEdit->insertPlainText(QString("%1").arg(lastRead.toString())+"\n");

    bool isFile = info.isFile();
    ui->textEdit->insertPlainText(QString("%1").arg(tr("isFile:"), -20));
    (isFile) ? (ui->textEdit->insertPlainText("YES\n")) :(ui->textEdit->insertPlainText("NO\n"));

    bool isSymLink = info.isSymLink();
    ui->textEdit->insertPlainText(QString("%1").arg(tr("isSymLink:"), -20));
    (isSymLink) ? (ui->textEdit->insertPlainText("YES\n")) :(ui->textEdit->insertPlainText("NO\n"));

    bool isHidden = info.isHidden();
    ui->textEdit->insertPlainText(QString("%1").arg(tr("isHidden:"), -20));
    (isHidden) ? (ui->textEdit->insertPlainText("YES\n")) :(ui->textEdit->insertPlainText("NO\n"));

    bool isReadable = info.isReadable();
    ui->textEdit->insertPlainText(QString("%1").arg(tr("isReadable:"), -20));
    (isReadable) ? (ui->textEdit->insertPlainText("YES\n")) :(ui->textEdit->insertPlainText("NO\n"));

    bool isWritable = info.isWritable();
    ui->textEdit->insertPlainText(QString("%1").arg(tr("isWritable:"), -20));
    (isWritable) ? (ui->textEdit->insertPlainText("YES\n")) :(ui->textEdit->insertPlainText("NO\n"));

    bool isExecutable = info.isFile();
    ui->textEdit->insertPlainText(QString("%1").arg(tr("isExecutable:"), -20));
    (isExecutable) ? (ui->textEdit->insertPlainText("YES\n")) :(ui->textEdit->insertPlainText("NO\n"));
}


























