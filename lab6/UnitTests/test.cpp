#include "pch.h"
#include <string>

//test 2
int exp(int x) {
    if (x == 0)
        return 1;
    else
        return 10 * exp(x - 1);
}


//task 2
//std::string delete_char(char* text)
// {
//  int  lenght_text = 3;
//    int lenght_delete = 1;
//    bool space = true, str = false;
//    int start = 0, stop = 0, number = 0;
//
//    for (int i = 0; i <= lenght_text; i++) {
//        if (space && (text[i] != 65 && text[i] != 69 && text[i] != 73 && text[i] != 79 && text[i] != 85 && text[i] != 89 && text[i] != 97 && text[i] != 101 && text[i] != 105 && text[i] != 111 && text[i] != 117 && text[i] != 121)) {
//            start = i;
//            str = true;
//            space = false;
//            number = 0;
//        }
//
//        if (text[i] == ' ' || lenght_text == i) {
//            space = true;
//
//            stop = i;
//
//            if (number == lenght_delete) {
//                for (start; start <= stop; start++) {
//                    text[start] = '~';
//                }
//            }
//        }
//
//        if (str) {
//            number++;
//        }
//    }
//
//    std::string strrr;
//
//    std::cout << "Строка после удаления слов: ";
//
//    int i = 0;
//
//   /* for (i; i < lenght_text; i++) {
//        if (text[i] != '~') {
//            strrr[i] == text[i];
//        }
//    }*/
//
//    strrr = "qqq";
//
//    strrr[3] = '\0';
//    
//
//    return "qqq";
//
//}

// TASK 4

std::string translate(std::string str) {

    long long int num = 0;

    while (num < str.length()) {
        if (str[num] == 'C' && num + 1 < str.length() && (tolower(str[num + 1]) == 'e' || tolower(str[num + 1]) == 'i' || tolower(str[num + 1]) == 'y')) {
            str[num] = 'S';
            continue;
        }
        else if (str[num] == 'c' && num + 1 < str.length() && (tolower(str[num + 1]) == 'e' || tolower(str[num + 1]) == 'i' || tolower(str[num + 1]) == 'y')) {
            str[num] = 's';
            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'Q' && tolower(str[num + 1] == 'u')) {
            str[num] = 'K';
            str[num + 1] = 'v';
            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'q' && tolower(str[num + 1] == 'u')) {
            str[num] = 'q';
            str[num + 1] = 'v';
            continue;
        }
        else if (str[num] == 'c' || str[num] == 'q') {
            str[num] = 'k';
            continue;
        }
        else if (str[num] == 'C' || str[num] == 'Q') {
            str[num] = 'K';
            continue;
        }
        else if (str[num] == 'X') {
            str[num] = 'K';
            str.insert(num + 1, "s");
            continue;
        }
        else if (str[num] == 'x') {
            str[num] = 'k';
            str.insert(num + 1, "s");
            continue;
        }
        else if (str[num] == 'W') {
            str[num] = 'V';
            continue;
        }
        else if (str[num] == 'w') {
            str[num] = 'v';
            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'P' && tolower(str[num + 1] == 'h')) {
            str[num] = 'F';
            str.erase(num + 1, 1);
            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'p' && tolower(str[num + 1] == 'h')) {
            str[num] = 'f';
            str.erase(num + 1, 1);
            continue;
        }
        else if (num + 2 < str.length() && str[num] == 'Y' && tolower(str[num + 1] == 'o') && tolower(str[num + 2] == 'u')) {
            str[num] = 'U';
            str.erase(num + 1, 2);
            continue;
        }
        else if (num + 2 < str.length() && str[num] == 'y' && tolower(str[num + 1] == 'o') && tolower(str[num + 2] == 'u')) {
            str[num] = 'u';
            str.erase(num + 1, 2);
            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'O' && tolower(str[num + 1] == 'o')) {
            str[num] = 'U';
            str.erase(num + 1, 1);
            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'o' && tolower(str[num + 1] == 'o')) {
            str[num] = 'u';
            str.erase(num + 1, 1);
            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'E' && tolower(str[num + 1] == 'e')) {
            str[num] = 'I';
            str.erase(num + 1, 1);
            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'e' && tolower(str[num + 1] == 'e')) {
            str[num] = 'i';
            str.erase(num + 1, 1);
            continue;
        }
        else if (num + 1 < str.length() && str[num] == 'T' && tolower(str[num + 1] == 'h')) {
            str[num] = 'Z';
            str.erase(num + 1, 1);
            continue;
        }
        else if (num + 1 < str.length() && str[num] == 't' && tolower(str[num + 1] == 'h')) {
            str[num] = 'z';
            str.erase(num + 1, 1);
            continue;
        }
        else if (num + 1 < str.length() && tolower(str[num]) == tolower(str[num + 1]) && tolower(str[num]) != 'a' && tolower(str[num]) != 'e' && tolower(str[num]) != 'i' && tolower(str[num]) != 'o' && tolower(str[num]) != 'u' && tolower(str[num]) != 'y') {
            str.erase(num, 1);
            if (num - 1 >= 0)
                num--;

            continue;
        }
        num++;
    }
    return str;
}

//TASK 5

int func(int l, int m, std::string s1, std::string s2) {
    int num_repit = 0;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == s2[num_repit]) {
            for (int j = i; j < s1.length(); j++) {
                if (s1[j] == s2[num_repit])
                    num_repit++;
                else {
                    num_repit = 0;
                    break;
                }
            }
        }
    }

    int power = l - s1.length() - s2.length() + num_repit;

    if (power > 0) return  int(pow(26, power) * 2) % m;
    else if (power == 0) return 1;
    else return 0;
}

//TASK 6

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

//TASK 7

int palindrome(std::string str) {
    bool palindrome = true;
    bool identical = true;

    for (int i = 0, j = str.length() - 1; i < j; i++, j--) {
        if (str[i] != str[j])
            palindrome = false;
    }

    for (int i = 0, j = 1; j < str.length(); i++, j++) {
        if (str[i] != str[j])
            identical = false;
    }


    if (identical)
        return  -1;
    else if (palindrome)
        return str.length() - 1;
    else
        return str.length();
}

//TASK 8

std::string fishka(std::string str1, std::string str2) {


    int count = 0, chip = -1, num_str2 = 0;

    chip = -1, num_str2 = 0;

    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] == str2[num_str2]) {
            chip = i;
            num_str2++;
            break;
        }
    }

    while (chip < str1.length() - 1) {
        if (str1[chip + 1] == str2[num_str2]) {
            chip++;
            num_str2++;
        }
        else
            break;
    }

    while (chip > 0 && num_str2 != str2.length()) {
        if (str1[chip - 1] == str2[num_str2]) {
            chip--;
            num_str2++;
        }
        else
            break;
    }

    if (num_str2 == str2.length())
        return "YES";
    else
        return "NO";
}

//TASK 9

double sum(std::string word) {
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

    return answer;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//TASK 4

int expp(int x) {
    if (x == 0)
        return 1;
    else
        return 10 * exp(x - 1);
}

int text_int(char* text, int lenght_text) {
    if (lenght_text > 10) {
        std::cout << "\nЧисло слишком большое!\n";
        return 0;
    }

    bool error = false;
    bool minus = false;

    int start = (text[0] == '-' || text[0] == '+') ? 1 : 0;
    int answer = 0;

    for (int i = start; i < lenght_text; i++) {
        if (text[i] < 48 || text[i] > 57) {
            error = true;
            break;
        }
    }

    if (error) {
        std::cout << "Вы ввели не целое число!\n";
        return 0;
    }

    if (text[0] == '-')
        minus = true;

    answer = text[start] - '0';

    for (int i = start + 1; i < lenght_text; i++)
        answer = answer * 10 + text[i] - '0';

    if (minus)
        answer *= -1;

    return answer;
}

TEST(test1_1, task1) {

    EXPECT_EQ(100, exp(2));
    EXPECT_TRUE(true);
}

TEST(test1_1, task3) {

    EXPECT_EQ(1, text_int("1",1));
    EXPECT_TRUE(true);
}


TEST(test1_1, task2) {

    EXPECT_EQ(100, expp(2));
    EXPECT_TRUE(true);
}

TEST(test1_2, task2) {

    EXPECT_EQ(10, exp(1));
    EXPECT_TRUE(true);
}

TEST(test1_2, task1) {

    EXPECT_EQ(10, exp(1));
    EXPECT_TRUE(true);
}

TEST(test1_4, task4) {

    EXPECT_EQ("Tu svift for Ziks, tu kvik for Galov,",translate("Too swift for Theex, too quick for Gallow,"));
    EXPECT_TRUE(true);
}

TEST(test2_4, task4) {

    EXPECT_EQ("Tu strong for ung Prinse Josef to folov.", translate("Too strong for young Prince Joseph to follow."));
    EXPECT_TRUE(true);
}

TEST(test3_4, task4) {

    EXPECT_EQ("dudmOnvftentabkozjapHPHF", translate("doodmOnvphtentabcothjapHPHPh"));
    EXPECT_TRUE(true);
}

TEST(test4_4, task4) {

    EXPECT_EQ("BremuokfanzhzhzhzhzhzhzhmuuuuoUUuOOn", translate("BremoookphanzhzhzhzhzhzhzhmoooooooooOoOoooOOn"));
    EXPECT_TRUE(true);
}

TEST(test5_4, task4) {

    EXPECT_EQ("vehkfokvefhlhflkvehmflkehmfl", translate("wehcfoqwefhlhflkwehmflkehmfl"));
    EXPECT_TRUE(true);
}

TEST(test6_4, task4) {

    EXPECT_EQ("f", translate("ffffffffffffffffffffff"));
    EXPECT_TRUE(true);
}

TEST(test7_4, task4) {

    EXPECT_EQ("OOOOOOOOOOOOOOOOOOOOhgH", translate("OOOOOOOOOOOOOOOOOOOOhhgHHHH"));
    EXPECT_TRUE(true);
}

TEST(test8_4, task4) {

    EXPECT_EQ("ksohy polyhit desyat", translate("xohy polyhit desyat"));
    EXPECT_TRUE(true);
}

//TASK 5

TEST(test1_5, task5) {

    EXPECT_EQ(752, func(14, 1000, "cup", "russia"));
    EXPECT_TRUE(true);
}

TEST(test2_5, task5) {

    EXPECT_EQ(0, func(7, 123, "russian", "codecup"));
    EXPECT_TRUE(true);
}

TEST(test3_5, task5) {

    EXPECT_EQ(1, func(7, 15, "codec", "decup"));
    EXPECT_TRUE(true);
}

TEST(test4_5, task5) {

    EXPECT_EQ(0, func(2, 2, "ba", "ab"));
    EXPECT_TRUE(true);
}

//TASK 6

TEST(test1_6, task6) {

    EXPECT_EQ(12, anagram("SOLO"));
    EXPECT_TRUE(true);
}

TEST(test2_6, task6) {

    EXPECT_EQ(1, anagram("QQQQQQQ"));
    EXPECT_TRUE(true);
}

TEST(test3_6, task6) {

    EXPECT_EQ(10, anagram("QQQQQQQQqQ"));
    EXPECT_TRUE(true);
}

TEST(test4_6, task6) {

    EXPECT_EQ(45360, anagram("dsfDFSfds"));
    EXPECT_TRUE(true);
}

//TASK 7

TEST(test1_7, task7) {

    EXPECT_EQ(2, palindrome("aba"));
    EXPECT_TRUE(true);
}

TEST(test2_7, task7) {

    EXPECT_EQ(-1, palindrome("QQQQQQQQQQQQQQ"));
    EXPECT_TRUE(true);
}

TEST(test3_7, task7) {

    EXPECT_EQ(8, palindrome("QQQQqQQQQ"));
    EXPECT_TRUE(true);
}

TEST(test4_7, task7) {

    EXPECT_EQ(9, palindrome("QQQQQqQQQ"));
    EXPECT_TRUE(true);
}

//TASK 8

TEST(test1_8, task8) {

    EXPECT_EQ("YES", fishka("abcdef", "cdedcb"));
    EXPECT_TRUE(true);
}

TEST(test2_8, task8) {

    EXPECT_EQ("YES", fishka("aaa", "aaaaa"));
    EXPECT_TRUE(true);
}

TEST(test3_8, task8) {

    EXPECT_EQ("NO", fishka("aab", "baaa"));
    EXPECT_TRUE(true);
}

TEST(test4_8, task8) {

    EXPECT_EQ("YES", fishka("ab", "b"));
    EXPECT_TRUE(true);
}

TEST(test5_8, task8) {

    EXPECT_EQ("YES", fishka("abcdef", "abcdef"));
    EXPECT_TRUE(true);
}

TEST(test6_8, task8) {

    EXPECT_EQ("NO", fishka("ba", "baa"));
    EXPECT_TRUE(true);
}

TEST(test7_8, task8) {

    EXPECT_EQ("YES", fishka("qwerqweewqr", "qwerqwe"));
    EXPECT_TRUE(true);
}

TEST(test8_8, task8) {

    EXPECT_EQ("NO", fishka("ppppppp", "poppp"));
    EXPECT_TRUE(true);
}

//TASK 9

TEST(test1_9, task9) {

    EXPECT_EQ(1, sum("9999-9999ertr1"));
    EXPECT_TRUE(true);
}

TEST(test2_9, task9) {

    EXPECT_EQ(35, sum("3e+-+-+-+-3de2d33"));
    EXPECT_TRUE(true);
}

TEST(test3_9, task9) {

    EXPECT_EQ(0, sum("fkdkdfkkdfkfdkfdkdfkfdk0.0.0.0e3.e"));
    EXPECT_TRUE(true);
}

TEST(test4_9, task9) {

    EXPECT_EQ(80, sum("qwerweqrqew5e1e1e1e1e1e1e1"));
    EXPECT_TRUE(true);
}
