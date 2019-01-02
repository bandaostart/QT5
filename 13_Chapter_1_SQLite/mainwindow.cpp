#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
QSqlQuery类提供执行和操作的SQL语句的方法
可以用来执行DML(数据操作语言)语句，如SELECT INSERT UPDATE DELETE
以及DDL（数据定义语言）语句，例如CREAT TABLE
也可以用来执行哪些不是标准的SQL的数据库特定的命令
QString create_sql     = "create table student(id int primary key, name varchar(30), age int)"
QString select_max_sql = "select max(id) from student"
QString insert_sql     = "insert into student values(?, ?, ?)"
QString update_sql     = "update student set name = :name where id = :id"
QString select_sql     = "select id, name from student"
QString select_all_sql = "select *from student"
QString delete_sql     = "delete from student where id = ?"
QString clear_sql      = "delete from student"
*/


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());


    //列表显示
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(&tableModel);


    //数据库相关操作
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("zzy-PC");                           //设置数据库主机名称
    db.setDatabaseName("Database.db");                  //设置数据库名
    db.setUserName("zzy");                              //设置数据库用户名
    db.setPassword("123456");                           //设置数据库密码

    if (!db.open())
    {
        ui->textEdit->insertPlainText(tr("打开数据库失败!\n"));
        ui->textEdit->moveCursor(QTextCursor::End);
    }


    //表相关操作
    query = QSqlQuery(db);

    //判断数据库中表是不是存在
    query.exec("select * from sqlite_master where type='table' and name='automobil'");
    bool isTableExist = query.next();
    if(!isTableExist)
    {
        //创建数据库表
        bool      success = query.exec("create table automobil"
                                       "(id int primary key,"
                                       "attribute   varchar,"
                                       "type        varchar,"
                                       "kind        varchar,"
                                       "nation      int,"
                                       "carnumber   int,"
                                       "elevaltor   int,"
                                       "distance    int,"
                                       "oil         int,"
                                       "temperature int)");
        if (success)
        {
            ui->textEdit->insertPlainText(tr("数据库表创建成功!\n"));
            ui->textEdit->moveCursor(QTextCursor::End);
        }
        else
        {
            ui->textEdit->insertPlainText(tr("数据库表创建失败!\n"));
            ui->textEdit->moveCursor(QTextCursor::End);
        }
    }
    else
    {
        ui->textEdit->insertPlainText(tr("数据表已存在!\n"));
    }


    //记录
    records = 100;
    t.start();
}


MainWindow::~MainWindow()
{
    delete ui;
}



//查询
void MainWindow::on_Record_clicked()
{
    query.exec("select * from automobil");
    QSqlRecord rec = query.record();
    ui->textEdit->insertPlainText(tr("automobil表字段数：") + QString::number(rec.count()) + "\n");

    QStringList strList;
    QString str;
    while(query.next())
    {
        for (int i=0; i<tableModel.columnCount(); i++)
        {
            str =  query.value(i).toString();
            strList << str;
        }
    }
    query.last();

    tableModel.ClearitemData();
    tableModel.AdditemData(strList, query.at()+1);
    ui->tableView->scrollToBottom();
}


//插入
void MainWindow::on_Insert_clicked()
{
    t.restart();

    query.prepare("insert into automobil values(?,?,?,?,?,?,?,?,?,?)");

    for (int i=0; i<records; i++)
    {
        query.bindValue(0, i);
        query.bindValue(1, tr("四轮"));
        query.bindValue(2, tr("轿车"));
        query.bindValue(3, tr("富康"));
        query.bindValue(4, rand()%100);
        query.bindValue(5, rand()%10000);
        query.bindValue(6, rand()%300);
        query.bindValue(7, rand()%200000);
        query.bindValue(8, rand()%52);
        query.bindValue(9, rand()%100);

        bool success = query.exec();
        if (!success)
        {
            QSqlError lastError = query.lastError();
            ui->textEdit->insertPlainText(lastError.driverText()+tr("插入失败\n"));
        }
    }
    ui->textEdit->insertPlainText(tr("输入%1条记录，耗时：%2 ms").arg(records).arg(t.elapsed()) + "\n");
}


//排序
void MainWindow::on_Sort_clicked()
{
    t.restart();
    bool success = query.exec("select * from automobil order by id desc");

    if (success)
    {
        ui->textEdit->insertPlainText(tr("排序%1条记录， 耗时：%2 ms").arg(tableModel.rowCount()).arg(t.elapsed()) + "\n");
    }
    else
    {
       ui->textEdit->insertPlainText(tr("排序失败!\n"));
    }
}


//更新
void MainWindow::on_Update_clicked()
{
    QStringList strList;
    int rowNum =0;

     t.restart();

    rowNum = ui->tableView->currentIndex().row();
    if (rowNum > 0)
    {
        strList = tableModel.getRowData(rowNum);

        itemDialog.setData(strList);
        if (itemDialog.exec() == QDialog::Accepted)
        {
            QString str;
            str = strList.at(0);
            query.prepare(QString("update automobil set "
                                  "attribute = ?,"
                                  "type      = ?,"
                                  "kind      = ?,"
                                  "nation    = ?,"
                                  "carnumber = ?,"
                                  "elevaltor = ?,"
                                  "distance  = ?,"
                                  "oil       = ?,"
                                  "temperature = ?"
                                  "where id = %1").arg(str.toInt()));
            query.bindValue(0, itemDialog.dataList.at(1));
            query.bindValue(1, itemDialog.dataList.at(2));
            query.bindValue(2, itemDialog.dataList.at(3));
            query.bindValue(3, itemDialog.dataList.at(4));
            query.bindValue(4, itemDialog.dataList.at(5));
            query.bindValue(5, itemDialog.dataList.at(6));
            query.bindValue(6, itemDialog.dataList.at(7));
            query.bindValue(7, itemDialog.dataList.at(8));
            query.bindValue(8, itemDialog.dataList.at(9));

            bool success = query.exec();
            if(!success)
            {
                QSqlError lastError = query.lastError();
                ui->textEdit->insertPlainText(lastError.driverText() + tr("更新失败!\n"));
            }

            strList.clear();
            strList = itemDialog.dataList;
            strList.replace(0, str);
            tableModel.updateRow(strList, rowNum);
        }
    }

    ui->textEdit->insertPlainText(tr("更新1条记录，耗时：%1 ms").arg(t.elapsed()) + "\n");
    ui->textEdit->moveCursor(QTextCursor::End);
}


//删除
void MainWindow::on_Delete_clicked()
{
    QStringList strList;
    QString     str;
    int rowNum  = 0;
    int sqlID   = 0;


    rowNum  = ui->tableView->currentIndex().row();

    if (rowNum >= 0)
    {
        strList = tableModel.getRowData(rowNum);
        str     = strList.at(0);
        sqlID   = str.toInt();

        t.restart();

        tableModel.removeRow(rowNum);

        query.exec(tr("delete from automobil where id=%1").arg(sqlID));
        ui->textEdit->insertPlainText(tr("删除一条记录，耗时：%1 ms").arg(t.elapsed()) + "\n");
    }
}



//添加
void MainWindow::on_Add_clicked()
{
    int rowNum =0;

    QStringList strList;
    rowNum = tableModel.rowCount();
    if (rowNum > 0)
    {
        strList = tableModel.getRowData(rowNum-1);
    }
    else
    {
        for (int i=0; i<tableModel.columnCount(); i++)
        {
            strList << "";
        }
    }

    itemDialog.setData(strList);

    if (itemDialog.exec() == QDialog::Accepted)
    {
        QString str;
        query.prepare("insert into automobil values(?,?,?,?,?,?,?,?,?,?)");

        str = itemDialog.dataList.at(0);
        query.bindValue(0, str.toInt());
        query.bindValue(1, itemDialog.dataList.at(1));
        query.bindValue(2, itemDialog.dataList.at(2));
        query.bindValue(3, itemDialog.dataList.at(3));
        query.bindValue(4, itemDialog.dataList.at(4));
        query.bindValue(5, itemDialog.dataList.at(5));
        query.bindValue(6, itemDialog.dataList.at(6));
        query.bindValue(7, itemDialog.dataList.at(7));
        query.bindValue(8, itemDialog.dataList.at(8));
        query.bindValue(9, itemDialog.dataList.at(9));

        bool success = query.exec();
        if (!success)
        {
            QSqlError lastError = query.lastError();
            ui->textEdit->insertPlainText(lastError.driverText()+tr("添加失败\n"));
        }
        else
        {
            tableModel.AdditemData(itemDialog.dataList, 1);
            ui->tableView->scrollToBottom();
            ui->textEdit->insertPlainText(tr("添加成功\n"));
        }
    }
}


//列表框双击
void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QStringList strList;

    strList = tableModel.getRowData(index.row());

    itemDialog.setData(strList);
    itemDialog.exec();
}
