/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:56:43 by ozakkare          #+#    #+#             */
/*   Updated: 2021/07/09 11:37:31 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

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
	check_args(argc, &vars, argv);
	push_swap(&vars, &head_a, &head_b, &instrcs);
	return (1);
}
