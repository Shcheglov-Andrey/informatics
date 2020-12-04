#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "linkedlist.h"
#include <stdlib.h>
printlist(list** head)
{
	list* l = *head;
	while (l != NULL)
	{
		printf("%d ", l->value);
		l = l->next;
	}
}
inithead(list** head, int a)
{
	list* l = (list*)malloc(sizeof(list));
	l->value = a;
	l->next = NULL;
	*head = l;
}
addfirst(list** head, int a)
{
	list* l = (list*)malloc(sizeof(list));
	l->value = a;
	l->next = *head;
	*head = l;
}
afterp(list** head, int p)
{
	list* l1 = *head;
	list* next = *head;
	
	while (l1 != NULL)
	{
		if (pnumb(l1,p))
		{
			list* l = (list*)malloc(sizeof(list));
			l->value = 0;
			l->next = l1->next;
			l1->next = l;
		}
		l1 = l1->next;
	}
}
int pnumb(list* l1, int p)
{
		if (l1->value == p)
		return 1;
	else
		return 0;
}