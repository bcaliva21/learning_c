#include <stdio.h>
#include <string.h>

int make_a_copy(void)
{
	char s[] = "Hello, World!";
	char t[100];

	strcpy(t, s);

	t[0] = 'Z';

	printf("%s\n", s);
	printf("%s\n", t);
}

int my_strlen(char *s)
{
	int count = 0;

	while (s[count] != '\0') // Single quotes for single char
	    count++;

	return count;
}

int string_length(void)
{
	char *s = "Hello, World!";

	printf("The string is %d bytes long.\n", my_strlen(s));
}

int change_index(void)
{
	char t[] = "Hello, again!";
	t[0] = 'Z'; // no problem
	printf("%s\n", t);
    // char *s = "Hello, World!";
	// s[0] = 'z'; BAD NEWS; tried to mutate a string literal
}

int array_notation(void)
{
	// char s[14] = "Hello, World!";
	// or for the lazy
	
	// char s[] = "Hello, World!";
	// works also like this
	char *s = "Hello, World!";

	for (int i = 0; i < 13; i++)
		printf("%c", s[i]);
	printf("\n");
}

int simple_string(void)
{
	char *s = "Hello, World!";
	printf("%s\n", s);
}

int main(void)
{
	make_a_copy();
}

