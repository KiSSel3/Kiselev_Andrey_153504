//������������ 8, ������ 2. ���������: ������ �.� 153504

/*��������� ���� ������ ��������� ��������� ����������
������������. �������� � ���������� ��������� ��������: ������������,
����������, ����� ����. ��� ��������� ���� ���������� �������
���������� ���������� ������� �� ������� ������������ � �������
�������� ����������.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

struct Factory {
	std::string name;
	int amount;
	int number;
};

Factory* AddStruct(Factory* factory, int amount) {
	if (amount == 0) {
		factory = new Factory[1]; // ��������� ������ ��� ������ ���������
	}
	else {
		Factory* buff = new Factory[amount + 1];

		for (int i = 0; i < amount; i++) {
			buff[i] = factory[i]; // �������� �� ��������� ������
		}

		delete[] factory;

		factory = buff;
	}
	return factory;
}

void sort(int* array, int size) {
	for (int s = size / 2; s > 0; s /= 2) {
		for (int i = s; i < size; ++i) {
			for (int j = i - s; j >= 0 && array[j] < array[j + s]; j -= s) {
				int temp = array[j];
				array[j] = array[j + s];
				array[j + s] = temp;
			}
		}
	}
}

void setData(Factory* factory, int amount) {
	std::cout << "\n������������: ";
	std::cin >> factory[amount].name;

	std::cout << "����������: ";
	std::cin >> factory[amount].amount;

	std::cout << "����� ����: ";
	std::cin >> factory[amount].number;

	std::cin.get();
	putchar('\n');
}

void sort(Factory* factory, int n) {	
	Factory tmp;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (factory[j].amount < factory[j + 1].amount) {
				tmp = factory[j];
				factory[j] = factory[j + 1];
				factory[j + 1] = tmp;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	std::string fileData;
	std::string fileName = "file.txt";

	std::fstream file;
	file.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);

	if (!file.is_open()) {
		std::cout << "������ �������� �����!";
		return 0;
	}	

	Factory* factory = 0;
	int amount = 0;

	std::cout << "������ ���� ������?\n(Y - ��, U - ���)";
	if (_getch() == 'y') {

		do {
			putchar('\n');

			factory = AddStruct(factory, amount);
			setData(factory, amount++);

			std::cout << "���������� ���� ������?\n(Y - ��, U - ���)";
		} while (_getch() == 'y');

		sort(factory, amount);

		int numFactory;
		std::cout << "\n�������� ����� ����, ������� �� ������ ��������� � ������� �� �����: ";
		std::cin >> numFactory;
		bool existenceFact = false;

		for (int i = 0; i < amount; i++) {
			if (numFactory == factory[i].number) {
				file << "\n";
				std::string s = std::to_string(factory[i].amount);
				fileData = factory[i].name + " " + s + "; ";
				std::cout << fileData;
				file << fileData << "\n";

				existenceFact = true;
			}
		}

		if (!existenceFact)
			std::cout << "\n��� �����������!\n";

		file.close();
	}

	std::cout << "\n\n������� �� ����� ��� ������ � �� ����������?\n(Y - ��, N - ���)\n";
	switch (_getch()) {
	case 'y':
		std::string fileData = "";

		while (!file.eof()) {
			fileData = "";
			std::getline(file, fileData);
			std::cout << fileData << std::endl;
		}

		file.close();
	}

	putchar('\n');	

	return 0;
}