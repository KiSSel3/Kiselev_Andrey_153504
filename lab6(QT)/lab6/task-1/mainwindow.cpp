#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHorizontalHeaderLabels(QStringList() << "Ключ" << "Данные");
    ui->treeWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->treeWidget->resizeRowsToContents();
    ui->treeWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::forwardBypass(TreeNode<QString> *treeNode)
{
    if(!treeNode){
        return;
    }
    addToTreeWidget(treeNode);
    forwardBypass(treeNode->left);
    forwardBypass(treeNode->right);
}

void MainWindow::reverseBypass(TreeNode<QString> *treeNode)
{
    if(!treeNode){
        return;
    }
    reverseBypass(treeNode->left);
    reverseBypass(treeNode->right);
    addToTreeWidget(treeNode);
}

void MainWindow::keyBypass(TreeNode<QString> *treeNode)
{
    if(!treeNode){
        return;
    }
    keyBypass(treeNode->left);
    addToTreeWidget(treeNode);
    keyBypass(treeNode->right);

}

void MainWindow::addToTreeWidget(TreeNode<QString> *treeNode)
{
    if(!treeNode){
        return;
    }

    ui->treeWidget->setRowCount(Rows+1);
    ui->treeWidget->setItem(Rows,0,new QTableWidgetItem(QString::number(treeNode->key)));
    ui->treeWidget->setItem(Rows,1,new QTableWidgetItem(treeNode->data));

    ++Rows;
}


void MainWindow::on_addInfoButton_clicked()
{
    QString data = ui->dataLine->text();
    int key = ui->keyLine->text().toInt();

    if (ui->dataLine->text().size() == 0 || ui->keyLine->text().size() == 0) {
        QMessageBox::warning(this, "Ошибка","Заполнены не все поля!");
    }
    else {
        std::pair<int,QString> buff(key,data);
        arr.push_back(buff);
        QMessageBox::information(this, "","Элемент успешно добавлен в массив!");
    }
}


void MainWindow::on_addToTreeButton_clicked()
{
    for(indexInArr; indexInArr<arr.size();++indexInArr){
        searchTree.add(arr[indexInArr]);
    }
    QMessageBox::information(this, "","Элементы успешно добавлены в дерево!");
}


void MainWindow::on_balanceButton_clicked()
{
    if(searchTree.root){
        searchTree.balance(searchTree.root);
        QMessageBox::information(this, "","Дерево успешно сбалансировано!");
    }
}


void MainWindow::on_searchButton_clicked()
{
    int key = ui->keyLine->text().toInt();

    if (ui->keyLine->text().size() == 0) {
        QMessageBox::warning(this, "Ошибка","Вы не ввели ключ!");
    }
    else {
        TreeNode<QString>* treeNode = searchTree.getTreeNodeByKey(searchTree.root, key);

        if(!treeNode){
            QMessageBox::warning(this, "Ошибка","Данные с таким ключём отсутствуют!");
        }
        else {
            ui->treeWidget->clear();
            Rows = 0;
            addToTreeWidget(treeNode);
        }
    }
}


void MainWindow::on_deleteButton_clicked()
{
    int key = ui->keyLine->text().toInt();

    if (ui->keyLine->text().size() == 0) {
        QMessageBox::warning(this, "Ошибка","Вы не ввели ключ!");
    }
    else {
        searchTree.root = searchTree.remove(searchTree.root, key);
        QMessageBox::information(this, "","Данные были удалены из дерева поиска!");

    }
}


void MainWindow::on_forwardBypassButton_clicked()
{
    ui->treeWidget->clear();
    ui->treeWidget->setHorizontalHeaderLabels(QStringList() << "Ключ" << "Данные");
    ui->treeWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->treeWidget->resizeRowsToContents();
    ui->treeWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    Rows = 0;
    forwardBypass(searchTree.root);
}


void MainWindow::on_reverseBypassButton_clicked()
{
    ui->treeWidget->clear();
    ui->treeWidget->setHorizontalHeaderLabels(QStringList() << "Ключ" << "Данные");
    ui->treeWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->treeWidget->resizeRowsToContents();
    ui->treeWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    Rows = 0;
    reverseBypass(searchTree.root);
}


void MainWindow::on_keyBypassButton_clicked()
{
    ui->treeWidget->clear();
    ui->treeWidget->setHorizontalHeaderLabels(QStringList() << "Ключ" << "Данные");
    ui->treeWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->treeWidget->resizeRowsToContents();
    ui->treeWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    Rows = 0;
    keyBypass(searchTree.root);
}


void MainWindow::on_forTaskOneButton_clicked()
{
    if(searchTree.root && searchTree.root->left){
        searchTree.removeMax(searchTree.root->left);
        searchTree.root = searchTree.balance(searchTree.root);

        QMessageBox::information(this, "","Данные были удалены из дерева поиска!");
    }else{
        QMessageBox::warning(this, "Ошибка","Ошибка удаления!");
    }
}

