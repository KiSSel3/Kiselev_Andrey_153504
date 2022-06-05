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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QPushButton *addInfoButton;
    QPushButton *searchButton;
    QPushButton *deleteButton;
    QPushButton *balanceButton;
    QPushButton *addToTreeButton;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_2;
    QLineEdit *keyLine;
    QLineEdit *lineEdit_3;
    QLineEdit *dataLine;
    QGridLayout *gridLayout_3;
    QPushButton *keyBypassButton;
    QPushButton *reverseBypassButton;
    QPushButton *forwardBypassButton;
    QLineEdit *lineEdit_5;
    QPushButton *forTaskOneButton;
    QSpacerItem *verticalSpacer;
    QTableWidget *treeWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(963, 497);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        addInfoButton = new QPushButton(centralwidget);
        addInfoButton->setObjectName(QString::fromUtf8("addInfoButton"));

        gridLayout_2->addWidget(addInfoButton, 0, 0, 1, 1);

        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        gridLayout_2->addWidget(searchButton, 1, 1, 1, 1);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(deleteButton, 2, 0, 1, 1);

        balanceButton = new QPushButton(centralwidget);
        balanceButton->setObjectName(QString::fromUtf8("balanceButton"));

        gridLayout_2->addWidget(balanceButton, 1, 0, 1, 1);

        addToTreeButton = new QPushButton(centralwidget);
        addToTreeButton->setObjectName(QString::fromUtf8("addToTreeButton"));

        gridLayout_2->addWidget(addToTreeButton, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);
        lineEdit_2->setMinimumSize(QSize(50, 0));
        lineEdit_2->setMaximumSize(QSize(50, 16777215));
        lineEdit_2->setReadOnly(true);

        gridLayout->addWidget(lineEdit_2, 0, 0, 1, 1);

        keyLine = new QLineEdit(centralwidget);
        keyLine->setObjectName(QString::fromUtf8("keyLine"));

        gridLayout->addWidget(keyLine, 0, 1, 1, 1);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(66, 0));
        lineEdit_3->setMaximumSize(QSize(66, 16777215));

        gridLayout->addWidget(lineEdit_3, 1, 0, 1, 1);

        dataLine = new QLineEdit(centralwidget);
        dataLine->setObjectName(QString::fromUtf8("dataLine"));

        gridLayout->addWidget(dataLine, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        keyBypassButton = new QPushButton(centralwidget);
        keyBypassButton->setObjectName(QString::fromUtf8("keyBypassButton"));

        gridLayout_3->addWidget(keyBypassButton, 2, 2, 1, 1);

        reverseBypassButton = new QPushButton(centralwidget);
        reverseBypassButton->setObjectName(QString::fromUtf8("reverseBypassButton"));

        gridLayout_3->addWidget(reverseBypassButton, 2, 1, 1, 1);

        forwardBypassButton = new QPushButton(centralwidget);
        forwardBypassButton->setObjectName(QString::fromUtf8("forwardBypassButton"));

        gridLayout_3->addWidget(forwardBypassButton, 2, 0, 1, 1);

        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setMinimumSize(QSize(200, 0));
        lineEdit_5->setMaximumSize(QSize(200, 16777215));
        lineEdit_5->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_5, 1, 0, 1, 1);

        forTaskOneButton = new QPushButton(centralwidget);
        forTaskOneButton->setObjectName(QString::fromUtf8("forTaskOneButton"));

        gridLayout_3->addWidget(forTaskOneButton, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        treeWidget = new QTableWidget(centralwidget);
        if (treeWidget->columnCount() < 2)
            treeWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        treeWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        treeWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        horizontalLayout->addWidget(treeWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 963, 25));
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
        addInfoButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\262 \320\274\320\260\321\201\321\201\320\270\320\262", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\277\320\276 \320\272\320\273\321\216\321\207\321\203", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\277\320\276 \320\272\320\273\321\216\321\207\321\203", nullptr));
        balanceButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\320\260\320\273\320\260\320\275\321\201\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        addToTreeButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\275\320\265\321\201\321\202\320\270 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\270\320\267 \320\274\320\260\321\201\321\201\320\270\320\262\320\260 \320\262 \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207:", nullptr));
        keyLine->setInputMask(QCoreApplication::translate("MainWindow", "99999", nullptr));
        keyLine->setText(QString());
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\320\275\320\275\321\213\320\265:", nullptr));
        keyBypassButton->setText(QCoreApplication::translate("MainWindow", "\320\222 \320\277\320\276\321\200\321\217\320\264\320\272\320\265 \320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\217 \320\272\320\273\321\216\321\207\320\260", nullptr));
        reverseBypassButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\321\202\320\275\321\213\320\274 \321\201\320\277\320\276\321\201\320\276\320\261\320\276\320\274", nullptr));
        forwardBypassButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\321\213\320\274 \321\201\320\277\320\276\321\201\320\276\320\261\320\276\320\274", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", " \320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216:", nullptr));
        forTaskOneButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\320\264\320\270\320\262\320\270\320\264\321\203\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\260\320\264\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem = treeWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = treeWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\320\275\320\275\321\213\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
