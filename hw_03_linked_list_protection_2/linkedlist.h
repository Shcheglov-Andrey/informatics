#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
struct list
{
	int value;
	struct list* next;
};
typedef struct list list;
printlist(list** head); /*выводит список*/
inithead(list** head, int a); /*создает список*/
addfirst(list** head, int a); /*ƒобавить в начало*/
afterp(list** head, int p); 
#endif
