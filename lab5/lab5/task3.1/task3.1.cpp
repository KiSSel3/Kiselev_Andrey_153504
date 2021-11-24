//������������ 5, ������ 3.1. ���������: ������ �.� 153504

/*��� ��������� ������������ ������ ����� ����� � ������������ n x k .
����������� ������� (n = 5, k = 6) ������ � ����������. �������� ��������� �������
������ � ����������. ������� ������������ ������ �� ���������, ������������� ��
������� ��������� ������� � ������� ������ ��������. ��������� ������������
��������� ������������� �������.
��������� ������ � ��������� ������������ ������� �� �����.
������������ �������.*/

#include <iostream>

void validation(double& x) {

	while (std::cin.fail() || std::cin.peek() != '\n' || x <= 0 || (int)x != x) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\n������ �����! ��������� �������: ";
		std::cin >> x;
	}

	return;
}

void arr_validation(double x) {

	while (std::cin.fail() || std::cin.peek() != '\n'|| (long long int)x != x) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\n������ �����! ��������� �������: ";
		std::cin >> x;
	}
	std::cout << std::endl;
	return;
}

long double sum(long long int x[],long long int size) {

	long double s = 0;

	for (long long i = 0; i < size; i++) {

		s += x[i];
	}

	return s;
}

int main() {

	setlocale(LC_ALL, "ru");
	std::ios_base::sync_with_stdio(0);

	double n = 0, m = 0;

	std::cout << "������� ������ ���������� �������\n���������� �����: ";
	std::cin >> n;
	validation(n);

	std::cout << "\n���������� ��������: ";
	std::cin >> m;
	validation(m);

	double** arr = new double* [n];

	for (int i = 0; i < n; i++) {

		arr[i] = new double[m];
	}

	std::cout << "\n��������� ��������� ������:\n";
	for (int i = 0, g = 1; i < n; i++) {

		for (int j = 0; j < m; j++, g++) {

			std::cout << g << "\\" << m * n << ": ";
			std::cin >> arr[i][j];
			arr_validation(arr[i][j]);
		}
	}

	long long size = 0;

	long long int min = (n < m) ? n : m;

	for (long long i = 0; i < min; i++) {

		if (long long(arr[i][i]) % 2 == 0) size++;
	}

	long long int* diog = new long long[size];

	for (long long i = 0, g = 0; i < min; i++) {

		if (long long int (arr[i][i]) % 2 == 0) {

			diog[g] = arr[i][i];
			g++;
		}
	}

	std::cout << "������ �� ��������� ������� �� ������� ��������� � ������x ������ ��������:\n";

	for (int i = 0; i < size; i++) {

		std::cout << diog[i] << " ";
	}

	std::cout << std::endl;

	std::cout << "\n����� ������ ������� ����� " << sum(diog, size) << std::endl;

	return 0;
}
