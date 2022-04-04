#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    planeArray = new Airport;
    flightsArray = new Flights;


    ui->aircraftList->setColumnCount(3);
    ui->aircraftList->setHorizontalHeaderLabels({"Тип самолёта", "Год выпуска", "Расход горючего"});
    ui->aircraftList->horizontalHeader()->resizeSection(0,320);
    ui->aircraftList->horizontalHeader()->resizeSection(1,320);
    ui->aircraftList->horizontalHeader()->resizeSection(2,320);

    ui->flightsList->setColumnCount(6);
    ui->flightsList->setHorizontalHeaderLabels({"№", "Куда", "Расстояние", "Тип самолёта","Время вылета","Время приземления"});
    ui->flightsList->horizontalHeader()->resizeSection(0,41);
    ui->flightsList->horizontalHeader()->resizeSection(1,181);
    ui->flightsList->horizontalHeader()->resizeSection(2,181);
    ui->flightsList->horizontalHeader()->resizeSection(3,181);
    ui->flightsList->horizontalHeader()->resizeSection(4,181);
    ui->flightsList->horizontalHeader()->resizeSection(5,181);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPlaneInTable(QString inputType, QString inputYear, QString inputFuel)
{
    ui->aircraftList->setRowCount(++row);

    Airport* buff = new Airport[row];

    for ( short int i = 0; i < row - 1; ++i) {
        buff[i] = planeArray[i];
    }

    planeArray = buff;

    planeArray[row-1].setAirport(inputType,inputYear.toInt(),inputFuel.toDouble());


    QTableWidgetItem* itemInputType = new QTableWidgetItem(inputType);
    QTableWidgetItem* itemInputYear = new QTableWidgetItem(inputYear);
    QTableWidgetItem* itemInputFuel = new QTableWidgetItem(inputFuel);

    ui->aircraftList->setItem(row-1,0,itemInputType);
    ui->aircraftList->setItem(row-1,1,itemInputYear);
    ui->aircraftList->setItem(row-1,2,itemInputFuel);


}

void MainWindow::addFlightInTable(QString inputDestination,
                                  QString inputDistance, QString inputPlaneType,
                                  QString inputDepartureTime, QString inputLandingTime)
{
    ui->flightsList->setRowCount(++rowFlight);

    Flights* buff = new Flights[rowFlight];

    for ( short int i = 0; i < rowFlight - 1; ++i) {
        buff[i] = flightsArray[i];
    }

    flightsArray = buff;

    flightsArray[rowFlight -1].setFlights(inputDestination, inputDistance, inputPlaneType, inputDepartureTime, inputLandingTime);

    QTableWidgetItem* itemInputNumber = new QTableWidgetItem(rowFlight);
    QTableWidgetItem* itemInputDestination = new QTableWidgetItem(inputDestination);
    QTableWidgetItem* itemInputDistance = new QTableWidgetItem(inputDistance);
    QTableWidgetItem* itemInputPlaneType = new QTableWidgetItem(inputPlaneType);
    QTableWidgetItem* itemInputDepartureTime = new QTableWidgetItem(inputDepartureTime);
    QTableWidgetItem* itemInputLandingTime = new QTableWidgetItem(inputLandingTime);

    ui->flightsList->setItem(rowFlight-1,0,itemInputNumber);
    ui->flightsList->setItem(rowFlight-1,1,itemInputDestination);
    ui->flightsList->setItem(rowFlight-1,2,itemInputDistance);
    ui->flightsList->setItem(rowFlight-1,3,itemInputPlaneType);
    ui->flightsList->setItem(rowFlight-1,4,itemInputDepartureTime);
    ui->flightsList->setItem(rowFlight-1,5,itemInputLandingTime);
}

bool MainWindow::individual(QString inputType)
{
    bool individual = true;
    for(short int i = 0; i<row;i++){
        if ( planeArray[i].getTypeAircraft() == inputType){
            individual = false;
            break;
        }
    }

    return individual;
}

int MainWindow::consumption(QString inputType)
{
    int consumption = 0;

    for (short int i =0;i<row;++i){
        if( planeArray[i].getTypeAircraft() == inputType){
            consumption = planeArray[i].getFuelConsumption();
            break;
        }
    }

    return consumption;
}

void MainWindow::on_addPlane_clicked()
{
    addPlaneWindow = new QDialog(this);
    addPlaneWindow->setModal(true);
    addPlaneWindow->resize(250,150);

    QLabel* typeLabel = new QLabel(addPlaneWindow);
    typeLabel->move(10,15);
    typeLabel->resize(100,15);
    typeLabel->setText("Тип самолёта: ");

    typeLineEdit = new QLineEdit(addPlaneWindow);
    typeLineEdit->move(115,15);

    QLabel* yearLabel = new QLabel(addPlaneWindow);
    yearLabel->move(10,40);
    yearLabel->resize(100,15);
    yearLabel->setText("Год выпуска: ");

    yearLineEdit = new QLineEdit(addPlaneWindow);
    yearLineEdit->setInputMask("9999");
    yearLineEdit->move(115,40);

    QLabel* fuelConsumptionLabel = new QLabel(addPlaneWindow);
    fuelConsumptionLabel->move(10,65);
    fuelConsumptionLabel->resize(100,15);
    fuelConsumptionLabel->setText("Расход горючего: ");

    fuelConsumptionLineEdit = new QLineEdit(addPlaneWindow);
    fuelConsumptionLineEdit->move(115,65);

    QPushButton* pushButtonAddPlane = new QPushButton(addPlaneWindow);
    pushButtonAddPlane->setText("Добавить");
    pushButtonAddPlane->move(90,100);

    connect(pushButtonAddPlane,SIGNAL(clicked()), this, SLOT(addPlaneButton()));

    addPlaneWindow->show();
}

void MainWindow::addPlaneButton()
{
    QString inputType = typeLineEdit->text(),
            inputYear = yearLineEdit->text(),
            inputFuel = fuelConsumptionLineEdit->text();

    if (inputType.isEmpty() || inputFuel.isEmpty() || inputYear.isEmpty()){
        QMessageBox::critical(addPlaneWindow, "", "Введены не все параметры");
    }
    else {
        QRegularExpression numberYear("[0-9]{4}");
        QRegularExpression number("[0-9]");

        QRegularExpressionMatch matchInputYear = numberYear.match(inputYear);
        QRegularExpressionMatch matchInputFuel = number.match(inputFuel);



        if (!matchInputYear.hasMatch()||!matchInputFuel.hasMatch() ||  inputYear.toInt()>2022 || inputYear.toInt()<1903 || inputFuel.toInt()<=0){
            QMessageBox::critical(addPlaneWindow, "", "Некорректный ввод");
        }
        else if (!individual(inputType)){
            QMessageBox::critical(addPlaneWindow, "", "Данный тип самолёта уже задан");
        }
        else {
            addPlaneInTable(inputType, inputYear, inputFuel);
            addPlaneWindow->close();
        }
    }
}

void MainWindow::on_addFlight_clicked()
{
    addFlightWindow = new QDialog(this);
    addFlightWindow->setModal(true);
    addFlightWindow->resize(260,210);

    QLabel* destinationLabel = new QLabel(addFlightWindow);
    destinationLabel->resize(105,15);
    destinationLabel->move(10,40);
    destinationLabel->setText("Пункт назначения: ");

    destinationLineEdit = new QLineEdit(addFlightWindow);
    destinationLineEdit->move(120,40);

    QLabel* distanceLabel = new QLabel(addFlightWindow);
    distanceLabel->resize(105,15);
    distanceLabel->move(10,65);
    distanceLabel->setText("Дистанция(км): ");

    distanceLineEdit = new QLineEdit(addFlightWindow);
    distanceLineEdit->move(120,65);

    QLabel* planeTypeLabel = new QLabel(addFlightWindow);
    planeTypeLabel->resize(105,15);
    planeTypeLabel->move(10,90);
    planeTypeLabel->setText("Тип саммолёта: ");

    planeTypeLineEdit = new QLineEdit(addFlightWindow);
    planeTypeLineEdit->move(120,90);

    QLabel* departureLabel = new QLabel(addFlightWindow);
    departureLabel->resize(105,15);
    departureLabel->move(10,115);
    departureLabel->setText("Время вылета: ");

    departureTimeLineEdit = new QLineEdit(addFlightWindow);
    departureTimeLineEdit->setInputMask("99:99");
    departureTimeLineEdit->setText(":");
    departureTimeLineEdit->move(120,115);

    QLabel* landingLabel = new QLabel(addFlightWindow);
    landingLabel->resize(105,15);
    landingLabel->move(10,140);
    landingLabel->setText("Время прибытия: ");

    landingTimeLineEdit = new QLineEdit(addFlightWindow);
    landingTimeLineEdit->setInputMask("99:99");
    landingTimeLineEdit->setText(":");
    landingTimeLineEdit->move(120,140);

    QPushButton* pushButtonAddFlight = new QPushButton(addFlightWindow);
    pushButtonAddFlight->setText("Добавить");
    pushButtonAddFlight->move(90,175);

    connect(pushButtonAddFlight,SIGNAL(clicked()), this, SLOT(addFlightButton()));

    addFlightWindow->show();

}

void MainWindow::addFlightButton()
{
    QString inputDestination = destinationLineEdit->text(),
            inputDistance = distanceLineEdit->text(),
            inputPlaneType = planeTypeLineEdit->text(),
            inputDepartureTime = departureTimeLineEdit->text(),
            inputLandingTime = landingTimeLineEdit->text();

    if ( inputDestination.isEmpty() || inputDistance.isEmpty() || inputPlaneType.isEmpty() || inputDepartureTime.isEmpty() || inputLandingTime.isEmpty()){
        QMessageBox::critical(addFlightWindow, "", "Введены не все параметры");
    }
    else {
        QRegularExpression time("[0-9]{2}\\:[0-9]{2}$");
        QRegularExpression number("[0-9]");

        QRegularExpressionMatch matchInputDepartureTime = time.match(inputDepartureTime);
        QRegularExpressionMatch matchInputLandingTime = time.match(inputLandingTime);
        QRegularExpressionMatch matchInputDistance = number.match(inputDistance);


        if (!matchInputDepartureTime.hasMatch()||!matchInputLandingTime.hasMatch() || !matchInputDistance.hasMatch()){
            QMessageBox::critical(addFlightWindow, "", "Некорректный ввод");
        }
        else if (individual(inputPlaneType)){
            QMessageBox::critical(addFlightWindow, "", "Введён несуществующий тип самолёта");
        }
        else if(inputDistance.toInt()<=0){
            QMessageBox::critical(addFlightWindow, "", "Вы ввели отрицательное значение");
        }
        else if(!correctTime(inputLandingTime) || !correctTime(inputDepartureTime) ){
            QMessageBox::critical(addFlightWindow, "", "Некорректный ввод");
        }
        else{
            addFlightInTable(inputDestination, inputDistance, inputPlaneType, inputDepartureTime, inputLandingTime);
            showTotalFuel();
            addFlightWindow->close();
        }
    }
}

void MainWindow::showTotalFuel()
{
    QString statusbarTotalFuel = "Необходимое количество топлива: ";

    double totalFuel = 0;

    for (unsigned short int i =0;i<rowFlight;++i){
        totalFuel+= consumption(flightsArray[i].getPlaneType()) * flightsArray[i].getDistance().toInt() / 1000.;
    }

    statusbarTotalFuel+=QString::number(totalFuel);

    ui->statusbar->showMessage(statusbarTotalFuel);
}

void MainWindow::on_flightSearchButton_clicked()
{
    showFlightsToDestination  = new QDialog(this);
    showFlightsToDestination->setModal(true);
    showFlightsToDestination->resize(1000,350);

    destinationTableWidget = new QTableWidget(showFlightsToDestination);
    destinationTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    destinationTableWidget->resize(979,289);
    destinationTableWidget->move(10,5);

    destinationTableWidget->setColumnCount(6);
    destinationTableWidget->setHorizontalHeaderLabels({"№", "Куда", "Расстояние", "Тип самолёта","Время вылета","Время приземления"});
    destinationTableWidget->horizontalHeader()->resizeSection(0,41);
    destinationTableWidget->horizontalHeader()->resizeSection(1,181);
    destinationTableWidget->horizontalHeader()->resizeSection(2,181);
    destinationTableWidget->horizontalHeader()->resizeSection(3,181);
    destinationTableWidget->horizontalHeader()->resizeSection(4,181);
    destinationTableWidget->horizontalHeader()->resizeSection(5,181);

    QLabel* textLable = new QLabel(showFlightsToDestination);
    textLable->setText("Введите город: ");
    textLable->resize(100,20);
    textLable->move(20,320);

    choiceDestinationLineEdit = new QLineEdit(showFlightsToDestination);
    choiceDestinationLineEdit->resize(100,20);
    choiceDestinationLineEdit->move(120,323);

    QPushButton* searchButton = new QPushButton(showFlightsToDestination);
    searchButton->setText("Поиск рейсов");
    searchButton->move(240,320);

    QPushButton* closeWindow = new QPushButton(showFlightsToDestination);
    closeWindow->setText("Закрыть");
    closeWindow->move(900,320);

    showFlightsToDestination->show();

    connect(searchButton,SIGNAL(clicked()),this,SLOT(showTableDestination()));
    connect(closeWindow,SIGNAL(clicked()),this,SLOT(closeWindowShowFlightsToDestination()));
}

void MainWindow::showTableDestination()
{
    QString inputTextLable = choiceDestinationLineEdit->text();

    if(!individualDestination(inputTextLable)){
        QMessageBox::critical(showFlightsToDestination, "", "Данный пункт назначения отсутствует");
    }
    else {
        for(short int i = 0, rowInDestinationTableWidget = 0; i < rowFlight;++i){

            if(flightsArray[i].getDestination() == inputTextLable) {
                destinationTableWidget->setRowCount(++rowInDestinationTableWidget);

                QTableWidgetItem* itemInputNumber = new QTableWidgetItem(rowInDestinationTableWidget);
                QTableWidgetItem* itemInputDestination = new QTableWidgetItem(flightsArray[i].getDestination());
                QTableWidgetItem* itemInputDistance = new QTableWidgetItem(flightsArray[i].getDistance());
                QTableWidgetItem* itemInputPlaneType = new QTableWidgetItem(flightsArray[i].getPlaneType());
                QTableWidgetItem* itemInputDepartureTime = new QTableWidgetItem(flightsArray[i].getDepartureTime());
                QTableWidgetItem* itemInputLandingTime = new QTableWidgetItem(flightsArray[i].getLandingTime());

                destinationTableWidget->setItem(rowInDestinationTableWidget-1,0,itemInputNumber);
                destinationTableWidget->setItem(rowInDestinationTableWidget-1,1,itemInputDestination);
                destinationTableWidget->setItem(rowInDestinationTableWidget-1,2,itemInputDistance);
                destinationTableWidget->setItem(rowInDestinationTableWidget-1,3,itemInputPlaneType);
                destinationTableWidget->setItem(rowInDestinationTableWidget-1,4,itemInputDepartureTime);
                destinationTableWidget->setItem(rowInDestinationTableWidget-1,5,itemInputLandingTime);
            }
        }
    }
}

void MainWindow::closeWindowShowFlightsToDestination()
{
    showFlightsToDestination->close();
}


bool MainWindow::individualDestination(QString object)
{
    bool individualDestination = false;

    for(short int i = 0; i<rowFlight;i++){
        if (flightsArray[i].getDestination() == object ){
            individualDestination = true;
            break;
        }
    }

    return individualDestination;
}

bool MainWindow::correctTime(QString object)
{
    bool correctTime= true;
    QString timeHour = object;
    QString timeMin = object;

    QString hour = timeHour.remove(2,3);
    QString min = timeMin.remove(0,3);

    if(hour.toInt()>23 || hour.toInt()<0 || min.toInt()<0 || min.toInt() > 59){
        correctTime = false;
    }

    return correctTime;
}

void MainWindow::on_fileCreatioButton_clicked()
{
    QFile schedule("C:/Users/User/Desktop./flightSchedule.txt");

    if (!schedule.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"","Ошибка создания файла!");
    }
    else {
        QMessageBox::information(this,"","Файл с расписанием создан на рабочем столе!");

        QTextStream stream(&schedule);

        for (short int i = 0;i<rowFlight;++i){
            QString buff = " " + flightsArray[i].getDestination() + "  " + flightsArray[i].getDistance() + "(km)  "
                    + flightsArray[i].getPlaneType() + "  " + flightsArray[i].getDepartureTime() + "  " + flightsArray[i].getLandingTime();

            stream<<i+1<<"."<<buff<<"\n\n";
        }
    }

    schedule.close();
}

