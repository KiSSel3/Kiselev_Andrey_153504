#include "mainwindow.h"
#include <QApplication>

////////////////////////////////
///         凸(￣ヘ￣)        ///
///    Created by KiSSel     ///
///        01.05.2022        ///
////////////////////////////////

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
