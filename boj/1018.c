#include <stdio.h>

char one[8][8] =
{
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}
};

int main()
{
	int N, M;
	char arr[51][51];
	int min = 65;
	
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", &arr[i]);
	}

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			int cnt = 0;

			for (int k = 0; k < 8; k++)
			{
				for (int h = 0; h < 8; h++)
				{
					if (arr[i + k][j + h] != one[k][h]) cnt++;
				}
			}

			if (cnt > 64 - cnt) cnt = 64 - cnt;

			if (min > cnt) min = cnt;
		}
	}

	printf("%d\n", min);
	return 0;
}