#include <stdio.h>

#define MAX 10001 

int main(void)
{
	long int primes[MAX] = {0};
	int idx = 0;

	for (long int i = 2; idx < MAX; i++) {
		if (idx > 10001) break;
		int is_prime = 0;
		long int j = i-1;
		while (j > 1) {
			if (i % j == 0) {
				is_prime = 1;
				break;
			};
			j--;
		}

		if (is_prime == 0) {
			primes[idx++] = i;
		}
	}

	printf("%ld\n", primes[10000]);

	return 0;
}
