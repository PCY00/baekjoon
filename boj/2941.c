#include <stdio.h>

int main(void)
{
    char s[101];
    scanf("%100s", s);

    int i = 0, cnt = 0;

    while (s[i] != '\0') {
        if (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=') {
            cnt++;
            i += 3;
        }
        else if ((s[i] == 'c' && (s[i + 1] == '=' || s[i + 1] == '-')) ||
            (s[i] == 'd' && s[i + 1] == '-') ||
            (s[i] == 'l' && s[i + 1] == 'j') ||
            (s[i] == 'n' && s[i + 1] == 'j') ||
            (s[i] == 's' && s[i + 1] == '=') ||
            (s[i] == 'z' && s[i + 1] == '=')) {
            cnt++;
            i += 2;
        }
        else {
            cnt++;
            i += 1;
        }
    }

    printf("%d\n", cnt);
    return 0;
}
