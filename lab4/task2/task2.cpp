#include <iostream>
#include <ctime>
#include <iomanip>

int main() {

	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	const int LENGTH = 10;
	const int WIDTH = 10;
	double arr[LENGTH][WIDTH];
	double min;

	for (int i = 0; i < LENGTH; i++) {

		for (int j = 0; j < WIDTH; j++) {

			arr[i][j] = rand() % 98 + 1;
		}
	}

	for (int i = 0; i < LENGTH; i++) {

		for (int j = 0; j < WIDTH; j++) {

			std::cout << std::setw(3) << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}

	min = arr[0][0];

	for (int i = 0, g = 1; i < LENGTH - 1; i++, g++) {

		for (int j = 0; j < WIDTH + g; j++) {

			if (arr[i][j] < min) min = arr[i][j];
		}
	}

	std::cout << min << std::endl;

	return 0;
}