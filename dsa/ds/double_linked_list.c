#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct LinkedList {
	Node *head;
} LinkedList;

Node *createNode(int val)
{
    Node *node = malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

LinkedList *createLinkedList(void)
{
	LinkedList *linkedlist = malloc(sizeof(LinkedList));
	linkedlist->head = NULL;

	return linkedlist;
}

void setLinkedListHead(LinkedList *obj, int val)
{
	if (obj == NULL) return;

	Node *head = createNode(val);
	Node *cur = obj->head;
	head->next = cur;
	head->prev = NULL;
	if (cur != NULL) {
		cur->prev = head;
	}

	obj->head = head;

	return;
}

void removeHead(LinkedList *obj)
{
	if (obj == NULL) return;

	Node *cur = obj->head;
	Node *newHead = cur->next;
	newHead->prev = NULL;
	obj->head = newHead;
	free(cur);
}

void setLinkedListTail(LinkedList *obj, int val)
{
	if (obj == NULL) return;

	Node *cur = obj->head;
	while (cur != NULL) {
		if (cur->next == NULL) {
			Node *node = createNode(val);
			cur->next = node;
			node->prev = cur;
			node->next = NULL;
			return;
		}

		cur = cur->next;
	}
}

void removeNodeAtIndex(LinkedList *obj, int index)
{
	if (obj == NULL) return;

	Node *cur = obj->head;
	Node *remove;
	int i = 0;
	if (i == index) {
		removeHead(obj);
		return;
	}
	while (cur != NULL && cur->next != NULL) {
		if (i+1 == index) {
			remove = cur->next;
			Node *next = remove->next;
			cur->next = next;
			if (next != NULL) {
				next->prev = cur;
			}
			free(remove);
			return;
		}
		i++;
		cur = cur->next;
	}

	return;
}

int getHeadVal(LinkedList *obj)
{
	if (obj == NULL) return -1;
	Node *cur = obj->head;
	return cur->val;
}

int getValueAtIndex(LinkedList *obj, int index)
{
	if (obj == NULL) return -1;
	Node *cur = obj->head;
	int i = 0;

	while(cur != NULL) {
		if (i == index) {
			return cur->val;
		}
		i++;
		cur = cur->next;
	}

	return -1;
}

void freeLinkedList(LinkedList *obj) {
	if (obj == NULL) return;
	Node *cur = obj->head;
	Node *temp;
	while (cur != NULL) {
		temp = cur;
		cur = temp->next;
		free(temp);
	}

	free(obj);
}

void reverse(LinkedList *obj) {
	if (obj == NULL) return;

	Node *cur = obj->head;
	Node *tmp = NULL;
	while (cur != NULL) {
		cur->prev = cur->next;
		cur->next = tmp;
		tmp = cur;
		cur = tmp->prev;
	}
	obj->head = tmp;
}

void logValues(LinkedList *obj)
{
	printf("---PRINTING LINKED LIST---]\n");
	int i = 0;
	Node *c = obj->head;
	if (c == NULL) {
		return;
	}
	while (c != NULL) {
		printf("idx: %d, val: %d\n", i, c->val);
		c = c->next;
		i++;
	}
}


int main(void)
{
	LinkedList *ll = createLinkedList();
	setLinkedListHead(ll, 5);
	setLinkedListHead(ll, 4);
	setLinkedListHead(ll, 3);
	setLinkedListHead(ll, 2);
	setLinkedListHead(ll, 1);

	logValues(ll);
	reverse(ll);
	logValues(ll);

	freeLinkedList(ll);

	return 0;
}
