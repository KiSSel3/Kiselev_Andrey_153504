// ������������ 6, ������ 6. ���������: ������ �.� 153504

/*���������� ����� ���������� ����� ������������ ���� ���� �����.
��������, �� ����� SOLO ����� �������� 12 ��������: SOLO, LOSO,
OSLO, OLSO, OSOL, OLOS, SLOO, LSOO, OOLS, OOSL, LOOS,
SOOL.
�������� ���������, ������� ������� ���������� ���������
��������, ������� ����� ���������� �� ����� �����. */


#include <iostream>
#include <string>

long long int fact(int x) {
    if (x == 0) return 1;
    else return x * fact(x - 1);
}

int anagram(std::string str) {
    int count;
    long long answer = fact(str.length());

    while (str.length()) {
        count = 1;

        for (int i = 1; i < str.length(); ++i) {
            if (str[i] == str[0]) {
                ++count;

                str.erase(i--, 1);
            }
        }

        str.erase(0, 1);

        answer /= fact(count);
    }

    return answer;
}

int main() {
    setlocale(LC_ALL, "ru");

    std::string input;

    std::cout << "������� �����, ��� ���������� ���-�� ��������: ";
    std::getline(std::cin, input);

    std::cout << "\n���������� ��������: " << anagram(input);
    putchar('\n');

    return 0;
}