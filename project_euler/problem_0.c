// A number is a perfect square, or a square number, if it is the square of a positive integer.
// For example,  is a square number because    ; it is also an odd square.

// The first 5 square numbers are: , and the sum of the odd squares is    .

// Among the first 928 thousand square numbers, what is the sum of all the odd squares?
//
//
#include <stdio.h>

int main(void)
{
	unsigned int max = 928000;
	long long int sum = 0;

	for (long long int i = 1; i < max; i++) {
		long long int squared = i * i;
		if (squared % 2 == 0) continue; // even
		printf("SQUARED = %lld\n", squared);
		sum += squared;
		printf("SUM = %lld\n", sum);
	}

	return 0;
}
