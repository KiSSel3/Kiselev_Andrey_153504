//������������ 5, ������ ��� 3. ���������: ������ �.� 153504

/*����� f(n) - ���������� �������� �������� ������������ ����� n. �� ���������
������������ n ���������� ��������� �������� ����� f(1) + f(2) + ... + f(n).*/


#include <iostream>

void validation(long long int& x) {

	while (std::cin.fail() || std::cin.peek() != '\n' || (long long int)x != x || x > 1e9) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\n������ �����! ��������� �������: ";
		std::cin >> x;
	}

	return;
}

long long int F(long  long int n) {

	long long sum = 0;

	for (long long int i = 1; i <= n; i++) {

		long long int f = i;

		while (f % 2 == 0) {

			f /= 2;
		}

		sum += f;
	}

	return sum;
}

int main() {

	setlocale(LC_ALL, "ru");
	std::ios_base::sync_with_stdio(0);

	long long int n = 0;
	char stop = 'y';
		
	while (stop == 'y') {

		system("cls");

		std::cout << "������� �������� ��� ��������: ";

		std::cin >> n;
		validation(n);
		
		long long sum = 0;

		for (long long int i = 1; i <= n; i++) {

			long long int f = i;

			while (f % 2 != 0) {

				f /= 2;
			}

			sum += f;
		}

		std::cout << "�������� ����� f(1) + f(2) + ... + f(" << n << ") ��������� " << F(n) << "\n\n";

		std::cout << "������� 'y' ����� ���������� ���� ������ ��� ������� ����� ������ ������ ����� ����������: ";
		std::cin >> stop;
	}

	return 0;
}