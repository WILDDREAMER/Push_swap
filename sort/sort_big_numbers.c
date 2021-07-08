/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 19:16:33 by ozakkare          #+#    #+#             */
/*   Updated: 2021/07/08 19:53:03 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_target_b_top(t_big_numbers *vars, t_stack **b,
	t_instructions **instrcs)
{
	if (vars->index_curr_move < (vars->size / 2))
	{
		while (++vars->k < vars->index_curr_move)
		{
			rotate(b);
			add_node("rb", instrcs);
		}
	}
	else
	{
		while (++vars->k < (vars->size - vars->index_curr_move))
		{
			reverse_rotate(b);
			add_node("rrb", instrcs);
		}
	}
}

void	make_target_a_top(t_big_numbers *vars, t_stack **a,
	t_instructions **instrcs)
{
	if (vars->closest < (vars->size / 2))
	{
		while (++vars->k < vars->closest)
		{
			rotate(a);
			add_node("ra", instrcs);
		}
	}
	else
	{
		while (++vars->k < (vars->size - vars->closest))
		{
			reverse_rotate(a);
			add_node("rra", instrcs);
		}
	}
}

void	rotate_until_min_top(t_big_numbers *vars, t_stack **a,
	t_instructions **instrcs)
{
	if (vars->min_index > (vars->size / 2))
	{
		while ((*a)->val != vars->min_val)
		{
			reverse_rotate(a);
			add_node("rra", instrcs);
		}
	}
	else
	{
		while ((*a)->val != vars->min_val)
		{
			rotate(a);
			add_node("ra", instrcs);
		}
	}
}

void	last_step_(t_big_numbers *vars, t_stack **a, t_instructions **instrcs)
{
	vars->size = stack_size(*a);
	vars->min_index = get_index_of_min(*a);
	vars->min_val = get_val_of_min(*a);
	rotate_until_min_top(vars, a, instrcs);
}

void	sort_big_numbers(t_stack **a, t_stack **b, t_instructions **instrcs)
{
	t_big_numbers	vars;

	vars.i = -1;
	isolate_min_max(a, b, instrcs);
	vars.first_size = stack_size(*b);
	while (++vars.i < vars.first_size)
	{
		vars.size = stack_size(*b);
		vars.n_moves = malloc(vars.size * sizeof(int));
		vars.cur = *b;
		vars.j = -1;
		while (++vars.j < vars.size)
			calculate_instrcs(&vars, a, b);
		vars.k = -1;
		vars.index_curr_move = index_of_curr_move(vars.n_moves, vars.size);
		make_target_b_top(&vars, b, instrcs);
		vars.k = -1;
		vars.closest = get_index_of_closest(*a, (*b)->val);
		vars.size = stack_size(*a);
		make_target_a_top(&vars, a, instrcs);
		pa(a, b);
		add_node("pa", instrcs);
		free(vars.n_moves);
	}
	last_step_(&vars, a, instrcs);
}
