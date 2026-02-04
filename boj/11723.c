#include <stdio.h>

// 21, 0번쨰 0 , 나머지 전부 1
#define ALL_MASK ((1<<21) - 2)

static inline void set(int* S, int x)			{ *S |= (1 << x); }
static inline void clr(int* S, int x)			{ *S &= ~(1 << x); }
static inline int set_check(int S, int x)		{ return (S & (1 << x)) ? 1 : 0; }
static inline void set_toggle(int* S, int x)	{ *S ^= (1 << x); }
static inline void set_all(int* S)				{ *S = ALL_MASK; }
static inline void set_empty(int* S)			{ *S = 0; }

static inline void process_cmd(int* S, const char* cmd)
{
	int x;

	switch (cmd[0])
	{
	case 'a':
		if (cmd[1] == 'd') {
			scanf("%d", &x);
			set(S, x);
		}
		else { set_all(S); }
		break;
	case 'c':
		scanf("%d", &x);
		printf("%d\n", set_check(*S, x));
		break;
	case 'e':
		set_empty(S);
		break;
	case 'r':
		scanf("%d", &x);
		clr(S, x);
		break;
	case 't':
		scanf("%d", &x);
		set_toggle(S, x);
		break;
	}

}

int main()
{
	int M;
	int S = 0;
	char cmd[7];

	scanf("%d", &M);

	while (M--)
	{
		scanf("%6s", cmd);
		process_cmd(&S, cmd);
	}
	return 0;
}