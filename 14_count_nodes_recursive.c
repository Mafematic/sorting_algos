#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
} * first = NULL;

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

void display_list (struct Node *p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}


/*
int r_count_nodes(struct Node *p)
{
	static int count = 0;
	if (p != NULL)
	{
		count++;
		r_count_nodes(p->next);
	}
	return count;
}
*/


int r_count_nodes(struct Node *p)
{
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		return r_count_nodes(p->next) + 1;
	}
}



int main(void)
{
	int arr[] = {3, 5, 7, 10, 15};
	int n = 5;

	// struct Node *first = NULL;


	create_list(arr, n);
	display_list(first);

	int count = r_count_nodes(first);

	printf("Count: %d\n", count);

	return 0;
}
