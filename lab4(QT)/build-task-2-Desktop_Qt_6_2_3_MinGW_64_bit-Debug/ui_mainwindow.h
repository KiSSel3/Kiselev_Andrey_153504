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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_17;
    QPushButton *pushButton_5;
    QPushButton *pushButton_10;
    QPushButton *pushButton_18;
    QPushButton *pushButton_2;
    QPushButton *pushButton_12;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_14;
    QPushButton *pushButton_16;
    QPushButton *pushButton_11;
    QPushButton *pushButton_13;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_15;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(595, 510);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 10, 532, 451));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textBrowser = new QTextBrowser(verticalLayoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        horizontalLayout->addWidget(textBrowser);

        textBrowser_2 = new QTextBrowser(verticalLayoutWidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));

        horizontalLayout->addWidget(textBrowser_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 1, 0, 1, 1);

        pushButton_17 = new QPushButton(verticalLayoutWidget);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));

        gridLayout_2->addWidget(pushButton_17, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout_2->addWidget(pushButton_5, 1, 2, 1, 1);

        pushButton_10 = new QPushButton(verticalLayoutWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout_2->addWidget(pushButton_10, 2, 2, 1, 1);

        pushButton_18 = new QPushButton(verticalLayoutWidget);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));

        gridLayout_2->addWidget(pushButton_18, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_12 = new QPushButton(verticalLayoutWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        gridLayout_2->addWidget(pushButton_12, 0, 1, 1, 1);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout_2->addWidget(pushButton_6, 2, 0, 1, 1);

        pushButton_8 = new QPushButton(verticalLayoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout_2->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_21 = new QPushButton(verticalLayoutWidget);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));

        gridLayout_2->addWidget(pushButton_21, 3, 0, 1, 1);

        pushButton_22 = new QPushButton(verticalLayoutWidget);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));

        gridLayout_2->addWidget(pushButton_22, 3, 1, 1, 1);

        pushButton_23 = new QPushButton(verticalLayoutWidget);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));

        gridLayout_2->addWidget(pushButton_23, 3, 2, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_4 = new QLineEdit(verticalLayoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 2, 1, 1);

        pushButton_14 = new QPushButton(verticalLayoutWidget);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        gridLayout->addWidget(pushButton_14, 2, 1, 1, 1);

        pushButton_16 = new QPushButton(verticalLayoutWidget);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));

        gridLayout->addWidget(pushButton_16, 3, 1, 1, 1);

        pushButton_11 = new QPushButton(verticalLayoutWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        gridLayout->addWidget(pushButton_11, 1, 2, 1, 1);

        pushButton_13 = new QPushButton(verticalLayoutWidget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        gridLayout->addWidget(pushButton_13, 2, 0, 1, 1);

        pushButton_7 = new QPushButton(verticalLayoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 1, 0, 1, 1);

        pushButton_9 = new QPushButton(verticalLayoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 1, 1, 1, 1);

        pushButton_15 = new QPushButton(verticalLayoutWidget);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        gridLayout->addWidget(pushButton_15, 2, 2, 1, 1);

        pushButton_19 = new QPushButton(verticalLayoutWidget);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));

        gridLayout->addWidget(pushButton_19, 3, 0, 1, 1);

        pushButton_20 = new QPushButton(verticalLayoutWidget);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));

        gridLayout->addWidget(pushButton_20, 3, 2, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 595, 25));
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
        label->setText(QCoreApplication::translate("MainWindow", "    Input Text: ", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        pushButton_17->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_5->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>char * strcat( char * destptr, const char * srcptr );</p><p>\320\236\320\261\321\212\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265 \321\201\321\202\321\200\320\276\320\272. \320\244\321\203\320\275\320\272\321\206\320\270\321\217 \320\264\320\276\320\261\320\260\320\262\320\273\321\217\320\265\321\202 \320\272\320\276\320\277\320\270\321\216 \321\201\321\202\321\200\320\276\320\272\320\270\302\240<span style=\" font-family:'Courier New';\">srcptr</span>\302\240\320\262 \320\272\320\276\320\275\320\265\321\206 \321\201\321\202\321\200\320\276\320\272\320\270\302\240<span style=\" font-family:'Courier New';\">destptr</span>. \320\235\321\203\320\273\320\265\320\262\320\276\320\271 \321\201\320\270\320\274\320\262\320\276\320\273 \320\272\320\276\320\275\321\206\320\260 \321\201\321\202\321\200\320\276\320\272\320\270 <span style=\" font-family:'Courier New';\">destptr</span>\302\240\320\267\320\260\320\274\320\265\320\275\321\217\320\265\321\202\321\201\321\217 \320\277\320"
                        "\265\321\200\320\262\321\213\320\274 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\274 \321\201\321\202\321\200\320\276\320\272\320\270 <span style=\" font-family:'Courier New';\">srcptr</span>, \320\270 \320\275\320\276\320\262\321\213\320\271 \320\275\321\203\320\273\321\214-\321\201\320\270\320\274\320\262\320\276\320\273 \320\264\320\276\320\261\320\260\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \320\262 \320\272\320\276\320\275\320\265\321\206 \321\203\320\266\320\265 \320\275\320\276\320\262\320\276\320\271 \321\201\321\202\321\200\320\276\320\272\320\270, \321\201\321\204\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\276\320\271 \320\276\320\261\321\212\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265\320\274 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \320\264\320\262\321\203\321\205 \321\201\321\202\321\200\320\276\320\272 \320\262 \321\201\321\202\321\200\320\276\320\272\320\265\302\240<span style=\""
                        " font-family:'Courier New';\">destptr</span>.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_5->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>char * strcat( char * destptr, const char * srcptr );</p><p>\320\236\320\261\321\212\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265 \321\201\321\202\321\200\320\276\320\272. \320\244\321\203\320\275\320\272\321\206\320\270\321\217 \320\264\320\276\320\261\320\260\320\262\320\273\321\217\320\265\321\202 \320\272\320\276\320\277\320\270\321\216 \321\201\321\202\321\200\320\276\320\272\320\270 <span style=\" font-family:'Courier New';\">srcptr</span> \320\262 \320\272\320\276\320\275\320\265\321\206 \321\201\321\202\321\200\320\276\320\272\320\270 <span style=\" font-family:'Courier New';\">destptr</span>. \320\235\321\203\320\273\320\265\320\262\320\276\320\271 \321\201\320\270\320\274\320\262\320\276\320\273 \320\272\320\276\320\275\321\206\320\260 \321\201\321\202\321\200\320\276\320\272\320\270 <span style=\" font-family:'Courier New';\">destptr</span> \320\267\320\260\320\274\320\265\320\275\321\217\320\265\321\202\321\201\321\217 \320\277\320\265\321\200\320\262\321\213"
                        "\320\274 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\274 \321\201\321\202\321\200\320\276\320\272\320\270 <span style=\" font-family:'Courier New';\">srcptr</span>, \320\270 \320\275\320\276\320\262\321\213\320\271 \320\275\321\203\320\273\321\214-\321\201\320\270\320\274\320\262\320\276\320\273 \320\264\320\276\320\261\320\260\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \320\262 \320\272\320\276\320\275\320\265\321\206 \321\203\320\266\320\265 \320\275\320\276\320\262\320\276\320\271 \321\201\321\202\321\200\320\276\320\272\320\270, \321\201\321\204\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\276\320\271 \320\276\320\261\321\212\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265\320\274 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \320\264\320\262\321\203\321\205 \321\201\321\202\321\200\320\276\320\272 \320\262 \321\201\321\202\321\200\320\276\320\272\320\265 <span style=\" font-family:'Courier New';\">destp"
                        "tr</span>.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "strcat", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_10->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>char * strtok( char * string, const char * delim );</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 <span style=\" font-family:'Courier New';\">strtok</span> \320\262\321\213\320\277\320\276\320\273\320\275\321\217\320\265\321\202 \320\277\320\276\320\270\321\201\320\272 \320\273\320\265\320\272\321\201\320\265\320\274 \320\262 \321\201\321\202\321\200\320\276\320\272\320\265 <span style=\" font-family:'Courier New';\">string</span>. \320\237\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\262\321\213\320\267\320\276\320\262\320\276\320\262 \321\215\321\202\320\276\320\271 \321\204\321\203\320\275\320\272\321\206\320\270\320\270 \321\200\320\260\320\267\320\261\320\270\320\262\320\260\321\216\321\202 \321\201\321\202\321\200\320\276\320\272\321\203 <span style=\" font-family:'Courier New';\">string</span> \320\275\320\260 \320\273\320\265\320\272\321\201\320\265\320\274\321\213, \320"
                        "\272\320\276\321\202\320\276\321\200\321\213\320\265 \320\277\321\200\320\265\320\264\321\201\321\202\320\260\320\262\320\273\321\217\321\216\321\202 \321\201\320\276\320\261\320\276\320\271 \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\320\270 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262, \321\200\320\260\320\267\320\264\320\265\320\273\320\265\320\275\320\275\321\213\321\205 \321\201\320\270\320\274\320\262\320\276\320\273\320\260\320\274\320\270 \321\200\320\260\320\267\320\264\320\265\320\273\320\270\321\202\320\265\320\273\321\217\320\274\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_10->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>char * strtok( char * string, const char * delim );</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 <span style=\" font-family:'Courier New';\">strtok</span> \320\262\321\213\320\277\320\276\320\273\320\275\321\217\320\265\321\202 \320\277\320\276\320\270\321\201\320\272 \320\273\320\265\320\272\321\201\320\265\320\274 \320\262 \321\201\321\202\321\200\320\276\320\272\320\265 <span style=\" font-family:'Courier New';\">string</span>. \320\237\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\262\321\213\320\267\320\276\320\262\320\276\320\262 \321\215\321\202\320\276\320\271 \321\204\321\203\320\275\320\272\321\206\320\270\320\270 \321\200\320\260\320\267\320\261\320\270\320\262\320\260\321\216\321\202 \321\201\321\202\321\200\320\276\320\272\321\203 <span style=\" font-family:'Courier New';\">string</span> \320\275\320\260 \320\273\320\265\320\272\321\201\320\265\320\274\321\213, \320"
                        "\272\320\276\321\202\320\276\321\200\321\213\320\265 \320\277\321\200\320\265\320\264\321\201\321\202\320\260\320\262\320\273\321\217\321\216\321\202 \321\201\320\276\320\261\320\276\320\271 \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\320\270 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262, \321\200\320\260\320\267\320\264\320\265\320\273\320\265\320\275\320\275\321\213\321\205 \321\201\320\270\320\274\320\262\320\276\320\273\320\260\320\274\320\270 \321\200\320\260\320\267\320\264\320\265\320\273\320\270\321\202\320\265\320\273\321\217\320\274\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "strtok", nullptr));
        pushButton_18->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_2->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-family:'Courier New';\">char* strcpy( char* destptr, constchar* srcptr );<br/></span>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 \320\272\320\276\320\277\320\270\321\200\321\203\320\265\321\202 \320\241\320\270-\321\201\321\202\321\200\320\276\320\272\321\203 <span style=\" font-family:'Courier New';\">srcptr</span>, \320\262\320\272\320\273\321\216\321\207\320\260\321\217\302\240\320\267\320\260\320\262\320\265\321\200\321\210\320\260\321\216\321\211\320\270\320\271 \320\275\321\203\320\273\320\265\320\262\320\276\320\271 \321\201\320\270\320\274\320\262\320\276\320\273 \320\262 \321\201\321\202\321\200\320\276\320\272\321\203 \320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\203\321\216 \321\201\321\201\321\213\320\273\320\260\320\265\321\202\321\201\321\217 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 <span style=\" font-family:'Cour"
                        "ier New';\">destptr</span>.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_2->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-family:'Courier New';\">char</span><span style=\" font-family:'Courier New';\">* strcpy( char</span><span style=\" font-family:'Courier New';\">* destptr, const</span><span style=\" font-family:'Courier New';\">char</span><span style=\" font-family:'Courier New';\">* srcptr );<br/></span>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 \320\272\320\276\320\277\320\270\321\200\321\203\320\265\321\202 \320\241\320\270-\321\201\321\202\321\200\320\276\320\272\321\203 <span style=\" font-family:'Courier New';\">srcptr</span>, \320\262\320\272\320\273\321\216\321\207\320\260\321\217\302\240\320\267\320\260\320\262\320\265\321\200\321\210\320\260\321\216\321\211\320\270\320\271 \320\275\321\203\320\273\320\265\320\262\320\276\320\271 \321\201\320\270\320\274\320\262\320\276\320\273 \320\262 \321\201\321\202\321\200\320\276\320\272\321\203 \320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217, \320\275\320\260 \320\272\320\276\321\202\320\276"
                        "\321\200\321\203\321\216 \321\201\321\201\321\213\320\273\320\260\320\265\321\202\321\201\321\217 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 <span style=\" font-family:'Courier New';\">destptr</span>.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "strcpy", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_12->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>size_t strlen( const char * string );<br/>\320\224\320\273\320\270\320\275\320\260 \320\241\320\270-\321\201\321\202\321\200\320\276\320\272\320\270 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\321\217\320\265\321\202\321\201\321\217 \320\277\320\276 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\216 \320\275\321\203\320\273\320\265\320\262\320\276\320\263\320\276 \321\201\320\270\320\274\320\262\320\276\320\273\320\260 \302\240\342\200\224\302\240\320\275\321\203\320\273\321\214 \321\202\320\265\321\200\320\274\320\270\320\275\320\260\321\202\320\276\321\200.\302\240\320\244\321\203\320\275\320\272\321\206\320\270\321\217 <span style=\" font-family:'Courier New';\">strlen</span> \320\262\320\270\320\264\320\270\321\202 \320\275\320\260\321\207\320\260\320\273\320\276 \320\241\320\270-\321\201\321\202\321\200\320\276\320\272\320\270 \302\240\320\270 \320\275\320\260\321\207\320\270\320\275\320\260\320\265\321\202 \321\201\320\275\320\260\321\207\320"
                        "\260\320\273\320\260 \321\201\321\207\320\270\321\202\320\260\321\202\321\214 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 (\320\261\320\260\320\271\321\202\320\276\320\262, \320\276\321\202\320\262\320\276\320\264\320\270\320\274\321\213\321\205 \320\277\320\276\320\264 \320\272\320\260\320\266\320\264\321\213\320\271 \321\201\320\270\320\274\320\262\320\276\320\273), \321\215\321\202\320\276\321\202 \320\277\321\200\320\276\321\206\320\265\321\201\321\201 \320\262\321\213\320\277\320\276\320\273\320\275\321\217\320\265\321\202\321\201\321\217 \320\264\320\276 \321\202\320\265\321\205 \320\277\320\276\321\200, \320\277\320\276\320\272\320\260 \320\275\320\265 \320\261\321\203\320\264\320\265\321\202 \320\264\320\276\321\201\321\202\320\270\320\263\320\275\321\203\321\202 \320\267\320\260\320\262\320\265\321\200\321\210\320\260\321\216\321\211\320\270\320\271 \320\275\321\203\320\273\320\265\320\262\320\276\320"
                        "\271 \321\201\320\270\320\274\320\262\320\276\320\273.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_12->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>size_t strlen( const char * string );<br/>\320\224\320\273\320\270\320\275\320\260 \320\241\320\270-\321\201\321\202\321\200\320\276\320\272\320\270 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\321\217\320\265\321\202\321\201\321\217 \320\277\320\276 \320\264\320\276\321\201\321\202\320\270\320\266\320\265\320\275\320\270\321\216 \320\275\321\203\320\273\320\265\320\262\320\276\320\263\320\276 \321\201\320\270\320\274\320\262\320\276\320\273\320\260  \342\200\224 \320\275\321\203\320\273\321\214 \321\202\320\265\321\200\320\274\320\270\320\275\320\260\321\202\320\276\321\200. \320\244\321\203\320\275\320\272\321\206\320\270\321\217 <span style=\" font-family:'Courier New';\">strlen</span> \320\262\320\270\320\264\320\270\321\202 \320\275\320\260\321\207\320\260\320\273\320\276 \320\241\320\270-\321\201\321\202\321\200\320\276\320\272\320\270  \320\270 \320\275\320\260\321\207\320\270\320\275\320\260\320\265\321\202 \321\201\320\275\320\260\321\207\320\260\320\273\320\260 \321\201"
                        "\321\207\320\270\321\202\320\260\321\202\321\214 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 (\320\261\320\260\320\271\321\202\320\276\320\262, \320\276\321\202\320\262\320\276\320\264\320\270\320\274\321\213\321\205 \320\277\320\276\320\264 \320\272\320\260\320\266\320\264\321\213\320\271 \321\201\320\270\320\274\320\262\320\276\320\273), \321\215\321\202\320\276\321\202 \320\277\321\200\320\276\321\206\320\265\321\201\321\201 \320\262\321\213\320\277\320\276\320\273\320\275\321\217\320\265\321\202\321\201\321\217 \320\264\320\276 \321\202\320\265\321\205 \320\277\320\276\321\200, \320\277\320\276\320\272\320\260 \320\275\320\265 \320\261\321\203\320\264\320\265\321\202 \320\264\320\276\321\201\321\202\320\270\320\263\320\275\321\203\321\202 \320\267\320\260\320\262\320\265\321\200\321\210\320\260\321\216\321\211\320\270\320\271 \320\275\321\203\320\273\320\265\320\262\320\276\320\271 \321\201\320\270\320\274"
                        "\320\262\320\276\320\273.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "strlen", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_6->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>int strcmp( const char * string1, const char * string2 );</p><p>\320\255\321\202\320\260 \321\204\321\203\320\275\320\272\321\206\320\270\321\217 \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\265\321\202 \321\201\320\270\320\274\320\262\320\276\320\273\321\213 \320\264\320\262\321\203\321\205 \321\201\321\202\321\200\320\276\320\272, <span style=\" font-family:'Courier New';\">string1</span> \320\270 <span style=\" font-family:'Courier New';\">string2</span>. \320\235\320\260\321\207\320\270\320\275\320\260\321\217 \321\201 \320\277\320\265\321\200\320\262\321\213\321\205 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \321\204\321\203\320\275\320\272\321\206\320\270\321\217 <span style=\" font-family:'Courier New';\">strcmp</span> \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\265\321\202 \320\277\320\276\320\276\321\207\320\265\321\200\320\265\320\264\320\275\320\276 \320\272\320\260\320\266\320\264\321\203\321\216 \320\277\320"
                        "\260\321\200\321\203 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262, \320\270 \320\277\321\200\320\276\320\264\320\276\320\273\320\266\320\260\320\265\321\202\321\201\321\217 \321\215\321\202\320\276 \320\264\320\276 \321\202\320\265\321\205 \320\277\320\276\321\200, \320\277\320\276\320\272\320\260 \320\275\320\265 \320\261\321\203\320\264\321\203\321\202 \320\275\320\260\320\271\320\264\320\265\320\275\321\213 \321\200\320\260\320\267\320\273\320\270\321\207\320\275\321\213\320\265 \321\201\320\270\320\274\320\262\320\276\320\273\321\213 \320\270\320\273\320\270 \320\275\320\265 \320\261\321\203\320\264\320\265\321\202 \320\264\320\276\321\201\321\202\320\270\320\263\320\275\321\203\321\202 \320\272\320\276\320\275\320\265\321\206 \321\201\321\202\321\200\320\276\320\272\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_6->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>int strcmp( const char * string1, const char * string2 );</p><p>\320\255\321\202\320\260 \321\204\321\203\320\275\320\272\321\206\320\270\321\217 \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\265\321\202 \321\201\320\270\320\274\320\262\320\276\320\273\321\213 \320\264\320\262\321\203\321\205 \321\201\321\202\321\200\320\276\320\272, <span style=\" font-family:'Courier New';\">string1</span> \320\270 <span style=\" font-family:'Courier New';\">string2</span>. \320\235\320\260\321\207\320\270\320\275\320\260\321\217 \321\201 \320\277\320\265\321\200\320\262\321\213\321\205 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \321\204\321\203\320\275\320\272\321\206\320\270\321\217 <span style=\" font-family:'Courier New';\">strcmp</span> \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\265\321\202 \320\277\320\276\320\276\321\207\320\265\321\200\320\265\320\264\320\275\320\276 \320\272\320\260\320\266\320\264\321\203\321\216 \320\277\320"
                        "\260\321\200\321\203 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262, \320\270 \320\277\321\200\320\276\320\264\320\276\320\273\320\266\320\260\320\265\321\202\321\201\321\217 \321\215\321\202\320\276 \320\264\320\276 \321\202\320\265\321\205 \320\277\320\276\321\200, \320\277\320\276\320\272\320\260 \320\275\320\265 \320\261\321\203\320\264\321\203\321\202 \320\275\320\260\320\271\320\264\320\265\320\275\321\213 \321\200\320\260\320\267\320\273\320\270\321\207\320\275\321\213\320\265 \321\201\320\270\320\274\320\262\320\276\320\273\321\213 \320\270\320\273\320\270 \320\275\320\265 \320\261\321\203\320\264\320\265\321\202 \320\264\320\276\321\201\321\202\320\270\320\263\320\275\321\203\321\202 \320\272\320\276\320\275\320\265\321\206 \321\201\321\202\321\200\320\276\320\272\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "strcmp", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_8->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>int strcmp( const char * string1, const char * string2 );</p><p>\320\255\321\202\320\260 \321\204\321\203\320\275\320\272\321\206\320\270\321\217 \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\265\321\202 \321\201\320\270\320\274\320\262\320\276\320\273\321\213 \320\264\320\262\321\203\321\205 \321\201\321\202\321\200\320\276\320\272, <span style=\" font-family:'Courier New';\">string1</span> \320\270 <span style=\" font-family:'Courier New';\">string2</span>. \320\235\320\260\321\207\320\270\320\275\320\260\321\217 \321\201 \320\277\320\265\321\200\320\262\321\213\321\205 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \321\204\321\203\320\275\320\272\321\206\320\270\321\217 <span style=\" font-family:'Courier New';\">strcmp</span> \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\265\321\202 \320\277\320\276\320\276\321\207\320\265\321\200\320\265\320\264\320\275\320\276 \320\272\320\260\320\266\320\264\321\203\321\216 \320\277\320"
                        "\260\321\200\321\203 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262, \320\270 \320\277\321\200\320\276\320\264\320\276\320\273\320\266\320\260\320\265\321\202\321\201\321\217 \321\215\321\202\320\276 \320\264\320\276 \321\202\320\265\321\205 \320\277\320\276\321\200, \320\277\320\276\320\272\320\260 \320\275\320\265 \320\261\321\203\320\264\321\203\321\202 \320\275\320\260\320\271\320\264\320\265\320\275\321\213 \321\200\320\260\320\267\320\273\320\270\321\207\320\275\321\213\320\265 \321\201\320\270\320\274\320\262\320\276\320\273\321\213 \320\270\320\273\320\270 \320\275\320\265 \320\261\321\203\320\264\320\265\321\202 \320\264\320\276\321\201\321\202\320\270\320\263\320\275\321\203\321\202 \320\272\320\276\320\275\320\265\321\206 \321\201\321\202\321\200\320\276\320\272\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_8->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>int strcoll( const char * string1, const char * string2 );</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\265\321\202 \321\201\321\202\321\200\320\276\320\272\321\203 <span style=\" font-family:'Courier New';\">string1</span> \321\201\320\276 \321\201\321\202\321\200\320\276\320\272\320\276\320\271 <span style=\" font-family:'Courier New';\">string2</span>, \321\201 \321\203\321\207\321\221\321\202\320\276\320\274 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260 <span style=\" font-family:'Courier New';\">LC_COLLATE</span>, \321\202\320\265\320\272\321\203\321\211\320\265\320\271 \320\273\320\276\320\272\320\260\320\273\320\270.<br/>\320\255\321\202\320\260 \321\204\321\203\320\275\320\272\321\206\320\270\321\217 \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\265\321\202 \321\201\320\270\320\274\320\262\320\276\320\273\321\213 \320\272\320\260\320\266\320\264\320"
                        "\276\320\271 \321\201\321\202\321\200\320\276\320\272\320\270, \320\275\320\260\321\207\320\270\320\275\320\260\321\217 \321\201 \320\277\320\265\321\200\320\262\320\276\320\263\320\276. \320\225\321\201\320\273\320\270 \321\201\320\270\320\274\320\262\320\276\320\273\321\213 \321\200\320\260\320\262\320\275\321\213 \321\201\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265 \320\277\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\201\321\217 \321\203\320\266\320\265 \321\201\320\276 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\271 \320\277\320\260\321\200\320\276\320\271 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \320\270 \321\202\320\260\320\272 \320\264\320\276 \321\202\320\265\321\205 \320\277\320\276\321\200, \320\277\320\276\320\272\320\260 \320\275\320\265 \320\261\321\203\320\264\321\203\321\202 \320\275\320\260\320\271\320\264\320\265\320\275\321\213 \321\200\320\260\320\267\320\273\320\270\321\207\320\275\321\213\320\265 \321"
                        "\201\320\270\320\274\320\262\320\276\320\273\321\213 \320\270\320\273\320\270 \320\275\320\265 \320\261\321\203\320\264\320\265\321\202 \320\275\320\260\320\271\320\264\320\265\320\275 \320\275\321\203\320\273\320\265\320\262\320\276\320\271 \321\201\320\270\320\274\320\262\320\276\320\273, \321\201\320\270\320\263\320\275\320\260\320\273\320\270\320\267\320\270\321\200\321\203\321\216\321\211\320\270\320\271 \320\276 \320\272\320\276\320\275\321\206\320\265 \321\201\321\202\321\200\320\276\320\272\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "strcoll", nullptr));
        pushButton_21->setText(QString());
        pushButton_22->setText(QString());
        pushButton_23->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_3->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>char * strncpy( char * destptr, const char * srcptr, size_t num );</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 \320\272\320\276\320\277\320\270\321\200\321\203\320\265\321\202 \320\277\320\265\321\200\320\262\321\213\320\265 <span style=\" font-family:'Courier New';\">num</span>\302\240\321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \320\270\320\267 \321\201\321\202\321\200\320\276\320\272\320\270\302\240<span style=\" font-family:'Courier New';\">srcptr</span>\302\240\320\262 \321\201\321\202\321\200\320\276\320\272\321\203 <span style=\" font-family:'Courier New';\">destptr</span>. \320\225\321\201\320\273\320\270 \320\272\320\276\320\275\320\265\321\206 \321\201\321\202\321\200\320\276\320\272\320\270\302\240<span style=\" font-family:'Courier New';\">srcptr</span>\302\240(\321\201\320\270\320\274\320\262\320\276\320\273 \320\272\320\276\320\275\321\206\320\260 \321\201\321\202\321\200\320\276\320\272\320\270 ) \320\264\320\276\321\201\321\202\320\270"
                        "\320\263\320\275\321\203\321\202 \320\277\321\200\320\265\320\266\320\264\320\265, \321\207\320\265\320\274 \320\261\321\213\320\273\320\270 \321\201\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\321\213\302\240<span style=\" font-family:'Courier New';\">num</span>\302\240\321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262, \320\272 \321\201\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\274 \321\201\320\270\320\274\320\262\320\276\320\273\320\260\320\274 \320\262 \320\272\320\276\320\275\320\265\321\206 \321\201\321\202\321\200\320\276\320\272\320\270\302\240<span style=\" font-family:'Courier New';\">destptr</span>\302\240\320\264\320\276\320\261\320\260\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \320\275\321\203\320\273\321\214-\321\201\320\270\320\274\320\262\320\276\320\273, \320\277\320\276\321\201\320\273\320\265 \321\207\320\265\320\263\320\276, \321\201\321\202\321\200\320\276\320\272\320\260 \321\201\321\207"
                        "\320\270\321\202\320\260\320\265\321\202\321\201\321\217 \321\201\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\276\320\271.</p><p>\320\225\321\201\320\273\320\270 \320\266\320\265 \321\201\321\202\321\200\320\276\320\272\320\260 \320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\276\320\272\320\260\320\266\320\265\321\202\321\201\321\217 \320\274\320\265\320\275\321\214\321\210\320\265 <span style=\" font-family:'Courier New';\">num</span>, \321\202\320\276\320\263\320\264\320\260 \321\201\320\272\320\276\320\277\320\270\321\200\321\203\321\216\321\202\321\201\321\217 \321\201\320\270\320\274\320\262\320\276\320\273\321\213, \320\272\320\276\321\202\320\276\321\200\321\213\320\265 \320\277\320\276\320\274\320\265\321\201\321\202\321\217\321\202\321\201\321\217 \320\262 <span style=\" font-family:'Courier New';\">destptr</span>, \321\203\321\207\320\270\321\202\321\213\320\262\320\260\321\217 \321\202\320\276, \321\207\321\202\320\276 \320"
                        "\262 \320\272\320\276\320\275\321\206\320\265 \321\201\321\202\321\200\320\276\320\272\320\270 \320\276\320\261\321\217\320\267\320\260\321\202\320\265\320\273\321\214\320\275\320\276 \320\264\320\276\320\273\320\266\320\265\320\275 \321\201\321\202\320\276\321\217\321\202\321\214 \321\201\320\270\320\274\320\262\320\276\320\273 \320\272\320\276\320\275\321\206\320\260 \321\201\321\202\321\200\320\276\320\272\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_3->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>char * strncpy( char * destptr, const char * srcptr, size_t num );</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 \320\272\320\276\320\277\320\270\321\200\321\203\320\265\321\202 \320\277\320\265\321\200\320\262\321\213\320\265 <span style=\" font-family:'Courier New';\">num</span> \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \320\270\320\267 \321\201\321\202\321\200\320\276\320\272\320\270 <span style=\" font-family:'Courier New';\">srcptr</span> \320\262 \321\201\321\202\321\200\320\276\320\272\321\203 <span style=\" font-family:'Courier New';\">destptr</span>. \320\225\321\201\320\273\320\270 \320\272\320\276\320\275\320\265\321\206 \321\201\321\202\321\200\320\276\320\272\320\270 <span style=\" font-family:'Courier New';\">srcptr</span> (\321\201\320\270\320\274\320\262\320\276\320\273 \320\272\320\276\320\275\321\206\320\260 \321\201\321\202\321\200\320\276\320\272\320\270 ) \320\264\320\276\321\201\321\202\320\270\320\263\320\275\321\203\321\202 \320"
                        "\277\321\200\320\265\320\266\320\264\320\265, \321\207\320\265\320\274 \320\261\321\213\320\273\320\270 \321\201\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\321\213 <span style=\" font-family:'Courier New';\">num</span> \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262, \320\272 \321\201\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\274 \321\201\320\270\320\274\320\262\320\276\320\273\320\260\320\274 \320\262 \320\272\320\276\320\275\320\265\321\206 \321\201\321\202\321\200\320\276\320\272\320\270 <span style=\" font-family:'Courier New';\">destptr</span> \320\264\320\276\320\261\320\260\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \320\275\321\203\320\273\321\214-\321\201\320\270\320\274\320\262\320\276\320\273, \320\277\320\276\321\201\320\273\320\265 \321\207\320\265\320\263\320\276, \321\201\321\202\321\200\320\276\320\272\320\260 \321\201\321\207\320\270\321\202\320\260\320\265\321\202\321\201\321\217 \321\201"
                        "\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\276\320\271.</p><p>\320\225\321\201\320\273\320\270 \320\266\320\265 \321\201\321\202\321\200\320\276\320\272\320\260 \320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\276\320\272\320\260\320\266\320\265\321\202\321\201\321\217 \320\274\320\265\320\275\321\214\321\210\320\265 <span style=\" font-family:'Courier New';\">num</span>, \321\202\320\276\320\263\320\264\320\260 \321\201\320\272\320\276\320\277\320\270\321\200\321\203\321\216\321\202\321\201\321\217 \321\201\320\270\320\274\320\262\320\276\320\273\321\213, \320\272\320\276\321\202\320\276\321\200\321\213\320\265 \320\277\320\276\320\274\320\265\321\201\321\202\321\217\321\202\321\201\321\217 \320\262 <span style=\" font-family:'Courier New';\">destptr</span>, \321\203\321\207\320\270\321\202\321\213\320\262\320\260\321\217 \321\202\320\276, \321\207\321\202\320\276 \320\262 \320\272\320\276\320\275\321\206\320\265 \321\201\321\202\321"
                        "\200\320\276\320\272\320\270 \320\276\320\261\321\217\320\267\320\260\321\202\320\265\320\273\321\214\320\275\320\276 \320\264\320\276\320\273\320\266\320\265\320\275 \321\201\321\202\320\276\321\217\321\202\321\214 \321\201\320\270\320\274\320\262\320\276\320\273 \320\272\320\276\320\275\321\206\320\260 \321\201\321\202\321\200\320\276\320\272\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "strncpy", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_4->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>char *strncat(char *str1, const char *str2, size_t count)</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 strncat() \320\264\320\276\320\261\320\260\320\262\320\273\321\217\320\265\321\202 \320\272 \321\201\321\202\321\200\320\276\320\272\320\265, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\203\321\216 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\320\265\321\202 str1, \320\275\320\265 \320\261\320\276\320\273\320\265\320\265 count \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \320\270\320\267 \321\201\321\202\321\200\320\276\320\272\320\270, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\203\321\216 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\320\265\321\202 str2. \320\222 \320\272\320\276\320\275\321\206\320\265 \320\274\320\276\320\264\320\270\321\204\320\270\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\276\320\271 \321\201\321\202\321\200\320\276\320\272\320\270 str1 \321\204"
                        "\321\203\320\275\320\272\321\206\320\270\321\217 \321\201\321\202\320\260\320\262\320\270\321\202 \320\275\321\203\320\273\320\265\302\255\320\262\320\276\320\271 \321\201\320\270\320\274\320\262\320\276\320\273. \320\235\321\203\320\273\320\265\320\262\320\276\320\271 \321\201\320\270\320\274\320\262\320\276\320\273, \320\277\320\265\321\200\320\262\320\276\320\275\320\260\321\207\320\260\320\273\321\214\320\275\320\276 \320\267\320\260\320\262\320\265\321\200\321\210\320\260\320\262\321\210\320\270\320\271 \321\201\321\202\321\200\320\276\320\272\321\203 str1, \320\267\320\260\320\274\320\265\321\211\320\260\320\265\321\202\321\201\321\217 \320\277\320\265\321\200\320\262\321\213\320\274 \321\201\320\270\320\274\320\262\320\276\302\255\320\273\320\276\320\274 \321\201\321\202\321\200\320\276\320\272\320\270 str2. \320\241\321\202\321\200\320\276\320\272\320\260 str2 \320\276\321\201\321\202\320\260\320\265\321\202\321\201\321\217 \320\262 \320\277\320\265\321\200\320\262\320\276\320\275\320\260\321\207\320\260"
                        "\320\273\321\214\320\275\320\276\320\274 \320\262\320\270\320\264\320\265.\320\244\321\203\320\275\320\272\321\206\320\270\321\217 strncat() \320\262\320\276\320\267\320\262\321\200\320\260\321\211\320\260\320\265\321\202 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 str1.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_4->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>char *strncat(char *str1, const char *str2, size_t count)</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 strncat() \320\264\320\276\320\261\320\260\320\262\320\273\321\217\320\265\321\202 \320\272 \321\201\321\202\321\200\320\276\320\272\320\265, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\203\321\216 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\320\265\321\202 str1, \320\275\320\265 \320\261\320\276\320\273\320\265\320\265 count \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \320\270\320\267 \321\201\321\202\321\200\320\276\320\272\320\270, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\203\321\216 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\320\265\321\202 str2. \320\222 \320\272\320\276\320\275\321\206\320\265 \320\274\320\276\320\264\320\270\321\204\320\270\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\276\320\271 \321\201\321\202\321\200\320\276\320\272\320\270 str1 \321\204"
                        "\321\203\320\275\320\272\321\206\320\270\321\217 \321\201\321\202\320\260\320\262\320\270\321\202 \320\275\321\203\320\273\320\265\302\255\320\262\320\276\320\271 \321\201\320\270\320\274\320\262\320\276\320\273. \320\235\321\203\320\273\320\265\320\262\320\276\320\271 \321\201\320\270\320\274\320\262\320\276\320\273, \320\277\320\265\321\200\320\262\320\276\320\275\320\260\321\207\320\260\320\273\321\214\320\275\320\276 \320\267\320\260\320\262\320\265\321\200\321\210\320\260\320\262\321\210\320\270\320\271 \321\201\321\202\321\200\320\276\320\272\321\203 str1, \320\267\320\260\320\274\320\265\321\211\320\260\320\265\321\202\321\201\321\217 \320\277\320\265\321\200\320\262\321\213\320\274 \321\201\320\270\320\274\320\262\320\276\302\255\320\273\320\276\320\274 \321\201\321\202\321\200\320\276\320\272\320\270 str2. \320\241\321\202\321\200\320\276\320\272\320\260 str2 \320\276\321\201\321\202\320\260\320\265\321\202\321\201\321\217 \320\262 \320\277\320\265\321\200\320\262\320\276\320\275\320\260\321\207\320\260"
                        "\320\273\321\214\320\275\320\276\320\274 \320\262\320\270\320\264\320\265.\320\244\321\203\320\275\320\272\321\206\320\270\321\217 strncat() \320\262\320\276\320\267\320\262\321\200\320\260\321\211\320\260\320\265\321\202 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 str1.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "strncat", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_14->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>int memcmp(const void *buf1, const void *buf2, size_t count)</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 memcmp() \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\265\321\202 \320\277\320\265\321\200\320\262\321\213\320\265 count \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \320\274\320\260\321\201\321\201\320\270\320\262\320\276\320\262, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\213\320\265 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\321\216\321\202 buf1 \320\270 buf2. \320\241\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \320\273\320\265\320\272\321\201\320\270\320\272\320\276\320\263\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\270. \320\244\321\203\320\275\320\272\321\206\320\270\321\217 memcmp() \320\262\320\276\320\267\320\262\321\200\320\260\321\211\320\260"
                        "\320\265\321\202 \321\206\320\265\320\273\320\276\320\265 \321\207\320\270\321\201\320\273\320\276</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_14->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>int memcmp(const void *buf1, const void *buf2, size_t count)</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 memcmp() \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\265\321\202 \320\277\320\265\321\200\320\262\321\213\320\265 count \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \320\274\320\260\321\201\321\201\320\270\320\262\320\276\320\262, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\213\320\265 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\321\216\321\202 buf1 \320\270 buf2. \320\241\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \320\273\320\265\320\272\321\201\320\270\320\272\320\276\320\263\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\270. \320\244\321\203\320\275\320\272\321\206\320\270\321\217 memcmp() \320\262\320\276\320\267\320\262\321\200\320\260\321\211\320\260"
                        "\320\265\321\202 \321\206\320\265\320\273\320\276\320\265 \321\207\320\270\321\201\320\273\320\276</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "memcmp", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_16->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>void * memcpy( void * destptr, const void * srcptr, size_t num );</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 <span style=\" font-family:'Courier New';\">memcpy</span> \320\272\320\276\320\277\320\270\321\200\321\203\320\265\321\202 <span style=\" font-family:'Courier New';\">num</span> \320\261\320\260\320\271\321\202\320\276\320\262 \320\277\320\265\321\200\320\262\320\276\320\263\320\276 \320\261\320\273\320\276\320\272\320\260 \320\277\320\260\320\274\321\217\321\202\320\270, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\213\320\271 \321\201\321\201\321\213\320\273\320\260\320\265\321\202\321\201\321\217 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 <span style=\" font-family:'Courier New';\">srcptr</span>, \320\262\320\276 \320\262\321\202\320\276\321\200\320\276\320\271 \320\261\320\273\320\276\320\272 \320\277\320\260\320\274\321\217\321\202\320\270, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\213\320\271"
                        " \321\201\321\201\321\213\320\273\320\260\320\265\321\202\321\201\321\217 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 <span style=\" font-family:'Courier New';\">destptr</span>.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_16->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>void * memcpy( void * destptr, const void * srcptr, size_t num );</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 <span style=\" font-family:'Courier New';\">memcpy</span> \320\272\320\276\320\277\320\270\321\200\321\203\320\265\321\202 <span style=\" font-family:'Courier New';\">num</span> \320\261\320\260\320\271\321\202\320\276\320\262 \320\277\320\265\321\200\320\262\320\276\320\263\320\276 \320\261\320\273\320\276\320\272\320\260 \320\277\320\260\320\274\321\217\321\202\320\270, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\213\320\271 \321\201\321\201\321\213\320\273\320\260\320\265\321\202\321\201\321\217 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 <span style=\" font-family:'Courier New';\">srcptr</span>, \320\262\320\276 \320\262\321\202\320\276\321\200\320\276\320\271 \320\261\320\273\320\276\320\272 \320\277\320\260\320\274\321\217\321\202\320\270, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\213\320\271"
                        " \321\201\321\201\321\213\320\273\320\260\320\265\321\202\321\201\321\217 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 <span style=\" font-family:'Courier New';\">destptr</span>.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "memcpy", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_11->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>char *strerror(int num)</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 strerror() \320\262\320\276\320\267\320\262\321\200\320\260\321\211\320\260\320\265\321\202 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 \320\275\320\260 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 \320\276\320\261 \320\276\321\210\320\270\320\261\320\272\320\265, \321\201\320\262\321\217\320\267\320\260\320\275\320\275\320\276\320\265 \321\201 \320\275\320\276\320\274\320\265\321\200\320\276\320\274 \320\276\321\210\320\270\320\261\320\272\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_11->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>char *strerror(int num)</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 strerror() \320\262\320\276\320\267\320\262\321\200\320\260\321\211\320\260\320\265\321\202 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 \320\275\320\260 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 \320\276\320\261 \320\276\321\210\320\270\320\261\320\272\320\265, \321\201\320\262\321\217\320\267\320\260\320\275\320\275\320\276\320\265 \321\201 \320\275\320\276\320\274\320\265\321\200\320\276\320\274 \320\276\321\210\320\270\320\261\320\272\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "strerror", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_13->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-family:'Courier New';\">void* memset( void* memptr, intval, size_tnum );</span></p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 <span style=\" font-family:'Courier New';\">memset</span> \320\267\320\260\320\277\320\276\320\273\320\275\321\217\320\265\321\202 <span style=\" font-family:'Courier New';\">num</span> \320\261\320\260\320\271\321\202\320\276\320\262 \320\261\320\273\320\276\320\272\320\260 \320\277\320\260\320\274\321\217\321\202\320\270, \321\207\320\265\321\200\320\265\320\267 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 <span style=\" font-family:'Courier New';\">memptr</span>. \320\232\320\276\320\264 \320\267\320\260\320\277\320\276\320\273\320\275\321\217\320\265\320\274\320\276\320\263\320\276 \321\201\320\270\320\274\320\262\320\276\320\273\320\260 \320\277\320\265\321\200\320\265\320\264\320\260\321\221\321\202\321\201\321\217 \320\262 \321\204\321\203\320\275\320\272\321\206\320\270\321\216 \321\207\320\265"
                        "\321\200\320\265\320\267 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200 <span style=\" font-family:'Courier New';\">val</span>.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_13->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-family:'Courier New';\">void</span><span style=\" font-family:'Courier New';\">* memset( void</span><span style=\" font-family:'Courier New';\">* memptr, int</span><span style=\" font-family:'Courier New';\">val, size_t</span><span style=\" font-family:'Courier New';\">num );</span></p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 <span style=\" font-family:'Courier New';\">memset</span> \320\267\320\260\320\277\320\276\320\273\320\275\321\217\320\265\321\202 <span style=\" font-family:'Courier New';\">num</span> \320\261\320\260\320\271\321\202\320\276\320\262 \320\261\320\273\320\276\320\272\320\260 \320\277\320\260\320\274\321\217\321\202\320\270, \321\207\320\265\321\200\320\265\320\267 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 <span style=\" font-family:'Courier New';\">memptr</span>. \320\232\320\276\320\264 \320\267\320\260\320\277\320\276\320\273\320\275\321\217\320\265\320\274\320\276\320\263\320\276 \321\201\320\270"
                        "\320\274\320\262\320\276\320\273\320\260 \320\277\320\265\321\200\320\265\320\264\320\260\321\221\321\202\321\201\321\217 \320\262 \321\204\321\203\320\275\320\272\321\206\320\270\321\216 \321\207\320\265\321\200\320\265\320\267 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200 <span style=\" font-family:'Courier New';\">val</span>.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "memset", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_7->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>int strncmp( const char * string1, const char * string2, size_t num );</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\265\321\202 \320\277\320\265\321\200\320\262\321\213\320\265 <span style=\" font-family:'Courier New';\">num</span> \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \321\201\321\202\321\200\320\276\320\272\320\270 <span style=\" font-family:'Courier New';\">string1</span> \321\201 \320\277\320\265\321\200\320\262\321\213\320\274\320\270 <span style=\" font-family:'Courier New';\">num</span> \321\201\320\270\320\274\320\262\320\276\320\273\320\260\320\274\320\270 \321\201\321\202\321\200\320\276\320\272\320\270 <span style=\" font-family:'Courier New';\">string2</span>.<br/>\320\255\321\202\320\260 \321\204\321\203\320\275\320\272\321\206\320\270\321\217 \320\275\320\260\321\207\320\270\320\275\320\260\320\265\321\202 \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320"
                        "\260\321\202\321\214 \320\277\320\265\321\200\320\262\321\213\320\271 \321\201\320\270\320\274\320\262\320\276\320\273 \320\272\320\260\320\266\320\264\320\276\320\271 \321\201\321\202\321\200\320\276\320\272\320\270. \320\225\321\201\320\273\320\270 \320\276\320\275\320\270 \321\200\320\260\320\262\320\275\321\213, <span style=\" font-family:'Courier New';\">strncmp</span> \320\277\321\200\320\276\320\264\320\276\320\273\320\266\320\260\320\265\321\202 \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320\260\321\202\321\214 \302\240\321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\265 \320\277\320\260\321\200\321\213 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262, \320\277\320\276\320\272\320\260 \320\275\320\265 \320\261\321\203\320\264\321\203\321\202 \320\275\320\260\320\271\320\264\320\265\320\275\321\213 \321\200\320\260\320\267\320\273\320\270\321\207\320\275\321\213\320\265 \321\201\320\270\320\274\320\262\320\276\320\273\321\213 \320\270\320\273\320\270 \320"
                        "\277\320\276\320\272\320\260 \320\275\320\265 \320\261\321\203\320\264\320\265\321\202 \320\264\320\276\321\201\321\202\320\270\320\263\320\275\321\203\321\202 \320\272\320\276\320\275\320\265\321\206 \321\201\321\202\321\200\320\276\320\272\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_7->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>int strncmp( const char * string1, const char * string2, size_t num );</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\265\321\202 \320\277\320\265\321\200\320\262\321\213\320\265 <span style=\" font-family:'Courier New';\">num</span> \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \321\201\321\202\321\200\320\276\320\272\320\270 <span style=\" font-family:'Courier New';\">string1</span> \321\201 \320\277\320\265\321\200\320\262\321\213\320\274\320\270 <span style=\" font-family:'Courier New';\">num</span> \321\201\320\270\320\274\320\262\320\276\320\273\320\260\320\274\320\270 \321\201\321\202\321\200\320\276\320\272\320\270 <span style=\" font-family:'Courier New';\">string2</span>.<br/>\320\255\321\202\320\260 \321\204\321\203\320\275\320\272\321\206\320\270\321\217 \320\275\320\260\321\207\320\270\320\275\320\260\320\265\321\202 \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320"
                        "\260\321\202\321\214 \320\277\320\265\321\200\320\262\321\213\320\271 \321\201\320\270\320\274\320\262\320\276\320\273 \320\272\320\260\320\266\320\264\320\276\320\271 \321\201\321\202\321\200\320\276\320\272\320\270. \320\225\321\201\320\273\320\270 \320\276\320\275\320\270 \321\200\320\260\320\262\320\275\321\213, <span style=\" font-family:'Courier New';\">strncmp</span> \320\277\321\200\320\276\320\264\320\276\320\273\320\266\320\260\320\265\321\202 \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320\260\321\202\321\214  \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\265 \320\277\320\260\321\200\321\213 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262, \320\277\320\276\320\272\320\260 \320\275\320\265 \320\261\321\203\320\264\321\203\321\202 \320\275\320\260\320\271\320\264\320\265\320\275\321\213 \321\200\320\260\320\267\320\273\320\270\321\207\320\275\321\213\320\265 \321\201\320\270\320\274\320\262\320\276\320\273\321\213 \320\270\320\273\320\270 \320\277\320"
                        "\276\320\272\320\260 \320\275\320\265 \320\261\321\203\320\264\320\265\321\202 \320\264\320\276\321\201\321\202\320\270\320\263\320\275\321\203\321\202 \320\272\320\276\320\275\320\265\321\206 \321\201\321\202\321\200\320\276\320\272\320\270.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "strncmp", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_9->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>size_t *strxfrm(char *dest, const char *source, size_t count)</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 strxfrm() \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\321\202\321\201\321\217 \320\264\320\273\321\217 \320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \320\264\320\276 count \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \321\201\320\276\320\264\320\265\321\200\320\266\320\270\320\274\320\276\320\263\320\276 \321\201\321\202\321\200\320\276\320\272\320\270, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\203\321\216 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\320\265\321\202 source, \320\262 \321\201\321\202\321\200\320\276\320\272\321\203, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\203\321\216 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\320\265\321\202 dest. \320\220\321\200\320\263\321\203\320\274\320\265\320\275\321\202"
                        " source \320\264\320\276\320\273\320\266\320\265\320\275 \320\261\321\213\321\202\321\214 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\320\265\320\274 \320\275\320\260 \321\201\321\202\321\200\320\276\320\272\321\203, \320\276\320\272\320\260\320\275\321\207\320\270\320\262\320\260\321\216\321\211\321\203\321\216\321\201\321\217 \320\275\321\203\320\273\320\265\320\262\321\213\320\274 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\274. \320\222 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\265 \320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \320\273\321\216\320\261\321\213\320\265 \320\275\320\260\321\206\320\270\320\276\320\275\320\260\320\273\321\214\320\275\321\213\320\265 \321\201\320\270\320\274\320\262\320\276\320\273\321\213 \320\277\321\200\320\265\320\276\320\261\321\200\320\260\320\267\321\203\321\216\321\202\321\201\321\217 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202, \321\205\320\260\321\200\320\260"
                        "\320\272\321\202\320\265\321\200\320\275\321\213\320\271 \320\264\320\273\321\217 \320\272\320\276\320\275\320\272\321\200\320\265\321\202\320\275\320\276\320\271 \321\201\321\202\321\200\320\260\320\275\321\213. \320\244\321\203\320\275\320\272\321\206\320\270\321\217 strncpy() \320\262\320\276\320\267\320\262\321\200\320\260\321\211\320\260\320\265\321\202 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 \320\275\320\260 dest. </p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_9->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>size_t *strxfrm(char *dest, const char *source, size_t count)</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 strxfrm() \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\321\202\321\201\321\217 \320\264\320\273\321\217 \320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \320\264\320\276 count \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \321\201\320\276\320\264\320\265\321\200\320\266\320\270\320\274\320\276\320\263\320\276 \321\201\321\202\321\200\320\276\320\272\320\270, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\203\321\216 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\320\265\321\202 source, \320\262 \321\201\321\202\321\200\320\276\320\272\321\203, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\203\321\216 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\320\265\321\202 dest. \320\220\321\200\320\263\321\203\320\274\320\265\320\275\321\202"
                        " source \320\264\320\276\320\273\320\266\320\265\320\275 \320\261\321\213\321\202\321\214 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\320\265\320\274 \320\275\320\260 \321\201\321\202\321\200\320\276\320\272\321\203, \320\276\320\272\320\260\320\275\321\207\320\270\320\262\320\260\321\216\321\211\321\203\321\216\321\201\321\217 \320\275\321\203\320\273\320\265\320\262\321\213\320\274 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\274. \320\222 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\265 \320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \320\273\321\216\320\261\321\213\320\265 \320\275\320\260\321\206\320\270\320\276\320\275\320\260\320\273\321\214\320\275\321\213\320\265 \321\201\320\270\320\274\320\262\320\276\320\273\321\213 \320\277\321\200\320\265\320\276\320\261\321\200\320\260\320\267\321\203\321\216\321\202\321\201\321\217 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202, \321\205\320\260\321\200\320\260"
                        "\320\272\321\202\320\265\321\200\320\275\321\213\320\271 \320\264\320\273\321\217 \320\272\320\276\320\275\320\272\321\200\320\265\321\202\320\275\320\276\320\271 \321\201\321\202\321\200\320\260\320\275\321\213. \320\244\321\203\320\275\320\272\321\206\320\270\321\217 strncpy() \320\262\320\276\320\267\320\262\321\200\320\260\321\211\320\260\320\265\321\202 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 \320\275\320\260 dest. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "strxfrm", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_15->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>void *memmove(void *dest, const void *source, size_t count)</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 memmove() \320\272\320\276\320\277\320\270\321\200\321\203\320\265\321\202 count \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \320\270\320\267 \320\274\320\260\321\201\321\201\320\270\320\262\320\260, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\213\320\271 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\320\265\321\202 source, \320\262 \320\274\320\260\321\201\302\255\321\201\320\270\320\262, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\213\320\271 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\320\265\321\202 dest.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_15->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>void *memmove(void *dest, const void *source, size_t count)</p><p>\320\244\321\203\320\275\320\272\321\206\320\270\321\217 memmove() \320\272\320\276\320\277\320\270\321\200\321\203\320\265\321\202 count \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \320\270\320\267 \320\274\320\260\321\201\321\201\320\270\320\262\320\260, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\213\320\271 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\320\265\321\202 source, \320\262 \320\274\320\260\321\201\302\255\321\201\320\270\320\262, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\213\320\271 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\320\265\321\202 dest.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "memmove", nullptr));
        pushButton_19->setText(QString());
        pushButton_20->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
