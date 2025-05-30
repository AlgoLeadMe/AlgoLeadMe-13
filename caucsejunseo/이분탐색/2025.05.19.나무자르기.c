#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdbool.h>



int main()
{

	int N, M;
	scanf("%d %d", &N, &M);

	int* arr = (int*)malloc(sizeof(int) * N);
	int biggist = 0;


	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		if (biggist < arr[i])
		{
			biggist = arr[i];
		}
	}


	long long left = 0;
	long long right = biggist;
	long long answer = 0;

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long result = 0;


		for (long long i = 0; i < N; i++)
		{
			if (mid < arr[i])
			{
				result = result + (arr[i] - mid);
			}
		}
		if (result >= M)
		{

			answer = mid;

			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}

	}

	printf("%lld", answer);


	return 0;
}