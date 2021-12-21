//Лабораторная 7, задача 3. Выполнена: Киселёв А.В. 153504

/*Осуществить сложение чисел. Разработать функции для
выполнения операции сложения. Предусмотреть ввод положительных и
отрицательных чисел.
8. Найдите сумму двоичных чисел, заданных в естественной форме.
Сложение выполните в дополнительном коде. Ответ выразите в прямом
коде.*/

#include <iostream>
#include <string>


void Swap(std::string& two) {
	for (int j = 0, j1 = two.length() - 1; j < two.length() / 2; j++, j1--)
		std::swap(two[j], two[j1]);
}

std::string to_dva(std::string s, std::string two, int t, int k, int c) {
	while(true) {
		for (int u = 0; u < s.length() - 1; u++) {
			if (s[u] == '0') {
				k = 0;
			}
			else {
				k = 1;
				break;
			}
		}
		if (s[s.length() - 1] == '1' && !k) {
			two += '1';
			break;
		}
		if (s[s.length() - 1] == '0' && !k) {
			two += '0';
			break;
		}

		for (int e = 0; e < s.length(); e++) {
			c = s[e] - '0';
			if (c % 2) {
				c = (c + t * 10) / 2;
				s[e] = c + '0';
				t = 1;
			}
			else {
				c = (c + t * 10) / 2;
				s[e] = c + '0';
				t = 0;
			}
			if (e == s.length() - 1) {
				if (t) two += '1';
				else  two += '0';
				t = 0;
			}
		}
	}

	Swap(two);

	return two;
}

std::string after_dot(std::string s, std::string s2, std::string two) {
	s2.erase(0, s2.find('.') + 1);
	if (s2.length() > 10) s2.erase(8, s2.length() - 1);
	s.erase(s.find('.'), s.length());
	two = to_dva(s, two, 0, 0, 0);
	two += '.';
	int size = s2.length() - 1;
	double dota = 0;
	for (int d = 0; d < s2.length(); d++) dota += pow(10, size--) * (s2[d] - '0');
	size = s2.length();
	for (int d = 0; d < 10; d++) {
		dota *= 2;
		if (dota - pow(10, size) > 0) {
			two += '1';
			dota -= pow(10, size);
		}
		else two += '0';
	}
	return two;
}

bool cin_string(std::string& s, char* minus, int p, bool& dot) {
	getline(std::cin, s);

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
			dot++;
		}
		while (p > 1) {
			std::cout << "Неверное значение!\n";
			return 0;
		}
	}

	for (int e = 0; e < s.length(); e++) {
		while ((s[e] < '0' || s[e]>'9') && s[e] != '.') {
			std::cout << "Неверное значение!\n";
			return 0;
		}
	}

	return 1;
}

std::string dop_code(std::string two, char* minus) {
	if (minus[0] == '0')
		return two;
	std::string s, s2;
	int tt = 0, z;
	if (two[1] == ',') {
		tt = 1;
		if (two[0]) z = 1;
		else z = 0;
		two.erase(0, 2);
	}
	Swap(two);

	two.erase(10, 1);
	s += '1';

	int dot = 10;
	if (two.find('1') > 9)two.erase(0, 10);
	else {
		dot = two.find('1');
		two.erase(0, dot);
	}

	for (int y = 0; y < two.length(); y++) {
		if (two[y] == '0') two[y] = '1';
		else two[y] = '0';
	}

	for (int y = 0, n = 0; y < two.length(); y++) {
		s += '0';
		n = 1;
	}

	int c;
	bool t = 0;
	for (int y = 0; y < two.length(); y++) {
		c = two[y] + s[y] - 2 * '0' + t;
		if (c < 2) {
			s2 += c + '0';
			t = 0;
		}
		else {
			s2 += '0';
			t = 1;
		}
	}
	s = "";
	for (int y = 0; y < dot; y++) s += '0';
	s2 = s + s2;
	s2.insert(10, ".");
	Swap(s2);
	if (tt) {
		if (z) s2.insert(0, "1");
		else s2.insert(0, "0");
		s2.insert(1, ",");
	}
	return s2;
}

bool cin_to_dop(std::string& s, std::string& dva) {
	bool dot = 0;
	char minus[] = "0";

	if (!cin_string(s, minus, 0, dot)) return 0;
	dva = after_dot(s, s, dva);
	dva = dop_code(dva, minus);
	dva.insert(0, minus);
	dva.insert(1, ",");
	return 1;
}

std::string suma(std::string two, std::string two2) {
	std::string s;
	two.erase(1, 1);
	two2.erase(1, 1);

	Swap(two);
	Swap(two2);

	two.erase(10, 1);
	two2.erase(10, 1);

	if (two.length() > two2.length())
		for (int y = 0, y1 = two.length() - two2.length(); y < y1; y++)
			two2 += '0';
	if (two.length() < two2.length())
		for (int y = 0, y1 = two2.length() - two.length(); y < y1; y++)
			two += '0';

	bool t = 0;
	int c;
	s = "";
	for (int y = 0; y < two.length(); y++) {
		c = two[y] + two2[y] - 2 * '0' + t;
		switch (c) {
		case 2:
			s += '0';
			t = 1;
			break;
		case 3:
			s += '1';
			t = 1;
			break;
		default:
			s += c + '0';
			t = 0;
			break;
		}
	}
	s.insert(10, ".");
	Swap(s);
	s.insert(1, ",");
	return s;
}

int main() {

	setlocale(LC_ALL, "ru");
	std::string s, two, s2, two2;

	if (!cin_to_dop(s, two))
		return 0;

	if (!cin_to_dop(s2, two2)) 
		return 0;

	s = suma(two, two2);

	char minus[2];
	minus[0] = s[0];

	s = dop_code(s, minus);

	std::cout << s << '\n';

	return 0;
}