#include "push_swap.h"

int handle_input(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "sa"))
		swap(*a);
	else if (!ft_strcmp(line, "sb"))
		swap(*b);
	else if (!ft_strcmp(line, "ss"))
		ss(*a, *b);
	else if (!ft_strcmp(line, "pa"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb"))
		pb(a, b);
	else if (!ft_strcmp(line, "ra"))
		rotate(a);
	else if (!ft_strcmp(line, "rb"))
		rotate(b);
	else if (!ft_strcmp(line, "rr"))
		rr(a, b);
	else if (!ft_strcmp(line, "rra"))
		reverse_rotate(a);
	else if (!ft_strcmp(line, "rrb"))
		reverse_rotate(b);
	else if (!ft_strcmp(line, "rrr"))
		rrr(a, b);
	else
	{
		write(1, RED, ft_strlen(RED));
		write(1, "SYNTAX ERROR\n", 13);
		write(1, WHT, ft_strlen(WHT));
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	sort_two(t_stack	*head)
{
	int min;
	int max;
	if (stack_size(head) != 2)
		return (0);
	min = get_index_of_min(head);
	if (min != 0)
	{
		swap(head);
			write(1, "sa\n", 3);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int	unsort_two(t_stack	*head)
{
	int min;
	int max;
	if (stack_size(head) != 2)
		return (0);
	min = get_index_of_min(head);
	if (min == 0)
	{
		swap(head);
			write(1, "sb\n", 3);
		return(1);
	}
	return (1);
}

int	sort_three(t_stack	*head)
{
	int min;
	int max;

	min = get_index_of_min(head);
	max = get_index_of_max(head);
	if (stack_size(head) != 3)
		return (0);
	if ((min == 0) && (max == 2))
		return(1);
	else if ((min == 2) && (max == 0))
	{
		write(1, "ra\n", 3);
		write(1, "sa\n", 3);
		return(1);
	}
	else if ((min == 2) && (max == 1))
	{
		write(1, "rra\n", 4);
		return(1);
	}
	else if ((min == 1) && (max == 0))
	{
		write(1, "ra\n", 3);
		return(1);
	}
	else if ((min == 0) && (max == 1))
	{
		write(1, "rra\n", 4);
		write(1, "sa\n", 3);
		return(1);
	}
	else if ((min == 1) && (max == 2))
	{
		write(1, "sa\n", 3);
		return(1);
	}
	return(0);
}

int	sort_five(t_stack	**a, t_stack **b)
{
	int min;
	int sec_min;
	int i;
	int j;

	i = 2;
	sec_min = get_val_of_second(*a);
	while (--i >= 0)
	{
		min = get_index_of_min(*a);
		if (min <= 2)
		{
			while (--min >= 0)
			{
				if (sec_min == (*a)->val)
				{
					write(1, "pb\n", 3);
					pb(a, b);
					--min;
					--i;
				}
				write(1, "ra\n", 3);
				rotate(a);
			}
			write(1, "pb\n", 3);
			pb(a, b);
			unsort_two(*b);
			sort_three(*a);
			write(1, "pa\npa\n", 6);
			pa(a, b);
			pa(a, b);
		}
	}
	return(0);
}

int main(int argc, char **argv)
{
	t_stack *head_a;
	t_stack *head_b;
	char **args;
	char *line;
	int number_of_args;
	int i;

	if (argc < 2)
		return 0;
	number_of_args = 0;
	head_a = NULL;
	head_b = NULL;
	args = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		number_of_args = args_length(args);
	}
	else
	{
		number_of_args = argc - 1;
		args = argv + 1;
	}
	i = number_of_args;
	check_duplicated_elements(args, number_of_args);
	while (--i >= 0)
		push(&head_a, atoi(args[i]));
	sort_five(&head_a, &head_b);
	return (1);
}