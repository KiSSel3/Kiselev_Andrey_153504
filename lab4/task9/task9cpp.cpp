#include <iostream>
#include <iomanip>

int main() {

	setlocale(LC_ALL, "ru");

	long double N;

	std::cout << "Введите размер матриц А и В: ";
	std::cin >> N;

	while (std::cin.fail() || std::cin.peek() != '\n' || N <= 0 || (long long int)N != N) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nВы ввели неверное значение, попробуйте ввести целое положительное число: ";
		std::cin >> N;
	}

	long long int n = N;
	int* arrA;
	int* arrB;
	int* arrC;

	arrA = (int*)calloc(n * n, sizeof(int));
	arrB = (int*)calloc(n * n, sizeof(int));
	arrC = (int*)calloc(n * n, sizeof(int));

	std::cout << "Заполните исходную матрицу A (ввод по одному символу):\n";

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			std::cin >> arrA[i * n + j];

			while (std::cin.fail() || std::cin.peek() != '\n' || (long long int)arrA[i * n + j] != arrA[i * n + j]) {

				std::cin.clear();
				std::cin.ignore(99999, '\n');

				std::cout << "\nВы ввели неверное значение, попробуйте ввести целое положительное число: ";
				std::cin >> arrA[i * n + j];
			}
		}
	}

	std::cout << "\nЗаполните исходную матрицу B (ввод по одному символу):\n";

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			std::cin >> arrB[i * n + j];

			while (std::cin.fail() || std::cin.peek() != '\n' || (long long int)arrB[i * n + j] != arrB[i * n + j]) {

				std::cin.clear();
				std::cin.ignore(99999, '\n');

				std::cout << "\nВы ввели неверное значение, попробуйте ввести целое положительное число: ";
				std::cin >> arrB[i * n + j];
			}
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			std::cout << std::setw(4) << arrA[i * n + j] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			std::cout << std::setw(4) << arrB[i * n + j] << " ";
		}

		std::cout << std::endl;
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			for (int g = 0; g < n; g++) {

				arrC[i * n + j] += arrA[i * n + g] * arrB[g * n + j];
			}
		}
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			std::cout << std::setw(4) << arrC[i * n + j] << " ";
		}

		std::cout << std::endl;
	}

	free(arrA);
	free(arrB);
	free(arrC);
	return 0;
}