#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QStandardItemModel>
#include <sstream>
#include<iostream>

#include"Vector.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateVectorTable();

private slots:
    void on_pushBack_clicked();

    void on_popBack_clicked();

    void on_clear_clicked();

    void on_insert_clicked();

    void on_erase_clicked();

    void on_assign_clicked();

    void on_emplace_clicked();

    void on_emplaceBack_clicked();

    void on_sizeLine_editingFinished();

    void on_capacityLine_editingFinished();

    void on_getAnswer_clicked();

private:
    Ui::MainWindow *ui;
    MyVector<int> vec;
    void Normalize(vector<int>& c);
    void AddZero(vector<int>& c, int x);
    vector<int> AddNum(const vector<int>& a, const vector<int>& b, int k);
    int GetBit(const vector<int>& v, int b);
    vector<int> Multiply(const vector<int>& a, int x, int k);
    void GenerateSequence(vector<int> n, const vector<vector<int>>& p, int k, int i, vector<std::pair<int, vector<int>> >& v);
};

#endif // MAINWINDOW_H
