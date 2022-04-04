#include "airport.h"



Airport::Airport(QString aircraftType, short yearManufacture, float fuelConsumption)
    : aircraftType(aircraftType), yearManufacture(yearManufacture), fuelConsumption(fuelConsumption)
{   }

QString Airport::getTypeAircraft()
{
    return aircraftType;
}

short int Airport::getYearManufacture()
{
    return yearManufacture;
}

float Airport::getFuelConsumption()
{
    return fuelConsumption;
}

void Airport::setAirport(QString aircraftType, short yearManufacture, float fuelConsumption)
{
    this->aircraftType = aircraftType;
    this->yearManufacture = yearManufacture;
    this->fuelConsumption = fuelConsumption;
}

Airport& Airport::operator =(const Airport &object)
{
    this->aircraftType = object.aircraftType;
    this->yearManufacture = object.yearManufacture;
    this->fuelConsumption = object.fuelConsumption;

    return *this;
}

