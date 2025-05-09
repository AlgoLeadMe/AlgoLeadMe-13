#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include <string.h>
#include <stdlib.h>

#define MAX_parrot 100
#define MAX_words 100
#define WORDLINE 33 

char sentence[350000];
char line[350000];

typedef struct
{
	char words[MAX_words][WORDLINE];
	int front, rear;
}Queue;

void initqueue(Queue* q) //Queue* q는 Queue 구조체의 주소를 매개변수로 받겠다는 뜻
{
	q->front = q->rear = 0;    // q.front = 0;  직접 구조체일 때는 .
}                              //qr->front = 0;  포인터일 땐 -> . (*q).front의 줄임표현

void enqueue(Queue* q, char* word)
{
	strcpy(q->words[q->rear++], word);
}

int dequeue(Queue* q, char* buffer)
{
	if (q->front < q->rear) {
		strcpy(buffer, q->words[q->front++]);
		return 1;
	}
	return 0;
}

int isEmpty(Queue* q) {
	return q->front == q->rear;
}
Queue parrot[MAX_parrot];
int main()

{
	int N;
	scanf("%d\n", &N); //fgets 쓸때 \n처리



	int i = 0;
	for (i = 0; i < N; i++)
	{
		initqueue(&parrot[i]);



		fgets(line, sizeof(line), stdin);

		char* token = strtok(line, " \n");//**"단어 전체를 가리키는 포인터"**니까 → char* token

		while (token)
		{
			enqueue(&parrot[i], token);
			token = strtok(NULL, " \n");
		}

	}

	fgets(sentence, sizeof(sentence), stdin);

	char* token = strtok(sentence, " \n");
	int success = 1;

	while (token)
	{
		int found = 0;
		for (i = 0; i < N; i++)
		{
			if (!isEmpty(&parrot[i]) && strcmp(parrot[i].words[parrot[i].front], token) == 0)
			{
				parrot[i].front++;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			success = 0;
			break;
		}

		token = strtok(NULL, " \n");


	}
	if (success) {
		for (int i = 0; i < N; ++i) {
			if (!isEmpty(&parrot[i])) {
				success = 0;
				break;
			}
		}
	}

	if (success == 1)
		printf("Possible");
	else if (success == 0)
		printf("Impossible");


	return 0;
}