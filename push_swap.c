#include "./includes/push_swap.h"

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

int	add_node(char *val, t_instructions **instrcs)
{
	t_instructions *new;
	t_instructions *curr;

	curr = (*instrcs);
	new = malloc(sizeof(t_instructions));
	new->val = val;
	new->next = NULL;
	if ((*instrcs) == NULL)
	{
		(*instrcs) = new;
		return (0);
	}
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	return (1);
}

int	sort_two(t_stack	*head, t_instructions **instrcs)
{
	int min;
	int max;
	if (stack_size(head) != 2)
		return (0);
	min = get_index_of_min(head);
	if (min != 0)
	{
		swap(head);
		add_node("sa", instrcs);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int	unsort_two(t_stack	*head, t_instructions **instcs)
{
	int min;
	int max;
	if (stack_size(head) != 2)
		return (0);
	min = get_index_of_min(head);
	if (min == 0)
	{
		swap(head);
			add_node("sb", instcs);
		return(1);
	}
	return (1);
}

int	sort_three(t_stack	*head, t_instructions **instrcs)
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
		add_node("ra", instrcs);
		add_node("sa", instrcs);
		return(1);
	}
	else if ((min == 2) && (max == 1))
	{
		add_node("rra", instrcs);
		return(1);
	}
	else if ((min == 1) && (max == 0))
	{
		add_node("ra", instrcs);
		return(1);
	}
	else if ((min == 0) && (max == 1))
	{
		add_node("rra", instrcs);
		add_node("sa", instrcs);
		return(1);
	}
	else if ((min == 1) && (max == 2))
	{
		add_node("sa", instrcs);
		return(1);
	}
	return(0);
}

int check_second_last(t_stack **a, t_stack **b, int *stop)
{
	int sec_min;

	sec_min = get_val_of_second(*a);
	if (*stop)
		return(0);
	if (sec_min == (*a)->prev->val)
	{
		write(1, "rra\n", 4);
		reverse_rotate(a);
		write(1, "pb\n", 3);
		pb(a, b);
		*stop = 1;
		return (1);
	}
	return (0);
}

int	sort_five(t_stack	**a, t_stack **b, t_instructions **instrcs)
{
	int min_index;
	int min_val;
	int stop_checking_for_second;
	int i;
	int j;
	int sec_min;

	// if((*a)->val == get_val_of_max(*a) && (*a)->next->val == get_val_of_second_max(*a))
	// {
	// 	swap(*a);
	// 	add_node("sa", instrcs);
	// }

	sec_min = get_val_of_second(*a);
	i = 0;
	stop_checking_for_second = 0;
	while (++i <= 2)
	{
		i += check_second_last(a, b, &stop_checking_for_second);
		min_index = get_index_of_min(*a);
		min_val = get_val_of_min(*a);
		if ((stack_size(*a) - min_index) >= 3)
		{
			while (--min_index >= 0)
			{
				if (sec_min == (*a)->val && !stop_checking_for_second )
				{
					add_node("pb", instrcs);
					pb(a, b);
					--min_index;
					++i;
					stop_checking_for_second = 1;
				}
				if (min_val != (*a)->val)
				{
					add_node("ra", instrcs);
					rotate(a);
				}
			}
			add_node("pb", instrcs);
			pb(a, b);
			stop_checking_for_second = 1;
		}
		else
		{
			while (++min_index <= 5)
			{
				if (i == 2)
					++min_index;
				if (check_second_last(a, b, &stop_checking_for_second))
				{
					++i;
					++min_index;
				}
				add_node("rra", instrcs);
				reverse_rotate(a);
			}
			add_node("pb", instrcs);
			pb(a, b);
			stop_checking_for_second = 1;
		}
	}
	unsort_two(*b, instrcs);
	sort_three(*a, instrcs);
	add_node("pa", instrcs);
	add_node("pa", instrcs);
	pa(a, b);
	pa(a, b);
	return(0);
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
int optimize_instrucs(t_instructions **head)
{
	t_instructions *curr;

	curr = *head;
	while (curr)
	{
		if(curr->next
			&& ((!ft_strcmp(curr->val, "ra") && !ft_strcmp(curr->next->val, "rb")) || 
			(!ft_strcmp(curr->next->val, "ra") && !ft_strcmp(curr->val, "rb"))))
		{
			write(1, "rr\n", 3);
			curr = curr->next->next;
		}
		else if(curr->next
			&& ((!ft_strcmp(curr->val, "rra") && !ft_strcmp(curr->next->val, "rrb")) || 
			(!ft_strcmp(curr->next->val, "rra") && !ft_strcmp(curr->val, "rrb"))) )
		{
			write(1, "rrr\n", 3);
			curr = curr->next->next;
		}
		else{
			write(1, curr->val, ft_strlen(curr->val));
			write(1, "\n", 1);
			curr = curr->next;
		}
	}
	return 1;
}

int main(int argc, char **argv)
{
	t_stack *head_a;
	t_stack *head_b;
	t_instructions *instrcs;

	instrcs = NULL;
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
	if (!ft_strcmp(checker(head_a), "\e[1;32mOK\n"))
		return(0);
	sort_five(&head_a, &head_b, &instrcs);
	optimize_instrucs(&instrcs);
	
	return (1);
}