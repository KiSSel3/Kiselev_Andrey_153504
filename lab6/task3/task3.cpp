#include <iostream>

int input_choice() {
	int x = 0;
	std::cin >> x;

	while (std::cin.fail() || std::cin.peek() != '\n' || x < 1 || x>4) {
		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "Ошибка ввода!Повторите попытку: ";
		std::cin >> x;
	}

	return x;
}

double input() {
	double x = 0;
	std::cin >> x;

	while (std::cin.fail() || std::cin.peek() != '\n') {
		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "Ошибка ввода!Повторите попытку: ";
		std::cin >> x;
	}

	return x;

}

int text_int(char* text,int lenght_text) {
	if (lenght_text > 10) {
		std::cout << "\nЧисло слишком большое!\n";
		return 0;
	}

	bool error = false;
	bool minus = false;

	int start = (text[0] == '-' || text[0] == '+') ? 1 : 0;
	int answer = 0;

	for (int i = start; i < lenght_text; i++) {
		if (text[i] < 48 || text[i] > 57) {
			error = true;
			break;
		}
	}

	if (error) {
		std::cout << "Вы ввели не целое число!\n";
		return 0;
	}

	if (text[0] == '-')
		minus = true;

	answer = text[start] - '0';

	for (int i = start + 1; i < lenght_text; i++)
		answer = answer * 10 + text[i] - '0';
	
	if (minus)
		answer *= -1;

	return answer;
}

void int_text(int x) {
	int power = 1;
	int start = 0;

	while (abs(x) / pow(10, power) > 1)
		power++;

	int lenght = (x > 0) ? power : power + 1;

	char* text = new char[lenght+1 * sizeof(char)];
	text[lenght] = '\0';

	if (x < 0)
		text[start++] = '-';

	for (start; start < lenght; start++)
		text[start] = int(abs(x) / pow(10, --power)) % 10 + '0';

	std::cout << "Полученная строка: " << text;
	putchar('\n');

	free(text);
}

double text_double(char* text, int lenght_text) {
	if (lenght_text > 8) {
		std::cout << "\nСишком много символов!(>8)";
		return 0;
	}

	bool error = false;
	bool minus = false;

	int start = (text[0] == '-' || text[0] == '+') ? 1 : 0;
	double answer = 0;
	int answer1 = 0;
	int dot = 0, place_dot = -1;

	for (int i = 0; i < lenght_text; i++) {
		if (text[i] == '.') {
			dot++;
			place_dot = i;
		}

		if (dot > 1)
			error = true;
	}

	for (int i = start; i < lenght_text; i++) {
		if ((text[i] < 48 || text[i] > 57) && text[i] != '.') {
			error = true;
			break;
		}
	}

	if (error || place_dot == -1) {
		std::cout << "Вы ввели не дробное число!\n";
		return 0;
	}

	if (text[0] == '-')
		minus = true;

	answer1 = text[start] - '0';

	for (int i = start + 1; text[i]!='.'; i++)
		answer1 = answer1 * 10 + text[i] - '0';

	double doub = 0;

	for (int i = place_dot + 1, step = 1; i < lenght_text; i++, step++)
		doub += (text[i] - '0') / pow(10, step);
		
	answer = answer1 + doub;

	if (minus)
		answer *= -1;

	return answer;

}

void doub_text(double x) {
	int integer = abs(x);
	double doub = abs(x) - integer;
	int count_doub = 0;

	int power = 2;
	int start = 0;

	while ((doub * pow(10, count_doub) != int(doub * pow(10, count_doub))) && count_doub < 6)
		count_doub++;

	while (abs(x) / pow(10, power) > 1)
		power++;

	int lenght = (x > 0) ? power : power + 1;

	char* text = new char[(lenght + count_doub + 1) * sizeof(char)];
	text[lenght + count_doub] = '\0';

	if (x < 0)
		text[start++] = '-';

	for (start; start < lenght; start++)
		text[start] = int(abs(integer) / pow(10, --power)) % 10 + '0';

	text[start++] = '.';

	

	for (int step = 1; start < count_doub+lenght; start++, step++)
		text[start] = int(doub * pow(10, step)) % 10 + '0';

	std::cout << "Полученная строка: " << text;
	putchar('\n');

	free(text);	
}

int main() {
	setlocale(LC_ALL, "ru");

	int choice = 0;
	std::cout << "Данный код выполняет следующие действия:\n1.Переводит строку в целое число.\n2.Переводит целое число в строку.\n3.Переводит дробное число в строку.\n4.Переводит строку в дробное число.\n\nВыберите действие, которое хотите выполнить: ";
	choice = input_choice();
	std::cin.ignore(99999, '\n');

	if (choice == 1) {
		int answer = 0, max_lenght = 2, lenght_text = 0;
		char* text = (char*)malloc(max_lenght * sizeof(char));

		std::cout << "Введите текст: ";
		for (lenght_text; '\n' - (text[lenght_text] = getchar()); lenght_text++) {
			if (max_lenght - 1 == lenght_text)
				text = (char*)realloc(text, (max_lenght *= 2) * sizeof(char));
		}

		text = (char*)realloc(text, (lenght_text + 1) * sizeof(char));
		text[lenght_text] = '\0';

		answer = text_int(text, lenght_text);

		std::cout << "Полученный ответ: " << answer;
		putchar('\n');
	}
	else if (choice == 2) {
		int integer = 0;
		std::cout << "Введите целое число: ";
		integer = (int)input();
		std::cin.ignore(99999, '\n');

		int_text(integer);
	}
	else if (choice == 3) {
		double doub = 0;
		std::cout << "Введите дробное число: ";
		doub = input();
		std::cin.ignore(99999, '\n');

		if ((int)doub == doub) {
			std::cout<< "Вы ввели целое число!";
			return 0;
		}

		doub_text(doub);
	}
	else if (choice == 4) {
		double answer = 0;
		int max_lenght = 2, lenght_text = 0;

		char* text = (char*)malloc(max_lenght * sizeof(char));

		std::cout << "Введите текст(до 8 символов): ";
		for (lenght_text; '\n' - (text[lenght_text] = getchar()); lenght_text++) {
			if (max_lenght - 1 == lenght_text)
				text = (char*)realloc(text, (max_lenght *= 2) * sizeof(char));
		}

		text = (char*)realloc(text, (lenght_text + 1) * sizeof(char));
		text[lenght_text] = '\0';

		answer = text_double(text,lenght_text);

		std::cout << "Полученный ответ: " << answer;
		putchar('\n');
	}

	return 0;
}