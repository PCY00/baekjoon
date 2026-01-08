#include <stdio.h>

int main(void)
{
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int count5 = N / 5;          // 5kg 최대 사용 개수부터 시작
    int ans = -1;

    while (count5 >= 0) {
        int rem = N - 5 * count5; // 5kg count5개 쓰고 남은 무게
        if (rem % 3 == 0) {
            ans = count5 + (rem / 3);
            break;               // 5를 최대한 썼으니 여기서 break하면 최소 보장
        }
        count5--;                // 5kg 한 개 줄이고 다시 시도
    }

    printf("%d\n", ans);
    return 0;
}