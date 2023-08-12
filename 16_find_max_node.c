#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int find_max(struct Node *p)
{
	int max = p->data;
	while (p != NULL)
	{
		if (p->data > max)
		{
			max = p->data;
		}
		p = p->next;
	}
	return max;
}

/* Recursive */
int r_find_max(struct Node *p)
{
	int x = 0;
	if (p == 0)
	{
		return INT_MIN;
	}
	else
	{
		x = r_find_max(p->next);
		if (x > p->data)
		{
			return x;
		}
		else
		{
			return p->data;
		}
	}
}


int main(void)
{
	int arr[] = {3, 5, 7, 10, 15};
	int n = 5;

	// struct Node *first = NULL;

	create_list(arr, n);
	display_list(first);

	int max = r_find_max(first);

	printf("Max %d\n", max);

	return 0;
}