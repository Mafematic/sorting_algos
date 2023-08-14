#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*top = NULL;

void push(int x)
{
	struct Node *t;
	t = (struct Node *)malloc(sizeof(struct Node));

	if (t == NULL)
	{
		printf("Stack is full\n");
	}
	else 
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}

int pop()
{
	struct Node *t;
	int x = -1; 

	if (top == NULL)
	{
		printf("Stack is empty\n");
	}
	else 
	{
		t = top;
		top = top->next; 
		x = t->data; 
		free(t); 
	}
	return x; 
}

void display()
{
	struct Node *p;
	p = top; 
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next; 
	}
	printf("\n"); 
}

void pa(struct Node **a, struct Node **b)
{
	int data = pop(b);
	if (data != -1)
	{ // check if b was not empty
		push(a, data);
	}
}

void pb(struct Node **a, struct Node **b)
{
	int data = pop(a);
	if (data != -1)
	{ // check if a was not empty
		push(b, data);
	}
}

int main (void)
{
	push(10);
	push(20);
	push(30);

	display();

	return 0; 
}