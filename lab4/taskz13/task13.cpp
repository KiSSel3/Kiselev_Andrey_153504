#include <iostream>

long double sum(long double n) {

	if (n == 0) {

		return 1;
	}
	else {

		return n + sum(n - 1);
	}
}

int main() {

	std::ios_base::sync_with_stdio(0);
	setlocale(LC_ALL, "ru");

	long double n;

	std::cout << "������� ���������� ��������� �����������: ";
	std::cin >> n;

	while (std::cin.fail() || std::cin.peek() != '\n' || n < 0 || (long long int)n != n) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\n�� ����� �������� ��������, ���������� ������ ����� ������������� �����: ";
		std::cin >> n;
	}

	std::cout << "���� ���� ���������� �������� " << n << " �����������, � ���� ��������� " << sum(n - 1) << " �������.\n";

	return 0;
}