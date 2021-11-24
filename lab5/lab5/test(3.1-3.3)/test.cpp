#include "pch.h"

unsigned long long int F(unsigned long long int x, unsigned long long int y, unsigned long long int z) {

	if (y == 0) return 1;
	else if (y % 2)return x * F(x * x % z, y / 2, z) % z;
	else return F(x * x % z, y / 2, z);
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

long long int F1(long long int x) {

	if (x % 10 > 0) return x % 10;
	else if (x == 0) return 0;
	else return F(x / 10);
}

long long int S(long long int p, long long int q) {

	long long int s = 0;

	for (long long int i = q; i <= p; i++) {

		s += F1(i);
	}

	return s;
}

TEST(test1, task3_1) {

	EXPECT_EQ(46, S(10,1));
	EXPECT_TRUE(true);
}

TEST(test2, task3_1) {

	EXPECT_EQ(48, S(20,10));
	EXPECT_TRUE(true);
}

TEST(test4, task3_1) {

	EXPECT_EQ(1, S(1, 1));
	EXPECT_TRUE(true);
}

//task 3.2
TEST(test1, task3_2) {

	unsigned long long int m = pow(10, 4);
	unsigned long long int l = 1234 % m;

  EXPECT_EQ(736, F(l,1234,m));
  EXPECT_TRUE(true);
}

TEST(test2, task3_2) {

	unsigned long long int m = pow(10, 8);
	unsigned long long int l = 2323 % m;

	EXPECT_EQ(39087387, F(l, 99999999999, m));
	EXPECT_TRUE(true);
}

TEST(test3, task3_2) {

	unsigned long long int m = pow(10, 1);
	unsigned long long int l = 1 % m;

	EXPECT_EQ(1, F(l, 1, m));
	EXPECT_TRUE(true);
}

TEST(test4, task3_2) {

	unsigned long long int m = pow(10, 8);
	unsigned long long int l = 888 % m;

	EXPECT_EQ(91255296, F(l, 888, m));
	EXPECT_TRUE(true);
}

//task 3.3
TEST(test1, task3_3) {

	EXPECT_EQ(21, F(7));
	EXPECT_TRUE(true);
}

TEST(test2, task3_3) {

	EXPECT_EQ(201537, F(777));
	EXPECT_TRUE(true);
}

TEST(test3, task3_3) {

	EXPECT_EQ(1, F(1));
	EXPECT_TRUE(true);
}

TEST(test4, task3_3) {

	EXPECT_EQ(283568838797, F(922337));
	EXPECT_TRUE(true);
}