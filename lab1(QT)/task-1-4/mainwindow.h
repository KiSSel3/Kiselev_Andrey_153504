#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QRegularExpression>
#include <QTableWidget>
#include <QFile>
#include <QTextStream>

#include "airport.h"
#include "flights.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addPlaneInTable(QString inputType, QString inputYear, QString inputFuel);
    void addFlightInTable( QString inputDestination,
                           QString inputDistance,QString inputPlaneType,
                           QString inputDepartureTime,QString inputLandingTime);

    bool individual(QString inputType);
    int consumption(QString inputType);

    bool individualDestination(QString object);

    bool correctTime(QString time);


private slots:
    void on_addPlane_clicked();
    void addPlaneButton();
    void on_addFlight_clicked();
    void addFlightButton();
    void showTotalFuel();
    void showTableDestination();
    void closeWindowShowFlightsToDestination();

    void on_flightSearchButton_clicked();

    void on_fileCreatioButton_clicked();

private:
    unsigned short int row = 0;
    unsigned short int rowFlight = 0;
    Airport* planeArray;
    Flights* flightsArray;

    Ui::MainWindow *ui;

    /* Номер рейса, пункт назначения, дальность полёта, тп самолёта, время вылета, время приземления*/

    //Plane
    QDialog* addPlaneWindow;

    QLineEdit* typeLineEdit;
    QLineEdit* yearLineEdit;
    QLineEdit* fuelConsumptionLineEdit;

    //Flight
    QDialog* addFlightWindow;

    QLineEdit* numberLineEdit;
    QLineEdit* destinationLineEdit;
    QLineEdit* distanceLineEdit;
    QLineEdit* planeTypeLineEdit;
    QLineEdit* departureTimeLineEdit;
    QLineEdit* landingTimeLineEdit;

    QDialog* showFlightsToDestination;
    QLineEdit* choiceDestinationLineEdit;
    QTableWidget* destinationTableWidget;

};
#endif // MAINWINDOW_H
