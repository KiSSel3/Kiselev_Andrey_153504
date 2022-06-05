#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::showDeq() {
    QString string;

    for (size_t i = 0; i < deq.size(); ++i) {
        string += QString::number(deq[i]);
        string += '\n';
    }

    ui->textShow->setText(string);
}

void MainWindow::on_push_b_clicked() {
    ui->textShow->clear();

    int val = rand() % 100;

    deq.push_back(val);
    showDeq();
}

void MainWindow::on_push_f_clicked() {
    ui->textShow->clear();

    int val = rand() % 100;

    deq.push_front(val);

    showDeq();
}


void MainWindow::on_pop_b_clicked() {
    if (deq.empty())
        return;

    ui->textShow->clear();

    deq.pop_back();

    showDeq();
}


void MainWindow::on_pop_f_clicked() {

    if (deq.empty())
        return;

    ui->textShow->clear();

    deq.pop_front();

    showDeq();
}


void MainWindow::on_cl_clicked() {

    if (deq.empty())
        return;

    ui->textShow->clear();

    deq.clear();
}


void MainWindow::on_sz_clicked() {
    if (deq.empty())
        return;

    ui->textShow->clear();

    QString d = "Размер: " + QString::number(deq.size());


    ui->textShow->setText(d);
}


void MainWindow::on_empt_clicked() {
    ui->textShow->clear();

    QString d = deq.empty() ? "пусто" : "не пусто";

    ui->textShow->setText(d);
}


void MainWindow::on_inv_clicked() {
    ui->textShow->clear();

    bool ok;

    int inputSize = QInputDialog::getInt(this, "", "Выберите число: ",0, 0, INT_MAX, 1, &ok);
    if(!ok) return;

    deq.resize(inputSize);
    showDeq();
}

void MainWindow::on_pushButton_clicked()
{
        showDeq();
}

