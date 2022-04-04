#ifndef DATE_H
#define DATE_H

#include<QDate>
#include<QDebug>
#include<QFile>

class Date
{
public:
    Date();
    Date(const int &day,const int &month, const int &year);
    Date(const int &day,const int &month);
    ~Date();
    Date nextDay();
    Date previousDay();
    bool isLeap();
    short int weekNummber();
    int daysTillYourBirthday(const Date &birthdayDate);
    int duration(Date &date);
    int day() const;
    int month() const;
    int year() const;
    void print();
    void readDatesFromFile(QList<Date> &listOfDates);
    QString getString();
    int maxDays(const int &month);
     bool isCorrect();

private:
    int _day;
    int _month;
    int _year;

    void addOneDay();
    void substractOneDay();
    bool moreThan(const Date &d2);
    int daysBetweenMonth(const Date &d1, const Date &d2);
    int daysBetweenYears(Date &d1, const Date &d2);
};

#endif // DATE_H
