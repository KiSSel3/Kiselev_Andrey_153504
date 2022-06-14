#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set = new MySet<QString>;

    ui->key_edit->setPlaceholderText("key");
    ui->erase_by_key->setPlaceholderText("key");
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Key(s)"));
}

void MainWindow::on_insert_clicked() {

    QString key_ = ui->key_edit->text();

    if (key_.isEmpty()) {

        QMessageBox::critical(this, "Trouble", "Enter valid key!");

        return;
    }

    ui->key_edit->clear();

    for (int i = 0; i < set->size(); ++i) {
        if (ui->tableWidget->item(i, 0)->text() == key_) {

            QMessageBox::warning(this, "Trouble", "Repeated value!");

            return;
        }
    }

    set->insert(key_);
    clear();

    MySet<QString>::l_iterator it(set->l_begin());

    for (int i = 0; i < set->size(); ++i, ++it) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(it->pair.first));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(it->pair.second));
    }
}

void MainWindow::on_erase_clicked() {
    QString key_ = ui->erase_by_key->text();
    if (set->empty()) {
        QMessageBox::critical(this, "Trouble!", "Your container is empty!");
        return;
    }

    if (key_.isEmpty()) {
        QMessageBox::critical(this, "Trouble!", "Enter your key!");
        return;
    }
    for (int i = 0; i < set->size(); ++i) {
        if (ui->tableWidget->item(i, 0)->text() == key_) {
            set->erase(key_);
            --set->sz;
            break;
        }
    }
    ui->erase_by_key->clear();


    clear();


    MySet<QString>::l_iterator it(set->l_begin());

    for (int i = 0; i < set->size(); ++i, ++it) {

        ui->tableWidget->insertRow(i);

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(it->pair.first));

        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(it->pair.second));
    }
}

void MainWindow::on_size_clicked() {

    int size_ = set->size();

    ui->label->setText(QString::number(size_));
}

void MainWindow::clear() {

    ui->tableWidget->clear();

    ui->tableWidget->setColumnCount(0);

    ui->tableWidget->setRowCount(0);

    ui->tableWidget->setColumnCount(1);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Key(s)"));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

