//Лабораторная 7, задача 8. Выполнена: Киселёв А.В 153504

/*Брюс недавно получил работу в NEERC (Numeric Expression Engineering &
Research Center), где изучают и строят много различных любопытных
чисел. Его первым заданием стало исследование двудесятичных чисел.
Натуральное число называется двудесятичным, если его десятичное
представление является суффиксом его двоичного представления; и
двоичное и десятичное представление рассматривается без ведущих
нулей. Например, 1010 = 10102, так что 10 двудесятичное число. Числа
101010 = 11111100102 и 4210 = 1010102 не являются двудесятичными.
Сначала Брюс хочет создать список двудесятичных чисел. Помогите
ему найти n-ое наименьшее двудесятичное число.*/

#include <iostream>
#include <string>

void Swap(std::string& two) {
	for (int j = 0, j1 = two.length() - 1; j < two.length() / 2; j++, j1--)
		std::swap(two[j], two[j1]);
}

std::string toTwo(std::string s, std::string two, int t, int k, int c) {
	while (true) {
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

	for (int j = 0, j1 = two.length() - 1; j < two.length() / 2; j++, j1--)
		std::swap(two[j], two[j1]);

	return two;
}

int main() {
	setlocale(LC_ALL, "ru");

	int h, h2;
	std::string s, two, two2, buf, buf2;

	int input;
	std::cin >> input;
	while (std::cin.fail() || input < 1 || input > 10000) {
		std::cin.clear();
		std::cin.ignore(9999, '\n');
		std::cout << "Вы ввели неверное значение!Повторите попытку: ";
		std::cin >> input;
	}

	s = std::to_string(input);

	if (input == 1) {
		std::cout << 1;
		return 0;
	}
	
	two = toTwo(s, two, 0, 0, 0);
	buf = two;
	buf2 = s;

	Swap(buf);
	Swap(buf2);

	h = two.length();
	h2 = s.length();

	buf.erase(h2, h);

	if (buf2 != buf) {
		std::cout << two;
		return 0;
	}

	two = toTwo(two, two2, 0, 0, 0);
	Swap(two);

	two.erase(0, h2);
	two.erase(h, two.length());

	Swap(two);

	while (two[0] == '0') two.erase(0, 1);
	std::cout << two;

	return 0;
}
