#include <stdio.h>

#define MAX 11

int main()
{
	int N, K;
	int arr[MAX];

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	int cnt = 0;
	for (int i = N-1; i >=0; i--)
	{
		if (K >= arr[i]) {
			cnt += K / arr[i];
			K %= arr[i];
		}
	}

	printf("%d\n", cnt);



	return 0;
}