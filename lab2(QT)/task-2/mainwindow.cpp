#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include "bracket.h"

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

QString Show (QList<bool> a) {
    QString s;
    for (int i = 0; i < a.size(); i++) {
        s += QString::number(a[i]);
    }
    return s;
}


void MainWindow::on_pushButton_clicked()
{
    QString finals;
    QString s = ui->textEdit->toPlainText();
    Bracket information;


    QList<bool> lst1;  // (
    QList<bool> lst2;  // {
    QList<bool> lst3;  // [

    QString::iterator it;
    it = s.begin();
    int cell = 1;     //cell
    int row = 1;

    int error = 0;

    while (*it != '\0') {
        if (*it == '(') {
            lst1.push_back(0);
        }
        if (*it == '{') {
            lst2.push_back(0);
        }
        if (*it == '[') {
            lst3.push_back(0);
        }

        if (*it == ')') {
            int count = 0;
            for (int i = 0; i < lst1.size(); i++) {
                if (lst1[i] == 1) count++;
            }

            if (lst1.isEmpty() || count == lst1.length()) {

                finals += "Для скобки ) нет открытой   номер ячейки: " + QString::number(cell) + "; номер ряда: " + QString::number(row) + "\n";
                error++;
                break;
            }

            if (count != lst1.length()) {
                for (int i = lst1.length() - 1; i >= 0; i--) {
                    if (lst1[i] == 0) {
                        lst1[i] = 1;
                        break;
                    }
                }
            }

        }
        if (*it == '}') {
            int count = 0;
            for (int i = 0; i < lst2.size(); i++) {
                if (lst2[i] == 1) count++;
            }

            if (lst2.isEmpty() || count == lst2.length()) {

                finals += "Для скобки } нет открытой   номер ячейки: " + QString::number(cell) + "; номер ряда: " + QString::number(row) + "\n";
                QMessageBox::information(this, "Brackets", finals);
                error++;
                return;
            }

            if (count != lst2.length()) {
                for (int i = lst2.length() - 1; i >= 0; i--) {
                    if (lst2[i] == 0) {
                        lst2[i] = 1;
                        break;
                    }
                }
            }


        }
        if (*it == ']') {

            int count = 0;
            for (int i = 0; i < lst3.size(); i++) {
                if (lst3[i] == 1) count++;
            }

            if (lst3.isEmpty() || count == lst3.length()) {

                finals += "Для скобки ] нет открытой   номер ячейки: " + QString::number(cell) + "; номер ряда: " + QString::number(row) + "\n";
                QMessageBox::information(this, "Brackets", finals);
                error++;
                return;
            }

            if (count != lst3.length()) {
                for (int i = lst3.length() - 1; i >= 0; i--) {
                    if (lst3[i] == 0) {
                        lst3[i] = 1;
                        break;
                    }
                }
            }
        }
        ++it;
        ++cell;
        if (*it == '\n') {
            row++;
            cell = 1;
            ++it;
        }

    }


    int counter1_1 = 0;
    int counter1_0 = 0;
    int counter2_1 = 0;
    int counter2_0 = 0;
    int counter3_1 = 0;
    int counter3_0 = 0;


    for (int i = 0; i < lst1.length(); i++) {
        if (lst1[i] == 1) counter1_1++;
    }
    for (int i = 0; i < lst1.length(); i++) {
        if (lst1[i] == 0) counter1_0++;
    }

    QString::Iterator it1;
    it1 = s.begin();

    if (counter1_1 != lst1.length()) {
//        QString::Iterator it1;
//        it1 = s.begin();
        int cell1 = 1;
        int row1 = 1;
        int i1 = 0;

    while (*it1 != '\0') {
            if (*it1 == '(') {
                if (lst1[i1] == 0) {
                    finals += "Нет закрывающей скобки для (   номер ячейки: " + QString::number(cell1) + "; номер ряда: " + QString::number(row1) + "\n";
                    QMessageBox::information(this, "Brackets", finals);
                    error++;
                    counter1_0--;
                    return;

                }

                i1++;
            }
            ++cell1;
            ++it1;
            if (*it1 == '\n') {
                row1++;
                cell1 = 1;
                ++it1;
            }
            if (counter1_0 == 0) break;
        }
    }




    for (int i = 0; i < lst2.length(); i++) {
        if (lst2[i] == 1) counter2_1++;
    }
    for (int i = 0; i < lst2.length(); i++) {
        if (lst2[i] == 0) counter2_0++;
    }

    if (counter2_1 != lst2.length()) {
//        QString::Iterator it2;
//        it2 = s.begin();
        int cell2 = 1;
        int row2 = 1;
        int i2 = 0;

    while (*it1 != '\0') {
            if (*it1 == '{') {
                if (lst2[i2] == 0) {
                    finals += "Нет закрывающей скобки для {   номер ячейки: " + QString::number(cell2) + "; номер ряда: " + QString::number(row2) + "\n";
                    QMessageBox::information(this, "Brackets", finals);
                    error++;
                    counter2_0--;
                    return;
                }

                i2++;
            }
            ++cell2;
            ++it1;
            if (*it1 == '\n') {
                row2++;
                cell2 = 1;
                ++it1;
            }
            if (counter2_0 == 0) break;
        }
    }


    for (int i = 0; i < lst3.length(); i++) {
        if (lst3[i] == 1) counter3_1++;
    }
    for (int i = 0; i < lst3.length(); i++) {
        if (lst3[i] == 0) counter3_0++;
    }

    if (counter3_1 != lst3.length()) {
//        QString::Iterator it3;
//        it3 = s.begin();
        int cell3 = 1;
        int row3 = 1;
        int i3 = 0;

    while (*it1 != '\0') {
            if (*it1 == '[') {
                if (lst3[i3] == 0) {
                    finals += "Нет закрывающей скобки для [   номер ячейки: " + QString::number(cell3) + "; номер ряда: " + QString::number(row3) + "\n";
                    QMessageBox::information(this, "Brackets", finals);
                    error++;
                    counter3_0--;
                    return;
                }

                i3++;
            }
            ++cell3;
            ++it1;
            if (*it1 == '\n') {
                row3++;
                cell3 = 1;
                ++it1;
            }
            if (counter3_0 == 0) break;
        }
    }


    //________________________________________________________


    if (error != 0) {
        QMessageBox::information(this, "Brackets", finals);

    }
    else {
        QMessageBox::information(this, "Brackets", "Success");
    }



}

QString path;

void MainWindow::on_pushButton_3_clicked()
{
    path = QFileDialog::getOpenFileName(this, "Выбрать файл", "D:/Programming/QtLabs/lab2", "*.txt");
    QFile file(path);

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Ошибка при открытии файла";
    }

    QTextStream in(&file);
    QString str = in.readAll();
    ui->textEdit->setText(str);

    file.close();
}
