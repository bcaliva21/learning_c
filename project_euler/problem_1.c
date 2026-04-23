// If we list all the natural numbers below  that are multiples of  or , we get  and . The sum of these multiples is .

// Find the sum of all the multiples of  or  below .
//
#include <stdio.h>

int main(void)
{
	int max = 1000;
	int sum = 0;
	for (int i = 1; i < max; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}

	printf("%d\n", sum);
}
