#include <iostream>

long long int pow(long long int y) {

	long double s = 1;

	while (y > 0) {

		s = s * 10;
		y--;
	}

	return s;

}

int main() {

	setlocale(LC_ALL, "ru");

	long double n, n1;
	long long length = 1;
	std::cout << "Введите натуральное число: ";
	std::cin >> n;

	while (std::cin.fail() || std::cin.peek() != '\n' || n <= 0 || (long long int)n != n) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nВы ввели неверное значение, попробуйте ввести целое положительное число: ";
		std::cin >> n;
	}

	n1 = n;

	while (long long int(n1 /= 10) != 0) {

		length++;
	}

	int* arr = new int[length];

	for (int i = 1; i <= length; i++) {

		arr[length - i] = long long int(n / pow(length - i)) % 10;
	}

	std::cout << "\nВ числе " << (long long int)n << " кол-во цифр равняется " << length << std::endl;


	std::cout << "\nВведите разряд, под которым вы хотите узнать цифру(разряды нумеруются с концаp[единицы - 0]): ";
	std::cin >> n1;//переопределение n1, n1 == разряду числа;

	while (std::cin.fail() || std::cin.peek() != '\n' || n1<0 || n1>length - 1 || (long long int)n1 != n1) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nВы ввели неверное значение, повторите попытку: ";
		std::cin >> n1;
	}

	std::cout << "В числе " << (long long int) n << " под разрядом " << n1 << " находиться цифра " << arr[(long long int)n1] << std::endl;

	delete arr;

	return 0;
}