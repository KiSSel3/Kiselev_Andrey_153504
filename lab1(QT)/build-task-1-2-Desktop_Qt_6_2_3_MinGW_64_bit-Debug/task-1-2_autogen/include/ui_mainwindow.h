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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_5;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *bottomBtn;
    QPushButton *upperBtn;
    QPushButton *rightBtn;
    QPushButton *leftBtn;
    QPushButton *canvaButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QSlider *rotateSlider;
    QSlider *horizontalSlider;
    QPushButton *btnRect;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 650);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(200, 0, 671, 501));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 0, 161, 441));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(verticalLayoutWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_6 = new QRadioButton(verticalLayoutWidget);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));

        verticalLayout->addWidget(radioButton_6);

        radioButton_3 = new QRadioButton(verticalLayoutWidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(verticalLayoutWidget);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        verticalLayout->addWidget(radioButton_4);

        radioButton_2 = new QRadioButton(verticalLayoutWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton_7 = new QRadioButton(verticalLayoutWidget);
        radioButton_7->setObjectName(QString::fromUtf8("radioButton_7"));

        verticalLayout->addWidget(radioButton_7);

        radioButton_8 = new QRadioButton(verticalLayoutWidget);
        radioButton_8->setObjectName(QString::fromUtf8("radioButton_8"));

        verticalLayout->addWidget(radioButton_8);

        radioButton_5 = new QRadioButton(verticalLayoutWidget);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));

        verticalLayout->addWidget(radioButton_5);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 510, 261, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        bottomBtn = new QPushButton(gridLayoutWidget);
        bottomBtn->setObjectName(QString::fromUtf8("bottomBtn"));

        gridLayout->addWidget(bottomBtn, 1, 1, 1, 1);

        upperBtn = new QPushButton(gridLayoutWidget);
        upperBtn->setObjectName(QString::fromUtf8("upperBtn"));

        gridLayout->addWidget(upperBtn, 0, 1, 1, 1);

        rightBtn = new QPushButton(gridLayoutWidget);
        rightBtn->setObjectName(QString::fromUtf8("rightBtn"));

        gridLayout->addWidget(rightBtn, 1, 2, 1, 1);

        leftBtn = new QPushButton(gridLayoutWidget);
        leftBtn->setObjectName(QString::fromUtf8("leftBtn"));

        gridLayout->addWidget(leftBtn, 1, 0, 1, 1);

        canvaButton = new QPushButton(gridLayoutWidget);
        canvaButton->setObjectName(QString::fromUtf8("canvaButton"));

        gridLayout->addWidget(canvaButton, 0, 2, 1, 1);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(300, 510, 571, 81));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        rotateSlider = new QSlider(verticalLayoutWidget_2);
        rotateSlider->setObjectName(QString::fromUtf8("rotateSlider"));
        rotateSlider->setMaximum(360);
        rotateSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(rotateSlider);

        horizontalSlider = new QSlider(verticalLayoutWidget_2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(200);
        horizontalSlider->setValue(101);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider);

        btnRect = new QPushButton(centralwidget);
        btnRect->setObjectName(QString::fromUtf8("btnRect"));
        btnRect->setGeometry(QRect(30, 460, 141, 29));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 900, 25));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "\320\242\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        radioButton_6->setText(QCoreApplication::translate("MainWindow", "\320\227\320\262\320\265\320\267\320\264\320\260", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "\320\240\320\276\320\274\320\261", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        radioButton_7->setText(QCoreApplication::translate("MainWindow", "\320\250\320\265\321\201\321\202\320\270\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        radioButton_8->setText(QCoreApplication::translate("MainWindow", "\320\236\320\262\320\260\320\273", nullptr));
        radioButton_5->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        bottomBtn->setText(QCoreApplication::translate("MainWindow", "v", nullptr));
        upperBtn->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        rightBtn->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        leftBtn->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
#if QT_CONFIG(tooltip)
        canvaButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\237\320\273\320\260\321\202\321\204\320\276\321\200\320\274\320\260 \320\264\320\273\321\217 \321\200\320\270\321\201\320\276\320\262\320\260\320\275\320\270\321\217</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        canvaButton->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\262\320\260", nullptr));
#if QT_CONFIG(tooltip)
        btnRect->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\247\320\270\321\201\320\273\320\276\320\262\321\213\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnRect->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
