#include  <iostream>
#include <ctime>

int main() {

	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	const int SIZE = 5;
	double arr[SIZE];
	double max, min;
	bool start = false;
	bool start1 = false;

	for (int i = 0; i < SIZE; i++) {

		arr[i] = rand() % 99;
	}

	std::cout << "������ ��� ������� ����������� � ������������ �������� �������\n�������� ������: ";

	for (int i = 0; i < SIZE; i++) {

		std::cout << arr[i] << "  ";
	}

	max = arr[0];
	min = arr[0];

	for (int i = 0; i < SIZE; i++) {

		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
	}

	std::cout << "������ ����� ��������������: ";

	for (int i = 0; i < SIZE; i++) {

		if (max != arr[i] && min != arr[i]) {

			std::cout << arr[i] << "  ";
		}

	}

	std::cout << std::endl;

	return 0;
}
