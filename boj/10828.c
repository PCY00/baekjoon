#include <stdio.h>
#include <string.h>

#define MAX 10001

typedef struct stack {
	int arr[MAX];
	int top;
}S;

static S s;

void init_stack()
{
	s.top = -1;
}

void push(int x)
{
	s.arr[++s.top] = x;
}

int pop()
{
	if (empty()) return -1;
	return s.arr[s.top--];
}

int size()
{
	return s.top + 1;
}

int empty()
{
	if (s.top == -1) return 1;
	return 0;
}

int top()
{
	if (s.top == -1) return -1;
	return s.arr[s.top];
}

int main()
{
	int N;
	char cmd[6];

	scanf("%d", &N);

	init_stack();
	
	for (int i = 0; i < N; i++)
	{
		scanf("%5s", cmd);

		if (strcmp(cmd, "push") == 0) {
			int num;
			scanf("%d", &num);

			push(num);
		}
		else if (strcmp(cmd, "pop") == 0) printf("%d\n", pop());
		else if (strcmp(cmd, "size") == 0) printf("%d\n", size());
		else if (strcmp(cmd, "empty") == 0) printf("%d\n", empty());
		else if (strcmp(cmd, "top") == 0) printf("%d\n", top());
		else return 0;
	}
	return 0;
}