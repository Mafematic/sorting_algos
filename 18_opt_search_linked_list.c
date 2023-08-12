#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
} *first = NULL;

void create_list(int arr[], int n)
{
	int i;
	struct Node *t, *last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = arr[0];
	first->next = NULL;
	last = first;

	i = 1;
	while (i < n)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = arr[i];
		t->next = NULL;
		last->next = t;
		last = t;
		i++;
	}
}

void display_list(struct Node *p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

struct Node *search_list(struct Node *p, int key)
{
	struct Node *q = NULL;
	while (p != NULL)
	{
		if (key == p->data)
		{
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next; 
	}
	return NULL;
}

int main(void)
{
	int arr[] = {3, 5, 7, 10, 15};
	int n = 5;

	struct Node *temp = NULL;
	int num = 15;

	create_list(arr, n);
	display_list(first);

	temp = search_list(first, num);
	if (temp)
	{
		printf("Key is found %d\n", temp->data);
	}
	else 
	{
		printf("Key is not found\n");
	}

	display_list(first);

	return 0;
}