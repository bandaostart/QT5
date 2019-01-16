#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDeclarativeView view;
    view.setFixedSize(400, 400);
    view.setSource(QUrl("applicaton.qml"));
    view.show();
    
    return a.exec();
}
