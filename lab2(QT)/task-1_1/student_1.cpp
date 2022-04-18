#include "student_1.h"

Student_1::Student_1(QString studentName, QString studentSurname, QString studentPatronymic, int Group, int AverageGrade, int Income)
{
    this->studentName = studentName;
    this->studentSurname = studentSurname;
    this->studentPatronymic = studentPatronymic;
    this->Group = Group;
    this->AverageGrade = AverageGrade;
    this->Income = Income;
}

QString Student_1::getStudentName()
{
    return studentName;
}

QString Student_1::getStudentSurname()
{
    return studentSurname;
}

QString Student_1::getStudentPatronymic()
{
    return studentPatronymic;
}

int Student_1::getStudentGroup()
{
    return Group;
}

int Student_1::getStudentAverageGrade()
{
    return AverageGrade;
}

int Student_1::getStudentIncome()
{
    return Income;
}
