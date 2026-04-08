#include <stdio.h>

int main(void)
{
	int i = 10;

	while (i < 10) {
		printf("while: i is now %d!\n", i);
		i++;
	}

	do {
		printf("do-while: i is %d\n", i);
		i++;
	} while (i < 10);

	printf("fin\n");
}
