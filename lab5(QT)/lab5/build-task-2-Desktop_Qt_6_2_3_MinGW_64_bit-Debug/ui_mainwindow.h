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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *push_b;
    QPushButton *push_f;
    QPushButton *pop_b;
    QPushButton *pop_f;
    QPushButton *empt;
    QPushButton *cl;
    QPushButton *sz;
    QPushButton *inv;
    QPushButton *pushButton;
    QTextEdit *textShow;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(817, 545);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(230, 390, 354, 103));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        push_b = new QPushButton(gridLayoutWidget);
        push_b->setObjectName(QString::fromUtf8("push_b"));

        gridLayout->addWidget(push_b, 0, 0, 1, 1);

        push_f = new QPushButton(gridLayoutWidget);
        push_f->setObjectName(QString::fromUtf8("push_f"));

        gridLayout->addWidget(push_f, 0, 1, 1, 1);

        pop_b = new QPushButton(gridLayoutWidget);
        pop_b->setObjectName(QString::fromUtf8("pop_b"));

        gridLayout->addWidget(pop_b, 1, 0, 1, 1);

        pop_f = new QPushButton(gridLayoutWidget);
        pop_f->setObjectName(QString::fromUtf8("pop_f"));

        gridLayout->addWidget(pop_f, 1, 1, 1, 1);

        empt = new QPushButton(gridLayoutWidget);
        empt->setObjectName(QString::fromUtf8("empt"));

        gridLayout->addWidget(empt, 1, 2, 1, 1);

        cl = new QPushButton(gridLayoutWidget);
        cl->setObjectName(QString::fromUtf8("cl"));

        gridLayout->addWidget(cl, 0, 2, 1, 1);

        sz = new QPushButton(gridLayoutWidget);
        sz->setObjectName(QString::fromUtf8("sz"));

        gridLayout->addWidget(sz, 2, 0, 1, 1);

        inv = new QPushButton(gridLayoutWidget);
        inv->setObjectName(QString::fromUtf8("inv"));

        gridLayout->addWidget(inv, 2, 2, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);

        textShow = new QTextEdit(centralwidget);
        textShow->setObjectName(QString::fromUtf8("textShow"));
        textShow->setGeometry(QRect(10, 0, 791, 391));
        QFont font;
        font.setPointSize(26);
        font.setItalic(true);
        textShow->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 817, 25));
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
        push_b->setText(QCoreApplication::translate("MainWindow", "push_back", nullptr));
        push_f->setText(QCoreApplication::translate("MainWindow", "push_front", nullptr));
        pop_b->setText(QCoreApplication::translate("MainWindow", "pop_back", nullptr));
        pop_f->setText(QCoreApplication::translate("MainWindow", "pop_front", nullptr));
        empt->setText(QCoreApplication::translate("MainWindow", "empty", nullptr));
        cl->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        sz->setText(QCoreApplication::translate("MainWindow", "size", nullptr));
        inv->setText(QCoreApplication::translate("MainWindow", "resize", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
