#include <stdio.h>
#include <stdlib.h>

static int cmp(const void* a, const void* b)
{
	const int A = *(const int*)a;
	const int B = *(const int*)b;
	
	if (A > B) return 1;
	else if (A < B) return -1;
	
	return 0;
}

int main()
{
	int N;
	int arr[1001];

	scanf("%d", &N);

	for(int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(int), cmp);

	int sum = 0;
	int prefix = 0;
	for (int i = 0; i < N; i++)
	{
		prefix += arr[i];
		sum += prefix;
	}
	printf("%d\n", sum);

	return 0;
}