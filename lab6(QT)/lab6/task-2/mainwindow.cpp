#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showHashTable()
{
    ui->textEdit->setText(hashTable.showHashTable());
}


void MainWindow::on_addButton_clicked()
{
    int data = ui->dataLine->text().toInt();
    if(ui->dataLine->text().size() == 0){
        QMessageBox::warning(this,"Ошибка","Вы не ввели данные!");
    }
    else{
        if(!hashTable.newValue(data)){
            QMessageBox::warning(this,"Ошибка","Данные уже есть в таблице!");
        }
        else{
            hashTable.insertData(data);
        }

        ui->dataLine->clear();
        ui->textEdit->clear();

        showHashTable();
    }

}


void MainWindow::on_deleteButton_clicked()
{
    int data = ui->dataLine->text().toInt();
    if(ui->dataLine->text().size() == 0){
        QMessageBox::warning(this,"Ошибка","Вы не ввели данные!");
    }
    else{
        if(hashTable.newValue(data)){
            QMessageBox::warning(this,"Ошибка","Данных нет в таблице!");
        }
        else {
            hashTable.deleteData(data);
        }

        ui->dataLine->clear();
        ui->textEdit->clear();

        showHashTable();

    }
}


void MainWindow::on_showButton_clicked()
{
    showHashTable();
}


void MainWindow::on_searchButton_clicked()
{
    int data = ui->dataLine->text().toInt();
    if(ui->dataLine->text().size() == 0){
        QMessageBox::warning(this,"Ошибка","Вы не ввели данные!");
    }
    else{
        if(hashTable.newValue(data)){
            QMessageBox::warning(this,"Ошибка","Данных нет в таблице!");
        }
        else {
            ui->dataLine->clear();
            ui->textEdit->clear();
            ui->textEdit->setText(hashTable.showDataInHashTable(data));
        }
    }
}


void MainWindow::on_emptyButton_clicked()
{
    if(hashTable.empty()){
        ui->textEdit->setText("В таблице нет данных!");
    }
    else {
        ui->textEdit->setText("В таблице есть данные!");
    }
}


void MainWindow::on_forTaskButton_clicked()
{
    if(hashTable.empty()){
        QMessageBox::warning(this,"Ошибка","В таблице нет данных!");
    }
    else{

        ui->dataLine->clear();
        ui->textEdit->setText(QString::number(hashTableForTask.forTask(hashTable.getMainStack(),hashTable.getSize())));

    }
}

