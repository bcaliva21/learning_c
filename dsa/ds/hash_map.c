#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 256

typedef struct {
	char name[MAX_NAME];
	int login_attempts;
} Person;

typedef struct {
	int current_size;
	Person **arr;
} HashMap;

HashMap *init_hash_map(void)
{
	HashMap *hm = calloc(1, sizeof(HashMap));
	hm->current_size = 10;
	if (!hm) {
		fprintf(stderr, "Error: memory allocation error on hashmap");
		exit(EXIT_FAILURE);
	}

	hm->arr = calloc(hm->current_size, sizeof(Person *));

	return hm;
}

unsigned int hash(HashMap *hm, char *name)
{
	int len = strnlen(name, MAX_NAME);
	unsigned int index;
	for (int i = 0; i < len; i++) {
		index += name[i];
		index = ((index * index) * name[i]) % hm->current_size;
	}
	return index;
}

bool insert_person(HashMap *hm, Person *p)
{
	int index = hash(hm, p->name);
	if (hm->arr[index] != NULL) {
		do {
			index++;
		} while (hm->arr[index] != NULL);
	}

	hm->arr[index] = p;
	return true;
}

void print_hash_map(HashMap *hm)
{
	for (int i = 0; i < hm->current_size; i++) {
		if (hm->arr[i] == NULL) continue;
		printf("%s\n", hm->arr[i]->name);
	}
}

Person *create_person(char *name, int login_attempts)
{
	Person *p = malloc(sizeof(Person));
	if (!p) {
		fprintf(stderr, "Error: memory allocation for person\n");
		exit(EXIT_FAILURE);
	}
	strncpy(p->name, name, MAX_NAME - 1);
	p->name[MAX_NAME - 1] = '\0';
	p->login_attempts = login_attempts;

	return p;
}

void free_hash_map(HashMap *hm)
{
	for (int i = 0; i < hm->current_size; i++) {
		free(hm->arr[i]);
	}
	free(hm->arr);
	free(hm);
}

int main(void)
{
	HashMap *hm = init_hash_map();
	Person *joe = create_person("Joe", 10);
	Person *bradley = create_person("Bradley", 10);
	Person *everest = create_person("Everest", 10);
	Person *erica = create_person("Erica", 10);
	Person *jax = create_person("Jax", 10);
	Person *laraine = create_person("Laraine", 10);
	insert_person(hm, joe);
	insert_person(hm, bradley);
	insert_person(hm, everest);
	insert_person(hm, erica);
	insert_person(hm, jax);
	insert_person(hm, laraine);
	
	print_hash_map(hm);

	free_hash_map(hm);
	return 0;
}

