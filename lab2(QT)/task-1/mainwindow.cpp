#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    admissionPlanWindowOpen();
}

MainWindow::~MainWindow()
{
    studentList.clear();
    delete ui;
}

void MainWindow::admissionPlanWindowOpen()
{
    admissionPlanWindow = new QDialog(this);
    admissionPlanWindow->setModal(true);
    admissionPlanWindow ->resize(210, 100);

    admissionPlanText = new QLabel("План приёма студентов: ", admissionPlanWindow);
    admissionPlanText->resize(140,15);
    admissionPlanText->move(10,15);

    admissionPlanInput = new QLineEdit(admissionPlanWindow);
    admissionPlanInput->resize(50,15);
    admissionPlanInput->move(150,15);

    admissionPlanEnter = new QPushButton(admissionPlanWindow);
    admissionPlanEnter->resize(50,20);
    admissionPlanEnter->setText("Ввод");
    admissionPlanEnter->move(80,50);

    admissionPlanWindow->show();


    connect(admissionPlanEnter,SIGNAL(clicked()), this,SLOT(pushButtonAdmissionPlanEnter()));

}

void MainWindow::createTableView()
{
    auto model = new QStandardItemModel(studentList.size(),4,this);
    ui->tableView->setModel(model);

    for(int i = 0; i < model->rowCount(); i++){
        model->setData( model->index(i,0), studentList[i].getStudentSurname() + " " + studentList[i].getStudentName() + " " +  studentList[i].getStudentPatronymic());

        model->setData( model->index(i,1),
                        QString::number(studentList[i].getStudentFirstGrade()) + " " +
                        QString::number(studentList[i].getStudentSecondGrade()) + " " +
                        QString::number(studentList[i].getStudentThirdGrade()));

        model->setData( model->index(i,2), studentList[i].getStudentAverageGrade());
        model->setData( model->index(i,3), studentList[i].getStudentCity() + ", " +  studentList[i].getStudentAddress());
    }

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableView->setColumnWidth(0,365);
    ui->tableView->setColumnWidth(1,100);
    ui->tableView->setColumnWidth(2,115);
    ui->tableView->setColumnWidth(3,375);

    model->setHeaderData(0,Qt::Horizontal, "Ф.И.О:");
    model->setHeaderData(1,Qt::Horizontal, "Оценки:");
    model->setHeaderData(2,Qt::Horizontal, "Средняя оценка:");
    model->setHeaderData(3,Qt::Horizontal, "Адрес:");

}

void MainWindow::quickSort()
{
    int j, step;
    double buff;
    Student tmp;
    for (step = studentList.size() / 2; step > 0; step /= 2)
        for (int i = step; i < studentList.size(); i++) {
            tmp = studentList[i];
            buff = studentList[i].getStudentAverageGrade();
            for (j = i; j >= step; j -= step)
                if (buff < studentList[j - step].getStudentAverageGrade()) studentList[j] = studentList[j - step];
                else break;

            studentList[j] = tmp;
        }
}

bool MainWindow::inputIsCorrect(QString path)
{
    /*QString arr[8];
    bool correct = true;

    QRegularExpression number("[0-9]");


    while(!file.atEnd()){
        static int i = 0;

        arr[i] = file.readLine();
        ++i;

        if(i==8){
            i=0;
               QRegularExpressionMatch check1 = number.match(arr[5]);
               QRegularExpressionMatch check2 = number.match(arr[6]);
               QRegularExpressionMatch check3 = number.match(arr[7]);

            if (!check1.hasMatch() ||!check2.hasMatch() ||!check2.hasMatch() || arr[5].toInt() > 10 ||  arr[5].toInt()<0 || arr[6].toInt() > 10 ||  arr[6].toInt()<0 ||arr[7].toInt() > 10 ||  arr[7].toInt()<0){
                break;
                correct = false;
            }
        }
    }
    return correct;*/
if (path != "D:/Programming/QtLabs/lab2/file/file.txt"){
    return 0;
}else
    return 1;

}



QString MainWindow::getStorage()
{
    QString way = storage;

    //проверка(пока что не нужна)

    return way;
}

void MainWindow::pushButtonAdmissionPlanEnter()
{
    QString maxSizeListInput =  admissionPlanInput->text();

    QRegularExpression number("[0-9]");
    QRegularExpressionMatch matchMaxSizeListInput = number.match(maxSizeListInput);

    if (!matchMaxSizeListInput.hasMatch() || maxSizeListInput.toInt() < 1 || maxSizeListInput.toInt() > 1e8){
        QMessageBox::critical(admissionPlanWindow, "", "Некорректный ввод!");
    }
    else {
        maxSizeList = maxSizeListInput.toInt();
        admissionPlanWindow->close();
    }
}

void MainWindow::on_openFileButton_clicked()
{
    storage = QFileDialog::getOpenFileName(0,"Выберите нужный файл:","","*.txt");

    QFile file(getStorage());
    file.open(QIODevice::ReadOnly);

    if (!inputIsCorrect(getStorage())){
        QMessageBox::warning(this,"","Данный файл невозможно открыть!");
    }else{

        QString arr[8];
        studentList.clear();

        file.seek(0);

        while(!file.atEnd()){
            static int i = 0;

            arr[i] = file.readLine();
            ++i;

            if(i==8){
                i=0;
                Student newStudent(arr[0].left(arr[0].count()-1),arr[1].left(arr[1].count()-1),arr[2].left(arr[2].count()-1),arr[3].left(arr[3].count()-1),arr[4].left(arr[4].count()-1),arr[5].toInt(),arr[6].toInt(),arr[7].toInt());
                studentList.push_back(newStudent);
            }
        }

        quickSort();

        while(studentList.size() > maxSizeList){
            studentList.pop_front();
        }

        createTableView();
    }

    file.close();

}


void MainWindow::on_updateTableViewButton_clicked()
{
    createTableView();
}


void MainWindow::on_addStudentButton_clicked()
{
    addStudentWindow = new QDialog(this);
    addStudentWindow->resize(220,280);
    addStudentWindow->setModal(true);

    informationAddStudentWindow = new QLabel(" Заполните информацию о студенте ",addStudentWindow);
    informationAddStudentWindow->resize(210,15);
    informationAddStudentWindow->move(10,10);

    //Name
    addStudentNameText = new QLabel("Имя:", addStudentWindow);
    addStudentNameText->resize(65,15);
    addStudentNameText->move(20, 45);

    addStudentNameInput = new QLineEdit(addStudentWindow);
    addStudentNameInput->resize(115,20);
    addStudentNameInput->move(90,45);


    //Surname
    addStudentSurnameText = new QLabel("Фамилия:", addStudentWindow);
    addStudentSurnameText->resize(65,15);
    addStudentSurnameText->move(20, 70);

    addStudentSurnameInput = new QLineEdit(addStudentWindow);
    addStudentSurnameInput->resize(115,20);
    addStudentSurnameInput->move(90,70);

    //Patronymic
    addStudentPatronymicText = new QLabel("Отчество:", addStudentWindow);
    addStudentPatronymicText->resize(65,15);
    addStudentPatronymicText->move(20, 95);

    addStudentPatronymicInput = new QLineEdit(addStudentWindow);
    addStudentPatronymicInput->resize(115,20);
    addStudentPatronymicInput->move(90,95);

    //FirstGrade
    addStudentFirstGradeText = new QLabel("Оценка 1:", addStudentWindow);
    addStudentFirstGradeText->resize(65,15);
    addStudentFirstGradeText->move(20, 120);

    addStudentFirstGradeInput = new QComboBox(addStudentWindow);
    addStudentFirstGradeInput->move(90,120);
    for(int i = 0; i < 11;i++){
        addStudentFirstGradeInput->addItem(QString::number(i));
    }

    //SecondGrade
    addStudentSecondGradeText = new QLabel("Оценка 2:", addStudentWindow);
    addStudentSecondGradeText->resize(65,15);
    addStudentSecondGradeText->move(20, 145);

    addStudentSecondGradeInput = new QComboBox(addStudentWindow);
    addStudentSecondGradeInput->move(90,145);
    for(int i = 0; i < 11;i++){
        addStudentSecondGradeInput->addItem(QString::number(i));
    }

    //ThirdGrade
    addStudentThirdGradeText = new QLabel("Оценка 3:", addStudentWindow);
    addStudentThirdGradeText->resize(65,15);
    addStudentThirdGradeText->move(20, 170);

    addStudentThirdGradeInput = new QComboBox(addStudentWindow);
    addStudentThirdGradeInput->move(90,170);
    for(int i = 0; i < 11;i++){
        addStudentThirdGradeInput->addItem(QString::number(i));
    }

    //City
    addStudentCityText = new QLabel("Город:", addStudentWindow);
    addStudentCityText->resize(65,15);
    addStudentCityText->move(20, 195);

    addStudentCityInput = new QLineEdit(addStudentWindow);
    addStudentCityInput->resize(115,20);
    addStudentCityInput->move(90,195);

    //Adress
    addStudentAddressText = new QLabel("Улица/дом:", addStudentWindow);
    addStudentAddressText->resize(65,15);
    addStudentAddressText->move(20, 220);

    addStudentAddressInput = new QLineEdit(addStudentWindow);
    addStudentAddressInput->resize(115,20);
    addStudentAddressInput->move(90,220);

    addStudentEnter = new QPushButton(addStudentWindow);
    addStudentEnter->setText("Ввод");
    addStudentEnter->resize(50,20);
    addStudentEnter->move(85,255);

    connect(addStudentEnter,SIGNAL(clicked()), this,SLOT(pushButtonAddStudentEnter()));

    addStudentWindow->show();
}

void MainWindow::pushButtonAddStudentEnter()
{
    QString inputName = addStudentNameInput->text(),
            inputSurname = addStudentSurnameInput->text(),
            inputPatronymic = addStudentPatronymicInput->text(),
            inputCity = addStudentCityInput->text(),
            inputAdress = addStudentAddressInput->text();

    if(inputName.isEmpty() ||inputSurname.isEmpty() ||inputPatronymic.isEmpty()||inputCity.isEmpty()||inputAdress.isEmpty() ){
        QMessageBox::critical(addStudentWindow, "", "Не все поля заполнены");
    }
    else{

        Student newStudent(inputName,inputSurname,inputPatronymic,inputCity,
                           inputAdress,addStudentFirstGradeInput->currentText().toDouble(),
                           addStudentSecondGradeInput->currentText().toDouble(),addStudentThirdGradeInput->currentText().toDouble());

        if(maxSizeList> studentList.size()) {
            studentList.push_back(newStudent);
        }else if (studentList[0].getStudentAverageGrade() < newStudent.getStudentAverageGrade()){
            studentList[0] = newStudent;
        }

        quickSort();

        addStudentWindow->close();

        createTableView();
    }
}



void MainWindow::on_surnameSearchButton_clicked()
{
    searchSurnameWindow  = new QDialog(this);
    searchSurnameWindow->setModal(true);
    searchSurnameWindow->resize(1000,350);

    searchSurnameTable = new QTableView(searchSurnameWindow);
    searchSurnameTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    searchSurnameTable->resize(979,289);
    searchSurnameTable->move(10,5);



    QLabel* textLable = new QLabel(searchSurnameWindow);
    textLable->setText("Введите Фамилию: ");
    textLable->resize(110,20);
    textLable->move(20,320);

    searchSurnameInput = new QLineEdit(searchSurnameWindow);
    searchSurnameInput->resize(100,20);
    searchSurnameInput->move(130,323);

    QPushButton* searchButton = new QPushButton(searchSurnameWindow);
    searchButton->setText("Поиск");
    searchButton->move(240,320);

    QPushButton* closeWindow = new QPushButton(searchSurnameWindow);
    closeWindow->setText("Закрыть");
    closeWindow->move(900,320);

    searchSurnameWindow->show();

    connect(searchButton,SIGNAL(clicked()),this,SLOT(showSearchSurnameTable()));
    connect(closeWindow,SIGNAL(clicked()),this,SLOT(closeSearchSurnameWindow()));

}

void MainWindow::showSearchSurnameTable()
{
    QString inputTextLable = searchSurnameInput->text();

    if(!individualSurname(inputTextLable)){
        QMessageBox::critical(searchSurnameWindow, "", "Данной фамилии нет в списке!");
    }
    else {
        auto model = new QStandardItemModel(studentList.size(),4,searchSurnameWindow);
        searchSurnameTable->setModel(model);

        for(short int i = 0,j = 0; i < studentList.size();++i){
            if(studentList[i].getStudentSurname() == inputTextLable) {
                model->setData( model->index(j,0), studentList[i].getStudentSurname() + " " + studentList[i].getStudentName() + " " +  studentList[i].getStudentPatronymic());

                model->setData( model->index(j,1),
                                QString::number(studentList[i].getStudentFirstGrade()) + " " +
                                QString::number(studentList[i].getStudentSecondGrade()) + " " +
                                QString::number(studentList[i].getStudentThirdGrade()));

                model->setData( model->index(j,2), studentList[i].getStudentAverageGrade());
                model->setData( model->index(j,3), studentList[i].getStudentCity() + ", " +  studentList[i].getStudentAddress());

                ++j;
            }
        }

        searchSurnameTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        searchSurnameTable->setColumnWidth(0,365);
        searchSurnameTable->setColumnWidth(1,100);
        searchSurnameTable->setColumnWidth(2,115);
        searchSurnameTable->setColumnWidth(3,375);

        model->setHeaderData(0,Qt::Horizontal, "Ф.И.О:");
        model->setHeaderData(1,Qt::Horizontal, "Оценки:");
        model->setHeaderData(2,Qt::Horizontal, "Средняя оценка:");
        model->setHeaderData(3,Qt::Horizontal, "Адрес:");
    }
}

void MainWindow::closeSearchSurnameWindow()
{
    searchSurnameWindow->close();
}

bool MainWindow::individualSurname(QString object)
{
    bool individualDestination = false;

    for(short int i = 0; i<studentList.size();i++){
        if (studentList[i].getStudentSurname() == object ){
            individualDestination = true;
            break;
        }
    }

    return individualDestination;
}

bool MainWindow::individualCity(QString object)
{
    bool individualDestination = false;

    for(short int i = 0; i<studentList.size();i++){
        if (studentList[i].getStudentCity() == object ){
            individualDestination = true;
            break;
        }
    }

    return individualDestination;
}

void MainWindow::on_citySearchButton_clicked()
{
    searchCityWindow  = new QDialog(this);
    searchCityWindow->setModal(true);
    searchCityWindow->resize(1000,350);

    searchCityTable = new QTableView(searchCityWindow);
    searchCityTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    searchCityTable->resize(979,289);
    searchCityTable->move(10,5);



    QLabel* textLable = new QLabel(searchCityWindow);
    textLable->setText("Введите Город: ");
    textLable->resize(110,20);
    textLable->move(20,320);

    searchCityInput = new QLineEdit(searchCityWindow);
    searchCityInput->resize(100,20);
    searchCityInput->move(130,323);

    QPushButton* searchButton = new QPushButton(searchCityWindow);
    searchButton->setText("Поиск");
    searchButton->move(240,320);

    QPushButton* closeWindow = new QPushButton(searchCityWindow);
    closeWindow->setText("Закрыть");
    closeWindow->move(900,320);

    searchCityWindow->show();

    connect(searchButton,SIGNAL(clicked()),this,SLOT(showSearchCityTable()));
    connect(closeWindow,SIGNAL(clicked()),this,SLOT(closeSearchCityWindow()));
}

void MainWindow::showSearchCityTable()
{
    QString inputTextLable = searchCityInput->text();

    if(!individualCity(inputTextLable)){
        QMessageBox::critical(searchCityWindow, "", "Данного города нет в списке!");
    }
    else {
        auto model = new QStandardItemModel(studentList.size(),4,searchCityWindow);
        searchCityTable->setModel(model);

        for(short int i = 0,j = 0; i < studentList.size();++i){
            if(studentList[i].getStudentCity() == inputTextLable) {
                model->setData( model->index(j,0), studentList[i].getStudentSurname() + " " + studentList[i].getStudentName() + " " +  studentList[i].getStudentPatronymic());

                model->setData( model->index(j,1),
                                QString::number(studentList[i].getStudentFirstGrade()) + " " +
                                QString::number(studentList[i].getStudentSecondGrade()) + " " +
                                QString::number(studentList[i].getStudentThirdGrade()));

                model->setData( model->index(j,2), studentList[i].getStudentAverageGrade());
                model->setData( model->index(j,3), studentList[i].getStudentCity() + ", " +  studentList[i].getStudentAddress());

                ++j;
            }
        }

        searchCityTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        searchCityTable->setColumnWidth(0,365);
        searchCityTable->setColumnWidth(1,100);
        searchCityTable->setColumnWidth(2,115);
        searchCityTable->setColumnWidth(3,375);

        model->setHeaderData(0,Qt::Horizontal, "Ф.И.О:");
        model->setHeaderData(1,Qt::Horizontal, "Оценки:");
        model->setHeaderData(2,Qt::Horizontal, "Средняя оценка:");
        model->setHeaderData(3,Qt::Horizontal, "Адрес:");
    }
}

void MainWindow::closeSearchCityWindow()
{
    searchCityWindow->close();
}

void MainWindow::on_gradeSearchButton_clicked()
{
    searchGradeWindow  = new QDialog(this);
    searchGradeWindow->setModal(true);
    searchGradeWindow->resize(1000,350);

    searchGradeTable = new QTableView(searchGradeWindow);
    searchGradeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    searchGradeTable->resize(979,289);
    searchGradeTable->move(10,5);



    QLabel* textLable = new QLabel(searchGradeWindow);
    textLable->setText("Введите средний балл: ");
    textLable->resize(130,20);
    textLable->move(20,320);

    searchGradeInput = new QLineEdit(searchGradeWindow);
    searchGradeInput->resize(100,20);
    searchGradeInput->move(150,323);

    QPushButton* searchButton = new QPushButton(searchGradeWindow);
    searchButton->setText("Поиск");
    searchButton->move(240,320);

    QPushButton* closeWindow = new QPushButton(searchGradeWindow);
    closeWindow->setText("Закрыть");
    closeWindow->move(900,320);

    searchGradeWindow->show();

    connect(searchButton,SIGNAL(clicked()),this,SLOT(showSearchGradeTable()));
    connect(closeWindow,SIGNAL(clicked()),this,SLOT(closeSearchGradeWindow()));
}

void MainWindow::showSearchGradeTable()
{
    QString inputTextLable = searchGradeInput->text();

    QRegularExpression number("[0-9]");

    QRegularExpressionMatch matchInputTextLable = number.match(inputTextLable);

    if(!matchInputTextLable.hasMatch() || inputTextLable.isEmpty() || inputTextLable.toDouble()<0 || inputTextLable.toDouble()>10){
        QMessageBox::critical(searchGradeWindow, "", "Ошибка ввода!");
    }
    else {
        auto model = new QStandardItemModel(studentList.size(),4,searchGradeWindow);
        searchGradeTable->setModel(model);

        for(short int i = 0,j = 0; i < studentList.size();++i){
            if(studentList[i].getStudentAverageGrade() >= inputTextLable.toDouble()) {
                model->setData( model->index(j,0), studentList[i].getStudentSurname() + " " + studentList[i].getStudentName() + " " +  studentList[i].getStudentPatronymic());

                model->setData( model->index(j,1),
                                QString::number(studentList[i].getStudentFirstGrade()) + " " +
                                QString::number(studentList[i].getStudentSecondGrade()) + " " +
                                QString::number(studentList[i].getStudentThirdGrade()));

                model->setData( model->index(j,2), studentList[i].getStudentAverageGrade());
                model->setData( model->index(j,3), studentList[i].getStudentCity() + ", " +  studentList[i].getStudentAddress());

                ++j;
            }
        }

        searchGradeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        searchGradeTable->setColumnWidth(0,365);
        searchGradeTable->setColumnWidth(1,100);
        searchGradeTable->setColumnWidth(2,115);
        searchGradeTable->setColumnWidth(3,375);

        model->setHeaderData(0,Qt::Horizontal, "Ф.И.О:");
        model->setHeaderData(1,Qt::Horizontal, "Оценки:");
        model->setHeaderData(2,Qt::Horizontal, "Средняя оценка:");
        model->setHeaderData(3,Qt::Horizontal, "Адрес:");
    }
}

void MainWindow::closeSearchGradeWindow()
{
    searchGradeWindow->close();
}

void MainWindow::on_studentListToFileButton_clicked()
{
    if (getStorage().isEmpty()) return;
    QFile m_file(getStorage());

    m_file.open(QFile::WriteOnly);

    QStringList data;

    for (unsigned i = 0; i < studentList.size(); ++i) {
        data.append(studentList[i].getStudentName() + "\n");
        data.append(studentList[i].getStudentSurname() + "\n");
        data.append(studentList[i].getStudentPatronymic() + "\n");
        data.append(studentList[i].getStudentCity() + "\n");
        data.append(studentList[i].getStudentAddress() + "\n");
        data.append(QString::number(studentList[i].getStudentFirstGrade()) + "\n");
        data.append(QString::number(studentList[i].getStudentSecondGrade()) + "\n");
        data.append(QString::number(studentList[i].getStudentThirdGrade()) + "\n");

    }

    m_file.resize(0);

    m_file.resize(data.size());

    m_file.seek(0);

    for (unsigned i = 0; i < data.size(); ++i) {
        m_file.write(data[i].toLatin1());
    }

    m_file.close();
}

