#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
//#include "Pointers.h"
#include "sharedptr.h"
#include "uniqueptr.h"
#include "weakptr.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_uniqueButton_clicked();
    void on_sharedButton_clicked();
    void on_weakButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
