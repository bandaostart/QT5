#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textEdit->clear();

    QString localHostName = QHostInfo::localHostName();                        //获得本机主机名
    ui->textEdit->insertPlainText(QString("%1").arg("LocalHostName: ", -30));
    ui->textEdit->insertPlainText(localHostName+"\n");

    QHostInfo hostInfo = QHostInfo::fromName(localHostName);
    QList<QHostAddress> listAddress = hostInfo.addresses();                     //获得主机的IP地址列表
    if (!listAddress.isEmpty())
    {
        ui->textEdit->insertPlainText(QString("%1").arg("IP Address: ", -30));
        ui->textEdit->insertPlainText(listAddress.at(1).toString());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();

    ui->textEdit->clear();
    for (int i=0; i< list.count(); i++)
    {
        QNetworkInterface interface = list.at(i);

        ui->textEdit->insertPlainText(QString("%1").arg("设备名称：", -30));
        ui->textEdit->insertPlainText(interface.name()+"\n");

        ui->textEdit->insertPlainText(QString("%1").arg("硬件地址：", -30));
        ui->textEdit->insertPlainText(interface.hardwareAddress()+"\n");

        QList<QNetworkAddressEntry> entryList = interface.addressEntries();
        for (int j=0; j<entryList.count(); j++)
        {
            QNetworkAddressEntry enter = entryList.at(j);

            ui->textEdit->insertPlainText(QString("%1").arg("IP地址：", -30));
            ui->textEdit->insertPlainText(enter.ip().toString()+"\n");

            ui->textEdit->insertPlainText(QString("%1").arg("子网掩码:", -30));
            ui->textEdit->insertPlainText(enter.netmask().toString()+"\n");

            ui->textEdit->insertPlainText(QString("%1").arg("广播地址:", -30));
            ui->textEdit->insertPlainText(enter.broadcast().toString()+"\n");
        }
    }


}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->clear();

    QString localHostName = QHostInfo::localHostName();                        //获得本机主机名
    ui->textEdit->insertPlainText(QString("%1").arg("LocalHostName: ", -30));
    ui->textEdit->insertPlainText(localHostName+"\n");

    QHostInfo hostInfo = QHostInfo::fromName(localHostName);
    QList<QHostAddress> listAddress = hostInfo.addresses();                     //获得主机的IP地址列表
    if (!listAddress.isEmpty())
    {
        ui->textEdit->insertPlainText(QString("%1").arg("IP Address: ", -30));
        ui->textEdit->insertPlainText(listAddress.at(1).toString());
    }
}
