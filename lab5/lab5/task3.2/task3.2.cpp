#include <iostream>

void validation(long double& x) {

	while (std::cin.fail() || std::cin.peek() != '\n' || x <= 0 || (long long int)x != x) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nОшибка ввода! Повторите попытку: ";
		std::cin >> x;
	}

	return;
}

void arr_validation(long double x) {

	while (std::cin.fail() || std::cin.peek() != '\n') {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nОшибка ввода! Повторите попытку: ";
		std::cin >> x;
	}
	std::cout << std::endl;
	return;
}

int main() {

	setlocale(LC_ALL, "ru");
	std::ios_base::sync_with_stdio(0);

long double sizen = 0, sizem = 0;

	std::cout << "Введите размер двумерного массива\nКоличество строк: ";
	std::cin >> sizen;
	validation(sizen);

	std::cout << "\nКоличество столбцов: ";
	std::cin >> sizem;
	validation(sizem);

	long long int n = sizen, m = sizem;

	long double** arr = new long double* [n];

	for (int i = 0; i < n; i++) {

		arr[i] = new long double[m];
	}

	std::cout << "\nЗаполните двумерный массив:\n";
	for (long long  int i = 0, g = 1; i < n; i++) {

		for (long long int j = 0; j < m; j++,g++) {

			std::cout << g << ": ";
			std::cin >> arr[i][j];
			arr_validation(arr[i][j]);
		}
	}

	long long int null = 0;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			if (arr[i][j] == 0) {

				null++;
			}
		}
	}

	long long int* indexI = new long long int[null];
	long long int* indexJ = new long long int[null];

	for (long long int i = 0, g = 0; i < n; i++) {

		for (long long int j = 0; j < m; j++) {

			if (arr[i][j] == 0) {

				indexI[g] = i;
				indexJ[g] = j;
				g++;
			}
		}
	}

	std::cout << "Данный массив содержит " << null << " нулевых(ое) значений(е)!\n";

	if (null != 0) {

		std::cout << "Индекс(ы) равен(ны):\n";

		for (long long int i = 0; i < null; i++) {

			std::cout << "(" << indexI[i] << ";" << indexJ[i] << ")" << std::endl;
		}
	}

	std::cout << "\nИсходный массив\n";

	for (long long int i = 0; i < n; i++) {

		for (long long int j = 0; j < m; j++) {

			std::cout << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}

	long double buf = 0;

	for (long long int i = 0, g = n,count=1; i <= n / 2; i++,g--) {

		for (long long int j = 0, k = m; j < m; j++, k--, count++) {

			if (count > n * m / 2) break;

			buf = arr[i][j];
			arr[i][j] = arr[g - 1][k - 1];
			arr[g - 1][k - 1] = buf;
		}

		if (count > n * m / 2) break;
	}

	std::cout << "\nЭлементы массива в обратном порядке:\n";

	for (long long int i = 0; i < n; i++) {

		for (long long int j = 0; j < m; j++) {

			std::cout << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}

	for (long long int i = 0; i < n; i++) {

		delete arr[i];
	}

	delete[] arr;
	delete indexI;
	delete indexJ;

	return 0;
}