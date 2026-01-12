#include <stdio.h>

typedef struct {
    int pr;        // priority
    int isTarget;  // 1이면 우리가 찾는 문서
} Doc;

int main(void)
{
    int T;
    if (scanf("%d", &T) != 1) return 1;

    while (T--) {
        int N, M;
        if (scanf("%d %d", &N, &M) != 2) return 1;

        // N <= 100 이라서 동적할당 없이 고정 배열로 충분 (임베디드 스타일)
        Doc q[100];
        int head = 0, tail = 0, len = 0;

        int cnt[10] = { 0 }; // 0~9 (실사용 1~9)

        // 입력: 큐에 넣기
        for (int i = 0; i < N; i++) {
            int p;
            scanf("%d", &p);
            q[tail].pr = p;
            q[tail].isTarget = (i == M);
            tail = (tail + 1) % 100;
            len++;
            cnt[p]++;
        }

        // 현재 최대 우선순위 찾기
        int curMax = 9;
        while (curMax >= 1 && cnt[curMax] == 0) curMax--;

        int printed = 0;

        while (1) {
            // pop front
            Doc cur = q[head];
            head = (head + 1) % 100;
            len--;

            if (cur.pr < curMax) {
                // 뒤에 더 큰 우선순위가 존재 -> 뒤로 보내기 (push back)
                q[tail] = cur;
                tail = (tail + 1) % 100;
                len++;
            }
            else {
                // 인쇄
                printed++;
                cnt[cur.pr]--;

                if (cur.isTarget) {
                    printf("%d\n", printed);
                    break;
                }

                // curMax가 소진되었으면 다음 최대 찾기
                while (curMax >= 1 && cnt[curMax] == 0) curMax--;
            }
        }
    }
    return 0;
}
