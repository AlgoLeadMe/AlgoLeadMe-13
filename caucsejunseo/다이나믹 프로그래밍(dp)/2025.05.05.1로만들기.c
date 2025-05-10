#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX 1000001


int main() {

    int N = 0;
    scanf("%d", &N);

    int* dp = (int*)malloc(sizeof(int) * MAX);

    if (dp == NULL) {
        printf("메모리 할당 실패!\n");
        return 1;
    }

    dp[1] = 0;

    for (int i = 2; i < N + 1; i++)
    {
        dp[i] = dp[i - 1] + 1;

        if (i % 3 == 0)
        {
            dp[i] = MIN(dp[i], dp[i / 3] + 1);
        }
        if (i % 2 == 0)
        {
            dp[i] = MIN(dp[i], dp[i / 2] + 1);
        }
    }

    printf("%d", dp[N]);

    return 0;
}
