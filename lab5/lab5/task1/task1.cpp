//������������ 5, ������ 1. ���������: ������ �.� 153504

/*��� 8:
��������� ��������� ��� ���������� ����������� �������� �����������
������������� ������� S = (S1, S2, �, Sm), ��� ������ ������� Sj ��������� �� ������� S+=Aij(if i <=n)
������������ �������.
����������� �������� n = 3, m = 4 ������ � ����������.*/

#include <iostream>
#include <Windows.h>

void validation(double& x) {

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

void arr_output(long double S[], long long int size) {

	std::cout << "��������� ������:\n";

	for (long long i = 0; i < size; i++) {

		std::cout << S[i] << " ";
	}
}

int main() {
	
	setlocale(LC_ALL, "ru");
	std::ios_base::sync_with_stdio(0);

	double n = 0, m = 0;

	std::cout << "������� ������ ���������� �������\n���������� �����: ";
	std::cin >> n;
	validation(n);

	std::cout << "\n���������� ��������: ";
	std::cin >> m;
	validation(m);

	double** arr = new double* [n];

	for (int i = 0; i < n; i++) {

		arr[i] = new double[m];
	}

	std::cout << "\n��������� ��������� ������:\n";
	for (int i = 0, g = 1; i < n; i++) {

		for (int j = 0; j < m; j++, g++) {

			std::cout << g << "\\" << m * n << ": ";
			std::cin >> arr[i][j];
			arr_validation(arr[i][j]);
		}
	}

	long long int size = n * m;
	long double* S = new long double[size];

	long long int sum = 0;

	for (int i = 0, g = 0; i < n; i++) {

		for (int j = 0; j < m; j++, g++) {

			sum += arr[i][j];
			S[g] = sum;
		}
	}

	arr_output(S, size);

	HINSTANCE load;
	load = LoadLibrary(L"dinlib.dll");
	typedef long double (*min) (long double S[], long long int size);
	min Min = (min)GetProcAddress(load, "Min");

	std::cout << "\n���������� ������� ������� ������� ��������� " << Min(S, size) << std::endl;

	FreeLibrary(load);
	
	for (int i = 0; i < n; i++) {

		delete arr[i];
	}

	delete[] arr;

	return 0;
}
