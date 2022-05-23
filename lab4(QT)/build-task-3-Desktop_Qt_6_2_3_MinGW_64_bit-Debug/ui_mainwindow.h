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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *number;
    QLineEdit *numberLine;
    QPushButton *getAnswer;
    QTextBrowser *textBrowser;
    QGridLayout *gridLayout_2;
    QLineEdit *assginLine;
    QPushButton *emplace;
    QPushButton *popBack;
    QPushButton *insert;
    QComboBox *inserBox;
    QPushButton *assign;
    QComboBox *eraseBox;
    QPushButton *erase;
    QPushButton *pushBack;
    QPushButton *emplaceBack;
    QLineEdit *emplaceBackLine;
    QLineEdit *emplaceLine;
    QComboBox *emplaceBox;
    QPushButton *clear;
    QTableView *tableView;
    QGridLayout *gridLayout;
    QLineEdit *rEndLine;
    QLineEdit *sizeLine;
    QLabel *capacity;
    QLineEdit *capacityLine;
    QLineEdit *beginLine;
    QLabel *size_2;
    QLineEdit *rBeginLine;
    QLabel *end;
    QLineEdit *emptyLine;
    QLabel *size_3;
    QLabel *empty;
    QLabel *begin;
    QLabel *rBegin;
    QLineEdit *endLine;
    QLabel *size;
    QLineEdit *max_size;
    QLabel *rEnd;
    QLineEdit *front;
    QLabel *size_4;
    QLineEdit *back;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1152, 402);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 1131, 347));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        number = new QLabel(horizontalLayoutWidget);
        number->setObjectName(QString::fromUtf8("number"));
        QFont font;
        font.setPointSize(14);
        number->setFont(font);

        verticalLayout->addWidget(number);

        numberLine = new QLineEdit(horizontalLayoutWidget);
        numberLine->setObjectName(QString::fromUtf8("numberLine"));

        verticalLayout->addWidget(numberLine);

        getAnswer = new QPushButton(horizontalLayoutWidget);
        getAnswer->setObjectName(QString::fromUtf8("getAnswer"));
        getAnswer->setMinimumSize(QSize(100, 0));

        verticalLayout->addWidget(getAnswer);

        textBrowser = new QTextBrowser(horizontalLayoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        horizontalLayout->addLayout(verticalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        assginLine = new QLineEdit(horizontalLayoutWidget);
        assginLine->setObjectName(QString::fromUtf8("assginLine"));

        gridLayout_2->addWidget(assginLine, 3, 1, 1, 1);

        emplace = new QPushButton(horizontalLayoutWidget);
        emplace->setObjectName(QString::fromUtf8("emplace"));

        gridLayout_2->addWidget(emplace, 4, 0, 1, 1);

        popBack = new QPushButton(horizontalLayoutWidget);
        popBack->setObjectName(QString::fromUtf8("popBack"));

        gridLayout_2->addWidget(popBack, 0, 1, 1, 1);

        insert = new QPushButton(horizontalLayoutWidget);
        insert->setObjectName(QString::fromUtf8("insert"));

        gridLayout_2->addWidget(insert, 1, 0, 1, 1);

        inserBox = new QComboBox(horizontalLayoutWidget);
        inserBox->setObjectName(QString::fromUtf8("inserBox"));
        inserBox->setMaximumSize(QSize(40, 16777215));

        gridLayout_2->addWidget(inserBox, 1, 1, 1, 1);

        assign = new QPushButton(horizontalLayoutWidget);
        assign->setObjectName(QString::fromUtf8("assign"));

        gridLayout_2->addWidget(assign, 3, 0, 1, 1);

        eraseBox = new QComboBox(horizontalLayoutWidget);
        eraseBox->setObjectName(QString::fromUtf8("eraseBox"));
        eraseBox->setMaximumSize(QSize(40, 16777215));

        gridLayout_2->addWidget(eraseBox, 2, 1, 1, 1);

        erase = new QPushButton(horizontalLayoutWidget);
        erase->setObjectName(QString::fromUtf8("erase"));

        gridLayout_2->addWidget(erase, 2, 0, 1, 1);

        pushBack = new QPushButton(horizontalLayoutWidget);
        pushBack->setObjectName(QString::fromUtf8("pushBack"));

        gridLayout_2->addWidget(pushBack, 0, 0, 1, 1);

        emplaceBack = new QPushButton(horizontalLayoutWidget);
        emplaceBack->setObjectName(QString::fromUtf8("emplaceBack"));

        gridLayout_2->addWidget(emplaceBack, 5, 0, 1, 1);

        emplaceBackLine = new QLineEdit(horizontalLayoutWidget);
        emplaceBackLine->setObjectName(QString::fromUtf8("emplaceBackLine"));

        gridLayout_2->addWidget(emplaceBackLine, 5, 1, 1, 1);

        emplaceLine = new QLineEdit(horizontalLayoutWidget);
        emplaceLine->setObjectName(QString::fromUtf8("emplaceLine"));

        gridLayout_2->addWidget(emplaceLine, 4, 1, 1, 1);

        emplaceBox = new QComboBox(horizontalLayoutWidget);
        emplaceBox->setObjectName(QString::fromUtf8("emplaceBox"));
        emplaceBox->setMaximumSize(QSize(40, 16777215));

        gridLayout_2->addWidget(emplaceBox, 4, 2, 1, 1);

        clear = new QPushButton(horizontalLayoutWidget);
        clear->setObjectName(QString::fromUtf8("clear"));

        gridLayout_2->addWidget(clear, 0, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        tableView = new QTableView(horizontalLayoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout->addWidget(tableView);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        rEndLine = new QLineEdit(horizontalLayoutWidget);
        rEndLine->setObjectName(QString::fromUtf8("rEndLine"));
        rEndLine->setReadOnly(true);

        gridLayout->addWidget(rEndLine, 7, 1, 1, 1);

        sizeLine = new QLineEdit(horizontalLayoutWidget);
        sizeLine->setObjectName(QString::fromUtf8("sizeLine"));
        sizeLine->setMouseTracking(true);
        sizeLine->setReadOnly(true);

        gridLayout->addWidget(sizeLine, 0, 1, 1, 1);

        capacity = new QLabel(horizontalLayoutWidget);
        capacity->setObjectName(QString::fromUtf8("capacity"));

        gridLayout->addWidget(capacity, 1, 0, 1, 1);

        capacityLine = new QLineEdit(horizontalLayoutWidget);
        capacityLine->setObjectName(QString::fromUtf8("capacityLine"));
        capacityLine->setReadOnly(true);

        gridLayout->addWidget(capacityLine, 1, 1, 1, 1);

        beginLine = new QLineEdit(horizontalLayoutWidget);
        beginLine->setObjectName(QString::fromUtf8("beginLine"));
        beginLine->setReadOnly(true);

        gridLayout->addWidget(beginLine, 4, 1, 1, 1);

        size_2 = new QLabel(horizontalLayoutWidget);
        size_2->setObjectName(QString::fromUtf8("size_2"));

        gridLayout->addWidget(size_2, 3, 0, 1, 1);

        rBeginLine = new QLineEdit(horizontalLayoutWidget);
        rBeginLine->setObjectName(QString::fromUtf8("rBeginLine"));
        rBeginLine->setReadOnly(true);

        gridLayout->addWidget(rBeginLine, 6, 1, 1, 1);

        end = new QLabel(horizontalLayoutWidget);
        end->setObjectName(QString::fromUtf8("end"));

        gridLayout->addWidget(end, 5, 0, 1, 1);

        emptyLine = new QLineEdit(horizontalLayoutWidget);
        emptyLine->setObjectName(QString::fromUtf8("emptyLine"));
        emptyLine->setReadOnly(true);

        gridLayout->addWidget(emptyLine, 2, 1, 1, 1);

        size_3 = new QLabel(horizontalLayoutWidget);
        size_3->setObjectName(QString::fromUtf8("size_3"));

        gridLayout->addWidget(size_3, 8, 0, 1, 1);

        empty = new QLabel(horizontalLayoutWidget);
        empty->setObjectName(QString::fromUtf8("empty"));

        gridLayout->addWidget(empty, 2, 0, 1, 1);

        begin = new QLabel(horizontalLayoutWidget);
        begin->setObjectName(QString::fromUtf8("begin"));

        gridLayout->addWidget(begin, 4, 0, 1, 1);

        rBegin = new QLabel(horizontalLayoutWidget);
        rBegin->setObjectName(QString::fromUtf8("rBegin"));

        gridLayout->addWidget(rBegin, 6, 0, 1, 1);

        endLine = new QLineEdit(horizontalLayoutWidget);
        endLine->setObjectName(QString::fromUtf8("endLine"));
        endLine->setReadOnly(true);

        gridLayout->addWidget(endLine, 5, 1, 1, 1);

        size = new QLabel(horizontalLayoutWidget);
        size->setObjectName(QString::fromUtf8("size"));

        gridLayout->addWidget(size, 0, 0, 1, 1);

        max_size = new QLineEdit(horizontalLayoutWidget);
        max_size->setObjectName(QString::fromUtf8("max_size"));
        max_size->setReadOnly(true);

        gridLayout->addWidget(max_size, 3, 1, 1, 1);

        rEnd = new QLabel(horizontalLayoutWidget);
        rEnd->setObjectName(QString::fromUtf8("rEnd"));

        gridLayout->addWidget(rEnd, 7, 0, 1, 1);

        front = new QLineEdit(horizontalLayoutWidget);
        front->setObjectName(QString::fromUtf8("front"));
        front->setReadOnly(true);

        gridLayout->addWidget(front, 8, 1, 1, 1);

        size_4 = new QLabel(horizontalLayoutWidget);
        size_4->setObjectName(QString::fromUtf8("size_4"));

        gridLayout->addWidget(size_4, 9, 0, 1, 1);

        back = new QLineEdit(horizontalLayoutWidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setReadOnly(true);

        gridLayout->addWidget(back, 9, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1152, 25));
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
        number->setText(QCoreApplication::translate("MainWindow", "\320\224\320\262\321\203\320\264\320\265\321\201\321\217\321\202\320\270\321\207\320\275\320\276\320\265", nullptr));
        numberLine->setText(QString());
        getAnswer->setText(QCoreApplication::translate("MainWindow", "\320\276\320\272", nullptr));
        assginLine->setInputMask(QString());
        emplace->setText(QCoreApplication::translate("MainWindow", "Emplace", nullptr));
        popBack->setText(QCoreApplication::translate("MainWindow", "Pop_back", nullptr));
        insert->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        assign->setText(QCoreApplication::translate("MainWindow", "Assign", nullptr));
        erase->setText(QCoreApplication::translate("MainWindow", "Erase", nullptr));
        pushBack->setText(QCoreApplication::translate("MainWindow", "Push_back", nullptr));
        emplaceBack->setText(QCoreApplication::translate("MainWindow", "Emplace_back", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        capacity->setText(QCoreApplication::translate("MainWindow", " Capacity", nullptr));
        size_2->setText(QCoreApplication::translate("MainWindow", " Max_size", nullptr));
        end->setText(QCoreApplication::translate("MainWindow", " End", nullptr));
        size_3->setText(QCoreApplication::translate("MainWindow", " Front", nullptr));
        empty->setText(QCoreApplication::translate("MainWindow", " Empty", nullptr));
        begin->setText(QCoreApplication::translate("MainWindow", " Begin", nullptr));
        rBegin->setText(QCoreApplication::translate("MainWindow", " RBegin", nullptr));
        size->setText(QCoreApplication::translate("MainWindow", " Size", nullptr));
        rEnd->setText(QCoreApplication::translate("MainWindow", " REnd", nullptr));
        size_4->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
