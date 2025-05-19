#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct
{
	int score;
	int time;

}Task;


int main()
{
	int top = -1;
	int total = 0;
	Task stack[1000001];

	int N = 0;
	scanf("%d", &N);

	int i = 0;
	for (i = 0; i < N; i++)
	{
		int new = 0;
		scanf("%d", &new);
		if (new == 1)
		{
			int A = 0;
			int T = 0;
			scanf("%d %d", &A, &T); //세그멘테이션 폴트: 잘못된 메모리에 접근
			stack[++top].score = A;
			stack[top].time = T;
		}

		if (top != -1)
		{
			stack[top].time -= 1;

			if (stack[top].time == 0)
			{
				total += stack[top].score;
				top--;
			}
		}



	}

	printf("%d", total);


	return 0;
}
