#include <stdio.h>

int main(void)
{
	long int sumOfSquares = 0;
	long int squareOfSum = 0;

	for (int i = 1; i < 101; i++) {
		sumOfSquares += i * i;
		squareOfSum += i;
	}
	 squareOfSum *= squareOfSum;

	 printf("%ld\n", squareOfSum - sumOfSquares);
}
