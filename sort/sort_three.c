/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:49:35 by ozakkare          #+#    #+#             */
/*   Updated: 2021/07/08 19:02:24 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	helper(int min, int max, t_instructions **instrcs)
{
	if ((min == 1) && (max == 0))
	{
		add_node("ra", instrcs);
		return (1);
	}
	else if ((min == 0) && (max == 1))
	{
		add_node("rra", instrcs);
		add_node("sa", instrcs);
		return (1);
	}
	else if ((min == 1) && (max == 2))
	{
		add_node("sa", instrcs);
		return (1);
	}
	return (0);
}

int	sort_three(t_stack	*head, t_instructions **instrcs)
{
	int	min;
	int	max;

	if (stack_size(head) != 3)
		return (0);
	min = get_index_of_min(head);
	max = get_index_of_max(head);
	if ((min == 0) && (max == 2))
		return (1);
	else if ((min == 2) && (max == 0))
	{
		add_node("ra", instrcs);
		add_node("sa", instrcs);
		return (1);
	}
	else if ((min == 2) && (max == 1))
	{
		add_node("rra", instrcs);
		return (1);
	}
	else
		return (helper(min, max, instrcs));
	return (0);
}
