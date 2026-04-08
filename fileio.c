#include <stdio.h>

int line_by_line(void)
{
	FILE *fp;
	char s[1024]; // Big enough for any line this program will encounter
    int linecount = 0;

	fp = fopen("assets/quote.txt", "r");

	while (fgets(s, sizeof s, fp) != NULL)
		printf("%d: %s", ++linecount, s);

	fclose(fp);
}

int basics(void)
{
	FILE *fp; // Var to represent open file
    int c;

	fp = fopen("assets/hello.txt", "r"); // Open file for reading

	// Get the character with fgetc(fp)
	while ((c = fgetc(fp)) != EOF)
		printf("%c", c);

	fclose(fp); // Close the file when done
}

int main(void)
{
	line_by_line();
}
