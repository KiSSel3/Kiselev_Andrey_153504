#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->assginLine->setValidator(new QIntValidator(1,20,ui->assginLine));
    ui->emplaceLine->setValidator(new QIntValidator(1,20,ui->assginLine));
    ui->numberLine->setValidator(new QIntValidator(1,10000,ui->assginLine));
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateVectorTable(){
    auto model = new QStandardItemModel(vec.capacity() ,1,this);

    ui->tableView->setModel(model);

    for(int i = 0; i < vec.size(); i++){
        model->setData( model->index(i,0), QString::number(vec.at(i)));
    }
    for(int i = vec.size(); i < vec.capacity(); i++){
        model->setData( model->index(i,0), "null");
    }
    model->setHeaderData(0,Qt::Horizontal, "Значение");

    ui->eraseBox->clear();
    ui->emplaceBox->clear();
    ui->inserBox->clear();

    for(int i = 0; i < model->rowCount(); i++){
        ui->eraseBox->addItem(QString::number(i+1));
        ui->emplaceBox->addItem(QString::number(i+1));
        ui->inserBox->addItem(QString::number(i+1));
    }

    std::ostringstream oss,ass;
    oss<< &vec.begin();
    ui->sizeLine->setText(QString::number(vec.size()));
    ui->max_size->setText(QString::number(vec.max_size()));
    ui->front->setText(QString::number(vec.front()));
    ui->back->setText(QString::number(vec.back()));
    ui->capacityLine->setText(QString::number(vec.capacity()));
    ui->emptyLine->setText(QString::number(vec.empty()));
    ui->beginLine->setText(QString::fromStdString(oss.str()));
    ui->rEndLine->setText(QString::fromStdString(oss.str()));
    ass<< &vec.end();
    ui->endLine->setText(QString::fromStdString(ass.str()));
    ui->rBeginLine->setText(QString::fromStdString(ass.str()));
    vec.print();
}

void MainWindow::on_pushBack_clicked()
{
    vec.push_back(rand());
    updateVectorTable();
}


void MainWindow::on_popBack_clicked()
{
    if(vec.size() <= 0)
        return;

    vec.pop_back();
    updateVectorTable();
}


void MainWindow::on_clear_clicked()
{
    if(vec.size() <= 0)
        return;

    vec.clear();
    updateVectorTable();
}


void MainWindow::on_insert_clicked()
{
    if(vec.size() <= 0)
        return;
    vec.insert(ui->inserBox->currentIndex(),rand());
    updateVectorTable();
}


void MainWindow::on_erase_clicked()
{
    if(vec.size() <= 0)
        return;

    vec.erase(ui->eraseBox->currentIndex());
    updateVectorTable();
}


void MainWindow::on_assign_clicked()
{
    if(ui->assginLine->text().toInt() <= 0)
        return ;

    vec.assign(ui->assginLine->text().toInt(),rand());
    updateVectorTable();

}


void MainWindow::on_emplace_clicked()
{
    if(vec.size() <= 0)
        return;

    vec.emplace(ui->emplaceBox->currentIndex(),std::move(ui->emplaceLine->text().toInt()));
    updateVectorTable();
}


void MainWindow::on_emplaceBack_clicked()
{
    if(vec.size() <= 0)
        return;

    vec.emplace_back(std::move(ui->emplaceBackLine->text().toInt()));
    updateVectorTable();
}


void MainWindow::on_sizeLine_editingFinished()
{
    vec.resize(ui->sizeLine->text().toInt());
    updateVectorTable();
}


void MainWindow::on_capacityLine_editingFinished()
{
    vec.reserve(ui->capacityLine->text().toInt());
    updateVectorTable();
}


void MainWindow::on_getAnswer_clicked()
{
    if(ui->numberLine->text().toInt()==0){
        ui->textBrowser->setText("error");
        return;
    }
    size_t n = ui->numberLine->text().toInt();

    if (n == 1) {
        ui->textBrowser->setText("1");
        return;
    }
    QString finalAnswer;
    --n;
    vector<pair<int, vector<int>>> sequence;

    for (int k = 1; n / 2 >= sequence.size(); ++k) {
        vector<int> a(k + 1);
        a[k] = 1;
        vector<vector<int>> b(k + 1);
        b[0].push_back(1);
        AddZero(b[0], k + 1);
        for (int i = 0; i < k; ++i) {
            b[i + 1] = Multiply(b[i], 10, k + 1);
        }
        GenerateSequence(a, b, k, 0, sequence);
    }

    for (int i = 0; i < sequence.size(); ++i) {
        reverse(sequence[i].second.begin(), sequence[i].second.end());
    }
    sort(sequence.begin(), sequence.end());
    --n;
    vector<int> answer = sequence[n / 2].second;
    reverse(answer.begin(), answer.end());
    if (n % 2) {
        answer[0] ^= 1;
    }
    for (int k = sequence[n / 2].first; k >= 0; --k) {
        finalAnswer.push_back(QString::number(GetBit(answer, k)));
    }
    ui->textBrowser->setText(finalAnswer);
    return ;
}

void MainWindow::Normalize(vector<int>& c) {
    for (size_t i = 0; i < c.size() - 1; ++i) {
        c[i + 1] += c[i] >> 1;
        c[i] &= 1;
    }
}

void MainWindow::AddZero(vector<int>& c, int x) {
    c.resize(x + 1);
    c[x] = 0;
}

vector<int> MainWindow::AddNum(const vector<int>& a, const vector<int>& b, int k) {

    vector<int> c(std::max(a.size(), b.size()) + 1);

    for (size_t i = 0; i < c.size(); ++i) {
        if (i < a.size()) {
            c[i] += a[i];
        }
        if (i < b.size()) {
            c[i] += b[i];
        }
    }

    Normalize(c);
    AddZero(c, k);

    return c;
}

int MainWindow::GetBit(const vector<int>& v, int b) {
    return v[b] & 1;
}

vector<int> MainWindow::Multiply(const vector<int>& a, int x, int k) {

    vector<int> b = a;
    b.push_back(0);

    for (size_t i = 0; i < b.size(); ++i) {
        b[i] *= x;
    }

    Normalize(b);
    AddZero(b, k);

    return b;
}

void MainWindow::GenerateSequence(vector<int> n, const vector<vector<int>>& p, int k, int i, vector<pair<int, vector<int>> >& v) {

    if (i == k) {
        n.resize(k + 1);
        if (GetBit(n, k)) {
            v.push_back(make_pair(k, n));
        }
        return;
    }

    if (GetBit(n, i)) {
        return;
    }

    GenerateSequence(n, p, k, i + 1, v);

    if (i) {
        GenerateSequence(AddNum(n, p[i], k + 1), p, k, i + 1, v);
    }
    return;
}

