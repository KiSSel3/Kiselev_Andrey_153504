#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "unordered_map.h"

#include <QMainWindow>
#include<QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();


private:
    Ui::MainWindow *ui;

    UnorderedMap<int> map;
    vector<int> keys;
    QRandomGenerator rand;
};
#endif // MAINWINDOW_H
