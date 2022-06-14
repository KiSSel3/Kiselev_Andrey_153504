#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    BitSetView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::BitSetView()
{
    ui->BitSetLine->setText(QString::fromStdString(bitset.To_String()));
}


void MainWindow::on_flipButton_clicked()
{
    if(ui->FlipLine->text().isEmpty()){
        bitset.Flip();
    }
    else if(ui->FlipLine->text().toInt()<0||ui->FlipLine->text().toInt()>7){
        QMessageBox::critical(this , "Ошибка" , "Введите значение от 0-7");
    }
    else{
        bitset.Flip(ui->FlipLine->text().toInt());
    }

    BitSetView();
}


void MainWindow::on_ResetButton_clicked()
{
    if(ui->ResetLine->text().isEmpty()){
        bitset.Reset();
    }
    else if(ui->ResetLine->text().toInt()<0||ui->ResetLine->text().toInt()>7){
        QMessageBox::critical(this , "Ошибка" , "Введите значение от 0-7");
    }
    else{
        bitset.Reset(ui->ResetLine->text().toInt());
    }

    BitSetView();
}


void MainWindow::on_SetButton_clicked()
{
    if(ui->SetLine->text().isEmpty()){
        bitset.Set();
    }
    else if(ui->SetLine->text().toInt()<0||ui->SetLine->text().toInt()>7){
        QMessageBox::critical(this , "Ошибка" , "Введите значение от 0-7");
    }
    else{
        bitset.Set(ui->SetLine->text().toInt());
    }

    BitSetView();
}


void MainWindow::on_TestButton_clicked()
{
    if(ui->TestLine->text().toInt()<0||ui->TestLine->text().toInt()>7){
        QMessageBox::critical(this , "Ошибка" , "Введите значение от 0-7");
    }
    else{
        QMessageBox::information(this, "",bitset.Test(ui->TestLine->text().toInt()) ? "Включён" : "Выключен");
    }
}


void MainWindow::on_AnyButton_clicked()
{
    QMessageBox::information(this, "any", bitset.Any() ? "Да" : "Нет");
}


void MainWindow::on_NoneButton_clicked()
{
    QMessageBox::information(this, "none", bitset.None() ? "Да" : "Нет");
}


void MainWindow::on_To_UlongButton_clicked()
{
    QMessageBox::information(this, "to_ulong", QString::number(bitset.To_Ulong()));
}


void MainWindow::on_AllButton_clicked()
{
    QMessageBox::information(this, "all", bitset.All() ? "Да" : "Нет");
}


void MainWindow::on_SizeButton_clicked()
{
    QMessageBox::information(this, "size", QString::number(bitset.Size()));
}

void MainWindow::on_To_UllongButton_clicked()
{
    QMessageBox::information(this, "to_ullong", QString::number(bitset.To_Ullong()));
}


void MainWindow::on_CountButton_clicked()
{
    QMessageBox::information(this, "count", QString::number(bitset.Count()));
}


void MainWindow::on_To_StringButton_clicked()
{
    QMessageBox::information(this, "to_string", QString::fromStdString(bitset.To_String()));
}

