#define _CRT_SECURE_NO_WARNINGS
#define B 1024
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
int main()
{
	int i,j, n;
	int** M;
	printf("Enter number of lines(N<=20):");
	scanf("%d", &n);
	if ((n > 20) || (n < 0))
		printf("Error\n");
	else
	{
		M = (int**)malloc(sizeof(int) * n);
		for (i = 0; i <n; i++)
		{
			M[i] = (int*)malloc(sizeof(int) * (i+1));
		}
		M[0][0] = 1;
		for (i = 1; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j == 0 || j == i)
					M[i][j] = 1;
				else
				{
					M[i][j] = M[i - 1][j - 1] + M[i - 1][j];
				}
			}
		}
		i = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < (i + 1); j++)
			{
				printf("%5d ", *(M + i * n + j));
			}
			printf("\n");
		}
	}
	for (i = 0; i < n; i++)
		free(M);
	while (getchar() != '\n');
	getchar();
	return 0;
}