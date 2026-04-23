#include <stdio.h>

int main(void)
{
	long long int test = 20;
	while (1) {
		for (long long int i = 20; i > -1; i--) {
			if (i == 0) {
				printf("%lld\n", test);
				return 0;
			}
			if (test % i != 0) break;
		}
		test++;
	}
}

