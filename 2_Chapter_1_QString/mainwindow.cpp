#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString str1 = "jone";
    QString str2 = "1982";
    QString str  = "";

    //字符串组合
    str = QString("%1 was born in %2.").arg(str1).arg(str2);
    ui->textEdit->insertPlainText(str);
    ui->textEdit->insertPlainText("\r\n\n");


    //在原字符串的特定位置插入另一个字符串
    str.insert(4, " not");
    ui->textEdit->insertPlainText(str);
    ui->textEdit->insertPlainText("\r\n\n");

    //在开头插入
    str.prepend("Mr ");
    ui->textEdit->insertPlainText(str);
    ui->textEdit->insertPlainText("\r\n\n");

    //在末尾加入
    str.append(" Year");
    ui->textEdit->insertPlainText(str);
    ui->textEdit->insertPlainText("\r\n\n");

    //替换指定字符串
    str.replace(0,2, "Mrt");
    ui->textEdit->insertPlainText(str);
    ui->textEdit->insertPlainText("\r\n\n");


    //判断是否以某字符串开头
    if (str.startsWith("Mrt"))
    {
        ui->textEdit->insertPlainText("Yes");
        ui->textEdit->insertPlainText("\r\n\n");
    }

    //判断是否以某字符结尾
    if (str.endsWith("Year"))
    {
        ui->textEdit->insertPlainText("Yes");
        ui->textEdit->insertPlainText("\r\n\n");
    }

    //判断是否包含
    if (str.contains("not"))
    {
        ui->textEdit->insertPlainText("Yes");
        ui->textEdit->insertPlainText("\r\n\n");
    }


    //把数字按照16进制转换成字符串 toUpper()大写
    unsigned short num = 100;
    str = QString("%1").arg(num, 4, 16, QLatin1Char('0')).toUpper();
    ui->textEdit->insertPlainText("0x"+str);
    ui->textEdit->insertPlainText("\r\n\n");


    //字符串转换成数字
    //toDouble(),toFlat(),toLong(),toLongLong()
    str = "123";
    num = str.toInt();
    qDebug()<<QString::number(num, 10);

    //toAscii()： 转换成ASCII编码的8位字符串
    //toLatin1()：返回一个Latin-1编码的8位字符串
    //toUtf8()：  返回一个UTF-8编码的8位字符串
    //toLoacl8Bit():返回一个系统本地编码的8位字符串


    //QString 转换成char
    {
	    char* ptr;
	    char  tempName[10];
	    QByteArray ba;
	    QString str = "hello";
	    ba = str.toLatin1();
	    ptr = ba.data();
	    memcpy(tempName, ptr, 10); 
    }
    
    //char转换成QString
    {
	    char a='b';
	    QString str;
	    str=QString(a);
    }
    
    //中文转换成char
    {
	    char *temp_Ptr;
	    char temp_buf[20];
	    QString str = tr("好好学习，天天向上。");
	    QByteArray tempArray = str.toLocal8Bit();
	    temp_Ptr = tempArray.data();
	    memcpy(temp_buf, temp_Ptr, tempArray.length());
    }
    
    //char转换成中文
    {
    	char    tempData[20];
      QString str;
      str = QString::fromLocal8Bit(tempData, 20);	
    }
    
    //浮点数转换成字符串
    {
    	float temp_data = 23.65;
    	QString("%1").arg(temp_data, 0, 'f',1);
  	}
    

    //判断字符串是否为空是否没指向
    QString().isNull();
    QString().isEmpty();
    QString("").isNull();
    QString("").isEmpty();
}



MainWindow::~MainWindow()
{
    delete ui;
}
