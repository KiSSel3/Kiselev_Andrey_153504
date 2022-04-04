#include "flights.h"



Flights::Flights(QString Destination, QString Distance, QString PlaneType, QString DepartureTime, QString LandingTime)
{

    this->Destination = Destination;
    this->Distance = Distance;
    this->PlaneType = PlaneType;
    this->DepartureTime = DepartureTime;
    this->LandingTime = LandingTime;
}

Flights &Flights::operator =(const Flights &object)
{

    this->Destination = object.Destination;
    this->Distance = object.Distance;
    this->PlaneType = object.PlaneType;
    this->DepartureTime = object.DepartureTime;
    this->LandingTime = object.LandingTime;

    return *this;
}



QString Flights::getDestination()
{
    return Destination;
}

QString Flights::getDistance()
{
    return Distance;
}

QString Flights::getPlaneType()
{
    return PlaneType;
}

QString Flights::getDepartureTime()
{
    return DepartureTime;
}

QString Flights::getLandingTime()
{
    return LandingTime;
}

void Flights::setFlights( QString Destination, QString Distance, QString PlaneType, QString DepartureTime, QString LandingTime)
{

    this->Destination = Destination;
    this->Distance = Distance;
    this->PlaneType = PlaneType;
    this->DepartureTime = DepartureTime;
    this->LandingTime = LandingTime;
}
