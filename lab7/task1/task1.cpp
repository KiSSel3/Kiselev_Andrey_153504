//Лабораторная 7, задача 1. Выполнена: Киселёв А.В. 153504

/*Необходимо разработать программу для перевода чисел из
одной системы счисления в другую. Выполнить два варианта решения
задачи: без использования массивов и с помощью массивов.
8) из двенадцатеричной в девятичную;
*/

#include <iostream>

int power = -1;
bool doub = false;

double toTen() {
    char symbol = getchar();
    if (symbol == '\n') return 0;

    if (doub) --power;
    if (symbol == '.') doub = true;

    double num = toTen();

    if (symbol == '-') {
        num *= -1;
        return num;
    }

    if (symbol == '.') return num;

    if (symbol >= '0' && symbol <= '9') {
        ++power;
        return num + (symbol - '0') * pow(12, power);
    }

    if (symbol == 'A' || symbol == 'a') {
        ++power;
        return num + 10.0 * pow(12, power);
    }

    if (symbol == 'B' || symbol == 'b') {
        ++power;
        return num + 11.0 * pow(12, power);
    }
}

double toNine(double num) {
    bool minus = false;
    double number = 0;
    power = -1;

    if (num < 0) {
        num *= -1;
        minus = true;
    }

    int intg = (int)num;
    double doub = num - (int)num;

    while (intg > 0) {
        ++power;
        number += intg % 9 * pow(10, power);
        intg /= 9;
    }

    if (doub != 0) {
        power = 0;

        for (int i = 0; i < 10; ++i) {
            --power;
            number = number + pow(10, power) * (int)(doub * 9);
            doub = doub * 9 - (int)(doub * 9);
        }
    }

    if (minus) number *= -1;

    return number;
}

int main() {
    setlocale(LC_ALL, "ru");
    //без массива
    std::cout << "Введите число : ";

    double number = toTen();
    std::cout << '\n' << toNine(number);

    return 0;
}
