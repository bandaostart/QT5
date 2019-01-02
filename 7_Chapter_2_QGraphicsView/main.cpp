#include "mainwindow.h"
#include <QApplication>
#include "mapwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    MapWidget mapWidget;
    mapWidget.show();

    return a.exec();
}
