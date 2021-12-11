// Лабораторная 6, задача 2. Выполнена: Киселёв А.В 153504

/*. Рассматривать строки как указатель типа char.
8. Из текста удалить все слова заданной длины, начинающиеся с
согласных букв. */

#include <iostream>

//65 69 73 79 85 89 97 101 105 111 117 121 -- ASCII

void delete_char(char* text, int lenght_text, int lenght_delete) {
	bool space = true, str = false;
	int start = 0, stop = 0, number = 0;

	for (int i = 0; i <= lenght_text; i++) {
		if (space && (text[i] != 65 && text[i] != 69 && text[i] != 73 && text[i] != 79 && text[i] != 85 && text[i] != 89 && text[i] != 97 && text[i] != 101 && text[i] != 105 && text[i] != 111 && text[i] != 117 && text[i] != 121)) {
			start = i;
			str = true;
			space = false;
			number = 0;
		}

		if (text[i] == ' ' || lenght_text == i) {
			space = true;

			stop = i;

			if (number == lenght_delete) {
				for (start; start <= stop; start++) {
					text[start] = '~';
				}
			}
		}

		if (str) {
			number++;
		}
	}

	std::cout << "Строка после удаления слов: ";

	for (int i = 0; i < lenght_text; i++) {
		if (text[i] != '~') {
			std::cout << text[i];
		}
	}

	putchar('\n');

	

}

int expp(int x) {
	if (x == 0)
		return 1;
	else
		return 10 * exp(x - 1);
}

int main() {
	setlocale(LC_ALL, "ru");

	int max_lenght = 2, lenght_text = 0, lenght_delete = 0;;
	char* text = (char*)malloc(max_lenght * sizeof(char));

	std::cout << "Введите текст: ";
	for (lenght_text; '\n' - (text[lenght_text] = getchar()); lenght_text++) {
		if (max_lenght - 1 == lenght_text) {
			text = (char*)realloc(text, (max_lenght *= 2) * sizeof(char));
		}
	}

	text = (char*)realloc(text, (lenght_text + 1) * sizeof(char));
	text[lenght_text] = '\0';

	std::cout << "Введите размер слов, которые вы хотите удалить: ";
	std::cin >> lenght_delete;

	while (std::cin.fail() || std::cin.peek() == '\0' || lenght_delete <= 0||lenght_delete>45) {
		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "Ошибка!Попробуйте ввести другое значение: ";
		std::cin >> lenght_delete;
	}

	delete_char(text, lenght_text, lenght_delete);

	free(text);
	text = NULL;
	
	return 0;
}

