//Лабораторная 7, задача 5. Выполнена: Киселёв А.В 153504

//Перевести число из арабской системы записи чисел в римскую.

#include <iostream>
#include <string>

long double input_(double min, double max) {
	long double x;
	while (true) {
		std::cin >> x;
		if (!std::cin.fail() && std::cin.peek() == '\n' && x <= max && x >= min)
			return x;
		std::cin.clear();
		std::cin.ignore(99999, '\n');
		std::cout << "Ошибка ввода!Введдите другое значение: " << std::endl;
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	int input = input_(0, 40000);

	for (int i = 0; i < input / 1000; i++)
		std::cout << "M";

	input %= 1000;

	if ((input % 500) / 100 + 5 == 9) {
		std::cout << "CM";
		input %= 900;
	}
	else if (input / 500 > 0) {
		std::cout << "D";
		input %= 500;
	}

	for (int i = 0; i < input / 100; i++)
		std::cout << "C";

	input %= 100;

	if ((input % 50) / 10 + 5 == 9) {
		std::cout << "XC";
		input %= 90;
	}
	else if (input / 50 > 0) {
		std::cout << "L";
		input %= 50;
	}

	if (input / 10 == 4) {
		std::cout << "XL";
		input %= 40;
	}

	for (int i = 0; i < input / 10; i++) {
		std::cout << "X";
	}

	input %= 10;

	if (input == 1)
		std::cout << "I";

	if (input == 2)
		std::cout << "II";

	if (input == 3)
		std::cout << "III";

	if (input == 4)
		std::cout << "IV";

	if (input == 5)
		std::cout << "V";

	if (input == 6)
		std::cout << "VI";

	if (input == 7)
		std::cout << "VII";

	if (input == 8)
		std::cout << "VIII";

	if (input == 9)
		std::cout << "IX";

	return 0;
}