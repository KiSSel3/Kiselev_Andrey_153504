#include <iostream>

int main() {

	setlocale(LC_ALL, "ru");

	char line[80];
	int start = 0, stop = 0, num = 0;

	std::cin >> line;
	std::cout << line << std::endl;

	/*		  ASCII
		48 - 57  --> 0-9
	*/

	bool yes = true;
	bool not_int = false;
	int dot = 0, minus = 0;

	do {

		if (yes && ((line[num] >= 48 && line[num] <= 57) || (line[num] == '-' && (line[num + 1] >= 48 && line[num + 1] <= 57)))) {

			start = num;
			yes = false;
		}

		if (line[num] == '.'&&!yes) {

			not_int = true;
			dot++;
		}

		if (line[num] == '-') {

			minus++;
		}

		if (minus != 0 && minus != 1) {

			start = num;
			minus = 0;
		}
		
		if ((line[num] < 48 || line[num] > 57) && !yes &&start!=num && line[num] != '.') {

			stop = num;
			yes = true;

			if (not_int && dot == 1) break;
			dot = 0;
			stop = start;
		}

	} while (line[num++] != '\0');

	if (stop-start>0) {

		for (int i = start; i <= stop - 1; i++) {

			std::cout << line[i];
		}
	}
	else {

		std::cout << "¬ данной строке нет вещественного числа!";
	}

	std::cout << std::endl;

	return 0;
}