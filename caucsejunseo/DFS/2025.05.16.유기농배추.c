#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 51

int arr[MAX][MAX];
int visited[MAX][MAX];
int count;

int tree(int a, int b)
{
    int count = 0;
    if (arr[b][a] == 1 && visited[b][a] == 0)
    {
        visited[b][a] = 1;
        count++;
        if (b != 0 && visited[b - 1][a] != 1 && arr[b - 1][a] == 1) //위
        {
            count += tree(a, b - 1);
        }
        if (b + 1 < MAX && visited[b + 1][a] != 1 && arr[b + 1][a] == 1)//아래
        {
            count += tree(a, b + 1);
        }
        if (a != 0 && visited[b][a - 1] != 1 && arr[b][a - 1] == 1)//왼
        {
            count += tree(a - 1, b);
        }
        if (a + 1 < MAX && visited[b][a + 1] != 1 && arr[b][a + 1] == 1)

        {
            count += tree(a + 1, b);
        }
        return count;
    }
    else
    {
        return 0;
    }


}


int main()
{
    int T = 0;
    scanf("%d", &T);
    int* answer = (int*)malloc(sizeof(int) * T);
    int top = 0;

    for (int i = 0; i < T; i++)
    {

        // 배열 초기화
        for (int y = 0; y < MAX; y++) {
            for (int x = 0; x < MAX; x++) {
                arr[y][x] = 0;
                visited[y][x] = 0;
            }
        }


        int M, N, K;
        scanf("%d %d %d", &N, &M, &K);




        for (int j = 0; j < K; j++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            arr[b][a] = 1;
        }

        for (int I = 0; I < N; I++) {
            for (int J = 0; J < M; J++)
            {
                int t = tree(I, J);
                if (t > 0)
                {
                    K = K - t + 1;

                }

            }

        }


        answer[top++] = K;



    }

    for (int i = 0; i < T; i++)
    {
        printf("%d\n", answer[i]);
    }


    return 0;
}