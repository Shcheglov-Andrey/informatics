#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
struct list
{
	int value;
	struct list* next;
};
typedef struct list list;
printlist(list** head); /*������� ������*/
inithead(list** head, int a); /*������� ������*/
addfirst(list** head, int a); /*�������� � ������*/
afterp(list** head, int p); 
#endif
