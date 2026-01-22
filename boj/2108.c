#include <stdio.h>
#include <stdlib.h>

// 기본적으로 int 캐스팅시 버림임
static int rounding(double value)
{
	if (value >= 0) return (int)(value + 0.5);
	else return (int)(value - 0.5);
}

static int cmp(const void* a, const void* b)
{
	const int A = *(const int*)a;
	const int B = *(const int*)b;

	if (A > B) return 1;
	else if (A < B) return -1;
	return 0;
}

// 산술 평균 값
// N개의 수들의 합을 N으로 나눈 값
static int avg(int * arr, int size)
{
	double answer = 0.0;

	for (int i = 1; i <= size; i++)
	{
		double x = (double)arr[i - 1];
		answer += (x - answer) / (double)i;
	}

	return rounding(answer);
}

// 중앙값
// N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
static int median(int * arr, int size)
{
	return arr[size / 2];
}

// 최빈값
// N개의 수들 중 가장 많이 나타나는 값
static int mode(int* arr, int size)
{
	int maxCnt = 0;
	int modeVal = arr[0];
	int foundSecond = 0;

	int cnt = 1;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] == arr[i - 1]) cnt++;
		else {
			if (maxCnt < cnt)
			{
				maxCnt = cnt;
				modeVal = arr[i - 1];
				foundSecond = 0;
			}
			else if (cnt == maxCnt && foundSecond == 0)
			{
				modeVal = arr[i - 1];
				foundSecond = 1;
			}
			cnt = 1;
		}
	}

	// 마지막 값 처리
	if (cnt > maxCnt) {
		maxCnt = cnt;
		modeVal = arr[size - 1];
	}
	else if (cnt == maxCnt && foundSecond == 0) {
		modeVal = arr[size - 1];
	}

	return modeVal;
}

// 범위
// N개의 수들 중 최댓값과 최솟값의 차이
static int range(int* arr, int size)
{
	return (arr[size - 1] - arr[0]);
}

int main()
{
	int N;

	scanf("%d", &N);

	int* arr = (int*)malloc(sizeof(int) * N);
	if (!arr) {
		return 1;
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(int), cmp);

	printf("%d\n", avg(arr, N));
	printf("%d\n", median(arr, N));
	printf("%d\n", mode(arr, N));
	printf("%d\n", range(arr, N));

	free(arr);
	return 0;
}