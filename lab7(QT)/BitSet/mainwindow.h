#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bitset.h"

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

    void BitSetView();

private slots:
    void on_flipButton_clicked();
    void on_ResetButton_clicked();
    void on_SetButton_clicked();
    void on_TestButton_clicked();
    void on_AnyButton_clicked();
    void on_NoneButton_clicked();
    void on_To_UlongButton_clicked();
    void on_AllButton_clicked();
    void on_SizeButton_clicked();
    void on_To_UllongButton_clicked();
    void on_CountButton_clicked();
    void on_To_StringButton_clicked();

private:
    Ui::MainWindow *ui;

    BitSet<8> bitset;
};
#endif // MAINWINDOW_H
