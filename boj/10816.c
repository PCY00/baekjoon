#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
	const int A = *(const int*)a;
	const int B = *(const int*)b;

	if (A > B) return 1;
	else if(A < B) return -1;

	return 0;
}

int lower_bound(const int* arr, int n, int x)
{
	int lo = 0, hi = n;
	while (lo < hi)
	{
		// lo에서 시작해서 (hi - lo)의 절반 만큼 간 위치
		int mid = lo + (hi - lo) / 2;
		
		// 작으면 왼쪽 크면 오른쪽
		if (arr[mid] >= x) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int upper_bound(const int* arr, int n, int x)
{
	int lo = 0, hi = n;
	while (lo < hi)
	{
		int mid = lo + (hi - lo) / 2;
		if (arr[mid] > x) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int main()
{
	int N, M;
	
	scanf("%d", &N);

	int* N_arr = (int*)malloc(sizeof(int) * N);
	if (!N_arr) return 1;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &N_arr[i]);
	}

	scanf("%d", &M);

	int* M_arr = (int*)malloc(sizeof(int) * M);
	if (!M_arr) return 1;

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &M_arr[i]);
	}

	qsort(N_arr, N, sizeof(int), cmp);

	for (int i = 0; i < M; i++)
	{
		int x = M_arr[i];
		int lb = lower_bound(N_arr, N, x);
		int ub = upper_bound(N_arr, N, x);
		int cnt = ub - lb;

		if (i) putchar(' ');
		printf("%d", cnt);
	}

	free(N_arr);
	free(M_arr);
	N_arr = NULL;
	M_arr = NULL;

	return 0;
}