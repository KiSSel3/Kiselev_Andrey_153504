#include "pch.h"
#include "dinlib.h"

long double Min(long double S[], long long int size) {

	long double m = S[0];

	for (long long int i = 0; i < size; i++) {

		if (S[i] < m) {

			m = S[i];
		}
	}

	return m;
}
