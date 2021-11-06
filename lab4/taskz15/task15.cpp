#include <iostream>
#include <iomanip>

int main() {

	setlocale(LC_ALL, "ru");

	long double n;
	long long int sum = 1, size = 1, number = 1;


	std::cout << "Введите натуральное число: ";
	std::cin >> n;

	while (std::cin.fail() || std::cin.peek() != '\n' || n <= 0 || (long long int)n != n) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nВы ввели неверное значение, попробуйте ввести целое положительное число: ";
		std::cin >> n;
	}

	for (int i = 1, sum2; sum < n; i += 2) {//нахождение размера массива

		sum2 = sum;
		sum += i;

		if (n > sum2 && n < sum) {

			break;
		}

		size++;
	}

	int** arr = new int* [size];

	for (int i = 0; i < size; i++) {

		arr[i] = new int[size];
	}

	int a, b, c = 1;

	arr[0][0] = number++;

	while (c < size) {

		b = c;
		a = 0;

		while (a < b) {

			arr[a][b] = number++;
			a++;
		}

		while (a == b || b >= 0) {

			arr[a][b] = number++;
			b--;
		}

		c++;
	}

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {

			std::cout << std::setw(5) << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {

			if (arr[i][j] == n) {

				std::cout << "Ваше число(" << n << ") находится в " << i << "x" << j << " ячейке массива.\n";
			}
		}
	}

	for (int i = 0; i < size; i++) {

		delete arr[i];
	}

	delete[] arr;

	return 0;
}