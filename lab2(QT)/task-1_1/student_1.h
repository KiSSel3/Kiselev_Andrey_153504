#ifndef STUDENT_1_H
#define STUDENT_1_H
#include <QString>

class Student_1
{
public:
    Student_1(QString studentName = "", QString studentSurname = "",QString studentPatronymic = "",
              int Group= 0,int AverageGrade=0,int Income =0);

    QString getStudentName();
    QString getStudentSurname();
    QString getStudentPatronymic();

    int getStudentGroup();
    int getStudentAverageGrade();
    int getStudentIncome();

private:
    QString studentName;
    QString studentSurname;
    QString studentPatronymic;

    int Group;
    int AverageGrade;
    int Income;
};

#endif // STUDENT_1_H
