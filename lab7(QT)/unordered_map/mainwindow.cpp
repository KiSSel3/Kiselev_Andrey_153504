#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->containsKey->setValidator(new QIntValidator);
}

void MainWindow::on_pushButton_2_clicked()
{
    keys.push_back(rand.bounded(0,1000));
    for(int i = 0; i < keys.size(); i++){
        qDebug() << keys[i];
    }
    map.insert(keys[keys.size() - 1],rand.bounded(0,1000));

    ui->listWidget->addItem("Key: " + QString::number(keys[keys.size() - 1]) + "; Value: " + QString::number(map[keys[keys.size() - 1]]));
    ui->deleteBox->addItem(QString::number(keys[keys.size() - 1]));
    ui->editBox->addItem(QString::number(keys[keys.size() - 1]));
}


void MainWindow::on_pushButton_3_clicked()
{
    if(ui->deleteBox->count() == 0)
        return ;

    map.remove(ui->deleteBox->currentText().toInt());
    keys.erase(keys.begin()+ui->deleteBox->currentIndex());

    ui->listWidget->clear();
    ui->deleteBox->clear();

    for(int i = 0; i < keys.size(); i++){
        ui->listWidget->addItem("Key: " + QString::number(keys[i]) + "; Value: " + QString::number(map[keys[i]]));
        ui->deleteBox->addItem(QString::number(keys[i]));
    }

}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->editBox->count() == 0)
        return ;

    map.insert(ui->editBox->currentText().toInt(),5);

    ui->listWidget->item(ui->editBox->currentIndex())->setText(
                "Key: " + QString::number(keys[ui->editBox->currentIndex()]) +
            "; Value: " + QString::number(map[keys[ui->editBox->currentIndex()]]));
}


void MainWindow::on_pushButton_5_clicked()
{
    if(map.contains(ui->containsKey->text().toInt()))
        ui->contains->setText("true");
    else
        ui->contains->setText("false");
}

MainWindow::~MainWindow()
{
    delete ui;
}

