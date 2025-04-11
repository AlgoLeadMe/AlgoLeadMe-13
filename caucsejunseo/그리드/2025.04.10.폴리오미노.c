#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include <string.h>

#define MAX 51
#define OUTPUT_MAX 500

int main()
{
    char str[MAX];
    scanf("%s", str);

    char div[MAX] = { 0 };
    char result[OUTPUT_MAX] = { 0 };  // 결과 저장용
    int res_index = 0;
    int i = 0, j = 0;
    int len1 = strlen(str);

    for (i = 0; i <= len1; i++)
    {
        if (str[i] == '.' || str[i] == '\0')
        {
            int len2 = strlen(div);

            if (len2 % 2 != 0) {
                printf("-1\n");
                return 0; // 중간에 오류 발생 시 즉시 종료
            }

            for (int k = 0; k < len2 / 4; k++)
                strcat(result, "AAAA");
            for (int k = 0; k < (len2 % 4) / 2; k++)
                strcat(result, "BB");

            if (str[i] == '.')
                strcat(result, ".");

            memset(div, 0, sizeof(div));
            j = 0;
        }
        else
        {
            div[j++] = str[i];
        }
    }

    printf("%s\n", result);  // 모든 구간 처리 후 출력

    return 0;
}
