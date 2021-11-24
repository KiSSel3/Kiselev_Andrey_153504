//������������ 5, ������ 3.3. ���������: ������ �.� 153504

/*��� ��������� ������������ ������ ����� �����. �������� ��������� �������
������� ������ � ����������. ������� ������������ ������ �� ���������,
������������� � ������ �������� ������� ������� � ������� �������� ��������.
��������� ������� �������������� ��������� ������������� �������.
������� ��������� �� �����.
������������ �������.*/

#include <iostream>

void validation(long double& x) {

	while (std::cin.fail() || std::cin.peek() != '\n' || x <= 0 || (long long int)x != x) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\n������ �����! ��������� �������: ";
		std::cin >> x;
	}

	return;
}

void arr_validation(long double x) {

	while (std::cin.fail() || std::cin.peek() != '\n' || (long long int)x != x) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\n������ �����! ��������� �������: ";
		std::cin >> x;
	}
	std::cout << std::endl;
	return;
}

long long int arithmetic_mean(long long int x[], long long int size) {

	long long int s = 0;

	for (long long int i = 0; i < size; i++) {

		s += x[i];
	}

	return s / size;
}

int main() {

	setlocale(LC_ALL, "ru");
	std::ios_base::sync_with_stdio(0);

	long double sizen = 0, sizem = 0;

	std::cout << "������� ������ ���������� �������\n���������� �����: ";
	std::cin >> sizen;
	validation(sizen);

	std::cout << "\n���������� ��������: ";
	std::cin >> sizem;
	validation(sizem);

	long long int n = sizen, m = sizem;

	long double** arr = new long double* [n];

	for (int i = 0; i < n; i++) {

		arr[i] = new long double[m];
	}

	std::cout << "\n��������� ��������� ������:\n";
	for (long long int i = 0, g = 1; i < n; i++) {

		for (long long int j = 0; j < m; j++, g++) {

			std::cout << g << ": ";
			std::cin >> arr[i][j];
			arr_validation(arr[i][j]);
		}
	}

	long long int size = 0, g = 0;

	long long int* arr1 = new long long int;

	for (long long int i = 0; i < n; i++) {

		for (long long int j = 0; j < m; j++) {

			if (j!=0&&j % 2 == 0 && long long int(arr[i][j]) % 2 == 1) {

				long long int* arr2 = new long long int[++size];

				for (long long i = 0; i < size; i++) {

					arr2[i] = arr1[i];
				}

				delete arr1;
				arr1 = arr2;

				arr1[g] = arr[i][j];
				g++;
			}
		}
	}

	std::cout << "\n�������� ������:\n";

	for (long long int i = 0; i < n; i++) {

		for (long long int j = 0; j < m; j++) {

			std::cout << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}
	std::cout << "\n����� ������:\n";

	for (long long int i = 0; i < g; i++) {

		std::cout << arr1[i] << " ";
	}

	std::cout << "\n������� �������������� ������ ������� ��������� " << arithmetic_mean(arr1, g) << std::endl;

	for (long long int i = 0; i < n; i++) {

		delete arr[i];
	}

	delete[] arr;
	delete arr1;

	return 0;
}