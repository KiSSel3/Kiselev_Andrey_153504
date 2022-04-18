#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidget>
#include <QPushButton>
#include <QPushButton>

#include <QStatusBar>
#include <Expression.h>
//#include "expression.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void CalculateExpr();

private:
    QTableWidget *table;
    QPushButton *calculate_btn;

    unsigned WIDTH = 1100, HEIGHT = 700, ROWS = 16;

    void CreateItem(QString expr, int row, int column) {

        QTableWidgetItem *itm = new QTableWidgetItem(expr);

        table->setItem(row, column, itm);
    }

    void SetExpressions();
};
#endif // MAINWINDOW_H
