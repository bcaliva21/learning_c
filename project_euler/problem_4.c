#include <stdio.h>

int is_palindrone(char *start, char *end)
{
	while (start < end) {
		if (*start == *end) {
			start++;
			end--;
		} else {
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	char str[20];
	long long int max = 0;

	for (long long int top = 999; top > 99; top--) {
		if (top * top <= max) break;
		for (long long int bot = top; bot > 99; bot--) {
			// printf("top: %lld, bot: %lld\n", top, bot);
			long long int product = top * bot;
			sprintf(str, "%lld", product);
			// printf("Product: %lld\n", product);

			if (product <= max) break;

			char *p = str;
			char *temp;
			while (*p) {
				temp = p;
				p++;
			}
			if (is_palindrone(str, temp) == 1) {
				printf("new max? %lld\n", product);
				printf("top %lld\n", top);
				printf("bot %lld\n", bot);
				if (product > max) max = product;
			}
		}
	}
	printf("%lld\n", max);

	// sprintf(str, "%d", 42);
	
	return 0;
}
