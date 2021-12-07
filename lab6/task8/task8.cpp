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
		std::cout << "Некорректный ввод.Повторите попытку: " << std::endl;
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	int num = 0;
	std::cout << "Введите количество наборов строк: ";
	std::cin >> num;
	while (std::cin.fail() || num <= 0) {
		std::cin.clear();
		std::cin.ignore(99999, '\n');
		std::cout << "Некорректный ввод.Повторите попытку: " << std::endl;
		std::cin >> num;
	}

	std::string str1;
	std::string str2;

	int* answer = new int[num];

	int count = 0, chip = -1, num_str2 = 0;
	while (count < num) {

		std::cout << "\nЗаполните первую строку: ";
		str1 = input(0, 501);

		std::cout << "\nЗаполните вторую строку: ";
		str2 = input(0, 1000);

		chip = -1, num_str2 = 0;

		for (int i = 0; i < str1.length(); i++) {
			if (str1[i] == str2[num_str2]) {
				chip = i;
				num_str2++;
				break;
			}
		}

		while (chip < str1.length()-1) {
			if (str1[chip + 1] == str2[num_str2]) {
				chip++;
				num_str2++;
			}
			else
				break;
		}

		while (chip > 0&& num_str2 != str2.length()) {
			if (str1[chip - 1] == str2[num_str2]) {
				chip--;
				num_str2++;
			}
			else
				break;
		}

		if (num_str2 == str2.length())
			answer[count++] = 1;
		else
			answer[count++] = 0;

	}

	for (int i = 0; i < num; i++) {
		if (answer[i] == 1)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

	delete answer;
	return 0;
}