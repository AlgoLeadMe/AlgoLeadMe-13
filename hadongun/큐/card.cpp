#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int implement(int card[], int N);

int main(void)
{
    int N = 0;
    int card[500001] = { 0 };
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        card[i] = i + 1;
    }

    printf("%d", implement(card, N));

}

int implement(int car[], int k)
{
    int first_card;
    int last_card;
    int last_index;
    int moving_box;
    int saving_box;
    int temp_1 = 0;
    int temp_2 = 0;
    // 제일 위에 카드를 버린다. -> 모든 카드를 한 칸씩 아래로 땡겨오기
    //이후 제일 아래에 있는 카드를 맨 위로 보낸다.
    //카드가 1개 남을 때 까지 수행한다.

    //카드 한 칸씩 앞으로 땡기기
    while (car[1] != 0)
    {
        for (int i = 0; i < k - 1; i++)
        {
            car[i] = car[i + 1];
        }
        //제일 아래 카드를 맨 위로 보내기
        car[k - 1] = 0;
        k--;
        saving_box = car[0];
        // 카드 한 칸씩 앞으로 땅기기
        for (int i = 0; i < k - 1; i++)
        {
            car[i] = car[i + 1];
        }
        car[k - 1] = saving_box;
    }
    return(car[0]);
}