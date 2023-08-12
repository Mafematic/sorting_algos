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

int count_nodes(struct Node *p)
{
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

int delete_node(struct Node *p, int index)
{
	struct Node *q = NULL;
	int x = -1;
	int i = 0;

	if (index < 1 || index > count_nodes(p))
		return -1;

	if (index == 1)
	{
		q = first;
		x = first->data;
		first = first->next;
		free(q); 
		return x;
	}
	else 
	{
		while (i < index - 1)
		{
			q = p;
			p = p->next;
			i++;
		}
		q->next = p->next;
		x = p->data;
		free(p);
		return x;
	}
}

int main(void)
{
	int arr[] = {3, 5, 7, 10, 15};
	int n = 5;


	create_list(arr, n);
	display_list(first);

	delete_node(first, 3);

	display_list(first);

	return 0;
}