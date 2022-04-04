/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QPushButton *addPlane;
    QPushButton *addFlight;
    QVBoxLayout *verticalLayout;
    QPushButton *flightSearchButton;
    QPushButton *fileCreatioButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *aircraftList;
    QTableWidget *flightsList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 800);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 629, 1001, 121));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        addPlane = new QPushButton(gridLayoutWidget);
        addPlane->setObjectName(QString::fromUtf8("addPlane"));

        verticalLayout_4->addWidget(addPlane);

        addFlight = new QPushButton(gridLayoutWidget);
        addFlight->setObjectName(QString::fromUtf8("addFlight"));

        verticalLayout_4->addWidget(addFlight);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        flightSearchButton = new QPushButton(gridLayoutWidget);
        flightSearchButton->setObjectName(QString::fromUtf8("flightSearchButton"));

        verticalLayout->addWidget(flightSearchButton);

        fileCreatioButton = new QPushButton(gridLayoutWidget);
        fileCreatioButton->setObjectName(QString::fromUtf8("fileCreatioButton"));

        verticalLayout->addWidget(fileCreatioButton);


        gridLayout->addLayout(verticalLayout, 0, 4, 1, 1);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 40, 981, 571));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        aircraftList = new QTableWidget(verticalLayoutWidget_2);
        aircraftList->setObjectName(QString::fromUtf8("aircraftList"));
        aircraftList->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(aircraftList);

        flightsList = new QTableWidget(verticalLayoutWidget_2);
        flightsList->setObjectName(QString::fromUtf8("flightsList"));
        flightsList->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(flightsList);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addPlane->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\260\320\274\320\276\320\273\321\221\321\202", nullptr));
        addFlight->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\265\320\271\321\201", nullptr));
        flightSearchButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \321\200\320\265\320\271\321\201\320\276\320\262", nullptr));
        fileCreatioButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202-\321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
