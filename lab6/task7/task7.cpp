// ������������ 6, ������ 7. ���������: ������ �.� 153504

/*� �������� ������ S ����� ������������ �� ����� ���������, �������
�� �������� �����������.
������ ������� ������:
�� ���� �������� ������ S, ��������� �� �������� ���� ����������
�������� (1 ? |S| ? 105 ).
������ �������� ������:
�������� ���� ����� ����� � ����� ������������� ������������.
���� ����� ��������� �� ����������, �� �������� -1.*/

#include <iostream>
#include <string>

std::string input(int min, int max) {
	std::string text;
	while (true) {
		std::cin >> text;
		if (text.length() < max && text.length() > min)
			return text;
		std::cin.clear();
		std::cin.ignore(32000, '\n');
		text = "";
		std::cout << "����������� ����!���������� ��� ���: " << std::endl;
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	std::string str;
	std::cout << "������� �������� ������: ";
	str = input(1, 105);

	bool palindrome = true;
	bool identical = true;

	for (int i = 0, j = str.length() - 1; i < j; i++, j--) {
		if (str[i] != str[j])
			palindrome = false;
	}

	for (int i = 0, j = 1; j < str.length(); i++, j++) {
		if (str[i] != str[j])
			identical = false;
	}


	if (identical)
		std::cout << -1 << std::endl;
	else if (palindrome)
		std::cout << str.length() - 1 << std::endl;
	else
		std::cout << str.length() << std::endl;

	return 0;
}