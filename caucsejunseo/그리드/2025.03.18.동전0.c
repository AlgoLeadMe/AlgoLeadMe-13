#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	int kind, amount, sum = 0;
	int arr[11] = { 0 };


	scanf("%d %d", &kind, &amount);

	for (int i = 1; i <= kind; i++)
	{
		scanf("%d", &arr[i]);
	}



	for (int i = 0; i <= kind - 1; i++)
	{
		if (arr[kind - i] <= amount)
		{
			sum += amount / arr[kind - i];

			amount -= (amount / arr[kind - i]) * arr[kind - i];

		}
	}



	printf("%d", sum);



	return 0;
}
