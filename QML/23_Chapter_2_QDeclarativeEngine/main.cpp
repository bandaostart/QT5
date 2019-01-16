#include <QtGui/QApplication>
#include <QDeclarativeEngine>
#include <QDeclarativeContext>
#include <QDeclarativeComponent>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDeclarativeEngine engine;
    QDeclarativeContext *objectContext = new QDeclarativeContext(engine.rootContext());
    QDeclarativeComponent component(&engine, "application.qml");

    QObject *object = component.create(objectContext);


    
    return a.exec();
}























































