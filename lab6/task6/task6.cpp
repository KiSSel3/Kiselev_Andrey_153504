// Лабораторная 6, задача 6. Выполнена: Киселёв А.В 153504

/*Анаграммой слова называется любая перестановка всех букв слова.
Например, из слова SOLO можно получить 12 анаграмм: SOLO, LOSO,
OSLO, OLSO, OSOL, OLOS, SLOO, LSOO, OOLS, OOSL, LOOS,
SOOL.
Напишите программу, которая выводит количество различных
анаграмм, которые могут получиться из этого слова. */


#include <iostream>
#include <string>

long long int fact(int x) {
    if (x == 0) return 1;
    else return x * fact(x - 1);
}

int anagram(std::string str) {
    int count;
    long long answer = fact(str.length());

    while (str.length()) {
        count = 1;

        for (int i = 1; i < str.length(); ++i) {
            if (str[i] == str[0]) {
                ++count;

                str.erase(i--, 1);
            }
        }

        str.erase(0, 1);

        answer /= fact(count);
    }

    return answer;
}

int main() {
    setlocale(LC_ALL, "ru");

    std::string input;

    std::cout << "Введите слово, для нахождения кол-во анаграмм: ";
    std::getline(std::cin, input);

    std::cout << "\nКоличество анаграмм: " << anagram(input);
    putchar('\n');

    return 0;
}