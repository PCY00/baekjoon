#include <stdio.h>
#include <stdlib.h>

int main()
{
	int K, head = -1;

	if(scanf("%d", &K) != 1) return 1;

	int* num = (int*)malloc(sizeof(int) * K);
	if (!num) return 1;

	for (int i = 0; i < K; i++)
	{
		int x;
		if (scanf("%d", &x) != 1) { free(num); return 1; }

		if (x == 0)
		{
			if(head>=0) head--;
		}
		else
		{
			num[++head] = x;
		}
	}

	long long sum = 0;
	for (int j = 0; j <= head; j++)
	{
		sum += num[j];
	}

	printf("%lld\n", sum);

	free(num);

	return 0;
}