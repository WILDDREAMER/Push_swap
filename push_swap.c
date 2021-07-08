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
	free_t_stack(a);
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
			write(1, "rrr\n", 4);
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

void free_double_pointer(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
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
		free_double_pointer(args);
	}
	else
	{
		number_of_args = argc - 1;
		args = argv + 1;
	}
	i = number_of_args;
	check_duplicated_elements(args, number_of_args);
	while (--i >= 0)
		push(&head_a, ft_atoi(args[i]));
	if (!ft_strcmp(checker(head_a), "\e[1;32mOK\n"))
		return(0);
	// sort_three(head_a, &instrcs);
	// sort_five(&head_a, &head_b, &instrcs);
	sort_big_numbers(&head_a, &head_b, &instrcs);
	optimize_instrucs(&instrcs);
	// visualize(head_a, head_b);
	free_t_instrcs(instrcs);
	free_t_stack(head_a);
	// free_t_stack(head_b);
	
	return (1);
}