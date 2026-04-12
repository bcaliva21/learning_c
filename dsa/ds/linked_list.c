#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node *next;
} Node;

typedef struct MyLinkedList {
	Node *head;
} MyLinkedList;

Node *createNode(int val)
{
	Node *n = malloc(sizeof(Node));
	n->val = val;
	n->next = NULL;

	return n;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
	Node *n = createNode(val);
	n->next = obj->head;
	obj->head = n;
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val) {
	Node *c = obj->head;
	if (index == 0) {
		myLinkedListAddAtHead(obj, val);
		return;
	}
	int i = 0;
	while (c != NULL) {
		if (i+1 == index) {
			Node *n, *t; 
			n = createNode(val);
			t = c->next;
			c->next = n;
			n->next = t;
			return;
		}

		i++;
		c = c->next;
	}
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index) {
	Node *c = obj->head;
	if (c == NULL) return;
	if (index == 0) {
		obj->head = c->next;
		free(c);
		return;
	}
	int i = 0;
	while (c != NULL && c->next != NULL) {
		if (i+1 == index) {
			Node *t = c->next;
			c->next = c->next->next;
			free(t);
			return;
		}
		i++;
		c = c->next;
	}
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
	if (obj->head == NULL) {
		myLinkedListAddAtHead(obj, val);
		return;
	}

	Node *c = obj->head;
	while (c->next != NULL) {
		c = c->next;
	}
	Node *t = createNode(val);
	c->next = t;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
	Node *c = obj->head;
	if (c == NULL) return -1;
	int i = 0;
	while (c != NULL) {
		if (i == index) {
			return c->val;
		} else {
			i++;
			c = c->next;
		}
	}

	return -1;
}

MyLinkedList *myLinkedListCreate(void)
{
	MyLinkedList *myLinkedList = malloc(sizeof(MyLinkedList));
	myLinkedList->head = NULL;

	return myLinkedList;
}

void logValues(MyLinkedList *obj)
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

void myLinkedListFree(MyLinkedList *obj) {
	Node *c = obj->head;
	Node *d;

	while(c != NULL) {
		d = c;
		c = c->next;
		free(d);
	}
	free(obj);
}

int main(void)
{
	MyLinkedList *obj = myLinkedListCreate();
	// printf("%d\n", obj->head->val);

	myLinkedListAddAtHead(obj, 1);
	// printf("%d\n", obj->head->val);

	myLinkedListAddAtHead(obj, 2);
	// printf("%d\n", obj->head->val);
	myLinkedListAddAtHead(obj, 3);
	myLinkedListAddAtHead(obj, 4);
	myLinkedListAddAtHead(obj, 5);

	logValues(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/

