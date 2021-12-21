//������������ 7, ������ 6. ���������: ������ �.� 153504

/*�� ����� �������� ����� � ����������, ���� S(x + 1) < S(x).
1 <= x <= n.n - �����.��������� ���������� � �����, ��� � - ����������.*/

#include <iostream>

long double input(double min, double max) {
	long double x;
	while (true) {
		std::cin >> x;
		if (!std::cin.fail() && std::cin.peek() == '\n' && x <= max && x >= min)
			return x;
		std::cin.clear();
		std::cin.ignore(99999, '\n');
		std::cout << "������ �����!�������� ������ ��������: " << std::endl;
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	std::cout << "������� ���������� ������� ������: ";
	int count = input(1, 1e9);

	while (count-- != 0) {
		std::cout << "������� ����� �����[1;10^9]: ";
		int x = input(1, 1e9);

		int num = x / 10;

		if (x % 10 == 9)

			num++;

		std::cout << "���������� ���������� " << num << '\n';
	}

	return 0;
}