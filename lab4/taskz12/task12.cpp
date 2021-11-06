//������������ 4, ������ 12. ���������: ������ �.� 153504

/*�������� ������� ������� ����� ������� ��������� ���������
�� �������. ������� ���������: ������, ������ �������. ��������
���������: ����� ������, ����� ������.*/

#include <iostream>

void remove(int* arr, long double& size);

int main() {

	setlocale(LC_ALL, "ru");

	long double size;

	std::cout << "\t������ ��� ������� ��������� ��������� �� ��������� �������\n\n";

	std::cout << "������� ���������� ��������� �������: ";
	std::cin >> size;

	while (std::cin.fail() || std::cin.peek() != '\n' || size <= 0 || size > 99 || (long long int)size != size) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\n�� ����� �������� ��������, ���������� ������ ����� ������������� �����: ";
		std::cin >> size;
	}

	int* arr = new int[size];

	std::cout << "��������� �������� ������: \n";

	for (int i = 0; i < size; i++) {

		std::cout << "������� " << i + 1 << "  ���� �������: ";
		std::cin >> arr[i];

		while (std::cin.fail() || std::cin.peek() != '\n' || (long long int)arr[i] != arr[i]) {

			std::cin.clear();
			std::cin.ignore(99999, '\n');

			std::cout << "�� ����� �������� ��������, ���������� ������ ����� ������������� �����: ";
			std::cin >> arr[i];
		}
	}

	std::cout << "�������� ������, �������� " << size << ": \n";

	for (int i = 0; i < size; i++) {

		std::cout << arr[i] << " ";
	}
	std::cout << "\n\n\n";
		
	remove(arr, size);
	
	delete arr;

	return 0;
}

void remove(int* arr, long double &size) {

	int duplicates = 0;

	for (int i = size-1; i >= 0; i--) {

		for (int j = i + 1; j < size-1; j++) {

			if (arr[i] == arr[j]) {

				duplicates++;
				break;
			}
		}
	}

	int size2 = size - duplicates;

	int* arr2 = new int[size];

	bool yes = true;

	arr2[0] = arr[0];

	int g = 1;
	
	for (int i = 1; i < size; i++, yes = true) {

		for (int j = i - 1; j >= 0; j--) {

			if (arr[i] == arr[j]) {

				yes = false;
				break;
			}
		}

		if (yes) {

			arr2[g] = arr[i];
			g++;
		}
	}

	int* arr3 = new int[g];

	for (int i = 0; i < g; i++) {

		arr3[i] = arr2[i];
	}

	std::cout << "������ ����� �������� ������������� ��������(������ ������� ������� ����� " << g << "): \n";

	for (int i = 0; i < g; i++) {

		std::cout << arr3[i] << " ";
	}
	std::cout << "\n\n\n";
	
	delete arr2;
	delete arr3;

	return;
}

