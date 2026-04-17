#include <stdio.h>

int main(void)
{
	int user_input;
	printf("Input Number: \n");
	scanf("%d", &user_input);
	int bits = sizeof(user_input) * 8;
	int msb = user_input >> 31;

	printf("Most Significant Bit=%d\n", msb);

	printf("Full Binary Number\n");
	for(int i = 31; i >= 0; i--) {
		int bit = (user_input >> i) & 1;
		printf("%d", bit);

		if (i % 4 == 0) printf("  ");
	}
	printf("\n");
}
