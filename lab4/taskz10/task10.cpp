//Лабораторная 4, задача 10. Выполнена: Киселёв А.В 153504

/*Построить магический квадрат любого порядка, используя любой
алгоритм. Выделение памяти через функции языка С.*/

#include <iostream>
#include <iomanip>

#define ll long long int

int main() {

    std::ios_base::sync_with_stdio(0);
    setlocale(LC_ALL, "ru");

    long double size;

    std::cout << "Данный код строит магический квадрат порядка n.\n\nВведите n: ";
    std::cin >> size;

    while (std::cin.fail() || std::cin.peek() != '\n' || size <= 0 || (long long int)size != size) {

        std::cin.clear();
        std::cin.ignore(99999, '\n');

        std::cout << "\nВы ввели неверное значение, попробуйте ввести целое положительное число: ";
        std::cin >> size;
    }

    ll n = size;

    int** msquare;

    msquare = (int**)calloc(n, sizeof(*msquare));

    for (ll i = 0; i < n; i++) {

        msquare[i] = (int*)calloc(n, sizeof(*msquare[i]));
    }

    ll i;
    ll j;

    if (n % 2 == 1) {

        i = 0;
        j = n / 2;

        msquare[i][j] = 1;

        for (ll g = 2; g < n * n + 1; g++) {

            if (i - 1 >= 0 && j - 1 >= 0 && msquare[i - 1][j - 1] == 0) {

                msquare[i - 1][j - 1] = g;
                i--;
                j--;
            }
            else if (i - 1 >= 0 && j - 1 >= 0 && msquare[i - 1][j - 1] != 0) {

                msquare[i + 1][j] = g;
                i++;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {

                msquare[n - 1][j - 1] = g;
                i = n - 1;
                j--;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {

                msquare[i - 1][n - 1] = g;
                i--;
                j = n - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && msquare[n - 1][n - 1] != 0) {

                msquare[i + 1][j] = g;
                i++;
            }
        }
    }
    else if (n % 4 == 0) {

        ll m = 1;

        int** ssquare;

        ssquare = (int**)malloc(n * sizeof(int*));

        for (int i = 0; i < n; i++) {

            ssquare[i] = (int*)malloc(n * sizeof(int));
        }

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                msquare[i][j] = m;
                m++;
            }
        }

        m = n * n;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                ssquare[i][j] = m;
                m--;
            }
        }

        m = (n / 4) * (n / 4);

        ll g = 1; j = 0; i = 0;

        while (g++ < m + 1) {

            ll y = i;
            ll x = j;

            while (y < i + 4) {

                msquare[y][x] = ssquare[y][x];
                y++;
                x++;
            }

            y = i + 3;
            x = j;

            while (x < i + 4) {

                msquare[y][x] = ssquare[y][x];
                y--;
                x++;
            }

            if (j + 4 < n) {

                j += 4;
            }
            else if (j + 4 >= n) {

                j = 0;
                i += 4;
            }
        }

        for (long long int i = 0; i < n; i++) {

            free(ssquare[i]);
        }

        free(ssquare);
    }
    else if (n == 1) {

        std::cout << "\nМагический квадрат:\n\t1\n";
    }
    else if (n == 2) {

        std::cout << "\nМагического квадрата порядка 2 не существует!";
    }
    else {

        ll size = n / 2;

        int** square1;
        square1 = (int**)calloc(size, sizeof(*square1));

        for (ll i = 0; i < size; i++) {

            square1[i] = (int*)calloc(size, sizeof(*square1[i]));
        }

        int** square2;
        square2 = (int**)calloc(size, sizeof(*square2));

        for (ll i = 0; i < size; i++) {

            square2[i] = (int*)calloc(size, sizeof(*square2[i]));
        }

        int** square3;
        square3 = (int**)calloc(size, sizeof(*square3));

        for (ll i = 0; i < size; i++) {

            square3[i] = (int*)calloc(size, sizeof(*square3[i]));
        }

        int** square4;
        square4 = (int**)calloc(size, sizeof(*square4));

        for (ll i = 0; i < size; i++) {

            square4[i] = (int*)calloc(size, sizeof(*square4[i]));
        }

        ll max1 = n * n / 4;
        ll max2 = n * n / 2;
        ll max3 = n * n / 4 * 3;
        ll max4 = n * n;

        ll k = 1;

        i = 0; j = size / 2;
        square1[i][j] = k++;


        while (k < max1 + 1) {

            if (i - 1 > -1 && j - 1 > -1 && square1[i - 1][j - 1] == 0) {

                square1[i - 1][j - 1] = k;
                i--;
                j--;
            }
            else if (i - 1 > -1 && j - 1 > -1 && square1[i - 1][j - 1] != 0 && i + 1 < size) {

                square1[i + 1][j] = k;
                i++;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {

                square1[size - 1][j - 1] = k;
                i = size - 1;
                j--;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {

                square1[i - 1][size - 1] = k;
                i--;
                j = size - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && square1[size - 1][size - 1] != 0 && i + 1 < size) {

                square1[i + 1][j] = k;
                i++;
            }

            k++;
        }

        i = 0; j = size / 2;
        square4[i][j] = k++;

        while (k < max2 + 1) {

            if (i - 1 > -1 && j - 1 >= 0 && square4[i - 1][j - 1] == 0) {

                square4[i - 1][j - 1] = k;
                i--;
                j--;
            }
            else if (i - 1 >= 0 && j - 1 >= 0 && square4[i - 1][j - 1] != 0 && i + 1 < size) {

                square4[i + 1][j] = k;
                i++;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {

                square4[size - 1][j - 1] = k;
                i = size - 1;
                j--;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {

                square4[i - 1][size - 1] = k;
                i--;
                j = size - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && square4[size - 1][size - 1] != 0 && i + 1 < size) {

                square4[i + 1][j] = k;
                i++;
            }

            k++;
        }

        i = 0; j = size / 2;
        square2[i][j] = k++;

        while (k < max3 + 1) {

            if (i - 1 >= 0 && j - 1 >= 0 && square2[i - 1][j - 1] == 0) {

                square2[i - 1][j - 1] = k;
                i--;
                j--;
            }
            else if (i - 1 >= 0 && j - 1 >= 0 && square2[i - 1][j - 1] != 0 && i + 1 < size) {

                square2[i + 1][j] = k;
                i++;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {

                square2[size - 1][j - 1] = k;
                i = size - 1;
                j--;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {

                square2[i - 1][size - 1] = k;
                i--;
                j = size - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && square2[size - 1][size - 1] != 0 && i + 1 < size) {

                square2[i + 1][j] = k;
                i++;
            }

            k++;
        }

        i = 0; j = size / 2;
        square3[i][j] = k++;

        while (k < max4 + 1) {

            if (i - 1 >= 0 && j - 1 >= 0 && square3[i - 1][j - 1] == 0) {

                square3[i - 1][j - 1] = k;
                i--;
                j--;
            }
            else if (i - 1 >= 0 && j - 1 >= 0 && square3[i - 1][j - 1] != 0 && i + 1 < size) {

                square3[i + 1][j] = k;
                i++;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {

                square3[size - 1][j - 1] = k;
                i = size - 1;
                j--;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {

                square3[i - 1][size - 1] = k;
                i--;
                j = size - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && square3[size - 1][size - 1] != 0 && i + 1 < size) {

                square3[i + 1][j] = k;
                i++;
            }

            k++;
        }

        ll ret;

        ret = square1[0][0];
        square1[0][0] = square3[0][0];
        square3[0][0] = ret;

        ll y = 1;

        while (y < size - 1) {

            ret = square1[y][1];
            square1[y][1] = square3[y][1];
            square3[y][1] = ret;

            y++;
        }

        k = (n - 2) / 4 - 1;

        if (k > 0) {

            while (k > 0) {

                for (ll i = 0; i < size; i++) {

                    ret = square1[i][size - k];
                    square1[i][size - k] = square3[i][size - k];
                    square3[i][size - k] = ret;

                    ret = square2[i][k - 1];
                    square2[i][k - 1] = square4[i][k - 1];
                    square4[i][k - 1] = ret;                           
                }

                k--;
            }
        }

        for (int i = 0; i < size; ++i) {

            for (int j = 0; j < size; ++j) {

                msquare[i][j] = square1[i][j];

                msquare[i][j + size] = square2[i][j];

                msquare[i + size][j] = square3[i][j];

                msquare[i + size][j + size] = square4[i][j];
            }
        }

        for (long long int i = 0; i < size; i++) {

            free(square1[i]);
        }

        free(square1);

        for (long long int i = 0; i < size; i++) {

            free(square2[i]);
        }

        free(square2);

        for (long long int i = 0; i < size; i++) {

            free(square3[i]);
        }

        free(square3);

        for (long long int i = 0; i < size; i++) {

            free(square4[i]);
        }

        free(square4);
    }

    if (n > 2) {

        std::cout << "\nМагический квадрат:\n\n";

        for (int i = 0; i < n; ++i) {

            for (int j = 0; j < n; ++j) {

                if (n < 100) {

                    std::cout << std::setw(4) << msquare[i][j] << " ";
                }
                else {

                    std::cout << std::setw(10) << msquare[i][j] << " ";
                }
            }

            std::cout << std::endl;
        }


    }

    for (ll i = 0; i < n; i++) {

        free(msquare[i]);
    }

    free(msquare);

    return 0;
}