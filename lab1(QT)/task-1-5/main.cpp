/*//#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
*/

#include <iostream>

struct Expression { // базовый класс иерархии
    virtual double evaluate() const = 0;// evaluate возвращает значение типа double - значение соответствующего арифметического выражения
    virtual ~Expression() {}
};

struct Number : public Expression {  // для представление чисел
    Number(double value) : value(value) {}
    double evaluate() const { return value; }

    ~Number() {}

private:
    double value;
};

struct BinaryOperation : public Expression { // описывает бинарную операцию и хранит указатель на левый и правый операнды - которые являются арифметическими выражения
    BinaryOperation(Expression const* left, char op, Expression const* right) :
        right(right), left(left), op(op) {}

    double evaluate() const {

        switch (op) {
        case '+':
            return (left->evaluate() + right->evaluate());
        case '-':
            return (left->evaluate() - right->evaluate());
        case '*':
            return (left->evaluate() * right->evaluate());
        case '/':
            return (left->evaluate() / right->evaluate());
        }
    }
    ~BinaryOperation() {
        delete left;
        delete right;
    }

private:
    Expression const* right;
    Expression const* left;
    char op;
};

bool check_equals(Expression const* left, Expression const* right)
{
    return (*((size_t*)left) == *((size_t*)right));
}

int main() {
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5)); // сначала создаём объекты для подвыражения 4.5 * 5

    Expression* expr = new BinaryOperation(new Number(3), '+', sube); // потом используем его в выражении для +

    std::cout << check_equals(new BinaryOperation(new Number(4.5), '*', new Number(5)), new BinaryOperation(new Number(3), '+', sube));

    std::cout << expr->evaluate();// выводим результат 25,5(4,5*5 = 22,5 + 3 = 25,5);

    delete expr;

    return 0;
}


