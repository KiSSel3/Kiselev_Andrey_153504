#ifndef AIRPORT_H
#define AIRPORT_H

#include <QObject>
#include <QString>

class Airport : public QObject
{
    Q_OBJECT
public:
    Airport(QString aircraftType = "",short int yearManufacture = 0, float fuelConsumption = 0);
    QString getTypeAircraft();
    short int getYearManufacture();
    float getFuelConsumption();

    void setAirport(QString aircraftType = "",short int yearManufacture = 0, float fuelConsumption = 0);

    Airport& operator = (const Airport &object);
private:
    QString aircraftType;
    short int yearManufacture;
    float fuelConsumption;

};

#endif // AIRPORT_H
