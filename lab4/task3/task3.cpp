//Лабораторная 4, задача 3. Выполнена: Киселёв А.В 153504

/*Память для массива выделить динамически.
8 Вар: 
Определить, является ли заданная целочисленная квадратная матрица размером N ортонормированной, т.е. такой,
в которой скалярное произведение каждой пары разлличный строк равно 0, а скалярное произведение каждой строки на себя равно 1 */


#include <iostream>
#include <iomanip>

int main() {

	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	long double N;
	long long int s1 = 0, s2 = 0;

	std::cout << "\tДанный код определяет, является ли заданная матрица ортонормированной\n\n";

	std::cout << "Введите размер квадратной матрицы N: ";
	std::cin >> N;

	while (std::cin.fail() || std::cin.peek() != '\n' || N <= 0 || (long long int)N != N) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nВы ввели неверное значение N, попробуйте ввести целое положительное число: ";
		std::cin >> N;

	}

	int** arr = new int* [N];

	for (int i = 0; i < N; i++) {

		arr[i] = new int[N];
	}

	std::cout << "Заполните квадратную матрицу размером " << N << " (матрица заполняется слева направо, сверху вниз; вводится по одному значению):\n";

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			std::cin >> arr[i][j];

			while (std::cin.fail() || std::cin.peek() != '\n' || (long long int)arr[i][j] != arr[i][j]) {

				std::cin.clear();
				std::cin.ignore(99999, '\n');

				std::cout << "\nВы ввели неверное значение, попробуйте ввести целое число: ";
				std::cin >> arr[i][j];

			}
		}
	}

	system("cls");

	std::cout << "Ваша матрица:\n";

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			std::cout << std::setw(3) << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}

	//произведение строк
	for (int i = 0; i < N-1; i++) {

		for (int j = 0; j < N; j++) {

			s1 += arr[i][j] * arr[i + 1][j];
		}
	}


	//произведение строки
	for (int j = 0; j < N; j++) {

		for (int i = 0; i < N; i++) {

			s2 += arr[i][j] * arr[i][j];
		}
	}

	if (s1 == 0 && s2 == N) {

		std::cout << "Заданная матрица является ортонормированной!\n";
	}
	else {

		std::cout << "Заданная матрица не является ортонормированной!\n";
	}

	for (int i = 0; i < N; i++) {

		delete arr[i];
	}

	delete[] arr;

	return 0;
}