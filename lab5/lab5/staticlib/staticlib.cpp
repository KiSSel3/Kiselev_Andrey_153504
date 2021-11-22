#include "staticlib.h"

long long int pow(unsigned long long int x, unsigned long long int y) {
 
	long long int s = 1;

	while (y-- > 0) {

		s *= x;
	}
	
	return s;
}
