#include <iostream>
#include <iomanip>

int main() {

	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	long double n;

	int left, right, up, down;

	int amound, mean;


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

	int** arr1 = new int* [n];

	for (int i = 0; i < n; i++) {

		arr1[i] = new int[n];
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

			amound = 1;
			right = 0;
			left = 0;
			up = 0;
			down = 0;

			if (j < n - 1 && j >= 0) {

				if (arr[i][j] != arr[i][j + 1]) {

					amound++;
					right = arr[i][j + 1];
				}
			}
			if (j > 0 && j <= n - 1) {

				if (arr[i][j] != arr[i][j - 1]) {

					amound++;
					left = arr[i][j - 1];
				}
			}
			if (i >= 0 && i < n - 1) {

				if (arr[i][j] != arr[i + 1][j]) {

					amound++;
					down = arr[i + 1][j];
				}
			}
			if (i > 0 && i <= n - 1) {

				if (arr[i][j] != arr[i - 1][j]) {

					amound++;
					up = arr[i - 1][j];
				}
			}

			arr1[i][j] = (arr[i][j] + right + left + up + down) / amound;
		}
	}

	std::cout << "\n\n";

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			std::cout << std::setw(4) << arr1[i][j] << " ";
		}

		std::cout << std::endl;
	}

	for (int i = 0; i < n; i++) {

		delete arr[i];
	}

	delete[] arr;

	for (int i = 0; i < n; i++) {

		delete arr1[i];
	}

	delete arr1;

	return 0;
}