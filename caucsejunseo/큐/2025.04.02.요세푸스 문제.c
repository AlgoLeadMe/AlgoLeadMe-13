#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h> //malloc�� ����ϱ� ����

int main()
{

	int i = 0;
	int N = 0;
	int K = 0;
	int count = 0;//���� ��� ��
	int step = 0;// ���� �� Ȯ��
	int gun = 0;
	scanf("%d", &N);
	scanf("%d", &K);


	int* table = (int*)malloc(N * sizeof(int)); //c������ �����Ϳ� �迭�� ����.

	if (table == NULL) {
		printf("�޸� �Ҵ� ����\n");
		return 1;
	}
	if (table != NULL)
	{
		for (i = 0; i < N; i++)
		{
			table[i] = i + 1;
		}

		gun = K - 1;
		printf("<%d", table[gun]);
		table[gun] = 0;
		count++;
		gun = (gun + 1) % N;

		while (count < N)
		{
			step = 0;
			while (step < K)
			{
				if (table[gun] != 0)
				{
					step++;

				}
				gun = (gun + 1) % N;
			}
			gun = (gun - 1 + N) % N;

			if (table[gun] != 0)
			{
				printf(", %d", table[gun]);
				table[gun] = 0;
				count++;
			}



		}
		printf(">");

	}

	free(table);

	return 0;
}