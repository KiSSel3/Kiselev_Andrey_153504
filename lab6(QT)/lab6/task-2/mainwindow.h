#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "HashTableForTask.h"
#include "HashTable.h"

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

    void showHashTable();

private slots:
    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_showButton_clicked();

    void on_searchButton_clicked();

    void on_emptyButton_clicked();

    void on_forTaskButton_clicked();

private:
    Ui::MainWindow *ui;

    HashTable hashTable;
    HashTableForTask hashTableForTask;
};
#endif // MAINWINDOW_H
