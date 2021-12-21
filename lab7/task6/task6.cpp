//Лабораторная 7, задача 6. Выполнена: Киселёв А.В 153504

/*Мы будем называть число х интересным, если S(x + 1) < S(x).
1 <= x <= n.n - число.Посчитать количество х таких, что х - интересное.*/

#include <iostream>

long double input(double min, double max) {
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

	std::cout << "Введите количество наборов данных: ";
	int count = input(1, 1e9);

	while (count-- != 0) {
		std::cout << "Введите целое число[1;10^9]: ";
		int x = input(1, 1e9);

		int num = x / 10;

		if (x % 10 == 9)

			num++;

		std::cout << "Количество интересных " << num << '\n';
	}

	return 0;
}