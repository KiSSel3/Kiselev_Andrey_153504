//������������ 4, ������ 3. ���������: ������ �.� 153504

/*������ ��� ������� �������� �����������.
8 ���: 
����������, �������� �� �������� ������������� ���������� ������� �������� N �����������������, �.�. �����,
� ������� ��������� ������������ ������ ���� ���������� ����� ����� 0, � ��������� ������������ ������ ������ �� ���� ����� 1 */


#include <iostream>
#include <iomanip>

int main() {

	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	long double N;
	long long int s1 = 0, s2 = 0;

	std::cout << "\t������ ��� ����������, �������� �� �������� ������� �����������������\n\n";

	std::cout << "������� ������ ���������� ������� N: ";
	std::cin >> N;

	while (std::cin.fail() || std::cin.peek() != '\n' || N <= 1 || (long long int)N != N) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\n�� ����� �������� �������� N, ���������� ������ ����� ������������� �����: ";
		std::cin >> N;

	}

	int** arr = new int* [N];

	for (int i = 0; i < N; i++) {

		arr[i] = new int[N];
	}

	std::cout << "��������� ���������� ������� �������� " << N << " (������� ����������� ����� �������, ������ ����; �������� �� ������ ��������):\n";

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			std::cin >> arr[i][j];

			while (std::cin.fail() || std::cin.peek() != '\n' || (long long int)arr[i][j] != arr[i][j]) {

				std::cin.clear();
				std::cin.ignore(99999, '\n');

				std::cout << "\n�� ����� �������� ��������, ���������� ������ ����� �����: ";
				std::cin >> arr[i][j];

			}
		}
	}

	system("cls");

	std::cout << "���� �������:\n";

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			std::cout << std::setw(3) << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N - 1; j++) {

			s1 += arr[i][j] * arr[i][j + 1];
		}
	}

	for (int j = 0; j < N; j++) {

		for (int i = 0; i < N; i++) {

			s2 += arr[i][j] * arr[i][j];
		}
	}

	if (s1 == 0 && s2 == 3) {

		std::cout << "�������� ������� �������� �����������������!\n";
	}
	else {

		std::cout << "�������� ������� �� �������� �����������������!\n";
	}

	for (int i = 0; i < N; i++) {

		delete arr[i];
	}

	delete[] arr;

	return 0;
}