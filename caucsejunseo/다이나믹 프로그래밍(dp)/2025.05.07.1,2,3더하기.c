#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    int T = 0;
    scanf("%d", &T);

    int dp[11];

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    int* count = (int*)malloc(sizeof(int) * T);
    int* answer = (int*)malloc(sizeof(int) * T);

    for (int i = 0; i < T; i++)
    {
        //값을 넘겨야 해서 &쓰기
        scanf("%d", &count[i]);

        if (count[i] < 4)
        {
            answer[i] = dp[count[i]];
        }
        else if (count[i] >= 4)
        {
            for (int k = 4; k <= count[i]; k++)
            {
                dp[k] = dp[k - 1] + dp[k - 2] + dp[k - 3];
            }
            answer[i] = dp[count[i]];
        }
    }

    for (int i = 0; i < T; i++)
    {
        printf("%d\n", answer[i]);
    }



    return 0;
}
/* 1
* 노가다
        1
        1

        2
        1 1
        2

        3
        1 1 1
        1 2
        2 1
        3

        4
        1 1 1 1
        1 1 2
        1 2 1
        2 1 1
        2 2
        1 3
        3 1

        5
        1 1 1 1 1
        1 1 1 2
        1 1 2 1
        1 2 1 1
        2 1 1 1
        1 2 2
        2 1 2
        2 2 1
        1 1 3
        1 3 1
        3 1 1
        2 3
        3 2

        6
        1 1 1 1 1 1
        1 1 1 1 2
        1 1 1 2 1
        1 1 2 1 1
        1 2 1 1 1
        2 1 1 1 1
        1 1 2 2
        1 2 1 2
        1 2 2 1
        2 1 1 2
        2 1 2 1
        2 2 1 1
        2 2 2
        1 1 1 3
        1 1 3 1
        1 3 1 1
        3 1 1 1
        1 2 3
        1 3 2
        2 1 3
        2 3 1
        3 1 2
        3 2 1
        3 3


        1 2 4 7 13 24*/