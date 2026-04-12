#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int capacity;
	int front;
	int rear;
	int size;
	int *arr;
} Queue;

Queue *initialize(int capacity) {
	Queue *queue = malloc(sizeof(Queue));
	int *arr = malloc(capacity * sizeof(int));
	queue->front = 0;
	queue->capacity = capacity;
	queue->rear = -1;
	queue->size = 0;
	queue->arr = arr;

	return queue;
}

bool is_full(Queue *queue) {
	return queue->size >= queue->capacity;
}

bool is_empty(Queue *queue) {
	return queue->size == 0;
}

int dequeue(Queue *queue) {
	if (is_empty(queue)) return -1;
	int value = queue->arr[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	return value;
}

void enqueue(Queue *queue, int value) {
	if (is_full(queue)) {
		return; // can't add to a full queue
	}
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->arr[queue->rear] = value;
	queue->size++;
	return;
}

void print(Queue *queue) {
	printf("|---PRINTING QUEUE---|\n");
	for (int i = 0; i < queue->size; i++) {
		int target = (queue->front + i) % queue->capacity;
		printf("%d\n", queue->arr[target]);
	}
	printf("|---END PRINTING QUEUE---|\n");

	return;
}

void free_queue(Queue *queue)
{
	printf("|---FREEING QUEUE MEMORY---|\n");
	free(queue->arr);
	free(queue);
	printf("|---END FREEING QUEUE MEMORY---|\n");
}

int main(void)
{
	Queue *queue = initialize(100);
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);
	enqueue(queue, 5);
	printf("%d\n", dequeue(queue));
	printf("%d\n", dequeue(queue));
	printf("%d\n", dequeue(queue));
	printf("%d\n", dequeue(queue));
	printf("%d\n", dequeue(queue));
	print(queue);

	free_queue(queue);
	return 0;
}
