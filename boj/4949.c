#include <stdio.h>
#include <string.h>

#define MAX 102

typedef struct stack
{
    int top;
    char box[MAX];
}S;

void stack_init(S* s)
{
    s->top = -1;
}

int is_empty(S* s)
{
    if (s->top == -1) return 1;
    return 0;
}

int is_full(S* s)
{
    if (s->top == MAX - 1) return 1;
    return 0;
}

void push(S* s, char value)
{
    if (is_full(s)) return;
    s->box[++s->top] = value;
}

int peek(S* s)
{
    if (is_empty(s)) return '\0';
    return s->box[s->top];
}

void pop(S* s)
{
    if (is_empty(s)) return;
    s->top--;
}

int main()
{
    char line[MAX];
    S s;

    while (fgets(line, sizeof(line), stdin) != NULL)
    {
        if (line[0] == '.' && (line[1] == '\n' || line[1] == '\0')) {
            break;
        }

        stack_init(&s);
        int error = 0;

        for (int i = 0; line[i] != '\0'; i++)
        {
            char ch = line[i];
            if (ch == '.') break;
            if (ch == '(' || ch == '[') push(&s, ch);
            else if (ch == ')' || ch == ']')
            {
                if (is_empty(&s))
                {
                    error = 1;
                    break;
                }

                char t = peek(&s);

                if ((s.box[s.top] == '(' && ch == ')') || (s.box[s.top] == '[' && ch == ']'))
                {
                    pop(&s);
                }
                else
                {
                    error = 1;
                    break;
                }
            }
        }

        if (!error && is_empty(&s)) puts("yes");
        else puts("no");
    }

	return 0;
}