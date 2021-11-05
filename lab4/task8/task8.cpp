#include <iostream>
#include <ctime>

int main() {

	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	long double size;
	int max, min, nummax, nummin, start, stop, nul = 0;

	std::cout << "Введите количество элементов массива: ";
	std::cin >> size;

	while (std::cin.fail() || std::cin.peek() != '\n' || size <= 0 || (long long int)size != size) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nВы ввели неверное значение, попробуйте ввести целое положительное число: ";
		std::cin >> size;
	}

	int* arr = new int[size];

	for (int i = 0; i < size; i++) {

		arr[i] = rand() % (long long int(size) * 2) + 1;

		for (int j = 0; j < i; j++) {

			if (arr[i] == arr[j]) {

				arr[i] = rand() % (long long int(size) * 2) + 1;
				j = -1;
			}
		}
	}

	max = arr[0];
	min = arr[0];

	for (int i = 0; i < size; i++) {

		if (max < arr[i]) {

			max = arr[i];
			nummax = i;
		}

		if (min > arr[i]) {

			min = arr[i];
			nummin = i;
		}

	}

	std::cout << "Исходный массив: \n\n";

	for (int i = 0; i < size; i++) {

		std::cout << arr[i] << " ";
	}

	std::cout << "\n\nМассив после преобразований: \n\n";

	start = (nummax > nummin) ? nummin : nummax;
	stop = (nummax < nummin) ? nummin : nummax;

	while (++start < stop) {

		arr[start] = 0;
	}

	for (int i = 0; i < size; i++) {

		if (arr[i] == 0) {

			nul++;
		}
	}

	if (nul > size - nul) {

		int* arr1 = new int[size - nul];

		for (int i = 0, j = 0; i < size; i++) {

			if (arr[i] != 0) {

				arr1[j] = arr[i];
				j++;
			}
		}

		for (int i = 0; i < size - nul; i++) {

			std::cout << arr1[i] << " ";
		}

		delete arr1;
	}
	else {

		for (int i = 0; i < size; i++) {

			std::cout << arr[i] << " ";
		}

		delete arr;
	}

	return 0;
}