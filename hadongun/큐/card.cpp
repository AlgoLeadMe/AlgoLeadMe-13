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

    while (car[1] != 0)
    {
        for (int i = 0; i < k - 1; i++)
        {
            car[i] = car[i + 1];
        }
 
        car[k - 1] = 0;
        k--;
        saving_box = car[0];
  
        for (int i = 0; i < k - 1; i++)
        {
            car[i] = car[i + 1];
        }
        car[k - 1] = saving_box;
    }
    return(car[0]);
}
