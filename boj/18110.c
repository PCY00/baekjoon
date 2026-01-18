#include <stdio.h>
#include <stdlib.h>

int m_round(double n)
{
	int r;
	if (n >= 0)
	{
		r = n + 0.5;
		return r;
	}
	else
	{
		r = n - 0.5;
		return r;
	}
}

int cmp(const void* a, const void* b)
{
	const int A = *(const int*)a;
	const int B = *(const int*)b;

	return (A > B) - (A < B);
}

int main()
{
	int n, save_range = 0;

	scanf("%d", &n);

	if (n == 0) {
		printf("0\n");
		return 0;
	}

	save_range = m_round(((double)n *15.0) / 100.0);
	
	int* score_arr = (int*)malloc(sizeof(int) * n);
	if (!score_arr) return 1;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &score_arr[i]);
	}

	qsort(score_arr, n, sizeof(int), cmp);

	int sum = 0;
	for (int i = save_range; i < n - save_range; i++)
	{
		sum += score_arr[i];
	}

	int denom = n - 2 * save_range;
	double avg = (double)sum / denom;

	printf("%d\n", m_round(avg));

	free(score_arr);
	return 0;
}

/* AI 코드
#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b)
{
	int A = *(const int*)a;
	int B = *(const int*)b;
	return (A > B) - (A < B);
}

static int round_nearest(double x)
{
	// 이 문제에선 평균이 음수가 안 나오지만, 습관적으로 양/음 모두 처리
	if (x >= 0) return (int)(x + 0.5);
	else        return (int)(x - 0.5);
}

int main(void)
{
	int n;
	if (scanf("%d", &n) != 1) return 0;

	// n==0이면 바로 0 출력
	if (n == 0) {
		puts("0");
		return 0;
	}

	// 0.15*n 반올림을 "정수"로 처리 (부동소수점 불필요)
	// round(n*15/100) == (n*15 + 50) / 100
	int t = (n * 15 + 50) / 100;

	int *a = (int*)malloc(sizeof(int) * n);
	if (!a) return 1;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	qsort(a, n, sizeof(int), cmp_int);

	long long sum = 0;
	for (int i = t; i < n - t; i++) {
		sum += a[i];
	}

	int denom = n - 2 * t;
	double avg = (double)sum / (double)denom;

	printf("%d\n", round_nearest(avg));

	free(a);
	return 0;
}

*/