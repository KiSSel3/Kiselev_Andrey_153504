// Лабораторная 6, задача 7. Выполнена: Киселёв А.В 153504

/*В заданной строке S найти максимальную по длине подстроку, которая
не является палиндромом.
Формат входных данных:
На вход задается строка S, состоящая из строчных букв латинского
алфавита (1 ? |S| ? 105 ).
Формат выходных данных:
Выведите одно целое число — длина максимального непалиндрома.
Если такой подстроки не существует, то выведите -1.*/

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
		std::cout << "Некоректный ввод!Попробуйте ещё раз: " << std::endl;
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	std::string str;
	std::cout << "Введите исходную строку: ";
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