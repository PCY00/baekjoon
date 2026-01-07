#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 51

char stack[MAX] = { 0, };

int string_length(const char* str) {
	int size = 0;
	while (str[size] != '\0') {
		size++;
	}
	return size;
}

int main() {
	int T;
	char str[MAX];

	if (scanf("%d", &T) != 1) return 0;

	for (int i = 0; i < T; i++) {
		if (scanf("%50s", str) != 1) continue;

		int stack_index = 0;
		int size = string_length(str);
		int is_vps = 1; // 1: YES, 0: NO

		for (int j = 0; j < size; j++) {
			if (str[j] == '(') {
				// ( : 스택에 푸시 (인덱스 증가 후 값 삽입)
				stack[stack_index++] = '(';
			}
			else {
				if (stack_index > 0) {
					stack_index--;
				}
				else {
					// 스택이 비었는데 ')'가 들어온 경우 (짝이 맞지 않음)
					is_vps = 0;
					break; // 더 이상 검사할 필요 없음
				}
			}
		}

		if (is_vps && stack_index == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}