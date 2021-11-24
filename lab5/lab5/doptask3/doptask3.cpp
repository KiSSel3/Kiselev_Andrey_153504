//Лабораторная 5, задача Доп 3. Выполнена: Киселёв А.В 153504

/*Пусть f(n) - наибольший нечетный делитель натурального числа n. По заданному
натуральному n необходимо вычислить значение суммы f(1) + f(2) + ... + f(n).*/


#include <iostream>

void validation(long long int& x) {

	while (std::cin.fail() || std::cin.peek() != '\n' || (long long int)x != x || x > 1e9) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nОшибка ввода! Повторите попытку: ";
		std::cin >> x;
	}

	return;
}

long long int F(long  long int n) {

	long long sum = 0;

	for (long long int i = 1; i <= n; i++) {

		long long int f = i;

		while (f % 2 == 0) {

			f /= 2;
		}

		sum += f;
	}

	return sum;
}

int main() {

	setlocale(LC_ALL, "ru");
	std::ios_base::sync_with_stdio(0);

	long long int n = 0;
	char stop = 'y';
		
	while (stop == 'y') {

		system("cls");

		std::cout << "Введите значение для подсчёта: ";

		std::cin >> n;
		validation(n);
		
		long long sum = 0;

		for (long long int i = 1; i <= n; i++) {

			long long int f = i;

			while (f % 2 != 0) {

				f /= 2;
			}

			sum += f;
		}

		std::cout << "Значение суммы f(1) + f(2) + ... + f(" << n << ") равняется " << F(n) << "\n\n";

		std::cout << "Нажмите 'y' чтобы продолжить ввод данных или введите любой другой символ чтобы прекратить: ";
		std::cin >> stop;
	}

	return 0;
}