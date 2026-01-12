#include <stdio.h>
#include <string.h>

#define MAX 10001

typedef struct {
    int front;
    int rear;
    int count;
    int buf[MAX];
} Queue;

static Queue q;

static void queue_init(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

static int queue_empty(const Queue* q) {
    return (q->count == 0);
}

static int queue_size(const Queue* q) {
    return q->count;
}

static int queue_push(Queue* q, int x) {
    if (q->count == MAX) return 0;
    q->buf[q->rear] = x;
    q->rear = (q->rear + 1) % MAX;
    q->count++;
    return 1;
}

static int queue_pop(Queue* q) {
    if (queue_empty(q)) return -1;
    int v = q->buf[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return v;
}

static int queue_front(const Queue* q) {
    if (queue_empty(q)) return -1;
    return q->buf[q->front];
}

static int queue_back(const Queue* q) {
    if (queue_empty(q)) return -1;
    int idx = (q->rear - 1 + MAX) % MAX;
    return q->buf[idx];
}

int main(void) {
    int N;
    scanf("%d", &N);

    queue_init(&q);

    for (int i = 0; i < N; i++) {
        char cmd[6];
        scanf("%5s", cmd);

        if (strcmp(cmd, "push") == 0) {
            int x;
            scanf("%d", &x);
            queue_push(&q, x);
        }
        else if (strcmp(cmd, "pop") == 0) {
            printf("%d\n", queue_pop(&q));
        }
        else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", queue_size(&q));
        }
        else if (strcmp(cmd, "empty") == 0) {
            printf("%d\n", queue_empty(&q));
        }
        else if (strcmp(cmd, "front") == 0) {
            printf("%d\n", queue_front(&q));
        }
        else if (strcmp(cmd, "back") == 0) {
            printf("%d\n", queue_back(&q));
        }
    }
    return 0;
}
