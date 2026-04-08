#include <stdio.h>
#define COUNT 5

void print_2D_array(int a[2][3])
{
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 3; col++) 
			printf("%d ", a[row][col]);
		printf("\n");
	}
}

int two_dimensions(void)
{
	int x[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};

	print_2D_array(x);
}

void double_array(int *a, int len)
{
	for (int i = 0; i < len; i++)
		a[i] *= 2;
}

int change_array_in_functions(void)
{
	int x[5] = {1, 2, 3, 4, 5};

	double_array(x, 5);

	for (int i = 0; i < 5; i++)
		printf("%d\n", x[i]); // 2, 4, 6, 8, 10!
}

void times2(int *a, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d\n", a[i] * 2);
}

void times3(int a[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d\n", a[i] * 3);
}

void times4(int a[5], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d\n", a[i] * 4);
}

int arrays_to_functions(void)
{
	int x[5] = {11, 22, 33, 44, 55};

	times2(x, 5);
}

int pointers(void)
{
	int a[5] = {1,2,3,4,5};
	int *p;

	p = &a[1];

	printf("%d\n", *p); // prints 2
}

int multi_dimension(void)
{
	int row, col;

	int a[2][5] = {
		{0, 1, 2, 3, 4},
		{5, 6, 7, 8, 9}
	};

	for (row = 0; row < 2; row++) {
		for (col = 0; col < 5; col++) {
			printf("(%d,%d) = %d\n", row, col, a[row][col]);
		}
	}
}

int out_of_bounds(void)
{
	int i;
	int a[5] = {22, 37, 3490, 18, 95};

	for (i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
}

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
	two_dimensions();
}

