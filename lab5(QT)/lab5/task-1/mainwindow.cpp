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

void MainWindow::on_createList_clicked()
{
    std::srand(std::time(NULL));

    while(ui->list->count()){
        delete ui->list->item(0);
        randomNumbersList.pop_back();
    }

    for(int i = 0; i < ui->spinBox->value(); ++i){
        int randomNumber =rand() % 1000 - 500;
        randomNumbersList.push_back(randomNumber);
        ui->list->addItem(QString::number(randomNumber));
    }
}


void MainWindow::on_deleteList_clicked()
{
    Queue<int> tempQueue;

    while(randomNumbersList.size()){
        if(randomNumbersList.back() >= 0){
            tempQueue.push(randomNumbersList.back());
        }
        randomNumbersList.pop_back();
    }

    while(!tempQueue.empty()){
        randomNumbersList.push_front(tempQueue.top());
        tempQueue.pop();
    }

    while(ui->list->count()){
        delete ui->list->item(0);
    }

    for(auto it = randomNumbersList.begin(); it != randomNumbersList.end(); ++it){
        ui->list->addItem(QString::number(*it));
    }
}
