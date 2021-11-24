//������������ 5, ������ 2. ���������: ������ �.� 153504

/*��� 8:
��� ��������� ����������� ������� X �� N ��������� ���������, ��� ��� ����
��������� ������� ����������� ������� cos Xi > 0. ����������� ������� ���������
������ ��� �������� ��� ������ ����� ������� � ��� ��������� ����� (2/3) �������.
����������� ������ �����������, ����� ��������� ������ ���� ��� ��� ��������.*/


#include <iostream>

void validation(long double& x) {

	while (std::cin.fail() || std::cin.peek() != '\n' || x <= 0 || (int)x != x) {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\n������ �����! ��������� �������: ";
		std::cin >> x;
	}

	return;
}

void arr_validation(double x) {

	while (std::cin.fail() || std::cin.peek() != '\n') {

		std::cin.clear();
		std::cin.ignore(99999, '\n');

		std::cout << "\n������ �����! ��������� �������: ";
		std::cin >> x;
	}
	std::cout << std::endl;
	return;
}  

void recursion(long double mas[], long long int &N,long long int end) {

	if (cos(mas[N]) > 0) std::cout << N + 1 << "-� ������� ������� ������������� �������\n";
	if (N == end) {
		N++;
		return;
	}

	recursion(mas, ++N, end);
}

int main() {

	setlocale(LC_ALL, "ru");
	std::ios_base::sync_with_stdio(0);
	
	long double n;

	std::cout << "������� ������ �������: ";
	std::cin >> n;
	validation(n);

	long double* X = new long double[n];

	std::cout << "\n��������� ������:\n";
	for (long long int i = 0, g = 1; i < n; i++, g++) {

		std::cout << g << ": ";
		std::cin >> X[i];
		arr_validation(X[i]);
	}

	long long int N = 0;

	if (long long int(n / 3) != 1)  recursion(X, N, n / 3 - 1);
	else  if (cos(X[N]) > 0) std::cout << ++N << "-� ������� ������� ������������� �������\n";


	recursion(X, N, n - 2);//-2 �.� ��������� ������� �� ��������������

	if (cos(X[N]) > 0) std::cout << N + 1 << "-� ������� ������� ������������� �������\n";

	delete X;

	return 0;
}