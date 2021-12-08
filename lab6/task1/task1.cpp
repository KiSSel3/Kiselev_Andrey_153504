#include <iostream>

int exp(int x) {
	if (x == 0)
		return 1;
	else
		return 10 * exp(x - 1);
}

int main() {

	setlocale(LC_ALL, "ru");

	char word[81] = { '\0' };
	int start = 0, stop = 0, num = 0;

	std::cout << "Введите строку, в которой вы хотите найти число с плавающей точкой: ";

	int i = 0;
	for (i; ('\n' - (word[i] = getchar()))&&i<=80; i++);
		
	while (i>80) {
		std::cin.clear();
		std::cin.ignore(99999, '\n');
		std::cout << "Ошибка!Попробуйте ввести другие данные: ";

		i = 0;
		for (i; ('\n' - (word[i] = getchar())) && i <= 80; i++);
	}

	/*		  ASCII
		48 - 57  --> 0-9
	*/
	
	int count = 0;
	bool minus = false;
	bool end = false;
	long double number = 0;

	while (count < 80 && word[count] != '\0'&&!end) {
		if (word[count]>=48&& word[count] <= 57) {
			if (count > 0 && word[count - 1] == '-')
				minus = true;

			number = word[count++] - '0';

			while (word[count] >= 48 && word[count] <= 57)
				number = number * 10 + word[count++] - '0';

			if (word[count] == '.' && (word[count+1] >= 48 && word[count+1] <= 57)) {
				count++;
				for (int i = 1; (word[count] >= 48 && word[count] <= 57); i++)
					number += double(word[count++] - '0') / exp(i);						
			}

			if (minus)
				number *= -1;

			if (int(number) != number)
				end = true;
		}

		count++;
	}

	if (!end)
		std::cout << "\nВ данной строке нет числа с плавающей точкой!\n";
	else
		std::cout << "Первое найденное число с плавающей точкой в заданной строке: "<<number;

	putchar('\n');

	return 0;
}