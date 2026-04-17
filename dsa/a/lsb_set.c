#include <stdio.h>

int main(void)
{
	int value;
	printf("Input a value:\n");
	scanf("%d", &value);

	int mask = 1;
	int y = value & mask;

	printf("%d", y >> 0);
	printf("\n");
}


