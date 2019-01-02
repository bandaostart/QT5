#-------------------------------------------------
#
# Project created by QtCreator 2018-12-21T16:09:16
#
#-------------------------------------------------

QT       += core gui

TARGET = QwtPlot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

#库编译的时候要和应用程序使用一样的编译方式或者调用时候会出错
LIBS += -L"C:/Qt/qwt-5.2.1/lib" -lqwt6
INCLUDEPATH += C:/Qt/qwt-5.2.1/src
