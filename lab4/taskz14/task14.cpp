//������������ 4, ������ 14. ���������: ������ �.� 153504

/*�� ���� ������� ���� ��� ���� � "����" �������� n*m
��������, ��� ������ '.' �������� ������ �����, � ������ '*' - �����. 
��������� ��������� ��� ���� ������� , ��� � ������������ ����. ���������
������ ����� ������� ����� �.*/

#include <iostream>
#include <iomanip>
#include <ctime>

int main() {

	std::ios_base::sync_with_stdio(0);
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	long double n, m;
	char symbol, number = 49;

	std::cout << "\t����� ���� \"����\"\n\n";

	std::cout << "������� ������ �������� ����: ";
	std::cin >> n;


	while (std::cin.fail() || std::cin.peek() != '\n' || n <= 1 || (long long int)n != n) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\n�� ����� �������� ��������, ������� ������ �����: ";
		std::cin >> n;

	}

	std::cout << "������� ������ �������� ����: ";
	std::cin >> m;

	while (std::cin.fail() || std::cin.peek() != '\n' || m <= 1 || (long long int)m != m) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\n�� ����� �������� ��������, ������� ������ �����: ";
		std::cin >> m;

	}

	n = n + 2;
	m = m + 2;

	char** arr;
	arr = (char**)calloc(n, sizeof(*arr));

	for (int i = 0; i < n; i++) {

		arr[i] = (char*)calloc(m, sizeof(*arr[i]));
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {

				arr[i][j] = '#';
			}
		}
	}

	int choice, bomb = 0;
	bool boom = true;

	std::cout << "��� �� ������ ��������� ������� ����?\n1.��������� �������\n2.��������� ����� ������� rand()\n";
	std::cin >> choice;

	while (std::cin.fail() || std::cin.peek() != '\n' || (choice != 1 && choice != 2)) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\n�� ����� �������� ��������, ������� ������ �����: ";
		std::cin >> choice;

	}

	if (choice == 1) {

		std::cout << "��������� ������� ����(\".\" - ������ �����; \"*\" - �����): \n";

		for (int i = 1; i < n - 1; i++) {

			for (int j = 1; j < m - 1; j++) {

				std::cin >> symbol;

				while (std::cin.fail() || std::cin.peek() != '\n' || (symbol != '.' && symbol != '*')) {

					std::cin.clear();
					std::cin.ignore(99999, '\n');

					std::cout << "\n�� ����� �������� ��������, ������� ���� \".\"\"*\": ";
					std::cin >> symbol;
				}

				if (symbol == '*') {

					arr[i][j] = '*';
				}
				else {

					arr[i][j] = ' ';
				}
			}
		}
	}
	else {

		for (int i = 1; i < n - 1; i++) {

			for (int j = 1; j < m - 1; j++) {

				if (rand() % 2 + 1 == 1 && bomb < (((n - 2) * (m - 2)) / 4) && boom) {

					arr[i][j] = '*';
					bomb++;
					boom = false;
				}
				else {

					arr[i][j] = ' ';
					boom = true;
				}
			}
		}

	}

	std::cout << "\n�������� ����:\n\n";

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			std::cout << arr[i][j] << " ";
		}

		std::cout << "\n";
	}

	for (int i = 1; i < n - 1; i++) {

		for (int j = 1; j < m - 1; j++) {

			if (arr[i][j] == '*') {

				if (arr[i][j + 1] == ' ') {

					arr[i][j + 1] = number;
				}
				else if (arr[i][j + 1] != '#' && arr[i][j + 1] != '*') {

					arr[i][j + 1] += 1;
				}

				if (arr[i][j - 1] == ' ') {

					arr[i][j - 1] = number;
				}
				else if (arr[i][j - 1] != '#' && arr[i][j - 1] != '*') {

					arr[i][j - 1] += 1;
				}

				if (arr[i + 1][j] == ' ') {

					arr[i + 1][j] = number;
				}
				else if (arr[i + 1][j] != '#' && arr[i + 1][j] != '*') {

					arr[i + 1][j] += 1;
				}

				if (arr[i - 1][j] == ' ') {

					arr[i - 1][j] = number;
				}
				else if (arr[i - 1][j] != '#' && arr[i - 1][j] != '*') {

					arr[i - 1][j] += 1;
				}

				if (arr[i - 1][j - 1] == ' ') {

					arr[i - 1][j - 1] = number;
				}
				else if (arr[i - 1][j - 1] != '#' && arr[i - 1][j - 1] != '*') {

					arr[i - 1][j - 1] += 1;
				}

				if (arr[i + 1][j + 1] == ' ') {

					arr[i + 1][j + 1] = number;
				}
				else if (arr[i + 1][j + 1] != '#' && arr[i + 1][j + 1] != '*') {

					arr[i + 1][j + 1] += 1;
				}

				if (arr[i - 1][j + 1] == ' ') {

					arr[i - 1][j + 1] = number;
				}
				else if (arr[i - 1][j + 1] != '#' && arr[i - 1][j + 1] != '*') {

					arr[i - 1][j + 1] += 1;
				}

				if (arr[i + 1][j - 1] == ' ') {

					arr[i + 1][j - 1] = number;
				}
				else if (arr[i + 1][j - 1] != '#' && arr[i + 1][j - 1] != '*') {

					arr[i + 1][j - 1] += 1;
				}
			}
		}
	}

	std::cout << "\n\n���� ����� ���������� ����:\n\n";

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			std::cout << arr[i][j] << " ";
		}

		std::cout << "\n";
	}

	for (int i = 0; i < n; i++) {

		free(arr[i]);
	}

	free(arr);

	return 0;
}