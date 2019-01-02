#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QFile>
#include "tablemodel.h"
#include "itemdialog.h"

class TableModel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Record_clicked();

    void on_Insert_clicked();

    void on_Sort_clicked();

    void on_Update_clicked();

    void on_Delete_clicked();

    void on_Add_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    ItemDialog itemDialog;

    TableModel          tableModel;
    QSqlDatabase        db;
    QSqlQuery           query;
    QTime               t;
    long                records;
};

#endif // MAINWINDOW_H
