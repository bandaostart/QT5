#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QDate>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <QFileDialog>
#include <QDateTime>
#include "fileview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    FileView fileView;


private slots:
    void on_QFile_clicked();

    void on_QTextSteam_clicked();

    void on_Bin_clicked();

    void on_QDir_clicked();

    void on_FileSys_clicked();

    void on_FileInfo_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
