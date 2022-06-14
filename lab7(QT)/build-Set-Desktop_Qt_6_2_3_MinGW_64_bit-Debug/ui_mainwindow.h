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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *insert;
    QLineEdit *key_edit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *erase;
    QLineEdit *erase_by_key;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *size;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(575, 371);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        verticalSpacer = new QSpacerItem(20, 57, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        insert = new QPushButton(centralwidget);
        insert->setObjectName(QString::fromUtf8("insert"));

        horizontalLayout->addWidget(insert);

        key_edit = new QLineEdit(centralwidget);
        key_edit->setObjectName(QString::fromUtf8("key_edit"));

        horizontalLayout->addWidget(key_edit);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        erase = new QPushButton(centralwidget);
        erase->setObjectName(QString::fromUtf8("erase"));

        horizontalLayout_2->addWidget(erase);

        erase_by_key = new QLineEdit(centralwidget);
        erase_by_key->setObjectName(QString::fromUtf8("erase_by_key"));

        horizontalLayout_2->addWidget(erase_by_key);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        size = new QPushButton(centralwidget);
        size->setObjectName(QString::fromUtf8("size"));

        horizontalLayout_3->addWidget(size);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(89);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(89, 0));

        horizontalLayout_3->addWidget(label);


        horizontalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_5);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 575, 25));
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
        insert->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        key_edit->setInputMask(QCoreApplication::translate("MainWindow", "99999", nullptr));
        erase->setText(QCoreApplication::translate("MainWindow", "Erase", nullptr));
        erase_by_key->setInputMask(QCoreApplication::translate("MainWindow", "99999", nullptr));
        size->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
