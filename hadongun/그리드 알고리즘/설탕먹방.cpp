#include <stdio.h>

int main()
{
    int N = 0;
    scanf("%d", &N);
    int sum = 0;
    if (N == 4)
    {
        goto end;

    }
    if (N == 3)
    {
        goto quick;
    }
    if (N > 4)
    {

        for (int i = 0; i < 5000; i++)
        {

            for (int k = 0; k < 5000; k++)
            {
                if (!(i == 0 && k == 0))
                {
                    if (N % (5 * i + 3 * k) == 0 && N / (5 * i + 3 * k) < 3)
                    {
                        sum = 0;
                        sum = i + k;
                    }
                }
            }
            // if �� ���ǿ��� 0���� ������ ������ ������ �߻���. �ƾƴϳ�
        }
    }
end:
    if (sum == 0)
    {
        printf("-1");
    }
    else
    {
        printf("%d", sum);
    }
quick:
    if (N == 3)
    {
        printf("1");
    }
}