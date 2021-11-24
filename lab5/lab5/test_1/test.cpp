#include "pch.h"

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

TEST(TestCaseName, Tes) {
  EXPECT_EQ(0, F(56));
  EXPECT_TRUE(true);
}