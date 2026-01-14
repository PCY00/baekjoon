#include <stdio.h>

#define MAX 1001

typedef struct queue {
	int front;
	int rear;
	int arr[MAX];
}que;

void init_queue(que* q)
{
	q->front = 0;
	q->rear = 0;
}

int empty_queue(que* q)
{
	return q->front == q->rear;
}

void push_queue(que* q, int x)
{
	q->arr[q->rear] = x;
	q->rear = (q->rear + 1) % MAX;
}

int pop_queue(que* q)
{
	int x = q->arr[q->front];
	q->front = (q->front + 1) % MAX;
	return x;
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	que q;

	init_queue(&q);

	for (int i = 1; i <= N; i++)
	{
		push_queue(&q, i);
	}

	printf("%c", '<');
	int count = 0;
	int printed = 0;

	while (printed < N)
	{
		int x = pop_queue(&q);
		count++;

		if (count == K)
		{
			if (printed > 0) printf(", ");
			printf("%d", x);
			printed++;
			count = 0;
		}
		else {
			push_queue(&q, x);
		}
	}
	printf("%c", '>');

	return 0;
}