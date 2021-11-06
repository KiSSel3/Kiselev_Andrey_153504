#include <iostream>

int main() {

	setlocale(LC_ALL, "ru");

	long double size;

	long long int diog1 = 0, diog2 = 0, diog3 = 0, diog4 = 0, max1, max2, max;

	std::cout << "Введите размер трёхмерного массива(n^3): ";
	std::cin >> size;

	while (std::cin.fail() || std::cin.peek() != '\n' || size <= 0 || (long long int)size != size) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nВы ввели неверное значение, попробуйте ввести целое положительное число: ";
		std::cin >> size;

	}

	int*** arr = new int** [size];

	for (int i = 0; i < size; i++) {

		arr[i] = new int* [size];

		for (int j = 0; j < size; j++) {

			arr[i][j] = new int[size];
		}
	}

	std::cout << "Заполните исходный массив: \n";

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {

			for (int g = 0; g < size; g++) {

				std::cin >> arr[i][j][g];

				while (std::cin.fail() || std::cin.peek() != '\n' || arr[i][j][g] <= 0 || (long long int)arr[i][j][g] != arr[i][j][g]) {

					std::cin.clear();
					std::cin.ignore(99999, '\n');

					std::cout << "Вы ввели неверное значение, попробуйте ввести целое положительное число: ";
					std::cin >> arr[i][j][g];
				}
			}
		}
	}

	for (int i = 0; i < size; i++) {

		diog1 += arr[i][i][i];
	}

	for (int i = 0; i < size; i++) {

		diog2 += arr[i][long long int(size) - i - 1][long long int(size) - i - 1];
	}

	for (int i = 0; i < size; i++) {

		diog3 += arr[i][long long int(size) - i - 1][i];
	}

	for (int i = 0; i < size; i++) {

		diog4 += arr[i][i][long long int(size) - i - 1];
	}

	max1 = (diog1 > diog2) ? diog1 : diog2;
	max2 = (diog3 > diog4) ? diog3 : diog4;
	max = (max1 > max2) ? max1 : max2;

	std::cout << "Диагональ с наибольшией суммой чисел равняется " << max << ". \n";

	return 0;
}