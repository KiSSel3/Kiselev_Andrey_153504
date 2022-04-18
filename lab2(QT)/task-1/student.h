#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    Student(QString studentName = "", QString studentSurname = "",QString studentPatronymic = "", QString studentCity = "",
            QString studentAddress = "",  int firstGrade= 0,int secondGrade=0,int thirdGrade =0);

    QString getStudentName();
    QString getStudentSurname();
    QString getStudentPatronymic();

    QString getStudentAddress();
    QString getStudentCity();

    int getStudentFirstGrade();
    int getStudentSecondGrade();
    int getStudentThirdGrade();
    double getStudentAverageGrade();



private:
    QString studentName;
    QString studentSurname;
    QString studentPatronymic;

    QString studentAddress;
    QString studentCity;

    int firstGrade;
    int secondGrade;
    int thirdGrade;
};

#endif // STUDENT_H
