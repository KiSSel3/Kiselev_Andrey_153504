//Лабораторная 7, задача 2. Выполнена: Киселёв А.В. 153504

/*Перевести числа. Предусмотреть ввод положительных и
отрицательных чисел.
 8)Из обратного кода в естественную форму*/

#include <iostream>
#include<string>

int main() {
	setlocale(LC_ALL, "ru");

	std::cout << "Введите обратный код числа: ";
	std::string Number;
	std::cin >> Number;


	bool minus = false;
	int number = 0;

	int j = 0;

	if (Number[0] == '-') {
		minus = true;
		j = 1;
	}

	for (int i = Number.length() - 1-j; j < Number.length(); j++, i--)
		number += (Number[j] - '0') * pow(2, i);

	if (minus) {
		number *= -1;
	}

	std::cout << number;
	
	return 0;
}