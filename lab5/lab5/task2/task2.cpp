#include <iostream>

long long int count1 = 0, count2 = 0, index = 0;

void validation(long double& x) {

	while (std::cin.fail() || std::cin.peek() != '\n' || x <= 0 || (int)x != x) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nОшибка ввода! Повторите попытку: ";
		std::cin >> x;
	}

	return;
}

void arr_validation(double x) {

	while (std::cin.fail() || std::cin.peek() != '\n') {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\nОшибка ввода! Повторите попытку: ";
		std::cin >> x;
	}
	std::cout << std::endl;
	return;
}

/*long double recursion(long double x[], long long int size) {

	if (cos(x[size]) > 0 && size > 0) {

		count1++;
		return recursion(x, size - 1);
	}
	else if (size > 0) {

		return  recursion(x, size - 1);
	}
	else {

		return count1;
	}
}

long double recursion(long double x[], long long int size,long long y) {

	if (cos(x[size]) > 0 && size > y) {

		count2++;
		return recursion(x, size - 1);
	}
	else if (size > 0) {

		return  recursion(x, size - 1);
	}
	else {

		return count2;
	}
}*/

long double recursion(long double x[], long long int size) {

	if (cos(x[index]) > 0 && index < size) {

		count1++;
		return recursion(x, index++);
	}
	else if (index < size) {

		return recursion(x, index++);
	}
	else return count1;
}

int main() {

	setlocale(LC_ALL, "ru");
	std::ios_base::sync_with_stdio(0);

	long double n;

	std::cout << "Введите размер массива: ";
	std::cin >> n;
	validation(n);
	
	long double* X = new long double[n];

	std::cout << "\nЗаполните массив:\n";
	for (long long int i = 0, g = 1; i < n; i++,g++) {

		std::cout << g << ": ";
		std::cin >> X[i];
		arr_validation(X[i]);
	}

	std::cout << "Условие выполняется для " << recursion(X, n)/*+ recursion(X, n, ((n - 1) / 3) - 1)*/ << " элементов массива!";

	return 0;
}