#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


char s[100001]; //문자열은 int말고 char
char answer[100001];
char stack[100001];
//전역변수로 선언하면 데이터 영역에 할당되므로 크기 제한이
//덜하다. 함수안에서 선언하면 오버플로우될 수도 있다


int main()
{


	int i = 0;
	int top = -1;

	scanf("%[^\n]", &s);
	int len = strlen(s); //scanf 뒤에 작성해야

	//top -1 --> 현재위치에서 사용하
	for (i = 0; i < len; i++)
	{
		if (s[i] == '<')
		{
			while (top != -1)
			{
				answer[i - (top + 1)] = stack[top];
				top--;
			}

			while (s[i] != '>')
			{
				answer[i] = s[i];
				i++;
			}
			answer[i] = s[i];
		}
		else if (s[i] == ' ')
		{
			while (top != -1)
			{
				answer[i - (top + 1)] = stack[top];
				top--;
			}
			answer[i] = s[i];
		}
		else
		{
			top++;
			stack[top] = s[i];
		}
	}
	while (top != -1)
	{
		answer[i - (top + 1)] = stack[top];
		top--;
	}

	printf("%s", answer);


	return 0;
}