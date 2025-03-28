#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



int stack[100001];
int top = -1;

int pop()
{
	if (top == -1)
	{
		printf("empty");
		return -1;
	}

	return stack[top--];

}
int push(char date)
{
	return stack[++top] = date;
}

int main()
{

	char srt[100001];
	int len;
	int count;
	int i = 0;
	int k = 0;
	int sum = 0;

	scanf("%d", &count);
	for (i = 0; i < count; i++)
	{
		top = -1;
		scanf("%s", &srt);   //문자열 전체받아야 함 [] X
		len = strlen(srt);  //srt[i]는 문자열 하나

		for (k = 0; k < len; k++)
		{
			if (top == -1)
			{
				push(srt[k]);
			}
			else if (stack[top] == srt[k])
			{
				pop();
			}
			else if (stack[top] != srt[k])
			{
				push(srt[k]);
			}

		}
		if (top == -1)
		{
			sum += 1;
		}
		for (int h = 0; h < len; h++)
		{

			stack[h] = '0';

		}
	}

	printf("%d", sum);




	return 0;
}
