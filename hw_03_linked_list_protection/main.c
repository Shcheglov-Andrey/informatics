#include<stdio.h>
#include< stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
void create_head_function(Node** head, Node** last) 
{
	*head = (Node*)malloc(sizeof(Node)); (*head)->next = NULL;
	*last = *head;
}
void add_new_element_function(Node** last, int x)
{
	Node* q;
	q = (Node*)malloc(sizeof(Node));
	q->data = x; 
	q->next = NULL; 
	(*last)->next = q;
	*last = q;
}

void print_list_function(Node* head)
{
	Node* q; q = head->next;
	while (q != NULL)
	{
		printf("%d ", q->data); q = q->next;
	}
	printf("\n");
}
void filter_function(Node* head, Node** last, int p)
{
	Node* q, * temp; q = head;
	while (q->next != NULL)
	{
		if (q->next->data % p)
		{
			temp = q->next;
			q->next = q->next->next;
			free(temp);
		}
		else
		{
			q = q->next;
		}
	}
	*last = q;
}
void distruct_list_function(Node* head, Node** last)
{
	Node* q, * temp; q = head->next;
	while (q != NULL)
	{
		temp = q;
		q = q->next;
		free(temp);
	}

	head->next = NULL; *last = head;
}
int main()
{
	Node* head, * last; 
	int value, p, size;
	int counter = 1;
	int flag = 1;
	printf("Welcome to filter list program, for stop entering new elements, enter 0 in the current elements\n");
	while (flag != 0)
	{
		printf("Input p = ");
		scanf_s("%d", &p);
		if (p > 1)
		{
			create_head_function(&head, &last); 
			printf("element %d:", counter);
			scanf_s("%d", &value);
			while (value != NULL) 
			{
				counter++;
				add_new_element_function(&last, value); 
				printf("element %d:", counter);
				scanf_s("%d", &value);

			}
			printf("Old list ");
			print_list_function(head); 
			filter_function(head, &last, p);
			printf("New list ");
			print_list_function(head);
			distruct_list_function(head, &last); 
			printf("\n");
			printf(" press 1 to try again or 0 to finish programm ");
			scanf_s("%d", &flag);
			printf("\n");
			if (flag == 0)
			{
				return 0;
			}
		}
		else
		{
			printf("ERROR!!!! Incorrect value of p... \n");
			printf(" press 1 to try again or 0 to finish programm ");
			scanf_s("%d", &flag);
			printf("\n");
			if (flag == 0)
			{
				return 0;
			}
		}
	}

}
