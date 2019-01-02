/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Dec 21 17:50:02 2018
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QwtPlot *qwtPlot;
    QPushButton *QuXianButton;
    QPushButton *QuXian2Button;
    QPushButton *pushButton_3;
    QPushButton *BrushButton;
    QPushButton *GridButton;
    QPushButton *DeleteButton;
    QPushButton *DontTaiButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(775, 456);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        qwtPlot = new QwtPlot(centralWidget);
        qwtPlot->setObjectName(QString::fromUtf8("qwtPlot"));

        gridLayout->addWidget(qwtPlot, 0, 0, 1, 7);

        QuXianButton = new QPushButton(centralWidget);
        QuXianButton->setObjectName(QString::fromUtf8("QuXianButton"));

        gridLayout->addWidget(QuXianButton, 1, 0, 1, 1);

        QuXian2Button = new QPushButton(centralWidget);
        QuXian2Button->setObjectName(QString::fromUtf8("QuXian2Button"));

        gridLayout->addWidget(QuXian2Button, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 1);

        BrushButton = new QPushButton(centralWidget);
        BrushButton->setObjectName(QString::fromUtf8("BrushButton"));

        gridLayout->addWidget(BrushButton, 1, 3, 1, 1);

        GridButton = new QPushButton(centralWidget);
        GridButton->setObjectName(QString::fromUtf8("GridButton"));

        gridLayout->addWidget(GridButton, 1, 4, 1, 1);

        DeleteButton = new QPushButton(centralWidget);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));

        gridLayout->addWidget(DeleteButton, 1, 5, 1, 1);

        DontTaiButton = new QPushButton(centralWidget);
        DontTaiButton->setObjectName(QString::fromUtf8("DontTaiButton"));

        gridLayout->addWidget(DontTaiButton, 1, 6, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 775, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        QuXianButton->setText(QApplication::translate("MainWindow", "\346\233\262\347\272\277", 0, QApplication::UnicodeUTF8));
        QuXian2Button->setText(QApplication::translate("MainWindow", "2\346\233\262\347\272\277", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\347\224\273\347\254\224", 0, QApplication::UnicodeUTF8));
        BrushButton->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\347\224\273\345\210\267", 0, QApplication::UnicodeUTF8));
        GridButton->setText(QApplication::translate("MainWindow", "\345\212\240\345\205\245\347\275\221\346\240\274", 0, QApplication::UnicodeUTF8));
        DeleteButton->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\346\233\262\347\272\277", 0, QApplication::UnicodeUTF8));
        DontTaiButton->setText(QApplication::translate("MainWindow", "\345\212\250\346\200\201\346\233\262\347\272\277", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
