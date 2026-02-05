#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N_MAX 20

typedef struct {
    char name[N_MAX + 1];
    int idx;
} Pbook;

static int cmp(const void* a, const void* b)
{
    const Pbook* A = (const Pbook*)a;
    const Pbook* B = (const Pbook*)b;
    return strcmp(A->name, B->name);
}

static int binary_search_pair(Pbook* pb, int N, const char* key)
{
    int lo = 0, hi = N - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        int c = strcmp(pb[mid].name, key);
        if (c == 0) return pb[mid].idx;
        else if (c < 0) lo = mid + 1;
        else hi = mid - 1;
    }
    return 0;
}

int main(void)
{
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 1;

    char (*cp_pb)[N_MAX + 1] = malloc(sizeof(*cp_pb) * N);
    if (!cp_pb) return 1;

    Pbook* pb = malloc(sizeof(*pb) * N);
    if (!pb) return 1;

    for (int i = 0; i < N; i++)
    {
        if (scanf("%20s", cp_pb[i]) != 1) return 1;

        strcpy(pb[i].name, cp_pb[i]);
        pb[i].idx = i + 1;
    }

    qsort(pb, N, sizeof(Pbook), cmp);

    char input_str[N_MAX + 1];
    for (int i = 0; i < M; i++)
    {
        if (scanf("%20s", input_str) != 1) return 1;

        if (isdigit((unsigned char)input_str[0]))
        {
            int idx = atoi(input_str);
            puts(cp_pb[idx - 1]);
        }
        else
        {
            int idx = binary_search_pair(pb, N, input_str);
            printf("%d\n", idx);
        }
    }

    free(pb);
    free(cp_pb);
    return 0;
}
