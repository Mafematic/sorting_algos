#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// ./ push_swap 2 1 3 6 5 8

struct Node
{
	int data;
	struct Node *next;
};

static int ft_iswhitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
	{
		return (1);
	}
	return (0);
}

long ft_atoi(const char *nptr, int *error)
{
	int i;
	int is_negative;
	long num;

	i = 0;
	is_negative = 1;
	num = 0;
	while (ft_iswhitespace(nptr[i]))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		is_negative *= -1;
		i++;
	}
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
	{
		*error = 1;
		return (0);
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num += nptr[i] - '0';
		i++;
	}
	return (num * is_negative);
}

void push(struct Node **p, int x)
{
	struct Node *t;
	t = (struct Node *)malloc(sizeof(struct Node));
	if (t == NULL)
	{
		printf("Memory Allocation failed.\n");
		return ;
	}
	else
	{
		t->data = x;
		t->next = *p;
		*p = t;
	}
}

struct Node *pop(struct Node **p)
{
	if (*p == NULL)
	{
		return NULL;
	}
	struct Node *temp = *p;
	*p = (*p)->next;
	return temp;
}

void pa(struct Node **a, struct Node **b)
{
	struct Node *node = pop(b);
	if (node != NULL)
	{ // check if b was not empty
		push(a, node->data);
		free(node);
	}
}

void pb(struct Node **a, struct Node **b)
{
	struct Node *node = pop(a);
	if (node != NULL)
	{ // check if a was not empty
		push(b, node->data);
		free(node); 
	}
}

void sa(struct Node **a)
{
	if (*a == NULL || (*a)->next == NULL) {
        return; // Nothing to swap
    }
	struct Node *first = *a;
	struct Node *second = (*a)->next;
	first->next = second->next;
	second->next = first; 
	*a = second;
}

void sb(struct Node **b)
{
	if (*b == NULL || (*b)->next == NULL) {
        return; // Nothing to swap
    }
	struct Node *first = *b;
	struct Node *second = (*b)->next; 
	first->next = second->next;
	second->next = first;
	*b = second;
}

void ss(struct Node **a, struct Node **b)
{
	if (*a != NULL && (*a)->next != NULL)
	{
        struct Node *first_a = *a;
        struct Node *second_a = (*a)->next;
        first_a->next = second_a->next;
        second_a->next = first_a;
        *a = second_a;
    }
    if (*b != NULL && (*b)->next != NULL)
	{
        struct Node *first_b = *b;
        struct Node *second_b = (*b)->next;
        first_b->next = second_b->next;
        second_b->next = first_b;
        *b = second_b;
    }
}

void ra(struct Node **a)
{
	if (*a == NULL || (*a)->next == NULL) {
        return;
    }
	struct Node *temp = *a;
	struct Node *last = *a;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*a = (*a)->next;
	temp->next = NULL;
	last->next = temp;
}

void rb(struct Node **b)
{
	if (*b == NULL || (*b)->next == NULL) {
        return;
    }
	struct Node *temp = *b;
	struct Node *last = *b;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*b = (*b)->next;
	temp->next = NULL;
	last->next = temp;
}

void rr(struct Node **a, struct Node **b)
{
	if (*a != NULL && (*a)->next != NULL)
	{
		struct Node *temp = *a;
		struct Node *last = *a;
		while (last->next != NULL)
		{
			last = last->next;
		}
		*a = (*a)->next;
		temp->next = NULL;
		last->next = temp;
	}
	if (*b != NULL && (*b)->next != NULL)
	{
		struct Node *temp = *b;
		struct Node *last = *b;
		while (last->next != NULL)
		{
			last = last->next;
		}
		*b = (*b)->next;
		temp->next = NULL;
		last->next = temp;
	}
}

void rra(struct Node **a)
{
	if (*a == NULL || (*a)->next == NULL) {
        return;
    }
	struct Node *node_before_last = *a;
	struct Node *last = *a;
	while (last->next != NULL)
	{
		node_before_last = last;
		last = last->next;
	}
	node_before_last->next = NULL;
	last->next = *a;
	*a = last;
}

void rrb(struct Node **b)
{
	if (*b == NULL || (*b)->next == NULL) {
        return;
    }
	struct Node *node_before_last = *b;
	struct Node *last = *b;
	while (last->next != NULL)
	{
		node_before_last = last;
		last = last->next;
	}
	node_before_last->next = NULL;
	last->next = *b;
	*b = last;
}

void rrr(struct Node **a, struct Node **b)
{
	if (*a != NULL && (*a)->next != NULL)
	{
		struct Node *node_before_last = *a;
		struct Node *last = *a;
		while (last->next != NULL)
		{
			node_before_last = last;
			last = last->next;
		}
		node_before_last->next = NULL;
		last->next = *a;
		*a = last;
	}

	if (*b != NULL && (*b)->next != NULL)
	{
		struct Node *node_before_last = *b;
		struct Node *last = *b;
		while (last->next != NULL)
		{
			node_before_last = last;
			last = last->next;
		}
		node_before_last->next = NULL;
		last->next = *b;
		*b = last;
	}
}

void display(struct Node *p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void free_stack(struct Node *p)
{
	struct Node *temp;
	while (p != NULL)
	{
		temp = p;
		p = p->next;
		free(temp);
	}
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

int count_digits(int max)
{
    int count = 0;
    if (max == 0) return 1;
    while (max > 0)
    {
        count++;
        max /= 10;
    }
    return count;
}


int count_size(struct Node *a)
{
	int count = 0;
	while (a->next != NULL)
	{
		count++;
		a = a->next;
	}
	return count + 1;
}


int get_digit(int num, int position) {
    // Return the digit at the given position (0-based)
    // position = 0 for least significant digit, 1 for next, and so on.
    for(int i = 0; i < position; i++) {
        num /= 10;
    }
    return num % 10;
}

void radix(struct Node **sa, struct Node *sb[10])
{
    int max = find_max(*sa);
    int digits = count_digits(max);
    
    for (int position = 0; position < digits; position++) {
        printf("\nPosition: %d\n", position); // Debug
        
        // Distribute numbers into digit buckets (using stack sb)
        while (*sa != NULL) {
            int number = pop(sa)->data;
            int digit = get_digit(number, position);
            printf("Distributing %d to bucket %d\n", number, digit); // Debug
            push(&sb[digit], number); // Push onto sb (bucket stack)
        }
        
        // Collect numbers from buckets and push back to stack a
        for (int i = 9; i >= 0; i--) 
		{
    		while (sb[i] != NULL)
			{
        		int number = pop(&sb[i])->data;
        		printf("Collecting %d from bucket %d\n", number, i); // Debug
        		push(sa, number);
    		}
		}
    }
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		write (1, "Need more arguments\n", 19);
		return 1;
	}
	struct Node *stack_a = NULL;
	int error = 0;

	long x;
	int i = 1;

	while (i < argc)
	{
		x = ft_atoi(argv[i], &error);
		if (error)
		{
			write(1, "Wrong Argument\n", 15);
			return 1;
		}
		push(&stack_a, x);
		i++;
	}

	int size = count_size(stack_a); 

	struct Node *stack_b[10] = {NULL}; // Initialize an array of 10 stack pointers, all NULL

	display(stack_a);

	radix(&stack_a, stack_b);

	display(stack_a);

	free_stack(stack_a);
	return 0;
}