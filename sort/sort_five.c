/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:49:43 by ozakkare          #+#    #+#             */
/*   Updated: 2021/07/09 12:26:42 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	min_in_top(t_five *vars, t_stack **a,
	t_stack **b, t_instructions **instrcs)
{
	while (--vars->min_index >= 0)
	{
		if (vars->sec_min == (*a)->val && !vars->stop_checking_for_second)
		{
			add_node("pb", instrcs);
			pb(a, b);
			--vars->min_index;
			++vars->i;
			vars->stop_checking_for_second = 1;
		}
		if (vars->min_val != (*a)->val)
		{
			add_node("ra", instrcs);
			rotate(a);
		}
	}
	add_node("pb", instrcs);
	pb(a, b);
	vars->stop_checking_for_second = 1;
}

void	min_in_bottom(t_five *vars, t_stack **a,
	t_stack **b, t_instructions **instrcs)
{
	while (++vars->min_index <= 5)
	{
		if (vars->i == 2)
			++vars->min_index;
		if (check_second_last(a, b, &vars->stop_checking_for_second))
		{
			++vars->i;
			++vars->min_index;
		}
		add_node("rra", instrcs);
		reverse_rotate(a);
	}
	add_node("pb", instrcs);
	pb(a, b);
	vars->stop_checking_for_second = 1;
}

void	last_step(t_stack **a, t_stack **b, t_instructions **instrcs)
{
	unsort_two(*b, instrcs);
	sort_three(*a, instrcs);
	add_node("pa", instrcs);
	add_node("pa", instrcs);
	pa(a, b);
	pa(a, b);
}

int	sort_five(t_stack **a, t_stack **b, t_instructions **instrcs)
{
	t_five	vars;

	if ((*a)->val == get_val_of_max(*a)
		&& (*a)->next->val == get_val_of_second_max(*a))
	{
		swap(*a);
		add_node("sa", instrcs);
	}
	vars.sec_min = get_val_of_second(*a);
	vars.i = 0;
	vars.stop_checking_for_second = 0;
	while (++vars.i <= 2)
	{
		vars.i += check_second_last(a, b, &vars.stop_checking_for_second);
		vars.min_index = get_index_of_min(*a);
		vars.min_val = get_val_of_min(*a);
		if ((stack_size(*a) - vars.min_index) >= 3)
			min_in_top(&vars, a, b, instrcs);
		else
			min_in_bottom(&vars, a, b, instrcs);
	}
	last_step(a, b, instrcs);
	return (0);
}
