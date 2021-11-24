//Лабораторная 5, задача 3.1. Выполнена: Киселёв А.В 153504

/*Дан двумерный динамический массив целых чисел А размерностью n x k .
Размерность массива (n = 5, k = 6) ввести с клавиатуры. Значения элементов массива
ввести с клавиатуры. Создать динамический массив из элементов, расположенных на
главной диагонали матрицы и имеющих четное значение. Вычислить произведение
элементов динамического массива.
Созданный массив и результат произведения вывести на экран.
Использовать функции.*/

#include <iostream>

void validation(double& x) {

	while (std::cin.fail() || std::cin.peek() != '\n' || x <= 0 || (int)x != x) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nОшибка ввода! Повторите попытку: ";
		std::cin >> x;
	}

	return;
}

void arr_validation(double x) {

	while (std::cin.fail() || std::cin.peek() != '\n'|| (long long int)x != x) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nОшибка ввода! Повторите попытку: ";
		std::cin >> x;
	}
	std::cout << std::endl;
	return;
}

long double sum(long long int x[],long long int size) {

	long double s = 0;

	for (long long i = 0; i < size; i++) {

		s += x[i];
	}

	return s;
}

int main() {

	setlocale(LC_ALL, "ru");
	std::ios_base::sync_with_stdio(0);

	double n = 0, m = 0;

	std::cout << "Введите размер двумерного массива\nКоличество строк: ";
	std::cin >> n;
	validation(n);

	std::cout << "\nКоличество столбцов: ";
	std::cin >> m;
	validation(m);

	double** arr = new double* [n];

	for (int i = 0; i < n; i++) {

		arr[i] = new double[m];
	}

	std::cout << "\nЗаполните двумерный массив:\n";
	for (int i = 0, g = 1; i < n; i++) {

		for (int j = 0; j < m; j++, g++) {

			std::cout << g << "\\" << m * n << ": ";
			std::cin >> arr[i][j];
			arr_validation(arr[i][j]);
		}
	}

	long long size = 0;

	long long int min = (n < m) ? n : m;

	for (long long i = 0; i < min; i++) {

		if (long long(arr[i][i]) % 2 == 0) size++;
	}

	long long int* diog = new long long[size];

	for (long long i = 0, g = 0; i < min; i++) {

		if (long long int (arr[i][i]) % 2 == 0) {

			diog[g] = arr[i][i];
			g++;
		}
	}

	std::cout << "Массив из элементов лежащих на главной диагонали и имеющиx чётное значение:\n";

	for (int i = 0; i < size; i++) {

		std::cout << diog[i] << " ";
	}

	std::cout << std::endl;

	std::cout << "\nСумма членов массива равна " << sum(diog, size) << std::endl;

	return 0;
}
