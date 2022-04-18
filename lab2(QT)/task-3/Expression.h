#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <QString>
#include "stack.h"


class Expression {
private:

    double a, b, c, d, e;

    std::string expr;

    bool isPolish = false;

    Stack<double> expr_stack;

    int Priority(char a) {

        switch (a) {
        case '*': case '/': return 3;
        case '-': case '+': return 2;
        case ')': return 1;
        }

        return 0;
    }

    double ToDouble(char& i) {
        switch (i) {

        case 'a': return a;
        case 'b': return b;
        case 'c': return c;
        case 'd': return d;
        case 'e': return e;

        }
        return 1;
    }

    void operation(char& op) {


        double op1 = expr_stack.pop();
        double op2 = expr_stack.pop();

        double res = 0;

        switch (op) {

        case '+': res = op2 + op1;
            break;
        case '-': res = op2 - op1;
            break;
        case '*': res = op2 * op1;
            break;
        case '/':
            res = op2 / op1;
        }

        expr_stack.push(res);
    }

public:

    Expression() : a(0), b(0), c(0), d(0), e(0), expr("") {}

    Expression(std::string expr_ = "", double a_ = 0, double b_ = 0, double c_ = 0, double d_ = 0, double e_ = 0) :
        a(a_), b(b_), c(c_), d(d_), e(e_), expr(expr_) {}

    ~Expression() {}

    void toPolish() {
        std::string infix = expr;
        Stack<char> operands;
        std::string polish;
        char operand;

        for (unsigned i = 0; i < infix.size(); ++i) {
            if (infix[i] == 'a' || infix[i] == 'b' || infix[i] == 'c' ||
                infix[i] == 'd' || infix[i] == 'e')
                polish.push_back(infix[i]);

            if (infix[i] == '(')
                operands.push(infix[i]);

            if (infix[i] == ')') {

                while (operands.Top() != '(') {

                    operand = operands.pop();

                    polish.push_back(operand);
                }
                operands.pop();
             }
            if (infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*') {
                while (!operands.isEmpty() && Priority(operands.Top()) >= Priority(infix[i])) {
                    operand = operands.pop();
                    polish.push_back(operand);
                }
                operands.push(infix[i]);
            }
        }

        while (!operands.isEmpty()) {
            operand = operands.pop();
            polish.push_back(operand);
       }


        expr = polish;
        isPolish = true;
    }

    QString result() {

        if (!isPolish)
            toPolish();


        double res = 0;

        for (char i : expr) {

            if (i == 'a' || i == 'b' || i == 'c' || i == 'd' || i == 'e')
                expr_stack.push(ToDouble(i));

            else if (i == '-' || i == '+' || i == '*' || i == '/') {
                operation(i);
            }
        }
        res = expr_stack.Top();

        return QString::number(res);
    }

};

#endif // EXPRESSION_H
