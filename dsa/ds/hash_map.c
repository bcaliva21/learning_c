#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 256

typedef struct {
	int id;
	char name[MAX_NAME];
} Person;

typedef struct {
	float capacity;
	int current_size;
	int max_size;
	Person **arr;
} HashMap;

bool insert_person(HashMap *hm, Person *p);
void resize(HashMap *hm);

HashMap *init_hash_map(void)
{
	HashMap *hm = calloc(1, sizeof(HashMap));
	hm->max_size = 10;
	if (!hm) {
		fprintf(stderr, "Error: memory allocation for hashmap");
		exit(EXIT_FAILURE);
	}

	hm->arr = calloc(hm->max_size, sizeof(Person *));

	return hm;
}

unsigned int hash(HashMap *hm, char *name)
{
	int len = strnlen(name, MAX_NAME);
	unsigned int index;
	for (int i = 0; i < len; i++) {
		index += name[i];
		index = ((index * index) * name[i]) % hm->max_size;
	}
	return index;
}

void resize(HashMap *hm)
{
	// allocate new, larger contiguous memory block 
	Person **arr = calloc(hm->max_size * 2, sizeof(Person *));
	if (!arr) {
		fprintf(stderr, "Error: memory allocation on hashmap resize");
		exit(EXIT_FAILURE);
	}

	// save ptr and data for old data
	Person **temp = hm->arr;
	int temp_size = hm->max_size;

	// update data
	hm->max_size = hm->max_size * 2;
	hm->current_size = 0;
	hm->capacity = 0.0;
	hm->arr = arr;

	for (int i = 0; i < temp_size; i++) {
		if (temp[i] == NULL) continue;
		insert_person(hm, temp[i]);
	}

	free(temp);
}

bool insert_person(HashMap *hm, Person *p)
{
	if (hm->capacity >= 0.7) {
		resize(hm);
	}
	int index = hash(hm, p->name);
	if (hm->arr[index] != NULL) {
		do {
			index++;
		} while (hm->arr[index] != NULL);
	}

	hm->arr[index] = p;
	hm->current_size++;
	hm->capacity = (float)hm->current_size / (float)hm->max_size;

	return true;
}

void print_hash_map(HashMap *hm)
{
	for (int i = 0; i < hm->max_size; i++) {
		if (hm->arr[i] == NULL) continue;
		printf("index: %d, name %s\n", i, hm->arr[i]->name);
	}
}

Person *create_person(char *name, int id)
{
	Person *p = malloc(sizeof(Person));
	if (!p) {
		fprintf(stderr, "Error: memory allocation for person\n");
		exit(EXIT_FAILURE);
	}
	strncpy(p->name, name, MAX_NAME - 1);
	p->name[MAX_NAME - 1] = '\0';
	p->id = id;

	return p;
}

void free_hash_map(HashMap *hm)
{
	for (int i = 0; i < hm->max_size; i++) {
		free(hm->arr[i]);
	}
	free(hm->arr);
	free(hm);
}

int main(void)
{
	HashMap *hm = init_hash_map();
	Person *joe = create_person("Joe", 1);
	Person *bradley = create_person("Bradley", 2);
	Person *everest = create_person("Everest", 3);
	Person *erica = create_person("Erica", 4);
	Person *jax = create_person("Jax", 5);
	Person *laraine = create_person("Laraine", 6);
	Person *diego = create_person("Diego", 6);
	Person *kat = create_person("Katherine", 7);
	Person *papa= create_person("PaPa", 8);
	Person *lulu = create_person("Lulu", 9);
	Person *victor = create_person("Victor", 10);
	Person *donald = create_person("Donald", 11);
	Person *tim = create_person("Tim", 12);
	insert_person(hm, joe);
	insert_person(hm, bradley);
	insert_person(hm, everest);
	insert_person(hm, erica);
	insert_person(hm, jax);
	insert_person(hm, laraine);
	insert_person(hm, diego);
	insert_person(hm, kat);
	insert_person(hm, papa);
	insert_person(hm, lulu);
	insert_person(hm, donald);
	insert_person(hm, tim);
	insert_person(hm, victor);
	
	print_hash_map(hm);

	free_hash_map(hm);
	return 0;
}

