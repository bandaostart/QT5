#include "mainwindow.h"
#include <QApplication>
#include <QTableView>
#include "modelex.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    ModelEx     modelEx;
    QTableView  view;

    view.setModel(&modelEx);
    view.setWindowTitle(QObject::tr("modelEx"));
    view.resize(400, 400);

    view.show();

    return a.exec();
}
