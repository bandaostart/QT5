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

#������ʱ��Ҫ��Ӧ�ó���ʹ��һ���ı��뷽ʽ���ߵ���ʱ������
LIBS += -L"C:/Qt/qwt-5.2.1/lib" -lqwt6
INCLUDEPATH += C:/Qt/qwt-5.2.1/src
