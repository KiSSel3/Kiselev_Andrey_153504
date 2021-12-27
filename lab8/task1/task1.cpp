//Лабораторная 8, задача 1. Выполнена: Киселёв А.В 153504

/*. Для книг, хранящихся в библиотеке, задаются регистрационный номер
книги, автор, название, год издания, издательство, количество страниц. Вывести
список книг с фамилиями авторов, изданных после заданного года (сортировка
Шелла по возрастанию).
*/

#include <iostream>
#include <string>

struct book {
	int number;
	std::string author;
	std::string name;
	int year;
	std::string publisher;
	long long int pages;
};

void ShellSort(book* lib, int size) {

	int i, j, step;
	int tmp;
	book buff;

	for (step = size / 2; step > 0; step /= 2) {
		for (i = step; i < size; i++) {
			tmp = lib[i].year;
			buff = lib[i];

			for (j = i; j >= step; j -= step) {
				if (tmp < lib[j - step].year)
					lib[j] = lib[j - step];
				else
					break;
			}

			lib[j] = buff;
		}
	}
}

void symbol(int size) {
	printf("\n\n");
	for (int i = 0; i < size; i++)
		printf("______________________________");
	printf("\n\n");
}


void show(book* lib,int size,int start) {	
	for (int i = start; i < size; i++) {
		printf("\n\nРегистрационный номер книги: %d", lib[i].number);
		std::cout << "\n\tАвтор: " << lib[i].author;
		std::cout << "\n\tНазвание: " << lib[i].name;
		printf("\n\tГод издания: %d", lib[i].year);
		std::cout << "\n\tИздательство: " << lib[i].publisher;
		printf("\n\tКоличество страниц: %lld", lib[i].pages);
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	int choice = 1;

	printf("Введите количество книг: ");
	int size = 0;
	scanf_s("%d", &size);

	while (size < 1) {
		rewind(stdin);
		printf("Вы ввели неверное значение.Повторите попытку: ");
		scanf_s("%d", &size);
	}

	book* lib = new book[size];

	for (int i = 0;choice; i++) {
		printf("\nРегистрационный номер %d книги: ",i+1);
		scanf_s("%d", &lib[i].number);
		rewind(stdin);

		while (lib[i].number<0) {			
			printf("Вы ввели неверное значение.Повторите попытку: ");
			scanf_s("%d", &lib[i].number);
			rewind(stdin);
		}

		printf("\tАвтор книги: ");
		getline(std::cin, lib[i].author);
		rewind(stdin);
		
		printf("\tНазвание книги: ");
		getline(std::cin, lib[i].name);
		rewind(stdin);

		printf("\tГод издания: ");
		scanf_s("%d", &lib[i].year);
		rewind(stdin);

		while (lib[i].year < 0|| lib[i].year > 2021) {
			printf("Вы ввели неверное значение.Повторите попытку: ");
			scanf_s("%d", &lib[i].year);
			rewind(stdin);
		}

		printf("\tИздательство: ");
		getline(std::cin, lib[i].publisher);
		rewind(stdin);

		printf("\tКоличество страниц: ");
		scanf_s("%lld", &lib[i].pages);
		rewind(stdin);


		symbol(4);

		printf("Хотите продолжить ввод книг в массив?(1/0): ");
		scanf_s("%d",&choice);

		while (choice != 1 && choice != 0) {			
			printf("Вы ввели неверное значение.Повторите попытку: ");
			scanf_s("%d", &choice);
			rewind(stdin);
		}

		
		if (i + 1 >= size&&choice) {
			book* buff = new book[size+1];

			for (int i = 0; i < size; i++) {
				buff[i] = lib[i];
			}
						
			lib = buff;

			size++;
		}
		else if (i < size && !choice) {

			size = i + 1;
		}
	}
	
	printf("Список книг:");
	show(lib, size, 0);
		
	int sort = 0;
	printf("\n\nВведите год, после которого были изданы интересующие вас книги: ");
	scanf_s("%d", &sort);
	rewind(stdin);

	ShellSort( lib, size);

	int i = 0;
	for (i;i<size;i++){
		if (lib[i].year >= sort)
			break;
	}

	printf("Список книг после заданного года:");
	show(lib, size, i);
	

	putchar('\n');

	return 0;
}

