#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

//TASK 5
string task5(int number) {
	string num;
	string* units = new string[]{ "","I","II","III","IV","V","VI","VII","VIII","IX" };
	for (int i = 0; i < number / 1000; i++)
	{
		num.push_back('M');
	}
	number %= 1000;
	if ((number % 500) / 100 + 5 == 9)
	{
		num += "CM";
		number %= 900;
	}
	else if (number / 500 > 0)
	{
		num.push_back('D');
		number %= 500;
	}
	for (int i = 0; i < number / 100; i++)
	{
		num.push_back('C');
	}
	number %= 100;


	if ((number % 50) / 10 + 5 == 9)
	{
		num += "XC";
		number %= 90;
	}
	else if (number / 50 > 0)
	{
		num.push_back('L');
		number %= 50;
	}
	if (number / 10 == 4)
	{
		num += "XL";
		number %= 40;
	}

	for (int i = 0; i < number / 10; i++)
	{
		num.push_back('X');
	}
	number %= 10;
	num += units[number];
	return num;
}

TEST(task5_1, task5) {
	EXPECT_EQ("I", task5(1));
	EXPECT_TRUE(true);
}

TEST(task5_2, task5) {
	EXPECT_EQ("II", task5(2));
	EXPECT_TRUE(true);
}

TEST(task5_3, task5) {
	EXPECT_EQ("III", task5(3));
	EXPECT_TRUE(true);
}

TEST(task5_4, task5) {
	EXPECT_EQ("IV", task5(4));
	EXPECT_TRUE(true);
}

TEST(task5_5, task5) {
	EXPECT_EQ("V", task5(5));
	EXPECT_TRUE(true);
}

TEST(task5_6, task5) {
	EXPECT_EQ("X", task5(10));
	EXPECT_TRUE(true);
}

TEST(task5_7, task5) {
	EXPECT_EQ("MMMMMMMMMMMMCCCXCXLV", task5(12345));
	EXPECT_TRUE(true);
}

TEST(task5_8, task8) {
	EXPECT_EQ("", task5(0));
	EXPECT_TRUE(true);
}

//TASK 6

long long int task6(long long int x) {	
	long long int num = x / 10;

	if (x % 10 == 9)
		num++;

	return num;
}


TEST(task6_1, task6) {
  EXPECT_EQ(0, task6(1));
  EXPECT_TRUE(true);
}

TEST(task6_2, task6) {
	EXPECT_EQ(1, task6(9));
	EXPECT_TRUE(true);
}

TEST(task6_3, task6) {
	EXPECT_EQ(1, task6(10));
	EXPECT_TRUE(true);
}

TEST(task6_4, task6) {
	EXPECT_EQ(3, task6(34));
	EXPECT_TRUE(true);
}

TEST(task6_5, task9) {
	EXPECT_EQ(88005553, task6(880055535));
	EXPECT_TRUE(true);
}

TEST(task6_6, task6) {
	EXPECT_EQ(2, task6(23));
	EXPECT_TRUE(true);
}

TEST(task6_7, task6) {
	EXPECT_EQ(12, task6(123));
	EXPECT_TRUE(true);
}

TEST(task6_8, task6) {
	EXPECT_EQ(33, task6(333));
	EXPECT_TRUE(true);
}

TEST(task6_9, task6) {
	EXPECT_EQ(77, task6(778));
	EXPECT_TRUE(true);
}

TEST(task6_10, task6) {
	EXPECT_EQ(1000000, task6(9999999));
	EXPECT_TRUE(true);
}

//TASK 7

int task7_1(int number) {

	bool del = false;

	//5
	for (int i = 0; i <= number; i += 5) {
		if (i == number)
			del = true;
	}

	if (del)
		return 1;
	else
		return 0;
}

TEST(task7_1, task7_1) {
	EXPECT_EQ(1, task7_1(5));
	EXPECT_TRUE(true);
}

TEST(task7_2, task7_1) {
	EXPECT_EQ(1, task7_1(10));
	EXPECT_TRUE(true);
}

TEST(task7_3, task7_1) {
	EXPECT_EQ(1, task7_1(500));
	EXPECT_TRUE(true);
}

int task7_2(int number) {

	bool del = false;

	//29
	for (int i = 0; i <= number; i += 29) {
		if (i == number)
			del = true;
	}

	if (del)
		return 1;
	else
		return 0;
}

TEST(task7_4, task7_2) {
	EXPECT_EQ(1, task7_2(29));
	EXPECT_TRUE(true);
}

TEST(task7_5, task7_2) {
	EXPECT_EQ(1, task7_2(290));
	EXPECT_TRUE(true);
}

TEST(task7_6, task7_2) {
	EXPECT_EQ(1, task7_2(3219));
	EXPECT_TRUE(true);
}

int task7_3(int number) {

	bool del = false;

	//223
	for (int i = 0; i <= number; i += 223) {
		if (i == number)
			del = true;
	}

	if (del)
		return 1;
	else
		return 0;
}

TEST(task7_7, task7_3) {
	EXPECT_EQ(1, task7_3(223));
	EXPECT_TRUE(true);
}

TEST(task7_8, task7_3) {
	EXPECT_EQ(1, task7_3(2230));
	EXPECT_TRUE(true);
}

TEST(task7_9, task7_3) {
	EXPECT_EQ(1, task7_3(2453));
	EXPECT_TRUE(true);
}
	

void t3swap_cod(string& dva) {
	for (int j = 0, j1 = dva.length() - 1; j < dva.length() / 2; j++, j1--)
		swap(dva[j], dva[j1]);
}

string t3to_dva(string s, string dva, int t, int k, int c) {
	for (;;) {
		for (int u = 0; u < s.length() - 1; u++) {
			if (s[u] == '0') {
				k = 0;
			}
			else {
				k = 1;
				break;
			}
		}
		if (s[s.length() - 1] == '1' && !k) {
			dva += '1';
			break;
		}
		if (s[s.length() - 1] == '0' && !k) {
			dva += '0';
			break;
		}

		for (int e = 0; e < s.length(); e++) {
			c = s[e] - '0';
			if (c % 2) {
				c = (c + t * 10) / 2;
				s[e] = c + '0';
				t = 1;
			}
			else {
				c = (c + t * 10) / 2;
				s[e] = c + '0';
				t = 0;
			}
			if (e == s.length() - 1) {
				if (t) dva += '1';
				else  dva += '0';
				t = 0;
			}
		}
	}

	t3swap_cod(dva);

	return dva;
}

string t3after_dot(string s, string s2, string dva) {
	s2.erase(0, s2.find('.') + 1);
	if (s2.length() > 10) s2.erase(8, s2.length() - 1);
	s.erase(s.find('.'), s.length());
	dva = t3to_dva(s, dva, 0, 0, 0);
	dva += '.';
	int size = s2.length() - 1;
	double dota = 0;
	for (int d = 0; d < s2.length(); d++) dota += pow(10, size--) * (s2[d] - '0');
	size = s2.length();
	for (int d = 0; d < 10; d++) {
		dota *= 2;
		if (dota - pow(10, size) > 0) {
			dva += '1';
			dota -= pow(10, size);
		}
		else dva += '0';
	}
	return dva;
}

bool t3cin_string(string& s, char* minus, int p, bool& dot) {
	//getline(cin, s);

	if (s.find('.') == -1) {
		s.insert(s.length(), ".");
		s.insert(s.length(), "0000000000");
	}

	if (s[0] == '-') {
		minus[0] = '1';
		s.erase(0, 1);
	}
	for (int e = 0; e < s.length(); e++) {
		if (s[e] == '.' || s[0] == '.' || s[s.length() - 1] == '.') {
			p++;
			dot++;
		}
		while (p > 1) {
			cout << "Incorrect value\n";
			return 0;
		}
	}
	for (int e = 0; e < s.length(); e++) {
		while ((s[e] < '0' || s[e]>'9') && s[e] != '.') {
			cout << "Incorrect value\n";
			return 0;
		}
	}
	return 1;
}

string t3dop_code(string dva, char* minus) {
	if (minus[0] == '0') return dva;
	string s, s2;
	int tt = 0, z;
	if (dva[1] == ',') {
		tt = 1;
		if (dva[0]) z = 1;
		else z = 0;
		dva.erase(0, 2);
	}
	t3swap_cod(dva);
	dva.erase(10, 1);
	s += '1';

	int dot = 10;
	if (dva.find('1') > 9)dva.erase(0, 10);
	else {
		dot = dva.find('1');
		dva.erase(0, dot);
	}

	for (int y = 0; y < dva.length(); y++) {
		if (dva[y] == '0') dva[y] = '1';
		else dva[y] = '0';
	}

	for (int y = 0, n = 0; y < dva.length(); y++) {
		s += '0';
		n = 1;
	}

	int c;
	bool t = 0;
	for (int y = 0; y < dva.length(); y++) {
		c = dva[y] + s[y] - 2 * '0' + t;
		if (c < 2) {
			s2 += c + '0';
			t = 0;
		}
		else {
			s2 += '0';
			t = 1;
		}
	}
	s = "";
	for (int y = 0; y < dot; y++) s += '0';
	s2 = s + s2;
	s2.insert(10, ".");
	t3swap_cod(s2);
	if (tt) {
		if (z) s2.insert(0, "1");
		else s2.insert(0, "0");
		s2.insert(1, ",");
	}
	return s2;
}

bool t3cin_to_dop(string& s, string& dva) {
	bool dot = 0;
	char minus[] = "0";

	if (!t3cin_string(s, minus, 0, dot)) return 0;
	dva = t3after_dot(s, s, dva);
	dva = t3dop_code(dva, minus);
	dva.insert(0, minus);
	dva.insert(1, ",");
	return 1;
}

string t3summa(string dva, string dva2) {
	string s;
	dva.erase(1, 1);
	dva2.erase(1, 1);

	t3swap_cod(dva);
	t3swap_cod(dva2);

	dva.erase(10, 1);
	dva2.erase(10, 1);

	if (dva.length() > dva2.length())
		for (int y = 0, y1 = dva.length() - dva2.length(); y < y1; y++)
			dva2 += '0';
	if (dva.length() < dva2.length())
		for (int y = 0, y1 = dva2.length() - dva.length(); y < y1; y++)
			dva += '0';

	bool t = 0;
	int c;
	s = "";
	for (int y = 0; y < dva.length(); y++) {
		c = dva[y] + dva2[y] - 2 * '0' + t;
		switch (c) {
		case 2:
			s += '0';
			t = 1; break;
		case 3:
			s += '1';
			t = 1; break;
		default:
			s += c + '0';
			t = 0; break;
		}
	}
	s.insert(10, ".");
	t3swap_cod(s);
	s.insert(1, ",");
	return s;
}

string task3(string s, string s2) {
	string dva, dva2;

	if (!t3cin_to_dop(s, dva)) return 0;
	if (!t3cin_to_dop(s2, dva2)) return 0;
	s = t3summa(dva, dva2);
	char minus[2];
	minus[0] = s[0];
	s = t3dop_code(s, minus);
	return s;
}

TEST(task_3, test1) {
	EXPECT_EQ(task3("1253", "6431"), "0,1111000000100.0000000000");
	EXPECT_TRUE(true);
}
TEST(task_3, test2) {
	EXPECT_EQ(task3("312857", "132875632187"), "0,1111011110000000001100000010001010100.0000000000");
	EXPECT_TRUE(true);
}
TEST(task_3, test3) {
	EXPECT_EQ(task3("83", "1"), "0,1010100.0000000000");
	EXPECT_TRUE(true);
}
//////////////////////////////////////////////////////////////////////////////////////////

void t4swap_cod(string& dva) {
	for (int j = 0, j1 = dva.length() - 1; j < dva.length() / 2; j++, j1--)
		swap(dva[j], dva[j1]);
}

bool t4cin_string(string& s, char* minus) {
	//getline(cin, s);
	int p = 0;

	if (s.find('.') == -1) {
		s.insert(s.length(), ".");
		s.insert(s.length(), "0000000000");
	}

	if (s[0] == '-') {
		minus[0] = '1';
		s.erase(0, 1);
	}
	for (int e = 0; e < s.length(); e++) {
		if (s[e] == '.' || s[0] == '.' || s[s.length() - 1] == '.') {
			p++;
		}
		while (p > 1) {
			cout << "Incorrect value\n";
			return 0;
		}
	}
	for (int e = 0; e < s.length(); e++) {
		while ((s[e] < '0' || s[e]>'9') && s[e] != '.' && s[e] != 'A') {
			cout << "Incorrect value\n";
			return 0;
		}
	}
	return 1;
}

bool t4cin_to_dop(string& s) {
	char minus[] = "0";

	if (!t4cin_string(s, minus)) return 0;
	if (minus[0] == '1') s = '-' + s;
	return 1;
}

string t4summa(string dva, string dva2) {
	string s;

	t4swap_cod(dva);
	t4swap_cod(dva2);

	dva.erase(10, 1);
	dva2.erase(10, 1);
	dva += '0';
	dva2 += '0';
	if (dva.length() > dva2.length())
		for (int y = 0, y1 = dva.length() - dva2.length(); y < y1; y++)
			dva2 += '0';
	if (dva.length() < dva2.length())
		for (int y = 0, y1 = dva2.length() - dva.length(); y < y1; y++)
			dva += '0';

	int c, t = 0, dv, dv2;
	s = "";
	for (int y = 0; y < dva.length(); y++) {
		if (dva[y] == 'A') dv = 10;
		else dv = dva[y] - '0';
		if (dva2[y] == 'A') dv2 = 10;
		else dv2 = dva2[y] - '0';
		c = dv + dv2 + t;
		if (c < 10) {
			s += c + '0';
			t = 0;
			continue;
		}
		if (c == 10) {
			s += 'A';
			t = 0;
			continue;
		}
		c--;
		if (c > 10) {
			s += c + '0' - 10;
			t = 1;
			continue;
		}
		if (c == 10) {
			s += '0';
			t = 1;
			continue;
		}
	}
	s.insert(10, ".");
	t4swap_cod(s);
	while (s[0] == '0') s.erase(0, 1);
	if (s[0] == '.') s.insert(0, "0");
	return s;
}

string t4subtraction(string dva, string dva2) {
	string s;

	t4swap_cod(dva);
	t4swap_cod(dva2);

	dva.erase(10, 1);
	dva2.erase(10, 1);
	dva += '0';
	dva2 += '0';
	if (dva.length() > dva2.length())
		for (int y = 0, y1 = dva.length() - dva2.length(); y < y1; y++)
			dva2 += '0';
	if (dva.length() < dva2.length())
		for (int y = 0, y1 = dva2.length() - dva.length(); y < y1; y++)
			dva += '0';

	int c, t = 0, dv, dv2;
	s = "";
	for (int y = 0; y < dva.length(); y++) {
		if (dva[y] == 'A') dv = 10;
		else dv = dva[y] - '0';
		if (dva2[y] == 'A') dv2 = 10;
		else dv2 = dva2[y] - '0';
		c = dv - dv2 - t;
		if (c >= 0) {
			s += c + '0';
			t = 0;
			continue;
		}
		else c = 11 + c;
		if (c == 10) {
			s += 'A';
			t = 1;
			continue;
		}
		if (c >= 0) {
			s += c + '0';
			t = 1;
			continue;
		}
	}
	s.insert(10, ".");
	t4swap_cod(s);
	while (s[0] == '0') s.erase(0, 1);
	if (s[0] == '.') s.insert(0, "0");
	return s;
}

string task4(string s, string s2, bool g) {
	string  s3;

	if (!t4cin_to_dop(s)) return 0;
	if (!t4cin_to_dop(s2)) return 0;

	s3 = t4summa(s, s2);
	if (g) return s3;
	if (s.length() > s2.length()) s3 = t4subtraction(s, s2);
	else {
		s3 = t4subtraction(s2, s);
		s3.insert(0, "-");
	}
	if (!g) return s3;
}
TEST(task_4, test1) {
	EXPECT_EQ(task4("1324", "6132", 1), "7456.0000000000");
	EXPECT_TRUE(true);
}
TEST(task_4, test2) {
	EXPECT_EQ(task4("3126", "741141347", 1), "741144472.0000000000");
	EXPECT_TRUE(true);
}
TEST(task_4, test3) {
	EXPECT_EQ(task4("3126", "741141347", 0), "-741139221.0000000000");
	EXPECT_TRUE(true);
}