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

struct Node *search_list(int num, struct Node *p)
{
	while (p != NULL)
	{
		if (num == p->data)
			return p;
		p = p->next;
	}
	return NULL;
}

/* Recursive */
int r_search_list(int num, struct Node *p)
{
	if (p == NULL)
	{
		return 0;
	}
	if (num == p->data)
	{
		return p->data;
	}
	return r_search_list(num, p->next);
}


int main(void)
{
	int arr[] = {3, 5, 7, 10, 15};
	int n = 5;

	struct Node *temp = NULL;

	create_list(arr, n);
	display_list(first);

	int num = 15;
	temp = search_list(num, first);
	if (temp)
	{
		printf("Key is found %d\n", temp->data);
	}
	else 
	{
		printf("Key is not found\n");
	}
	return 0;
}