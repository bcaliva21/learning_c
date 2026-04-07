#include <stdio.h>
#define COUNT 5

int initialization(void)
{
	int a[5] = {33, 34, 1234};
	// same as int a[5] = {33, 34, 1234, 0, 0};
	int b[10] = {0, 11, 22, [5]=55, 66, 77}; // 0 11 22 00 00 55 66 77 0 0

	int c[COUNT] = {[COUNT-3]=3, 2, 1}; // 0 0 3 2 1
	
	int d[3] = {1,2,3};
	// same as e
	int e[] = {1,2,3};
}

int lesson_one(void)
{
	int i;
	float f[4];

	f[0] = 3.14159;
	f[1] = 1.41421;
	f[2] = 1.61803;
	f[3] = 2.71828;

	for (i = 0; i < 4; i++) {
		printf("%f\n", f[i]);
	}

}

int getting_the_length(void)
{
	int x[12];
	size_t sizeOfXInBytes = sizeof x;
	size_t sizeOfAnInt = sizeof(int);

	printf("%zu\n", sizeOfXInBytes); // 48 total bytes
	printf("%zu\n", sizeOfAnInt); // 4 bytes per int

    printf("%zu\n", sizeOfXInBytes / sizeOfAnInt); // 48/4 = 12 ints!
}

int main(void)
{
	getting_the_length();
}
