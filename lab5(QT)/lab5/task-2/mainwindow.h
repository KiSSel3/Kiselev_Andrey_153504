#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Deque.h"
#include <QInputDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showDeq();

private slots:
    void on_push_b_clicked();
    void on_push_f_clicked();
    void on_pop_b_clicked();
    void on_pop_f_clicked();
    void on_cl_clicked();
    void on_sz_clicked();
    void on_empt_clicked();
    void on_inv_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    deque<int> deq;
};
#endif // MAINWINDOW_H
