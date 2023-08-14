#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int size;
	int top;
	int *s;
};

void create(struct stack *st)
{
	printf("Enter Size: ");
	scanf("%d", &st->size); 
	st->top = -1;
	st->s = (int *)malloc(st->size * sizeof(int)); 
}

void display(struct stack st)
{
	int i = st.top; 
	while (i >= 0)
	{
		printf("%d ", st.s[i]);
		i--;
	}
	printf("\n"); 
}

void push(struct stack *st, int x)
{
	if (st->top == st->size-1)
	{
		printf("Stack Overflow"); 
	}
	else
	{
		st->top++; 
		st->s[st->top] = x;
	}
}

int pop(struct stack *st)
{
	int x = -1; 
	if (st->top == -1)
	{
		printf("Stack Underflow\n"); 
	}
	else
	{
		x = st->s[st->top--];
	}
	return x;
}

int peek(struct stack st, int index)
{
	int x = -1;
	if (st.top - index + 1 < 0)
	{
		printf("Invalid Index\n");
	}
	x = st.s[st.top - index + 1];

	return x; 
}

int is_empty(struct stack st)
{
	if (st.top == -1)
	{
		return 1; 
	}
	return 0;
}

int is_full(struct stack st)
{
	return st.top = st.size - 1;
}

int stack_top(struct stack st)
{
	if (!is_empty(st))
	{
		return st.s[st.top];
	}
	return -1;
}

int main(void)
{
	struct stack st; 
	create(&st);
	push(&st, 10);
	push(&st, 20);
	push(&st, 30);
	push(&st, 40);

	printf("%d \n", peek(st, 1));

	display(st);

	return 0;
}