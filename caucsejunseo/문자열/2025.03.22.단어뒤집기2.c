#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


char s[100001]; //���ڿ��� int���� char
char answer[100001];
char stack[100001];
//���������� �����ϸ� ������ ������ �Ҵ�ǹǷ� ũ�� ������
//���ϴ�. �Լ��ȿ��� �����ϸ� �����÷ο�� ���� �ִ�


int main()
{


	int i = 0;
	int top = -1;

	scanf("%[^\n]", &s);
	int len = strlen(s); //scanf �ڿ� �ۼ��ؾ�

	//top -1 --> ������ġ���� �����
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