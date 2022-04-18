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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *openFileButton;
    QPushButton *studentListToFileButton;
    QPushButton *updateTableViewButton;
    QTableView *tableView;
    QPushButton *addStudentButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *surnameSearchButton;
    QPushButton *citySearchButton;
    QPushButton *gradeSearchButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 620);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(680, 410, 311, 20));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 400, 365, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        openFileButton = new QPushButton(horizontalLayoutWidget);
        openFileButton->setObjectName(QString::fromUtf8("openFileButton"));

        horizontalLayout->addWidget(openFileButton);

        studentListToFileButton = new QPushButton(horizontalLayoutWidget);
        studentListToFileButton->setObjectName(QString::fromUtf8("studentListToFileButton"));

        horizontalLayout->addWidget(studentListToFileButton);

        updateTableViewButton = new QPushButton(horizontalLayoutWidget);
        updateTableViewButton->setObjectName(QString::fromUtf8("updateTableViewButton"));

        horizontalLayout->addWidget(updateTableViewButton);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 0, 980, 400));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        addStudentButton = new QPushButton(centralwidget);
        addStudentButton->setObjectName(QString::fromUtf8("addStudentButton"));
        addStudentButton->setGeometry(QRect(120, 470, 191, 41));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(680, 430, 311, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        surnameSearchButton = new QPushButton(verticalLayoutWidget);
        surnameSearchButton->setObjectName(QString::fromUtf8("surnameSearchButton"));

        verticalLayout->addWidget(surnameSearchButton);

        citySearchButton = new QPushButton(verticalLayoutWidget);
        citySearchButton->setObjectName(QString::fromUtf8("citySearchButton"));

        verticalLayout->addWidget(citySearchButton);

        gradeSearchButton = new QPushButton(verticalLayoutWidget);
        gradeSearchButton->setObjectName(QString::fromUtf8("gradeSearchButton"));

        verticalLayout->addWidget(gradeSearchButton);

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
        label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\276\320\262 \320\277\320\276 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\274 \320\272\321\200\320\265\321\202\320\265\321\200\320\270\321\217\320\274:", nullptr));
        openFileButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        studentListToFileButton->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\200\321\200\320\265\320\272\321\202\320\270\321\200\320\276\320\262\320\272\320\260 \321\204\320\260\320\271\320\273\320\260", nullptr));
        updateTableViewButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        addStudentButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", nullptr));
        surnameSearchButton->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        citySearchButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\321\205\320\276\320\264", nullptr));
        gradeSearchButton->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\270\320\271 \320\261\320\260\320\273\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
