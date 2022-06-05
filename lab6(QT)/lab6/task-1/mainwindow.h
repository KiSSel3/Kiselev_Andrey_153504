#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "SearchTree.h"

#include <QMainWindow>
#include <iostream>
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

    void forwardBypass(TreeNode<QString>* treeNode);
    void reverseBypass(TreeNode<QString>* treeNode);
    void keyBypass(TreeNode<QString>* treeNode);

    void addToTreeWidget(TreeNode<QString>* treeNode);

private slots:
    void on_addInfoButton_clicked();

    void on_addToTreeButton_clicked();

    void on_balanceButton_clicked();

    void on_searchButton_clicked();

    void on_deleteButton_clicked();

    void on_forwardBypassButton_clicked();

    void on_reverseBypassButton_clicked();

    void on_keyBypassButton_clicked();

    void on_forTaskOneButton_clicked();

private:
    Ui::MainWindow *ui;
    SearchTree<QString> searchTree;
    int Rows = 0;
    std::vector<std::pair<int,QString>> arr;
    int indexInArr = 0;
};
#endif // MAINWINDOW_H
