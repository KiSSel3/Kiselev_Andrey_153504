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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *BitSetLine;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QPushButton *flipButton;
    QLineEdit *FlipLine;
    QPushButton *ResetButton;
    QLineEdit *ResetLine;
    QPushButton *SetButton;
    QLineEdit *SetLine;
    QPushButton *TestButton;
    QLineEdit *TestLine;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QPushButton *CountButton;
    QPushButton *NoneButton;
    QPushButton *SizeButton;
    QPushButton *AnyButton;
    QPushButton *AllButton;
    QPushButton *To_UlongButton;
    QPushButton *To_UllongButton;
    QPushButton *To_StringButton;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 257);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        BitSetLine = new QLineEdit(centralwidget);
        BitSetLine->setObjectName(QString::fromUtf8("BitSetLine"));
        BitSetLine->setReadOnly(true);

        verticalLayout_2->addWidget(BitSetLine);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        flipButton = new QPushButton(centralwidget);
        flipButton->setObjectName(QString::fromUtf8("flipButton"));

        formLayout->setWidget(0, QFormLayout::LabelRole, flipButton);

        FlipLine = new QLineEdit(centralwidget);
        FlipLine->setObjectName(QString::fromUtf8("FlipLine"));
        FlipLine->setMaxLength(1);

        formLayout->setWidget(0, QFormLayout::FieldRole, FlipLine);

        ResetButton = new QPushButton(centralwidget);
        ResetButton->setObjectName(QString::fromUtf8("ResetButton"));

        formLayout->setWidget(1, QFormLayout::LabelRole, ResetButton);

        ResetLine = new QLineEdit(centralwidget);
        ResetLine->setObjectName(QString::fromUtf8("ResetLine"));
        ResetLine->setMaxLength(1);

        formLayout->setWidget(1, QFormLayout::FieldRole, ResetLine);

        SetButton = new QPushButton(centralwidget);
        SetButton->setObjectName(QString::fromUtf8("SetButton"));

        formLayout->setWidget(2, QFormLayout::LabelRole, SetButton);

        SetLine = new QLineEdit(centralwidget);
        SetLine->setObjectName(QString::fromUtf8("SetLine"));
        SetLine->setMaxLength(1);

        formLayout->setWidget(2, QFormLayout::FieldRole, SetLine);

        TestButton = new QPushButton(centralwidget);
        TestButton->setObjectName(QString::fromUtf8("TestButton"));

        formLayout->setWidget(3, QFormLayout::LabelRole, TestButton);

        TestLine = new QLineEdit(centralwidget);
        TestLine->setObjectName(QString::fromUtf8("TestLine"));
        TestLine->setMaxLength(1);

        formLayout->setWidget(3, QFormLayout::FieldRole, TestLine);


        horizontalLayout->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CountButton = new QPushButton(centralwidget);
        CountButton->setObjectName(QString::fromUtf8("CountButton"));

        gridLayout->addWidget(CountButton, 2, 0, 1, 1);

        NoneButton = new QPushButton(centralwidget);
        NoneButton->setObjectName(QString::fromUtf8("NoneButton"));

        gridLayout->addWidget(NoneButton, 0, 1, 1, 1);

        SizeButton = new QPushButton(centralwidget);
        SizeButton->setObjectName(QString::fromUtf8("SizeButton"));

        gridLayout->addWidget(SizeButton, 1, 1, 1, 1);

        AnyButton = new QPushButton(centralwidget);
        AnyButton->setObjectName(QString::fromUtf8("AnyButton"));

        gridLayout->addWidget(AnyButton, 0, 0, 1, 1);

        AllButton = new QPushButton(centralwidget);
        AllButton->setObjectName(QString::fromUtf8("AllButton"));

        gridLayout->addWidget(AllButton, 1, 0, 1, 1);

        To_UlongButton = new QPushButton(centralwidget);
        To_UlongButton->setObjectName(QString::fromUtf8("To_UlongButton"));

        gridLayout->addWidget(To_UlongButton, 0, 2, 1, 1);

        To_UllongButton = new QPushButton(centralwidget);
        To_UllongButton->setObjectName(QString::fromUtf8("To_UllongButton"));

        gridLayout->addWidget(To_UllongButton, 1, 2, 1, 1);

        To_StringButton = new QPushButton(centralwidget);
        To_StringButton->setObjectName(QString::fromUtf8("To_StringButton"));

        gridLayout->addWidget(To_StringButton, 2, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

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
        flipButton->setText(QCoreApplication::translate("MainWindow", "flip", nullptr));
        FlipLine->setInputMask(QCoreApplication::translate("MainWindow", "9", nullptr));
        FlipLine->setText(QString());
        ResetButton->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
        ResetLine->setInputMask(QCoreApplication::translate("MainWindow", "9", nullptr));
        SetButton->setText(QCoreApplication::translate("MainWindow", "set", nullptr));
        SetLine->setInputMask(QCoreApplication::translate("MainWindow", "9", nullptr));
        TestButton->setText(QCoreApplication::translate("MainWindow", "test", nullptr));
        TestLine->setInputMask(QCoreApplication::translate("MainWindow", "9", nullptr));
        CountButton->setText(QCoreApplication::translate("MainWindow", "count", nullptr));
        NoneButton->setText(QCoreApplication::translate("MainWindow", "none", nullptr));
        SizeButton->setText(QCoreApplication::translate("MainWindow", "size", nullptr));
        AnyButton->setText(QCoreApplication::translate("MainWindow", "any", nullptr));
        AllButton->setText(QCoreApplication::translate("MainWindow", "all", nullptr));
        To_UlongButton->setText(QCoreApplication::translate("MainWindow", "to_ulong", nullptr));
        To_UllongButton->setText(QCoreApplication::translate("MainWindow", "to_ullong", nullptr));
        To_StringButton->setText(QCoreApplication::translate("MainWindow", "to_string", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
