#include <iostream>

void validation(long long int& x, long long int& y) {

	while (std::cin.fail() || std::cin.peek() != '\n'|| (long long int)x != x|| (long long int)y != y) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nОшибка ввода! Повторите попытку: ";
		std::cin >> x >> y;
	}

	return;
}

long long int F(long long x) {

	if (x % 10 > 0) return x % 10;
	else if (x == 0) return 0;
	else return F(x / 10);
}

long long int S(long long int p, long long int q) {

	long long int s = 0;

	for (long long int i = q; i <= p; i++) {

		s += F(i);
	}

	return s;
}

int main() {

	setlocale(LC_ALL, "ru");
	std::ios_base::sync_with_stdio(0);

	long long int size = 0;

	long long int* arr = new long long int[2];

	std::cout << "Введите данные для расчёта:\n";

	while (true) {

		std::cin >> arr[size++] >> arr[size++];
		validation(arr[size - 2], arr[size - 1]);

		if (arr[size - 2] == -1 && arr[size - 1] == -1) break;

		long long int* buf = new long long int[size + 2];

		for (int i = 0; i < size; i++) {
			buf[i] = arr[i];
		}

		delete arr;
		arr = buf;
	}

	std::cout << "\nВведённые данные:\n";

	for (int i = 0; i < size; i++) {

		std::cout << arr[i] << " ";
		if (i % 2 == 1)std::cout << std::endl;
	}

	std::cout << "\nФункция S(p,q): \n";
	for (long long int i = 0; i < size - 2; i += 2) {

		std::cout << S(arr[i], arr[i + 1]) << std::endl;
	}

	delete arr;

	return 0;
}