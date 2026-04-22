#include <stdio.h>
#include <stdlib.h>

char alpha[] = {
	'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l',
	'm', 'n', 'o', 'p', 'q', 'r',
	's', 't', 'u', 'v', 'w', 'x',
	'y', 'z'
};

void generate_word(char *word, int len)
{
	for (int i = 0; i < len; i++) {
		word[i] = alpha[rand() % 26];
	}
}

void log_word(char *word, int len) {
	for (int i = 0; i < len; i++) {
		printf("%c", word[i]);
	}
	printf("\n");
}

int main(void)
{
	int WORD_LENGTH = 10;
	char word[WORD_LENGTH];
	printf("Welcome to the guessing game!\n");

	generate_word(&word, WORD_LENGTH);
	log_word(&word, WORD_LENGTH);
	generate_word(&word, WORD_LENGTH);
	log_word(&word, WORD_LENGTH);

	return 0;

}
