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

void insert_node(struct Node *p, int pos, int value)
{
	struct Node *t = NULL;
	if (pos == 0)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = value;
		t->next = first;
		first = t;
	}
	else if (pos > 0)
	{
		p = first;
		int i = 0; 
		while (i < pos - 1 && p != NULL)
		{
			p = p->next;
			i++;
		}
		if (p != NULL)
		{
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = value;
			t->next = p->next;
			p->next = t;
		}
	}
}

int main(void)
{
	int arr[] = {3, 5, 7, 10, 15};
	int n = 5;

	struct Node *temp = NULL;
	int num = 15;

	create_list(arr, n);
	display_list(first);

	insert_node(first, 2, 20);

	display_list(first);

	return 0;
}