#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	if (scanf("%d", &N) != 1) return 0;

	int* q = (int*)malloc(sizeof(int) * N);
	if (!q) return 0;

	int front = 0;
	int rear = 0;
	int size = 0;

	for (int i = 1; i <= N; i++)
	{
		q[rear] = i;
		rear = (rear + 1) % N;
		size++;
	}
	return 0;
}