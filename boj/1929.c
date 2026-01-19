#include <stdio.h>
#include <stdlib.h>

int main()
{
	int M, N;

	scanf("%d %d", &M, &N);
	if (N < M) return 1;

	char* isComposite = (char*)calloc(N+1, 1);
	if (!isComposite) return 1;
	
	isComposite[0] = 1;
	if (N >= 1) isComposite[1] = 1;

	for (int i = 2; (long long)i * i <= N; i++)
	{
		if (!isComposite[i]) {
			for (int j = i * i; j <= N; j += i)
			{
				isComposite[j] = 1;
			}
		}
	}

	for (int x = M; x <= N; x++)
	{
		if (!isComposite[x]) printf("%d\n", x);
	}

	free(isComposite);
	return 0;
}