#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_uniqueButton_clicked()
{
    ui->uniqueButton->setEnabled(false);
    QString text = "";

    uniquePtr<int> Pointer_1(new int(111));
    text+="Объект Pointer_1 создан\nPointer_1 = ";
    text+=QString::number(*Pointer_1);
    text+="\n";

    uniquePtr<int> Pointer_2(new int(222));
    text+="Объект Pointer_2 создан\nPointer_2 = ";
    text+=QString::number(*Pointer_2);
    text+="\n";

    Pointer_1.swap(Pointer_2);
    text+="Метод Swap:\n";

    text+="Pointer_1 = ";
    text+=QString::number(*Pointer_1);
    text+="\n";

    text+="Pointer_2 = ";
    text+=QString::number(*Pointer_2);
    text+="\n";

    text+="Метод Reset:\n";
    Pointer_1.reset();
    if (Pointer_1.get() == nullptr) {
        text+="Pointer_1 = nullptr\n";
    }

    text+="Метод Release:\n";
    Pointer_2.release();
    if (!(Pointer_2.operator bool())) {
        text+="Pointer_2 пустой\n";
    }
    uniquePtr<int> Pointer_3(new int(333));

    text+="Метод Get:\n";
    text+="Pointer_3.get() = ";
    text+=QString::number(*(Pointer_3.get()));
    text+="\n";

    ui->uniqueText->appendPlainText(text);
}

void MainWindow::on_sharedButton_clicked()
{
    ui->sharedButton->setEnabled(false);
    QString text = "";

    sharedPtr<int> Pointer_1(new int(11));
    text+="Объект Pointer_1 создан\nPointer_1 = ";
    text+=QString::number(*Pointer_1);
    text+="\n";

    sharedPtr<int> Pointer_2;
    sharedPtr<int> temp (new int (22));
    text+="Пустой объект Pointer_2 создан\nОбъект temp создан\ntemp = ";
    text+=QString::number(*temp);
    text+="\n";
    Pointer_2 = temp;
    text+="Объекту Pointer_2 присвоен объект temp\nОбъект Pointer_2 = ";
    text+=QString::number(*Pointer_2);
    text+="\n";
    text+="Объект temp = ";
    text+=QString::number(*temp.get());
    text+="\n";

    Pointer_1.swap(Pointer_2);
    text+="Метод Swap:\n";

    text+="Pointer_1 = ";
    text+=QString::number(*Pointer_1);
    text+="\n";

    text+="Pointer_2 = ";
    text+=QString::number(*Pointer_2);
    text+="\n";

    text+="Метод Release:\n";
    Pointer_2.release();
    if (!(Pointer_2.operator bool())) {
        text+="Pointer_2 пустой\n";
    }

    text+="Метод Reset:\n";
    Pointer_1.reset();
    if (Pointer_1.get() == nullptr) {
        text+="Pointer_1 = nullptr\n";
    }


    sharedPtr<int> Pointer_3(new int(33));

    text+="Метод Get:\n";
    text+="*(Pointer_3.get()) = ";
    text+=QString::number(*(Pointer_3.get()));
    text+="\n";

    text+="Метод Use_count:\n";
    text+="count = ";
    text+=QString::number(Pointer_3.use_count());
    text+="\n";

    //7 Use_count_w
    text+="Метод Use_count_weak:\n";
    text+="countWeak = ";
    text+=QString::number(Pointer_3.use_count_weak());
    text+="\n";

    ui->sharedText->appendPlainText(text);
}


void MainWindow::on_weakButton_clicked()
{
    ui->weakButton->setEnabled(false);
    QString text = "";

    sharedPtr<int> PointerShared_1(new int(1));
    text+="Объект PointerShared_1 создан\nPointerShared_1 = ";
    text+=QString::number(*PointerShared_1);
    text+="\n";
    weakPtr<int> PointerWeak_1(PointerShared_1);
    text+="Объект PointerWeak_1 создан";
    text+="\n";

    sharedPtr<int> PointerShared_2(new int(2));
    text+="Объект PointerShared_2 создан\nPointerShared_2 = ";
    text+=QString::number(*PointerShared_2);
    text+="\n";
    weakPtr<int> PointerWeak_2;   //2 конструктор
    text+="Пустой объект PointerWeak_2 создан\nOбъект PointerWeak_2 присвоен объект PointerShared_2";
    PointerWeak_2 = PointerShared_2;
    text+="\n";

    text+="Метод Swap/Метод Lock:\n";
    PointerWeak_1.swap(PointerWeak_2);

    text+="PointerWeak_1.lock() = ";
    text+=QString::number(*PointerWeak_1.lock());
    text+="\n";

    text+="PointerWeak_2.lock() = ";
    text+=QString::number(*PointerWeak_2.lock());
    text+="\n";

    text+="Метод Expired:\n";

    if (!PointerWeak_1.expired()){
        text+="w_ptr1 не удален\n";
    }

    if (!PointerWeak_2.expired()){
        text+="w_ptr2 не удален\n";
    }

    text+="Метод Use_count:\n";
    text+="cout = ";
    text+=QString::number(PointerWeak_1.use_count());
    text+="\n";

    ui->weakText->appendPlainText(text);
}

