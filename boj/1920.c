#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
	const int A = *(const int*)a;
	const int B = *(const int*)b;

	if (A > B) return 1;
	if (A < B) return -1;
	return 0;
}

int search_binary(const void* arr, const int count, const int key)
{
	const int* a = (const int*)arr;
	int start = 0;
	int end = count - 1;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (a[mid] == key) return 1;
		else if (a[mid] > key) end = mid - 1;
		else start = mid + 1;
	}
	return -1;
}

int main()
{
	int N, M;
	int num;

	scanf("%d", &N);

	int* memorize = (int*)malloc(sizeof(int) * N);
	if (memorize == NULL) return -1;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &memorize[i]);
	}

	qsort(memorize, N, sizeof(int), cmp);

	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &num);

		if (search_binary(memorize, N, num) == 1) printf("%d\n", 1);
		else printf("%d\n", 0);
	}

	free(memorize);
	return 0;
}