//������������ 8, ������ 1. ���������: ������ �.� 153504

/*. ��� ����, ���������� � ����������, �������� ��������������� �����
�����, �����, ��������, ��� �������, ������������, ���������� �������. �������
������ ���� � ��������� �������, �������� ����� ��������� ���� (����������
����� �� �����������).
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
		printf("\n\n��������������� ����� �����: %d", lib[i].number);
		std::cout << "\n\t�����: " << lib[i].author;
		std::cout << "\n\t��������: " << lib[i].name;
		printf("\n\t��� �������: %d", lib[i].year);
		std::cout << "\n\t������������: " << lib[i].publisher;
		printf("\n\t���������� �������: %lld", lib[i].pages);
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	int choice = 1;

	printf("������� ���������� ����: ");
	int size = 0;
	scanf_s("%d", &size);

	while (size < 1) {
		rewind(stdin);
		printf("�� ����� �������� ��������.��������� �������: ");
		scanf_s("%d", &size);
	}

	book* lib = new book[size];

	for (int i = 0;choice; i++) {
		printf("\n��������������� ����� %d �����: ",i+1);
		scanf_s("%d", &lib[i].number);
		rewind(stdin);

		while (lib[i].number<0) {			
			printf("�� ����� �������� ��������.��������� �������: ");
			scanf_s("%d", &lib[i].number);
			rewind(stdin);
		}

		printf("\t����� �����: ");
		getline(std::cin, lib[i].author);
		rewind(stdin);
		
		printf("\t�������� �����: ");
		getline(std::cin, lib[i].name);
		rewind(stdin);

		printf("\t��� �������: ");
		scanf_s("%d", &lib[i].year);
		rewind(stdin);

		while (lib[i].year < 0|| lib[i].year > 2021) {
			printf("�� ����� �������� ��������.��������� �������: ");
			scanf_s("%d", &lib[i].year);
			rewind(stdin);
		}

		printf("\t������������: ");
		getline(std::cin, lib[i].publisher);
		rewind(stdin);

		printf("\t���������� �������: ");
		scanf_s("%lld", &lib[i].pages);
		rewind(stdin);


		symbol(4);

		printf("������ ���������� ���� ���� � ������?(1/0): ");
		scanf_s("%d",&choice);

		while (choice != 1 && choice != 0) {			
			printf("�� ����� �������� ��������.��������� �������: ");
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
	
	printf("������ ����:");
	show(lib, size, 0);
		
	int sort = 0;
	printf("\n\n������� ���, ����� �������� ���� ������ ������������ ��� �����: ");
	scanf_s("%d", &sort);
	rewind(stdin);

	ShellSort( lib, size);

	int i = 0;
	for (i;i<size;i++){
		if (lib[i].year >= sort)
			break;
	}

	printf("������ ���� ����� ��������� ����:");
	show(lib, size, i);
	

	putchar('\n');

	return 0;
}

