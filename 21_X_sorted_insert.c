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

void sorted_insert(struct Node *p, int value)
{
	struct Node *t = NULL;
	struct Node *q = NULL;
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = value;
	t->next = NULL;

	if (p == NULL)
	{
		p = t;
	}
	else
	{
		while (p != NULL && p->data < value)
		{
			q = p;
			p = p->next;
		}
		if (p == first)
		{
			t->next = p;
			p = t;
		}
	}

}

int main(void)
{
	int arr[] = {1, 5, 9, 10, 15};
	int n = 5;

	struct Node *temp = NULL;
	int num = 15;

	create_list(arr, n);
	display_list(first);

	sorted_insert(first, 12);

	display_list(first);

	return 0;
}