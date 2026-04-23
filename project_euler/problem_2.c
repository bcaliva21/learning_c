#include <stdio.h>

void run_fibonnaci()
{
	long long int x = 0;
	long long int y = 1;
	long long int fib;
	long long int sum;
	long long int MAX = 4000000;

	while (1) {
		fib = x + y;
		if (fib >= MAX) break;
		if (fib % 2 == 0) sum += fib;
		x = y;
		y = fib;
	}

	printf("%lld\n", sum);
}

int main(void)
{
	run_fibonnaci();

	return 0;
}
