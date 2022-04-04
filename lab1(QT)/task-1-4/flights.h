#ifndef FLIGHTS_H
#define FLIGHTS_H
#include <QString>

class Flights
{
public:
    Flights(QString Destination = "",QString Distance = "",QString PlaneType = "",QString DepartureTime = "",QString LandingTime = "");

    Flights& operator = (const Flights &object);


    QString getDestination();
    QString getDistance();
    QString getPlaneType();
    QString getDepartureTime();
    QString getLandingTime();



    void setFlights( QString Destination, QString Distance, QString PlaneType, QString DepartureTime, QString LandingTime);

private:
    QString Destination, Distance, PlaneType, DepartureTime, LandingTime;
    int time;
    int distance;
};

#endif // FLIGHTS_H
