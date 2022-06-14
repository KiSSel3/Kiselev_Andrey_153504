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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QLabel *contains;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_5;
    QLineEdit *containsKey;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_4;
    QComboBox *editBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QComboBox *deleteBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_6->addWidget(label_5);

        contains = new QLabel(centralwidget);
        contains->setObjectName(QString::fromUtf8("contains"));
        contains->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(contains);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_4->addWidget(pushButton_5);

        containsKey = new QLineEdit(centralwidget);
        containsKey->setObjectName(QString::fromUtf8("containsKey"));

        horizontalLayout_4->addWidget(containsKey);


        verticalLayout_6->addLayout(horizontalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        editBox = new QComboBox(centralwidget);
        editBox->setObjectName(QString::fromUtf8("editBox"));

        horizontalLayout_2->addWidget(editBox);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        deleteBox = new QComboBox(centralwidget);
        deleteBox->setObjectName(QString::fromUtf8("deleteBox"));

        horizontalLayout->addWidget(deleteBox);


        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
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
        label_5->setText(QCoreApplication::translate("MainWindow", "Contains thi key", nullptr));
        contains->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Contains", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Change by key", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Change", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Add element", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Remove by key", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
