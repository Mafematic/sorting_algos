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
		return;
	}
	else
	{
		t->data = x;
		t->next = *p;
		*p = t;
	}
}

void append(struct Node **p, int x)
{
	struct Node *t, *last;
	t = (struct Node *)malloc(sizeof(struct Node));

	if (t == NULL)
	{
		printf("Memory Allocation failed.\n");
		return;
	}

	t->data = x;
	t->next = NULL;

	if (*p == NULL) // if it's the first node
	{
		*p = t;
	}
	else // navigate to the last node and append
	{
		last = *p;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = t;
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
	if (*a == NULL || (*a)->next == NULL)
	{
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
	if (*b == NULL || (*b)->next == NULL)
	{
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
	if (*a == NULL || (*a)->next == NULL)
	{
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
	if (*b == NULL || (*b)->next == NULL)
	{
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
	if (*a == NULL || (*a)->next == NULL)
	{
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
	if (*b == NULL || (*b)->next == NULL)
	{
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

int find_min(struct Node *p)
{
	int min = p->data;
	while (p != NULL)
	{
		if (p->data < min)
		{
			min = p->data;
		}
		p = p->next;
	}
	return min;
}

int count_digits(int max)
{
	int count = 0;
	if (max == 0)
		return 1;
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

int check_if_sorted(struct Node *s)
{
	while (s != NULL && s->next != NULL)
	{
		if (s->next->data < s->data)
		{
			return 0;
		}
		s = s->next;
	}
	return 1;
}

int check_if_reverse_sorted(struct Node *s)
{
	while (s != NULL && s->next != NULL)
	{
		if (s->next->data > s->data)
		{
			return 0;
		}
		s = s->next;
	}
	return 1;
}

int position_minimum(struct Node *p, int min)
{
	int index = 0;
	while (p != NULL)
	{
		if (min == p->data)
		{
			return index;
		}
		index++;
		p = p->next;
	}
	return -1;
}

int position_maximum(struct Node *p, int max)
{
	int index = 0;
	while (p != NULL)
	{
		if (max == p->data)
		{
			return index;
		}
		index++;
		p = p->next;
	}
	return -1;
}

void sort_size_three(struct Node **stack_a)
{
	// Case 3 1 2
	if ((*stack_a)->data > (*stack_a)->next->next->data && (*stack_a)->next->data < (*stack_a)->next->next->data)
	{
		ra(stack_a);
		printf("ra\n");
	}
	// Case 2 1 3
	else if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->data < (*stack_a)->next->next->data)
	{
		sa(stack_a);
		printf("sa\n");
	}
	// Case 1 3 2
	else if ((*stack_a)->data < (*stack_a)->next->next->data && (*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		sa(stack_a);
		ra(stack_a);
		printf("sa\n");
		printf("ra\n");
	}
	// Case 2 3 1
	else if ((*stack_a)->data > (*stack_a)->next->next->data && (*stack_a)->next->data > (*stack_a)->data)
	{
		rra(stack_a);
		printf("rra\n");
	}
	// Case 3 2 1
	else if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		sa(stack_a);
		rra(stack_a);
		printf("sa\n");
		printf("rra\n");
	}
}

void sort_size_four(struct Node **stack_a, struct Node **stack_b, int size)
{
	int min = find_min(*stack_a);
	int pos = position_minimum(*stack_a, min);
	// printf("Min: %d\n", min);
	// printf("Position: %d\n", pos);
	if (pos == 3)
	{
		while (1)
		{
			if ((*stack_a)->data == min)
			{
				pb(stack_a, stack_b);
				printf("pb\n");
				break;
			}
			rra(stack_a);
			printf("rra\n");
		}
	}
	else
	{
		while (1)
		{
			if ((*stack_a)->data == min)
			{
				pb(stack_a, stack_b);
				printf("pb\n");
				break;
			}
			ra(stack_a);
			printf("ra\n");
		}
	}
	size--;
	sort_size_three(stack_a);
	pa(stack_a, stack_b);
	printf("pa\n");
}

void sort_size_five(struct Node **stack_a, struct Node **stack_b, int size)
{
	int min = find_min(*stack_a);
	int pos = position_minimum(*stack_a, min);
	// printf("Min: %d\n", min);
	// printf("Position: %d\n", pos);
	if (pos == 3 || pos == 4)
	{
		while (1)
		{
			if ((*stack_a)->data == min)
			{
				pb(stack_a, stack_b);
				printf("pb\n");
				break;
			}
			rra(stack_a);
			printf("rra\n");
		}
	}
	else
	{
		while (1)
		{
			if ((*stack_a)->data == min)
			{
				pb(stack_a, stack_b);
				printf("pb\n");
				break;
			}
			ra(stack_a);
			printf("ra\n");
		}
	}
	size--;
	sort_size_four(stack_a, stack_b, size);
	pa(stack_a, stack_b);
	printf("pa\n");
}

void sort_size_other(struct Node **stack_a, struct Node **stack_b)
{
	struct Node *a_first = NULL;
	struct Node *a_second = NULL;
	struct Node *a_last = NULL;
	struct Node *temp_a = NULL;

	struct Node *b_first = NULL;
	struct Node *b_second = NULL;
	struct Node *b_last = NULL;
	struct Node *temp_b = NULL;

	while (1)
	{
		temp_a = *stack_a;
		temp_b = *stack_b;

		a_first = temp_a;
		if (temp_a)
			a_second = temp_a->next;
		else
			a_second = NULL;

		b_first = temp_b;

		if (temp_b)
			b_second = temp_b->next;
		else
			b_second = NULL;

		while (temp_a && temp_a->next)
		{
			temp_a = temp_a->next;
		}
		a_last = temp_a;

		while (temp_b && temp_b->next)
		{
			temp_b = temp_b->next;
		}
		b_last = temp_b;

		// Exit condition - might need further refinement
		if ((check_if_sorted(*stack_a) && check_if_reverse_sorted(*stack_b)) ||
			(check_if_sorted(*stack_a) && !temp_b))
		{
			break;
		}
		if (b_first && b_last && b_first->data < b_last->data)
		{
			rb(stack_b);
			printf("rb\n");
			continue;
		}
		if (b_first && b_second && b_first->data < b_second->data)
		{
			sb(stack_b);
			printf("sb\n");
			continue;
		}
		if (a_first && a_last && a_first->data > a_last->data)
		{
			ra(stack_a);
			printf("ra\n");
			continue;
		}
		if (a_first && a_second && a_first->data > a_second->data)
		{
			sa(stack_a);
			printf("sa\n");
			continue;
		}
		if (a_first && a_second && a_first->data < a_second->data)
		{
			pb(stack_a, stack_b);
			printf("pb\n");
			continue;
		}
		if (a_first && b_first && a_first->data > b_first->data)
		{
			pa(stack_a, stack_b);
			printf("pa\n");
			continue;
		}
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		printf("pa\n");
	}
}

void push_swap(struct Node **stack_a, struct Node **stack_b)
{
	int size = count_size(*stack_a);
	if (check_if_sorted(*stack_a))
	{
		// printf("Already sorted.\n");
		return;
	}
	if (size <= 1)
	{
		return;
	}
	if (size == 2)
	{
		if ((*stack_a)->data < (*stack_a)->next->data)
		{
			sa(stack_a);
			printf("sa\n");
		}
		return;
	}
	if (size == 3)
	{
		sort_size_three(stack_a);
	}
	if (size == 4)
	{
		sort_size_four(stack_a, stack_b, size);
	}
	if (size == 5)
	{
		sort_size_five(stack_a, stack_b, size);
	}
	if (size > 5)
	{
		sort_size_other(stack_a, stack_b);
	}
}

int main(void)
{
	struct Node *stack_a = NULL;
	struct Node *stack_b = NULL;

	// Create a static stack, feel free to change these numbers
	long numbers[] = {15, 8, 32, 3, 21, 12}; // example numbers
	int size = sizeof(numbers) / sizeof(numbers[0]);

	for (int i = 0; i < size; i++)
	{
		append(&stack_a, numbers[i]);
	}

	display(stack_a);
	display(stack_b);

	push_swap(&stack_a, &stack_b);

	display(stack_a);
	display(stack_b);

	free_stack(stack_a);
	return 0;
}
