
#include <iostream>
#include <string>

std::string translate(std::string str);

int main() {
    setlocale(LC_ALL, "ru");

    std::string str;
    std::cout << "Введите исходную строку: ";
    std::getline(std::cin, str);

    std::cout << "\nОбработанная строка: " << translate(str) << std::endl;

    return 0;
}

std::string translate(std::string str) {

    long long int num = 0;

    while (num < str.length()) {
        if (str[num] == 'C' && num + 1 < str.length() && (tolower(str[num + 1]) == 'e' || tolower(str[num + 1]) == 'i' || tolower(str[num + 1]) == 'y')) {
            str[num] = 'S';

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (str[num] == 'c' && num + 1 < str.length() && (tolower(str[num + 1]) == 'e' || tolower(str[num + 1]) == 'i' || tolower(str[num + 1]) == 'y')) {
            str[num] = 's';

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'Q' && tolower(str[num+1] == 'u')) {
            str[num] = 'K';
            str[num + 1] = 'v';

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'q' && tolower(str[num+1] == 'u')) {
            str[num] = 'q';
            str[num + 1] = 'v';

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (str[num] == 'c' || str[num] == 'q') {
            str[num] = 'k';

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (str[num] == 'C' || str[num] == 'Q') {
            str[num] = 'K';

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (str[num] == 'X') {
            str[num] = 'K';
            str.insert(num + 1, "s");

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (str[num] == 'x') {
            str[num] = 'k';
            str.insert(num + 1, "s");

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (str[num] == 'W') {
            str[num] = 'V';

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (str[num] == 'w') {
            str[num] = 'v';

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'P' && tolower(str[num+1] == 'h')) {
            str[num] = 'F';
            str.erase(num + 1, 1);

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'p' && tolower(str[num + 1] == 'h')) {
            str[num] = 'f';
            str.erase(num + 1, 1);

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (num + 2 < str.length() && str[num] == 'Y' && tolower(str[num + 1] == 'o')&&tolower(str[num + 2] == 'u')) {
            str[num] = 'U';
            str.erase(num + 1, 2);

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (num + 2 < str.length() && str[num] == 'y' && tolower(str[num + 1] == 'o') && tolower(str[num + 2] == 'u')) {
            str[num] = 'u';
            str.erase(num + 1, 2);

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'O' && tolower(str[num + 1] == 'o')) {
            str[num] = 'U';
            str.erase(num + 1, 1);

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'o' && tolower(str[num + 1] == 'o')) {
            str[num] = 'u';
            str.erase(num + 1, 1);

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'E' && tolower(str[num + 1] == 'e')) {
            str[num] = 'I';
            str.erase(num + 1, 1);

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'e' && tolower(str[num + 1] == 'e')) {
            str[num] = 'i';
            str.erase(num + 1, 1);

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'T' && tolower(str[num + 1] == 'h')) {
            str[num] = 'Z';
            str.erase(num + 1, 1);

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (num + 1 < str.length() && str[num] == 't' && tolower(str[num + 1] == 'h')) {
            str[num] = 'z';
            str.erase(num + 1, 1);

            if (num - 1 >= 0)
                num--;

            continue;
        }
        else if (num + 1 < str.length() && tolower(str[num]) ==tolower(str[num + 1])&&tolower(str[num]) != 'a' && tolower(str[num]) != 'e' && tolower(str[num]) != 'i' && tolower(str[num]) != 'o' && tolower(str[num]) != 'u' && tolower(str[num]) != 'y') {
            str.erase(num, 1);

            if (num - 1 >= 0)
                num--;

            continue;
        }
        num++;
    }

    return str;
}
