//Лабораторная 7, задача 1. Выполнена: Киселёв А.В. 153504

/*Необходимо разработать программу для перевода чисел из
одной системы счисления в другую. Выполнить два варианта решения
задачи: без использования массивов и с помощью массивов.
8) из двенадцатеричной в девятичную;
*/

#include <iostream>

double toTen(char* input, int lenght_input) {
    bool minus = false;
    double answer = 0;

    if (input[0] == '-')
        minus = true;

    for (int i = (input[0] == '-') ? 1 : 0, step = lenght_input - 1; i < lenght_input; i++, step--) {

        if (input[i] >= '0' && input[i] <= '9') {
            answer += (input[i] - '0') * pow(12, step);
            continue;
        }

        if (input[i] == 'A' || input[i] == 'a') {
            answer += 10 * pow(12, step);
            continue;
        }

        if (input[i] == 'B' || input[i] == 'b') {
            answer += 11 * pow(12, step);
            continue;
        }
    }

    if (minus)
        answer *= -1;

    return answer;
}

double toNine(double num) {
    bool minus = false;
    double number = 0;
   int power = -1;

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

    //c использованием массива
    int max_lenght = 2, lenght_input = 0;
    char* input = (char*)malloc(max_lenght * sizeof(char));

    std::cout << "Введите число : ";
    for (lenght_input; '\n' - (input[lenght_input] = getchar()); lenght_input++) {
        if (input[lenght_input] < 48 || (input[lenght_input] > 57 && input[lenght_input] != 'A' && input[lenght_input] != 'B')) {
            std::cout << "Вы ввели неверный символ!\n";
            return 0;
        }

        if (max_lenght - 1 == lenght_input)
            input = (char*)realloc(input, (max_lenght *= 2) * sizeof(char));
    }

    input = (char*)realloc(input, (lenght_input + 1) * sizeof(char));
    input[lenght_input] = '\0';

    double number1 = toTen(input, lenght_input);
    std::cout << '\n' << toNine(number1) << "\n";

    return 0;
}