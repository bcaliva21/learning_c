#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int capacity;
	int top;
	int *arr;
} Stack;

Stack *initialize(int cap)
{
	Stack *stack = malloc(sizeof(Stack));
	int *arr = malloc(cap * sizeof(int));
	stack->capacity = cap;
	stack->top = -1;
	stack->arr = arr;

	return stack;
}

bool is_empty(Stack *s) {
	return s->top == -1;
}

bool is_full(Stack *s) {
	return s->top >= s->capacity - 1;
}

int peak(Stack *s) {
	if (is_empty(s)) return -1;
	printf("peaking... %d\n", s->arr[s->top]);
	return s->arr[s->top];
}

int pop(Stack *s) {
	if (is_empty(s)) return -1;
	int value = s->arr[s->top--];
	printf("popping... %d\n", value);
	return value;
}

int push(Stack *s, int v) {
	if (is_full(s)) {
		return s->top+1;
	} else {
		s->arr[++s->top] = v;
		return s->top+1;
	}
}

void print(Stack *s) {
	printf("|---PRINTING STACK---|\n");
	for (int i = 0; i <= s->top; i++) {
		printf("index: %d, value: %d\n", i, s->arr[i]);
	}
	printf("|---END PRINTING---|\n");
}

int size(Stack *s) {
	return s->top + 1;
}

void free_stack(Stack *s) {
	printf("|---FREEING STACK MEMORY---|\n");
	free(s->arr);
	free(s);
	printf("|---END FREEING STACK MEMORY---|\n");
}

int main(void)
{
	Stack *stack = initialize(100);
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	peak(stack);
	push(stack, 4);
	peak(stack);
	push(stack, 5);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);

	free_stack(stack);

	return 0;
}
