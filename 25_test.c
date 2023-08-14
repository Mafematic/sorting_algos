#include <stdio.h>
#include <stdlib.h>
// ./ push_swap 2 1 3 6 5 8

struct stack
{
	int size;
	int top;
	int *s;
};

static int ft_iswhitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
	{
		return (1);
	}
	return (0);
}

int ft_atoi(const char *nptr)
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
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num += nptr[i] - '0';
		i++;
	}
	return (num * is_negative);
}

void
display(struct stack st)
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
	if (st->top == st->size - 1)
	{
		printf("Stack Overflow");
		return ;
	}
	else
	{
		st->top++;
		st->s[st->top] = x;
	}
}

int main(int argc, char **argv)
{
	struct stack st; 
	st.size = argc -; 
	st.top = -1;
	st.s = (int *)malloc(st.size * sizeof(int));

	int x; 

	int i = 1; 
	while (i < argc)
	{
		x = ft_atoi(argv[i]); 
		push(&st, x);
		i++;
	}

	display(st);
	free (st.s);

	return 0; 
}