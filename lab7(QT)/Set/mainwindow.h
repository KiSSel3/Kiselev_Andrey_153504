#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Set.h"

#include <QMainWindow>
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

    void clear() ;

private slots:
    void on_insert_clicked();

    void on_erase_clicked();

    void on_size_clicked();

private:
    Ui::MainWindow *ui;

    MySet<QString> *set;
};
#endif // MAINWINDOW_H
