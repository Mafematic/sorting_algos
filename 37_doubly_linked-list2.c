#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct DoublyLinkedList
{
	Node *head;
	Node *tail;
} DoublyLinkedList;

// Initialize a new node
Node *create_node(long data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		perror("Failed to create node");
		exit(1);
	}
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

// Append a new node at the end
void append(DoublyLinkedList **stack, long data)
{
	Node *new_node = create_node(data);
	if (*stack == NULL)
	{
		*stack = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
		if (*stack == NULL)
		{
			perror("Failed to initialize stack");
			exit(1);
		}
		(*stack)->head = new_node;
		(*stack)->tail = new_node;
		new_node->prev = new_node; // Point to itself initially
		new_node->next = new_node; // Point to itself initially
	}
	else
	{
		new_node->prev = (*stack)->tail;
		new_node->next = (*stack)->head; // The new node's next is the head

		(*stack)->tail->next = new_node; // Old tail's next is the new node
		(*stack)->head->prev = new_node; // Head's previous is the new node
		(*stack)->tail = new_node;
	}
}

void display(DoublyLinkedList *stack)
{
	if (stack == NULL)
	{
		printf("Empty Stack\n");
		return;
	}

	Node *p = stack->head;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void free_stack(DoublyLinkedList *stack)
{
	if (stack == NULL)
		return; // Check if the stack is already NULL

	Node *p = stack->head;
	Node *temp;

	while (p != NULL)
	{
		temp = p;
		p = p->next;
		free(temp);
	}

	free(stack); // Free the DoublyLinkedList structure itself
}

void push(DoublyLinkedList **stack, int x)
{
	Node *t = create_node(x);

	if (!*stack)
	{
		*stack = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
		if (!*stack)
		{
			perror("Failed to initialize stack");
			exit(1);
		}
		(*stack)->head = t;
		(*stack)->tail = t;
	}
	else
	{
		t->next = (*stack)->head;
		(*stack)->head->prev = t;
		(*stack)->head = t;
	}
}

Node *pop(DoublyLinkedList **stack)
{
	if (!*stack || !(*stack)->head)
	{
		return NULL;
	}

	Node *temp = (*stack)->head;
	(*stack)->head = (*stack)->head->next;

	if ((*stack)->head)
	{
		(*stack)->head->prev = NULL;
	}
	else
	{
		(*stack)->tail = NULL; // The stack is empty after the pop
	}

	return temp;
}

void pa(DoublyLinkedList **a, DoublyLinkedList **b)
{
	Node *node = pop(b);
	if (node)
	{
		push(a, node->data);

		if (!(*a)->head->next)
		{
			(*a)->tail = (*a)->head;
		}
		free(node);
	}
}

void pb(DoublyLinkedList **a, DoublyLinkedList **b)
{
	Node *node = pop(a);
	if (node)
	{
		push(b, node->data);

		if (!(*b)->head->next)
		{
			(*b)->tail = (*b)->head;
		}
		free(node);
	}
}

void sa(DoublyLinkedList **a)
{
	if (!*a || !(*a)->head || !(*a)->head->next)
	{
		return; // Nothing to swap
	}
	Node *first = (*a)->head;
	Node *second = first->next;

	first->next = second->next;
	if (second->next)
	{
		second->next->prev = first;
	}
	second->prev = NULL;
	second->next = first;
	first->prev = second;

	if (first == (*a)->tail)
	{
		(*a)->tail = second;
	}

	(*a)->head = second;
}

void sb(DoublyLinkedList **b)
{
	sa(b); // Use the same logic for sb as sa
}

void ss(DoublyLinkedList **a, DoublyLinkedList **b)
{
	sa(a);
	sb(b);
}

void ra(DoublyLinkedList **a)
{
	if (!*a || !(*a)->head || !(*a)->head->next)
	{
		return; // Nothing to rotate
	}
	Node *temp = (*a)->head;

	(*a)->head = (*a)->head->next;
	(*a)->head->prev = NULL;

	(*a)->tail->next = temp;
	temp->prev = (*a)->tail;
	temp->next = NULL;
	(*a)->tail = temp;
}

void rb(DoublyLinkedList **b)
{
	ra(b); // Use the same logic for rb as ra
}

void rr(DoublyLinkedList **a, DoublyLinkedList **b)
{
	ra(a);
	rb(b);
}

void rra(DoublyLinkedList **a)
{
	if (!*a || !(*a)->head || !(*a)->head->next)
	{
		return;
	}

	Node *last = (*a)->tail;
	(*a)->tail = (*a)->tail->prev;
	(*a)->tail->next = NULL;

	last->next = (*a)->head;
	last->prev = NULL;
	(*a)->head->prev = last;

	(*a)->head = last;
}

void rrb(DoublyLinkedList **b)
{
	rra(b); // Use the same logic for rrb as rra
}

void rrr(DoublyLinkedList **a, DoublyLinkedList **b)
{
	rra(a);
	rrb(b);
}

int count_size(DoublyLinkedList *list)
{
	int count = 0;

	if (!list || !list->head)
		return 0; // if the list is empty or list head is null, return 0

	Node *current = list->head;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

int check_if_sorted(DoublyLinkedList *list)
{
	if (!list || !list->head)
		return 1; // if the list is empty or list head is null, consider it sorted

	Node *current = list->head;

	while (current->next != NULL)
	{
		if (current->next->data < current->data)
		{
			return 0;
		}
		current = current->next;
	}
	return 1;
}

int find_min(DoublyLinkedList *list)
{
	int min = INT32_MAX;
	struct Node *p = list->head;
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

int position_minimum(DoublyLinkedList *list, int min)
{
	int index = 0;
	struct Node *p = list->head;
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

void sort_size_three(DoublyLinkedList **stack_a)
{
	if (!*stack_a || !(*stack_a)->head || !(*stack_a)->head->next || !(*stack_a)->head->next->next)
	{
		return; // Nothing to sort, should not happen as this function is for size 3 stacks
	}

	int first = (*stack_a)->head->data;
	int second = (*stack_a)->head->next->data;
	int third = (*stack_a)->head->next->next->data;

	// Case 3 1 2
	if (first > third && second < third)
	{
		ra(stack_a);
		printf("ra\n");
	}
	// Case 2 1 3
	else if (first > second && first < third)
	{
		sa(stack_a);
		printf("sa\n");
	}
	// Case 1 3 2
	else if (first < third && second > third)
	{
		sa(stack_a);
		ra(stack_a);
		printf("sa\n");
		printf("ra\n");
	}
	// Case 2 3 1
	else if (first > third && second > first)
	{
		rra(stack_a);
		printf("rra\n");
	}
	// Case 3 2 1
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
		printf("sa\n");
		printf("rra\n");
	}
}

void sort_size_four(DoublyLinkedList **stack_a, DoublyLinkedList **stack_b)
{
	int min = find_min(*stack_a);
	int pos = position_minimum(*stack_a, min);

	// Move the minimum value to the top of the stack
	if (pos == 2) // if position_minimum is 0-based
	{
		while ((*stack_a)->head->data != min)
		{
			rra(stack_a);
			printf("rra\n");
		}
	}
	else
	{
		while ((*stack_a)->head->data != min)
		{
			ra(stack_a);
			printf("ra\n");
		}
	}

	// Push the minimum value to stack_b
	pb(stack_a, stack_b);
	printf("pb\n");

	// Sort the remaining 3 elements
	sort_size_three(stack_a);

	// Pop the element back from stack_b to stack_a
	pa(stack_a, stack_b);
	printf("pa\n");
}

void sort_size_five(DoublyLinkedList **list_a, DoublyLinkedList **list_b, int size)
{
	int min = find_min(*list_a);
	int pos = position_minimum(*list_a, min);

	if (pos == 3 || pos == 4)
	{
		while ((*list_a)->head->data != min)
		{
			rra(list_a);
			printf("rra\n");
		}
	}
	else
	{
		while ((*list_a)->head->data != min)
		{
			ra(list_a);
			printf("ra\n");
		}
	}

	pb(list_a, list_b);
	printf("pb\n");

	size--;

	sort_size_four(list_a, list_b);

	pa(list_a, list_b);
	printf("pa\n");
}

int move_to_top(DoublyLinkedList **stack, struct Node *node)
{
	if (node == (*stack)->head)
	{
		return 0;
	}
	else if (node == (*stack)->head->next)
	{
		//sa(stack);
		//printf("sa\n");
		return 1;
	}
	else if (node == (*stack)->tail->prev)
	{
		//rra(stack);
		//rra(stack);
		//printf("rra\n");
		//printf("rra\n");
		return 2;
	}
	else if (node == (*stack)->tail)
	{
		//rra(stack);
		//printf("rra\n");
		return 1;
	}
	return -1; // This is for unexpected cases. It's good to handle or at least acknowledge them.
}

void move_to_top_op(DoublyLinkedList **stack, struct Node *node)
{
	if (node == (*stack)->head)
	{
		return ;
	}
	else if (node == (*stack)->head->next)
	{
		sa(stack);
		printf("sa\n");
		return ;
	}
	else if (node == (*stack)->tail->prev)
	{
		rra(stack);
		rra(stack);
		printf("rra\n");
		printf("rra\n");
		return ;
	}
	else if (node == (*stack)->tail)
	{
		rra(stack);
		printf("rra\n");
		return ;
	}
	printf("Mistake\n"); 
	return ; // This is for unexpected cases. It's good to handle or at least acknowledge them.
}

typedef struct Result
{
	int data;
	int is_valid;
} Result;

Result get_middle_of_stack(DoublyLinkedList *stack)
{
	Result res;
	if (!stack || !stack->head)
	{
		res.is_valid = 0; // invalid data
		return res;
	}

	int half = count_size(stack) / 2;
	struct Node *mid = stack->head;

	int i = 0;
	while (i < half)
	{
		mid = mid->next;
		i++;
	}

	res.data = mid->data;
	res.is_valid = 1; 
	return res;
}

int count_operations_to_insert(DoublyLinkedList **stack_b, int value)
{
	Result mid_res = get_middle_of_stack(*stack_b);
	int mid; 
	int count = 0;

	if (!mid_res.is_valid)
		return 1; // just push

	mid = mid_res.data;
	if (value < (*stack_b)->tail->data)
		return 2; // pb and rb

	else if (value > (*stack_b)->head->data)
		return 1; // pb

	else
	{
		struct Node *current;

		if (value > mid)
		{
			// Count the reverse rotations needed without actually rotating.
			current = (*stack_b)->head;
			while (value < current->data && current->prev != NULL)
			{
				count++;
				current = current->prev;
			}
		}
		else
		{
			// Count the rotations needed without actually rotating.
			current = (*stack_b)->tail;
			while (value > current->data && current->next != NULL)
			{
				count++;
				current = current->next;
			}
		}
	}
	return count + 1; // +1 for the pb operation
}

void run_operations_to_insert(DoublyLinkedList **stack_a, DoublyLinkedList **stack_b, int value)
{
	Result mid_res = get_middle_of_stack(*stack_b);
	int mid;

	if (!mid_res.is_valid)
	{
		pb(stack_a, stack_b); 
		printf("pb\n");
		return ;
	}
	mid = mid_res.data;
	if (value < (*stack_b)->tail->data)
	{
		pb(stack_a, stack_b);
		printf("pb\n");
		rb(stack_b);
		printf("rb\n");
		return ;
	}
	if (value > (*stack_b)->head->data)
	{
		pb(stack_a, stack_b);
		printf("pb\n");
		return ;
	}
	else
	{
		if (value > mid)
		{
			while (value < (*stack_b)->head->data)
			{
				rb(stack_b);
				printf("rb\n");
			}
			pb(stack_a, stack_b);
			printf("pb\n");
			return;
		}
		else // if value < mid
		{
			while (value > (*stack_b)->tail->data)
			{
				rrb(stack_b);
				printf("rrb\n");
			}
			pb(stack_a, stack_b);
			printf("pb\n");
			return;
		}
	}
}

int calculate_ops(DoublyLinkedList **stack_a, DoublyLinkedList **stack_b, struct Node *node)
{
	int operations = 0;
	operations += move_to_top(stack_a, node);			   // Just count moves
	operations += count_operations_to_insert(stack_b, node->data); // Just count moves
	return operations;
}

void perform_best_operation(DoublyLinkedList **stack_a, DoublyLinkedList **stack_b, struct Node *node)
{
	
	move_to_top_op(stack_a, node); // move the node to top of stack_a
	run_operations_to_insert(stack_a, stack_b, node->data); 		

	//printf("Performed operations for node: %d\n", node->data);
}

void sort_size_other(DoublyLinkedList **stack_a, DoublyLinkedList **stack_b)
{
	struct Node *a_first = NULL;
	struct Node *a_second = NULL;
	struct Node *a_before_last = NULL;
	struct Node *a_last = NULL;

	struct Node *b_first = NULL;
	struct Node *b_second = NULL;
	struct Node *b_before_last = NULL;
	struct Node *b_last = NULL;

	int i = 0;
	while (i < 4)
	{
		if (stack_a && *stack_a)
		{
			a_first = (*stack_a)->head;
			a_last = (*stack_a)->tail;
			a_second = a_first ? a_first->next : NULL;
			a_before_last = a_last ? a_last->prev : NULL;
		}

		if (stack_b && *stack_b)
		{
			b_first = (*stack_b)->head;
			b_last = (*stack_b)->tail;
			b_second = b_first ? b_first->next : NULL;
			b_before_last = b_last ? b_last->prev : NULL;
		}

		if (a_first)
			printf("first: %d\n", a_first->data);
		if (a_second)
			printf("second: %d\n", a_second->data);
		if (a_before_last)
			printf("pre-last: %d\n", a_before_last->data);
		if (a_last)
			printf("last: %d\n", a_last->data);

		int ops1 = calculate_ops(stack_a, stack_b, a_first);
		int ops2 = calculate_ops(stack_a, stack_b, a_second);
		int ops3 = calculate_ops(stack_a, stack_b, a_before_last);
		int ops4 = calculate_ops(stack_a, stack_b, a_last);

		printf("Ops 1: %d\n", ops1);
		printf("Ops 2: %d\n", ops2);
		printf("Ops 3: %d\n", ops3);
		printf("Ops 4: %d\n", ops4);

		struct Node *min_op_node = a_first; // default
		int min_ops = ops1;

		if (ops2 < min_ops)
		{
			min_ops = ops2;
			min_op_node = a_second;
		}

		if (ops3 < min_ops)
		{
			min_ops = ops3;
			min_op_node = a_before_last;
		}

		if (ops4 < min_ops)
		{
			min_ops = ops4;
			min_op_node = a_last;
		}

		perform_best_operation(stack_a, stack_b, min_op_node); // perform operations for the node with minimum operations.
		i++;
	}
}

void push_swap(DoublyLinkedList * *stack_a, DoublyLinkedList * *stack_b)
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
		if ((*stack_a)->head->data > (*stack_a)->head->next->data)
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
		sort_size_four(stack_a, stack_b);
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
	DoublyLinkedList *stack_a = NULL;
	DoublyLinkedList *stack_b = NULL;

	// Create a static stack, feel free to change these numbers
	long numbers[] = {18, 4, 15, 3, 1, 6}; // example numbers
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
