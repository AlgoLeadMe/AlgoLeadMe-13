#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
int main(void)
{
	int N = 0;
	scanf("%d\n", &N);
	int A[50] = { 0 };
	int B[50] = { 0 };
	
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &B[i]);
	}
	
	int n = sizeof(A) / sizeof(A[0]);
	std::sort(A, A + N);

	int C[50] = { 0 };
	for (int i = 0; i < N; i++)
	{
		C[i] = B[i];
	}
	int k = sizeof(B) / sizeof(B[0]);
	std::sort(B, B + N, std::greater<int>());
	int sum = 0;


	for (int i = 0; i < N; i++)
	{
		sum = sum + (A[i] * B[i]);
	}
	printf("%d", sum);

	for (int i = 0; i < N; i++)
	{
		B[i] = C[i];
	}
}