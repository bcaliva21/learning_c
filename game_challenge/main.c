#include <stdio.h>
#include "structs.h"

int main(void)
{
	struct u_state user_start_state = {100, 100, 100};
	struct user hero, *h; 

	h = &hero;
	h->state = &user_start_state;

	char knowsName;
	printf("Welcome, do you remember your name? (y/n)\n");
	scanf(" %c", &knowsName);

	if (knowsName == 'y') {
		printf("What is your name?\n");
		scanf("%49s", h->name);
	} else {
		printf("Ohh, well we can go with Unknown for now.\n");
		snprintf(h->name, sizeof(h->name), "Unknown");
	}

	printf("Hello, %s!\n", h->name);

	return 0;
}
