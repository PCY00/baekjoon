#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);

	int* stack = (int*)malloc(sizeof(int) * n);
	char* out = (char*)malloc((size_t)(4 * n + 1));
	if (!stack || !out) return 1;

	int top = -1;
	int next = 1;
	int out_idx = 0;

	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);

		if (next <= x)
		{
			while (next <= x)
			{
				if (top + 1 >= n) {
					printf("NO\n");
					free(stack);
					free(out);
					return 0;
				}
				stack[++top] = next++;
				out[out_idx++] = '+';
				out[out_idx++] = '\n';
			}
		}

		if (top >= 0 && stack[top] == x)
		{
			top--;
			out[out_idx++] = '-';
			out[out_idx++] = '\n';
		}
		else
		{
			printf("NO\n");
			free(stack);
			free(out);
			return 0;
		}

	}

	out[out_idx] = '\0';
	printf("%s", out);

	free(stack);
	free(out);
	return 0;
}