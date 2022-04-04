#include "date.h"

Date::Date()
{
    _day = QDate::currentDate().day();
    _month = QDate::currentDate().month();
    _year = QDate::currentDate().year();
}

Date::Date(const int &day, const int &month, const int &year){
    _day = day;
    _month = month;
    _year = year;
}

Date::Date(const int &day,const int &month){
    _day = day;
    _month = month;
    _year = 0;
}


Date::~Date(){

}

Date Date::nextDay(){
    addOneDay();
    Date tmp = *this;
    substractOneDay();
    return tmp;
}

Date Date::previousDay(){
    substractOneDay();
    Date tmp = *this;
    addOneDay();
    return tmp;
}

bool Date::isLeap(){ // определяем високосность года
    return (_year % 4 == 0 && !(_year % 100 == 0)) || (_year % 100 == 0 && _year % 400 == 0);
}

short Date::weekNummber(){
    short amountDays = _day;
    for(int i = 1; i < _month; i++){
        amountDays += maxDays(i);
    }
    return amountDays/7;
}

int Date::daysTillYourBirthday(const Date &birthdayDate){

    if(_month > birthdayDate._month){
        return daysBetweenMonth(birthdayDate,*this);
    }
    else if(_month < birthdayDate._month){
        return daysBetweenMonth(*this,birthdayDate);
    }
    else{
        return fabs(_day-birthdayDate._day);
    }
}

int Date::daysBetweenMonth(const Date &d1, const Date &d2){
    int amountDays = 0;

    for(int i = d1._month + 1; i < d2._month; i++){
        amountDays += maxDays(i);
    }

    return amountDays + (maxDays(d1._month) - d1._day) + d2._day;
}

int Date::daysBetweenYears(Date &d1, const Date &d2){
    int amountDays = 0;
    for (++d1._year; d1._year < d2._year; d1._year++) {
        amountDays += 365;

        if(d1.isLeap())
            ++amountDays;
    }

    for(int i = d1._month; i < 13; i++){
        amountDays += maxDays(i);
    }

    for(int i = d2._month; i > 1; i--){
        amountDays += maxDays(i);
    }

    return amountDays + (maxDays(d1._month) - d1._day) + d2._day;
}

int Date::duration(Date &date){

    Date maxTmp = *this,minTmp = date;

    if(date.moreThan(*this)){
        qSwap(maxTmp,minTmp);
    }
    if(minTmp._year == maxTmp._year){
        if(minTmp._month == maxTmp._month){
            return fabs(maxTmp._day-minTmp._day);
        }
        else{
            return daysBetweenMonth(minTmp,maxTmp);
        }
    }
    else{
        return daysBetweenYears(minTmp,maxTmp);
    }
}

int Date::day() const{
    return _day;
}

int Date::month() const{
    return _month;
}

int Date::year() const{
    return _year;
}

void Date::print(){
    qDebug() << _day << "." << _month << "." << _year;
}

bool Date::moreThan(const Date &d2){
    if(this->year() == d2.year()){
        if(this->month() == d2.month()){
            return this->day() >= d2.day();
        }
        else{
            return this->month() > d2.month();
        }
    }
    else{
        return this->year() > d2.year();
    }
}

QString Date::getString()
{
    QString str;

    if(QString::number(_day).length()<2){
        str.push_back("0");
    }

    str.push_back(QString::number(_day));
    str.push_back(".");

    if(QString::number(_month).length()<2){
        str.push_back("0");
    }

    str.push_back(QString::number(_month));
    str.push_back(".");

    if(QString::number(_year).length()<2){
        for(int i = 0;i < 4 - QString::number(_day).length(); i++){
            str.push_back("0");
        }
    }

    str.push_back(QString::number(_year));

    return str;
}

void Date::addOneDay(){
    if(_day < maxDays(_month)){
        _day++;
    }
    else if(_day == maxDays(_month) && _month != 12){
        _day = 1;
        _month++;
    }
    else{
        _day = 1;
        _month = 1;
        _year++;
    }
}

void Date::substractOneDay(){
    if(_day > 1){
        _day--;
    }
    else if(_day == 1 && _month != 1){
        _month--;
        _day = maxDays(_month);
    }
    else{
        _day = 31;
        _month = 12;
        _year--;
    }
}

int Date::maxDays(const int &month){
    QMap<int,int> daysInMonth{
        {1,31},
        {2,28},
        {3,31},
        {4,30},
        {5,31},
        {6,30},
        {7,31},
        {8,31},
        {9,30},
        {10,31},
        {11,30},
        {12,31}
    };
    if(month == 2 && this->isLeap())
        return daysInMonth[month] + 1;
    return daysInMonth[month];
}

bool Date::isCorrect(){
    if(_year >0){
        if(_month > 0 && _month < 13){
            if(_day > 0 && _day <= this->maxDays(_month)){
                return true;
            }
        }
    }

    return false;
}
