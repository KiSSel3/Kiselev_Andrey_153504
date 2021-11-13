//������������ 4, ������ 6. ���������: ������ �.� 153504

/*��� �������� ������� � ����������� NxM ��������� ������� � ������ �� �������,
�������� ������� �������� ��������� ���������: ������� B[i,j] ����� ������������� �� ��������� ������� �,
������������� ����� � ���� ������� (i,j), ������� ������� (i,j).
��� ���� ���������, ��� ������� (1,1) - ������� ����� ������� �������.*/

#include <iostream>
#include <iomanip>

long double inputCheck(long double& x) {

	while (std::cin.fail() || std::cin.peek() != '\n' || x <= 0 || (long long int)x != x) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\n�� ����� �������� ��������, ������� ������ �����: ";
		std::cin >> x;

	}

	return x;
}

long double inputCheckArr(long double x) {

	while (std::cin.fail() || std::cin.peek() != '\n' || (long long int)x != x) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\n�� ����� �������� ��������, ������� ������ �����: ";
		std::cin >> x;

	}

	return x;
}

int main() {

	setlocale(LC_ALL, "ru");
	std::ios_base::sync_with_stdio(0);

	long double n, m;
	int max;

	std::cout << "������ ��� ����������� �������� ������� �� ���������� ��������: \n������� B[i,j] ����� ������������� �� ��������� ������� �,\n������������� ����� � ���� �������(i, j), ������� �������(i, j)\n\n";

	std::cout << "������� ���������� ������� � ����� �������: ";
	std::cin >> n;
	inputCheck(n);

	std::cout << "������� ���������� �������� � ����� �������: ";
	std::cin >> m;
	inputCheck(m);

	int** arr = new int* [n];

	for (int i = 0; i < n; i++) {

		arr[i] = new int[m];
	}

	std::cout << "��������� �������� ������� " << n << "�" << m << " (���� �� ������ �������):\n";

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			std::cin >> arr[i][j];
			inputCheckArr(arr[i][j]);
		}
	}

	system("cls");
	std::cout << "�������� �������: \n\n";

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			std::cout << std::setw(4) << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << "\n������� ����� ���������:\n\n";

	int** arr2 = new int* [n];

	for (int i = 0; i < n; i++) {

		arr2[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			max = 0;

			for (int a = 0; a <= i; a++) {

				for (int b = 0; b <= j; b++) {

					if (arr[a][b] > max) {

						max = arr[a][b];
					}
				}
			}

			arr2[i][j] = max;
		}
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			std::cout << std::setw(4) << arr2[i][j] << " ";
		}

		std::cout << std::endl;
	}

	for (int i = 0; i < n; i++) {

		delete arr[i];
	}

	for (int i = 0; i < n; i++) {

		delete arr2[i];
	}

	delete[] arr;
	delete[] arr2;

	return 0;
}