#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100001

int heap[MAX];
int size = 0;

void push(int x)
{
    int i = size++;
    while (i > 0 && x < heap[(i - 1) / 2]) //부모 노드보다 작으면 위로 올림
    {
        heap[i] = heap[(i - 1) / 2];  // 부모 값을 아래로 내림
        i = (i - 1) / 2;
    }
    heap[i] = x;
}

int pop()
{
    if (size == 0) return 0;

    int min = heap[0]; //루트값이 최솟값이니까 루트값 저장
    int temp = heap[--size]; // 마지막 값을 꺼냄

    int parent = 0;
    int child = 1;

    while (child < size)
    {

        if (child + 1 < size && heap[child] > heap[child + 1])
            child++;

        if (temp <= heap[child]) break;

        heap[parent] = heap[child]; //자식을 부모 자리로 올림
        parent = child;
        child = 2 * parent + 1;
    }
    heap[parent] = temp; //temp를 적절한 위치에 삽입

    return min;
}


int main()
{
    int N, x;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        if (x == 0)
            printf("%d\n", pop());
        else
            push(x);
    }



    return 0;
}