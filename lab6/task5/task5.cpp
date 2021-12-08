#include<iostream>
#include<string>

int input(int min, int max) {
	int x = 0;
	while (true){
		std::cin >> x;
		if (x <= max && x >= min)
			return x;
		std::cin.clear();
		std::cin.ignore(99999, '\n');
		std::cout << "ќшибка ввода!¬веддите другое значение: " << std::endl;
	}
}

int func(int l, int m, std::string s1, std::string s2) {
	int num_repit = 0;

	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == s2[num_repit]) {
			for (int j = i; j < s1.length(); j++) {
				if (s1[j] == s2[num_repit])
					num_repit++;
				else {
					num_repit = 0;
					break;
				}
			}
		}
	}

	int power = l - s1.length() - s2.length() + num_repit;

	if (power > 0) return  int(pow(26, power) * 2) % m;
	else if (power == 0) return 1;
	else return 0;
}

int main() {
	setlocale(LC_ALL, "ru");
	
	int num = 0;
	std::cout << "¬ведите количество наборов входных данных: ";
	num = input(1, 100);

	while (num-- > 0) {
		std::cout << "\n¬ведите длинну искомой строки: ";
		int lenght = 0;
		lenght = input(1, 1e9);

		std::cout << "¬ведите модуль, по которому вы хотите получить ответ: ";
		int mod = 0;
		mod = input(1, 1e4);

		std::cin.ignore(32767, '\n');
		std::string s1, s2;
		
		std::cout << "¬ведите первую строку: ";
		std::getline(std::cin, s1);

		std::cout << "¬ведите вторую строку: ";
		std::getline(std::cin, s2);

		putchar('\n');
		std::cout << func(lenght, mod, s1, s2);
	}

	putchar('\n');
	return 0;
}