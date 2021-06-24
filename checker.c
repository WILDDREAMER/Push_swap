#include "./includes/push_swap.h"

int	handle_input(t_stack **a, t_stack **b, char *line)
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
		write(1, "SYNTAX ERROR !\n", 15);
		exit(EXIT_FAILURE);
	}
	return (1);
}

char	*checker(t_stack *a)
{
	t_stack	*curr_node;
	int		curr_val;

	curr_val = a->val;
	curr_node = a->next;
	while(curr_node != a)
	{
		if (curr_val > curr_node->val)
			return ("\e[1;31mKO\n");
		curr_val = curr_node->val;
		curr_node = curr_node->next;
	}
	return ("\e[1;32mOK\n");
}

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;
	char	**args;
	char	*line;
	int		number_of_args;
	int		i;
	int		j;
	int		arg_len;

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
	if (number_of_args == 0)
		return (0);
	check_duplicated_elements(args, number_of_args);
	while (--i >= 0)
	{
		j = -1;
		arg_len = ft_strlen(args[i]);
		while (++j < arg_len)
			if (!ft_isdigit(args[i][j]))
			{
				write(1, RED, ft_strlen(RED));
				write(1, "SYNTAX ERROR !\n", 15);
				exit(EXIT_FAILURE);
			}
		push(&head_a, atoi(args[i]));
	}
	// visualize(head_a, head_b);
	while (get_next_line(0, &line) > 0)
	{	
		handle_input(&head_a, &head_b, line);
		// visualize(head_a, head_b);
	}
	printf("%s",checker(head_a));
	return (1);
}