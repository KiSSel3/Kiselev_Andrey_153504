#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Queue.h"
#include <ctime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showList();

private slots:
    void on_createList_clicked();

    void on_deleteList_clicked();

private:
    Ui::MainWindow *ui;

    Queue<int> queue;
    std::list<int> randomNumbersList;
};
#endif // MAINWINDOW_H
