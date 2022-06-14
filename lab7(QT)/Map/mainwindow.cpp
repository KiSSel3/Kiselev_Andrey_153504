#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
}

void MainWindow::updateListWidget()
{
    while(ui->listWidget->count())
        delete ui->listWidget->item(0);

    for(auto el : m){
        ui->listWidget->addItem(QString("key: %1\tvalue: %2").arg(el.first).arg(el.second.c_str()));
    }
}



void MainWindow::on_pushButton_clicked()
{
    m.insert({ui->spinBox->value(), ui->lineEdit->text().toStdString()});

    updateListWidget();
}



void MainWindow::on_pushButton_2_clicked()
{
    if(!ui->listWidget->count()) return;

    if(it != m.end() && ui->spinBox_2->value() == it->first){
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);

        ui->label_3->setText("");
        ui->label_5->setText("");
    }

    m.erase(ui->spinBox_2->value());

    updateListWidget();
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    it = m.find(ui->spinBox_3->value());

    setIterator();
}


void MainWindow::on_pushButton_4_clicked()
{
    ++it;

    setIterator();
}

void MainWindow::on_pushButton_5_clicked()
{
    --it;

    setIterator();
}

void MainWindow::setIterator()
{
    if(it == m.end()){
        ui->label_3->setText("end");
        ui->label_5->setText("");
    }
    else{
        ui->label_3->setText(QString::number(it->first));
        ui->label_5->setText(QString::fromStdString(it->second));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

