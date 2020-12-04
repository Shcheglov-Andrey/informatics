#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "linkedlist.h"
#include <stdlib.h>
int main()
{
	int a, menu = -1;
	list* l = NULL;
	printf("Enter first number: ");
	scanf("%d", &a);
	inithead(&l, a);
	while (menu != 0)
	{
		printf("1 - print list\n");
		printf("2 - add number to the beginning\n");
		printf("3 - zero after p-numbers\n");
		printf("0 - Exit\n");
		scanf("%d", &menu);
		if (menu == 1)
		{
			if (l == NULL)
				printf("Empty\n");
			else
			{
				printf("Numbers in list: ");
				printlist(&l);
				printf("\n");
			}
		}
		else if (menu == 2)
		{
			int b;
			printf("Enter your number: ");
			scanf("%d", &b);
			addfirst(&l, b);
			printf("First number was added\n");
		}
		else if (menu == 3)
		{
			int p;
			printf("Enter p: ");
			scanf("%d", &p);
			afterp(&l,p);
			printf("Zero was added after each P-number\n");
		}
		else if (menu == 0)
		{
			printf("\n");
		}
		else
		{
			printf("Wrong number\n");
		}
	}
	printf("Stopping programm\n");
	return 0;
}