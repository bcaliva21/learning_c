#include <stdio.h>

int size_of(void)
{
	int *p;

	printf("%zu\n", sizeof(int)); // prints size of an int
	printf("%zu\n", sizeof p); // prints size of int*
	printf("%zu\n", sizeof *p); // prints size of int
}

int increment(int *p)
{
	*p = *p + 1;
}

int increment_example(void)
{
	int i = 10;
	int *j = &i;

	printf("i is %d\n", i);
	printf("i is also %d\n", *j);

	increment(j);
	printf("i is %d\n", i);
	increment(&i); // this is also valid

	printf("i is %d\n", i);
}

int knowledge_check(void)
{
	int x; // declare integer named x
	int *y; // declare integer-pointer named y

	y = &x; // assign y address of x

	x = 65; // assign x 65
	printf("x is %d\n", x); // prints 65

	*y = 100; // assigns thing y points to 100
	printf("x is %d\n", x); // prints 100
}

int pointers(void)
{
	int i; // i's tpe is int
	int *p; // p's type is pointer to an int, or int-pointer
	p = &i; // p is assigned the address of i--p now "points to" i
}

int dereferencing(void)
{
	int i; // declare an integer called i
	int *p; // declare a int-pointer called p

	p = &i; // p is assigned to the address of i

	i = 10; // i is assiged 10
	*p = 20; // the thing p points to (namely i!) is now 20!
			 //
	printf("i is %d\n", i);
	printf("i is %d\n", *p); // dereference-p is the same as i!
}

int first_lesson(void)
{
	int i = 10;

	printf("The value of i is %d\n", i);
	printf("And its address is %p\n", (void *)&i);
}

int main(void)
{
	increment_example();
}
