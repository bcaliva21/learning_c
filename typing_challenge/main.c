#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"

// struct run {
//         double time;
//         int errors;
// };
// 
// struct user {
//     char *name;
//         struct run bestRun;
//         double bestTime;
//         int leastErrors;
//         int mostErrors;
// };

void addWords(char **a, int len)
{
	char *words[] = {
        "apple", "river", "mountain", "sky", "ocean",
        "bird", "tree", "forest", "cloud", "sun",
        "moon", "star", "wind", "rain", "storm",
        "fire", "earth", "sand", "stone", "path",
        "eagle", "wolf", "bear", "fish", "leaf"
    };
	int num_words = sizeof(words) / sizeof(words[0]);

	srand(time(NULL));
	
	for (int i = 0; i < len; i++) {
		int random_index = rand() % num_words;
		a[i] = words[random_index];
	}
}

void handle_words(int len)
{
	char *words[len];
	addWords(words, len);
	for (int i = 0; i < len; i++) {
		printf("%s ", words[i]);
	}
	printf("\n");
}

int main(void)
{
	char name[100];
	printf("---Typing Challenge---\n");
	printf("What's your name?\n");

	fgets(name, sizeof(name), stdin);

	char difficulty;
	printf("Welcome, %s\n", name);
	printf("Select challenge length\n");
	printf("short (10 words), medium (20), long (30)\n");
	printf("Enter s/m/l\n");

	scanf(" %c", &difficulty);

	if (difficulty == 's') {
		handle_words(10);
	} if (difficulty == 'm') {
		handle_words(20);
	} else if (difficulty == 'l') {
		handle_words(30);
	}

	return 0;
}

