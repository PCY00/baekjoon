#include <stdio.h>
#include <stdlib.h>

#define MAX 20001

typedef struct BOX {
	char str[51];
	int size;
}box;

static int str_len(const char *s)
{
	int length = 0;
	while (s[length] != '\0') length++;

	return length;
}

static int my_strcmp(const char* a, const char* b)
{
	int i = 0;
	while (a[i] != '\0' && b[i] != '\0')
	{
		if (a[i] != b[i]) return (a[i] < b[i]) ? -1 : 1;
		i++;
	}
	if (a[i] == '\0' && b[i] == '\0') return 0;
	return (a[i] == '\0') ? -1 : 1;

}

static int cmp(const void* a, const void* b)
{
	const box* A = (const box*)a;
	const box* B = (const box*)b;

	if (A->size != B->size) return (A->size < B->size) ? -1 : 1;
	return my_strcmp(A->str, B->str);
}

int main()
{
	int N;
	scanf("%d", &N);

	box* arr = (box*)malloc(sizeof(box) * N);
	if (!arr) return 1;

	for (int i = 0; i < N; i++)
	{
		scanf("%s", arr[i].str);
		arr[i].size = str_len(arr[i].str);
	}

	qsort(arr, N, sizeof(box), cmp);

	if (N > 0)
	{
		printf("%s\n", arr[0].str);
		for (int i = 1; i < N; i++)
		{
			if (my_strcmp(arr[i].str, arr[i - 1].str) != 0) {
				printf("%s\n", arr[i].str);
			}
		}
	}

	free(arr);
	return 0;
}