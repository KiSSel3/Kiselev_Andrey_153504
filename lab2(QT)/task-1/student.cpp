#include "student.h"

Student::Student(QString studentName, QString studentSurname, QString studentPatronymic, QString studentCity, QString studentAddress, int firstGrade, int secondGrade, int thirdGrade)
{
    this->studentName = studentName;
    this->studentSurname = studentSurname;
    this->studentPatronymic = studentPatronymic;

    this->studentAddress = studentAddress;
    this->studentCity = studentCity;

    this->firstGrade = firstGrade;
    this->secondGrade = secondGrade;
    this->thirdGrade = thirdGrade;
}

QString Student::getStudentName()
{
    return studentName;
}

QString Student::getStudentSurname()
{
    return studentSurname;
}

QString Student::getStudentPatronymic()
{
    return studentPatronymic;
}

QString Student::getStudentAddress()
{
    return studentAddress;
}

QString Student::getStudentCity()
{
    return studentCity;
}

int Student::getStudentFirstGrade()
{
    return firstGrade;
}

int Student::getStudentSecondGrade()
{
    return secondGrade;
}

int Student::getStudentThirdGrade()
{
    return thirdGrade;
}

double Student::getStudentAverageGrade()
{
    return double(firstGrade+secondGrade+thirdGrade) / 3;
}

