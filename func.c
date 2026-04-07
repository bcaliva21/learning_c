#include <stdio.h>

int foo(void); // function prototype

int plus_one(int n)
{
	return n + 1;
}

void hello(void)
{
	printf("Hello, World!\n");
}

void increment(int a)
{
	a++;
}

void trap()
{
	int i = 10;
	increment(i);
	printf("i == %d\n", i);
}

int main(void)
{
	hello();
	int i = 10, j;

	j = plus_one(i);

	printf("i + 1 is %d\n", j);

	trap();

	int k;
	k = foo();

	printf("%d\n", k);
}

int foo(void)
{
	return 3490;
}
