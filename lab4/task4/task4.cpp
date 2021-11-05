#include <iostream>
#include <iomanip>

int main() {

	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	long double n;

	int min = 0;

	std::cout << "Введите размер квадратной матрицы N: ";
	std::cin >> n;

	while (std::cin.fail() || std::cin.peek() != '\n' || n <= 0 || (long long int)n != n) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nВы ввели неверное значение N, попробуйте ввести целое положительное число: ";
		std::cin >> n;

	}

	std::cout << std::endl;

	int** arr = new int* [n];

	for (int i = 0; i < n; i++) {

		arr[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			arr[i][j] = rand() % 9 + 1;
		}
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			std::cout << std::setw(4) << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if (j < n - 1 && j >= 0) {

				if (arr[i][j] > arr[i][j + 1]) {

					continue;
				}
			}
			if (j > 0 && j <= n - 1) {

				if (arr[i][j] > arr[i][j - 1]) {

					continue;
				}
			}
			if (i >= 0 && i < n - 1) {

				if (arr[i][j] > arr[i + 1][j]) {

					continue;
				}
			}
			if (i > 0 && i <= n - 1) {

				if (arr[i][j] > arr[i - 1][j]) {

					continue;
				}
			}

			min++;
		}
	}

	std::cout << min << std::endl;

	for (int i = 0; i < n; i++) {

		delete arr[i];
	}

	delete[] arr;

	return 0;
}