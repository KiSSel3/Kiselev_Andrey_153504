#include <iostream>
#include <string>

int exp(int x) {
    if (x == 0)
        return 1;
    else
        return 10 * exp(x - 1);
}

int main() {
    setlocale(LC_ALL, "ru");

    std::string word;
    std::cout << "¬ведите строку: ";
    std::getline(std::cin, word);

    int count = 0, num_exp = 0;;
    bool minus = false, minus_exp = false;
    double number = 0, answer = 0;

    while (count < word.length()) {
        number = 0;
        num_exp = 0;
        minus = false;
        minus_exp = false;

        if (isdigit(word[count])) {
            if (count > 0 && word[count - 1] == '-')
                minus = true;
            
                number = word[count] - '0';

            while (isdigit(word[++count]))
                number = number * 10 + word[count] - '0';

            if (word[count] == '.' && isdigit(word[count + 1])) {
                for (int i = 1; isdigit(word[++count]); i++)
                    number += double(word[count] - '0') / exp(i);
            }

            if (tolower(word[count]) == 'e' && (isdigit(word[count + 1]) || (word[count + 1] == '+' && isdigit(word[count + 2])) || (word[count + 1] == '-' && isdigit(word[count + 2])))) {
                if (word[++count] == '-') {
                    minus_exp = true;
                    count++;
                }
                else if (word[count] == '-')
                    count++;

                num_exp = word[count] - '0';

                while (isdigit(word[++count]))
                    num_exp = num_exp * 10 + word[count] - '0';

                if (minus_exp)
                    num_exp *= -1;

                number *= pow(10, num_exp);
            }

            if (minus)
                number *= -1;

            answer += number;    
        }

        count++;
    }

    std::cout << "—умма всех чисел равна: " << answer;
    putchar('\n');

    return 0;
}
