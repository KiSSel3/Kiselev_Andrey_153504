//������������ 7, ������ 2. ���������: ������ �.�. 153504

/*��������� �����. ������������� ���� ������������� �
������������� �����.
 8)�� ��������� ���� � ������������ �����*/

#include <iostream>
#include<string>

int main() {
	setlocale(LC_ALL, "ru");

	std::cout << "������� �������� ��� �����: ";
	std::string Number;
	std::cin >> Number;


	bool minus = false;
	int number = 0;

	int j = 0;

	if (Number[0] == '-') {
		minus = true;
		j = 1;
	}

	for (int i = Number.length() - 1-j; j < Number.length(); j++, i--)
		number += (Number[j] - '0') * pow(2, i);

	if (minus) {
		number *= -1;
	}

	std::cout << number;
	
	return 0;
}