// Лабораторная 6, задача 5. Выполнена: Киселёв А.В 153504

/*Во многих прикладных задачах, таких как поиск в сети или расшифровка
генома, требуется совершать некоторые действия со строками. Например,
часто требуется по некоторым данным о строке восстановить ее саму.
Вам даны две строки S1 и S2. Известно, что одна из них была суффиксом
искомой строки S, а другая — ее префиксом. Также известна длина искомой
строки L, а также то, что строка S состояла только из строчных букв
латинского алфавита.
Необходимо определить число строк, удовлетворяющих этим
ограничениям. Так как это число может быть достаточно большим, то
необходимо вывести его по модулю m. */

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
		std::cout << "Ошибка ввода!Введдите другое значение: " << std::endl;
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
	std::cout << "Введите количество наборов входных данных: ";
	num = input(1, 100);

	while (num-- > 0) {
		std::cout << "\nВведите длинну искомой строки: ";
		int lenght = 0;
		lenght = input(1, 1e9);

		std::cout << "Введите модуль, по которому вы хотите получить ответ: ";
		int mod = 0;
		mod = input(1, 1e4);

		std::cin.ignore(32767, '\n');
		std::string s1, s2;
		
		std::cout << "Введите первую строку: ";
		std::getline(std::cin, s1);

		std::cout << "Введите вторую строку: ";
		std::getline(std::cin, s2);

		putchar('\n');
		std::cout << func(lenght, mod, s1, s2);
	}

	putchar('\n');
	return 0;
}