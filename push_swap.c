/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:56:43 by ozakkare          #+#    #+#             */
/*   Updated: 2021/07/08 21:11:25 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	handle_input_2(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "rb"))
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
}

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
	else
		handle_input_2(a, b, line);
	return (1);
}

char	*checker(t_stack *a)
{
	t_stack	*curr_node;
	int		curr_val;

	curr_val = a->val;
	curr_node = a->next;
	while (curr_node != a)
	{
		if (curr_val > curr_node->val)
			return ("\e[1;31mKO\n");
		curr_val = curr_node->val;
		curr_node = curr_node->next;
	}
	free_t_stack(a);
	return ("\e[1;32mOK\n");
}

void	push_swap(t_main *vars, t_stack **a,
	t_stack **b, t_instructions **instrcs)
{
	vars->i = vars->number_of_args;
	check_duplicated_elements(vars->args, vars->number_of_args);
	while (--vars->i >= 0)
		push(a, ft_atoi(vars->args[vars->i]));
	if (!ft_strcmp(checker(*a), "\e[1;32mOK\n"))
		exit(EXIT_SUCCESS);
	sort_three(*a, instrcs);
	sort_five(a, b, instrcs);
	sort_big_numbers(a, b, instrcs);
	if (vars->argc == 2)
		free_double_pointer(vars->args);
	optimize_instrucs(instrcs);
	free_t_instrcs(*instrcs);
	free_t_stack(*a);
	free_t_stack(*b);
}

int	main(int argc, char **argv)
{
	t_stack			*head_a;
	t_stack			*head_b;
	t_instructions	*instrcs;
	t_main			vars;

	vars.argc = argc;
	instrcs = NULL;
	if (argc < 2)
		return (0);
	vars.number_of_args = 0;
	head_a = NULL;
	head_b = NULL;
	vars.args = NULL;
	if (argc == 2)
	{
		vars.args = ft_split(argv[1], ' ');
		vars.number_of_args = args_length(vars.args);
	}
	else
	{
		vars.number_of_args = argc - 1;
		vars.args = argv + 1;
	}
	push_swap(&vars, &head_a, &head_b, &instrcs);
	return (1);
}
