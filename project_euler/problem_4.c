#include <stdio.h>

int is_palindrone(char *start, char *end)
{
	while (start != end) {
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
	char str[12];
	long long int max = 0;

	for (int top = 999; top > 99; top--) {
		for (int bot = 999; bot > 99; bot--) {
			long long int product = top * bot;
			sprintf(str, "%lld", product);

			char *p = str;
			char *temp;
			while (*p) {
				temp = p;
				p++;
			}
			if (is_palindrone(str, temp) == 1) {
				if (product > max) max = product;
				// printf("found it!\n");
				// printf("%s\n", str);
			}
		}
	}
	printf("%lld\n", max);

	// sprintf(str, "%d", 42);

	return 0;
}
