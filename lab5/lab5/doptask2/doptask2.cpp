//Лабораторная 5, задача Доп 2. Выполнена: Киселёв А.В 153504

/*Написать рекурсивную функцию возведения в степень по модулю

Входные данные
Каждая строка содержит три целых числа: k (0 < k < 1019), n (0 < n < 1019) и t (0 < t < 10).
Последняя строка содержит три нуля и не обрабатывается.
Выходные данные
Для каждого теста в отдельной строке вывести номер теста и значение x. Формат вывода
приведен в примере.
Входные данные
1234 1234 4
2323 99999999999 8
4 99999 9
888 888 8
0 0 0
Выходные данные
Case #1: 736
Case #2: 39087387
Case #3: 494777344
Case #4: 91255296  */


#include <iostream>
#include <staticlib.h>

unsigned long long int F(unsigned long long int x, unsigned long long int y, unsigned long long int z) {

	if (y == 0) return 1;
	else if (y % 2)return x * F(x * x % z, y / 2, z) % z;
	else return F(x * x % z, y / 2, z);
}

void validation(unsigned long long int& x, unsigned long long int& y, unsigned long long int& z) {

	while (std::cin.fail() || std::cin.peek() != '\n' || (long long int)x != x || (long long int)y != y || (long long int)z != z || x < 0 || y < 0 || z < 0) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nОшибка ввода! Повторите попытку: ";
		std::cin >> x >> y >> z;
	}

	return;
}


int main() {

	setlocale(LC_ALL, "ru");
	std::ios_base::sync_with_stdio(0);

	unsigned long long int size = 0;

	unsigned long long int* arr = new unsigned long long int[3];

	std::cout << "Введите данные для расчёта:\n";

	while (true) {

		std::cin >> arr[size++];
		std::cin >> arr[size++];
		std::cin >> arr[size++];

		validation(arr[size - 3], arr[size - 2], arr[size - 1]);

		if (arr[size - 3] == 0 && arr[size - 2] == 0 && arr[size - 1] == 0) break;

		unsigned long long int* buf = new unsigned long long int[size + 3];

		for (unsigned long long int i = 0; i < size; i++) {
			buf[i] = arr[i];
		}

		delete arr;
		arr = buf;
	}

	std::cout << "\nВведённые данные:\n";

	for (unsigned long long int i = 0; i < size; i++) {

		std::cout << arr[i] << " ";
		if (i % 3 == 2)std::cout << std::endl;
	}

	unsigned long long int m = 0;

	unsigned long long int* result = new unsigned long long int [size / 3 -1];

	for (unsigned long long int i = 0, j = 0; i < size - 3; i += 3,j++) {

		m = pow(10, arr[i + 2]);//функция статик либ 
		unsigned long long int l = arr[i] % m;
		result[j] = F(l, arr[i + 1], m);
	}

	std::cout << "\n\nРезультат:\n";

	for (unsigned long long int i = 0, g = 1; i < size / 3 - 1; i++,g++) {

		std::cout << "Case #" << g << ": " << result[i] << std::endl;
	}

	delete arr;
	delete result;

	return 0;
}