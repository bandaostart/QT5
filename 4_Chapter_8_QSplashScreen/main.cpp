#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap(":/image/tools_header_frames_generator.png");
    QSplashScreen splash(pixmap);
    splash.show();                                              //显示启动画面
    a.processEvents();                                          //使程序在显示启动画面的同时仍能响应鼠标等其他时间

    MainWindow w;
    w.show();

    splash.finish(&w);                                          //表示在主窗体初始化完成后，结束启动画面

    return a.exec();
}
