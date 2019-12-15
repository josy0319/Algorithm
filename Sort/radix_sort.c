#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 20
#define BUCKETS 10
#define DIGITS 4
#define SIZE 10

void print_sort(int list[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%5d", list[i]);
	}
	printf("\n");
}

typedef int element;
typedef struct { 				// 큐 타입
	int  front;
	int rear;
	element  data[MAX_QUEUE_SIZE];
} QueueType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q)
{
	q->rear = -1;
	q->front = -1;
}
void queue_print(QueueType* q)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf("   | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}
int is_full(QueueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}
int is_empty(QueueType* q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}
void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}

void radix_sort(int list[], int n) {
	QueueType queues[BUCKETS];
	int factor = 1;
	int i;
	for (int b = 0; b < BUCKETS; b++)
		init_queue(&queues[b]);
	for (int d = 0; d < DIGITS; d++) {
		for (int i = 0; i < n; i++)
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
		for (int b = i = 0; b < BUCKETS; b++)
			while (!is_empty(&queues[b]))
				list[i++] = dequeue(&queues[b]);
		factor *= 10;
		print_sort(list,SIZE);
	}
}

int main(void) {
	int list[SIZE];
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 200;
	printf("--------Initial State---------\n");
	for (int i = 0; i < SIZE; i++)
		printf("%5d", list[i]);
	printf("\n");

	printf("------------------------------\n");
	radix_sort(list, SIZE);
	printf("------------------------------\n");
	for (int i = 0; i < SIZE; i++)
		printf("%5d", list[i]);
	printf("\n");
	return 0;
}