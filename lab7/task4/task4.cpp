//Лабораторная 7, задача 4. Выполнена: Киселёв А.В 153504

/*Осуществить сложение и вычитание чисел в заданной системе
счисления. В другую систему счисления не переводить. В системах
счисления больших десятичной использовать буквы по аналогии с
шестнадцатеричной системой. Разработать функции для выполнения
операции сложения и функции для выполнения операции вычитания.
Предусмотреть ввод положительных и отрицательных чисел.

8) в одиннадцатеричной*/

#include <iostream>
#include <string>


void Swap(std::string& two) {
	for (int j = 0, j1 = two.length() - 1; j < two.length() / 2; j++, j1--)
		std::swap(two[j], two[j1]);
}

bool cin_string(std::string& s, char* minus) {
	getline(std::cin, s);
	int p = 0;

	if (s.find('.') == -1) {
		s.insert(s.length(), ".");
		s.insert(s.length(), "0000000000");
	}

	if (s[0] == '-') {
		minus[0] = '1';
		s.erase(0, 1);
	}
	for (int e = 0; e < s.length(); e++) {
		if (s[e] == '.' || s[0] == '.' || s[s.length() - 1] == '.') {
			p++;
		}
		while (p > 1) {
			std::cout << "Неверное значение!\n";
			return 0;
		}
	}
	for (int e = 0; e < s.length(); e++) {
		while ((s[e] < '0' || s[e]>'9') && s[e] != '.' && s[e] != 'A') {
			std::cout << "Неверное значение!\n";
			return 0;
		}
	}
	return 1;
}

bool cin_to_dop(std::string& s) {
	char minus[] = "0";

	if (!cin_string(s, minus)) return 0;
	if (minus[0] == '1') s = '-' + s;
	return 1;
}

std::string suma(std::string two, std::string two2) {
	std::string s;

	Swap(two);
	Swap(two2);

	two.erase(10, 1);
	two2.erase(10, 1);
	two += '0';
	two2 += '0';
	if (two.length() > two2.length())
		for (int y = 0, y1 = two.length() - two2.length(); y < y1; y++)
			two2 += '0';
	if (two.length() < two2.length())
		for (int y = 0, y1 = two2.length() - two.length(); y < y1; y++)
			two += '0';

	int c, t = 0, dv, dv2;
	s = "";
	for (int y = 0; y < two.length(); y++) {
		if (two[y] == 'A') dv = 10;
		else dv = two[y] - '0';
		if (two2[y] == 'A') dv2 = 10;
		else dv2 = two2[y] - '0';
		c = dv + dv2 + t;
		if (c < 10) {
			s += c + '0';
			t = 0;
			continue;
		}
		if (c == 10) {
			s += 'A';
			t = 0;
			continue;
		}
		c--;
		if (c > 10) {
			s += c + '0' - 10;
			t = 1;
			continue;
		}
		if (c == 10) {
			s += '0';
			t = 1;
			continue;
		}
	}
	s.insert(10, ".");
	Swap(s);
	while (s[0] == '0') s.erase(0, 1);
	if (s[0] == '.') s.insert(0, "0");
	return s;
}

std::string min(std::string two, std::string two2) {
	std::string s;

	Swap(two);
	Swap(two2);

	two.erase(10, 1);
	two2.erase(10, 1);
	two += '0';
	two2 += '0';
	if (two.length() > two2.length())
		for (int y = 0, y1 = two.length() - two2.length(); y < y1; y++)
			two2 += '0';
	if (two.length() < two2.length())
		for (int y = 0, y1 = two2.length() - two.length(); y < y1; y++)
			two += '0';

	int c, t = 0, dv, dv2;
	s = "";
	for (int y = 0; y < two.length(); y++) {
		if (two[y] == 'A') dv = 10;
		else dv = two[y] - '0';
		if (two2[y] == 'A') dv2 = 10;
		else dv2 = two2[y] - '0';
		c = dv - dv2 - t;
		if (c >= 0) {
			s += c + '0';
			t = 0;
			continue;
		}
		else c = 11 + c;
		if (c == 10) {
			s += 'A';
			t = 1;
			continue;
		}
		if (c >= 0) {
			s += c + '0';
			t = 1;
			continue;
		}
	}
	s.insert(10, ".");
	Swap(s);
	while (s[0] == '0') s.erase(0, 1);
	if (s[0] == '.') s.insert(0, "0");
	return s;
}

int main() {
	setlocale(LC_ALL, "ru");

	std::string s, s3, s2;

	if (!cin_to_dop(s)) return 0;
	if (!cin_to_dop(s2)) return 0;
	s3 = suma(s, s2);
	
	std::cout << "\nСумма: " << s3;
	s3 = min(s, s2);
	std::cout << "\n\nВычетание: " << s3;

	return 0;
}