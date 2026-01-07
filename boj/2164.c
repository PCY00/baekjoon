//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct link {
//	int value;
//	struct link* next;
//}L;
//
//L* head = NULL;
//L* tail = NULL;
//
//void create(int N)
//{
//	for (int i = 1; i <= N; i++)
//	{
//		L* node = (L*)malloc(sizeof(L));
//		if (!node) exit(1);
//		node->value = i;
//		node->next = NULL;
//
//		if (head == NULL) head = tail = node;
//		else {
//			tail->next = node;
//			tail = node;
//		}
//	}
//}
//
//void solution()
//{
//	int action = 0;
//	while (head != tail)
//	{
//		// 맨 앞 제거
//		if (action == 0)
//		{
//			L* Del = head;
//			head = head->next;
//			free(Del);
//
//			action = 1;
//		}
//		// 그 뒤는 맨 뒤로 보내기
//		else
//		{
//			L* current = head;
//			tail->next = head;
//			head = head->next;
//			current->next = NULL;
//			tail = current;
//
//			action = 0;
//		}
//	}
//
//	printf("%d\n", head->value);
//	free(head);
//	head = tail = NULL;
//}
//
//int main()
//{
//	int N;
//
//	scanf("%d", &N);
//
//	// O(N)
//	create(N);
//
//	solution();
//	
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    if (scanf_s("%d", &N) != 1) return 0;

    // 큐 용량: N개면 충분 (원형 큐)
    int* q = (int*)malloc(sizeof(int) * (size_t)N);
    if (!q) return 0;

    int front = 0;   // pop 위치
    int rear = 0;    // push 위치 (다음에 들어갈 자리)
    int size = 0;    // 현재 원소 개수

    // 1..N 초기화 (push)
    for (int i = 1; i <= N; i++) {
        q[rear] = i;
        rear = (rear + 1) % N;
        size++;
    }

    // size가 1개 남을 때까지 반복
    while (size > 1)
    {
        // 1) 맨 앞 버리기 (pop)
        front = (front + 1) % N;
        size--;

        // 2) 맨 앞을 맨 뒤로 보내기: x = pop(); push(x);
        int x = q[front];
        front = (front + 1) % N;
        size--;

        q[rear] = x;
        rear = (rear + 1) % N;
        size++;
    }

    // 마지막 남은 값은 q[front]
    printf("%d\n", q[front]);

    free(q);
    return 0;
}
